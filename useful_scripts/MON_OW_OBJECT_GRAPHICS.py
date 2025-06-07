import re

# Starting hex ID
start_id_hex = 0x16A0

# Your species define list
species_defines = """
#define SPECIES_ROTOM_HEAT 0x2C9
#define SPECIES_ROTOM_WASH 0x2CA
#define SPECIES_ROTOM_FROST 0x2CB
#define SPECIES_ROTOM_FAN 0x2CC
#define SPECIES_ROTOM_MOW 0x2CD
"""  # Paste your #define list here

# Regex to capture species names
pattern = re.compile(r"#define SPECIES_([A-Z0-9_]+)\s+0x[0-9A-Fa-f]+")

def format_name(raw_name):
    parts = raw_name.lower().split('_')
    return ''.join(part.capitalize() for part in parts)

# Generate output
for i, match in enumerate(pattern.finditer(species_defines)):
    raw_name = match.group(1)
    name = format_name(raw_name)
    hex_id = start_id_hex + i
    print(f"    MON_OW_OBJECT_GRAPHICS({hex_id:X}, {name})")
