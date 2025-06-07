import re

# Starting hex ID (user-defined)
start_hex_id = 0x179F
start_hex_id_poke = 0x2C9

# Input species list
input_species_block = """
#define SPECIES_ROTOM_HEAT 0x2C9
#define SPECIES_ROTOM_WASH 0x2CA
#define SPECIES_ROTOM_FROST 0x2CB
#define SPECIES_ROTOM_FAN 0x2CC
#define SPECIES_ROTOM_MOW 0x2CD
"""

# Regex to extract species names
pattern = re.compile(r"#define SPECIES_([A-Z0-9_]+)")

# Process each line
species_names = []
for line in input_species_block.strip().splitlines():
    match = pattern.search(line)
    if match:
        species_names.append(match.group(1))

# Output lines with incremented hex IDs
for i, species in enumerate(species_names):
    hex_id = start_hex_id + i
    hex_id_2 = start_hex_id_poke + i
    print(f"        {{gFollowerMonPic2{hex_id_2}_{species.title()}ShinyPal, 0x{hex_id:04X}}},")
