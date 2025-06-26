import re

def ConvertHeaderToASM(inputFile, outputFile):
    with open(inputFile, 'r') as file:
        lines = file.readlines()

    definedMacros = {}
    orderedEqus = []
    rawEnumLines = []
    insideEnum = False
    inBlockComment = False

    # First Pass: Process #defines and collect enums
    for line in lines:
        line = line.strip()

        # Handle block comments
        if inBlockComment:
            if '*/' in line:
                inBlockComment = False
                line = line.split('*/', 1)[1].strip()
            else:
                continue

        if '/*' in line:
            if '*/' in line:
                line = re.sub(r'/\*.*?\*/', '', line)  # Remove inline block comment
            else:
                inBlockComment = True
                line = line.split('/*', 1)[0].strip()

        # Remove single-line comments
        line = line.split('//')[0].strip()
        if not line:
            continue

        # Simple #define (decimal or hex)
        defineMatch = re.match(r"#define\s+(\w+)\s+(0x[0-9A-Fa-f]+|\d+)", line)
        if defineMatch:
            macroName, value = defineMatch.groups()
            definedMacros[macroName] = int(value, 0)
            orderedEqus.append(f".equ {macroName}, {definedMacros[macroName]}")
            continue

        # Macro expression like BASE_MACRO + 1
        exprMatch = re.match(r"#define\s+(\w+)\s+(.+)", line)
        if exprMatch:
            macroName, expr = exprMatch.groups()
            try:
                value = eval(expr, {"__builtins__": None}, definedMacros)
                definedMacros[macroName] = value
                orderedEqus.append(f".equ {macroName}, {value}")
            except Exception:
                pass  # Skip if not evaluable yet
            continue

        # Enum detection
        if re.match(r"enum", line):
            insideEnum = True
            rawEnumLines.append(line)
            continue

        if insideEnum:
            rawEnumLines.append(line)
            if "}" in line:
                insideEnum = False

    # Second Pass: Evaluate enums
    enumValue = None
    for line in rawEnumLines:
        # End of enum block
        if "}" in line:
            enumValue = None
            continue

        # Enum entry with explicit value or expression
        entryMatch = re.match(r"\s*(\w+)\s*=\s*(.+?)(?:,)?$", line)
        if entryMatch:
            name, expr = entryMatch.groups()
            try:
                value = eval(expr, {"__builtins__": None}, definedMacros)
                definedMacros[name] = value
                orderedEqus.append(f".equ {name}, {value}")
                enumValue = value + 1
            except Exception as e:
                raise ValueError(f"Failed to evaluate expression '{expr}' for {name}: {e}")
            continue

        # Auto-incremented enum
        incrementMatch = re.match(r"\s*(\w+),", line)
        if incrementMatch:
            name = incrementMatch.group(1)
            if enumValue is None:
                raise ValueError(f"Auto-increment value uninitialized for '{name}'")
            definedMacros[name] = enumValue
            orderedEqus.append(f".equ {name}, {enumValue}")
            enumValue += 1
            continue

    # Write output
    with open(outputFile, 'w') as file:
        file.write('\n'.join(orderedEqus))
        file.write('\n')

    print(f"Conversion complete! {inputFile} ➝ {outputFile}")

# Conversion of trainer_defines.h so as to include it in scripts
ConvertHeaderToASM("src/Tables/trainer_defines.h", "trainers.s")
