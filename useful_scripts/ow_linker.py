import re

# Set your custom starting hex ID here
start_hex_id = 0x179f

# Your input species map — paste it below
input_species_block = """
#define SPECIES_ROTOM_HEAT 0x2C9
#define SPECIES_ROTOM_WASH 0x2CA
#define SPECIES_ROTOM_FROST 0x2CB
#define SPECIES_ROTOM_FAN 0x2CC
#define SPECIES_ROTOM_MOW 0x2CD
"""

# Pattern to extract species inside square brackets
pattern = re.compile(r"#define SPECIES_([A-Z0-9_]+)")

# Generate new formatted lines
lines = input_species_block.strip().splitlines()

for i, line in enumerate(lines):
    match = pattern.search(line)
    if match:
        species = match.group(1)
        hex_id = start_hex_id + i
        print(f"    [SPECIES_{species}] = 0x{hex_id:04X},")
