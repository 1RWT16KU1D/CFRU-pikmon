import os
from pathlib import Path
from difflib import get_close_matches

# Path configuration
BASE_DIR = Path(r"F:\Dark Worship 2\CFRU Base 2")
TRAINER_DATA_PATH = BASE_DIR / "src" / "Tables" / "trainer_tables.c"
TRAINER_PARTIES_PATH = BASE_DIR / "src" / "Tables" / "trainer_parties.h"
OPPONENTS_PATH = BASE_DIR / "include" / "constants" / "opponents.h"
SPECIES_PATH = BASE_DIR / "include" / "constants" / "species.h"
MOVES_PATH = BASE_DIR / "include" / "constants" / "moves.h"
ITEMS_PATH = BASE_DIR / "include" / "constants" / "items.h"
EASY_TEXT_PATH = BASE_DIR / "include" / "easy_text.h"

# Party type mappings
PARTY_TYPE_STRUCT_MAP = {
    1: "TrainerMonNoItemDefaultMoves",
    2: "TrainerMonItemDefaultMoves",
    3: "TrainerMonNoItemCustomMoves",
    4: "TrainerMonItemCustomMoves"
}

PARTY_TYPE_UNION_MAP = {
    1: "NoItemDefaultMoves",
    2: "ItemDefaultMoves", 
    3: "NoItemCustomMoves",
    4: "ItemCustomMoves"
}

def load_text_definitions():
    text_map = {}
    char_to_define = {}
    try:
        with open(EASY_TEXT_PATH, 'r', encoding='utf-8') as f:
            for line in f:
                if '#define _' in line and '0x' in line:
                    parts = line.split()
                    if len(parts) >= 3:
                        define = parts[1]
                        value = parts[2]
                        text_map[define] = value
                        if len(define) == 2 and define[1].isalpha():
                            char_to_define[define[1].upper()] = define
                        elif define == '_SPACE':
                            char_to_define[' '] = define
    except Exception as e:
        print(f"Error loading easy_text.h: {e}")
    return text_map, char_to_define

TEXT_DEFINITIONS, CHAR_TO_DEFINE = load_text_definitions()

# Tera Type options
TERA_TYPES = {
    '0': ('TYPE_NORMAL', 0x00),
    '1': ('TYPE_FIGHTING', 0x01),
    '2': ('TYPE_FLYING', 0x02),
    '3': ('TYPE_POISON', 0x03),
    '4': ('TYPE_GROUND', 0x04),
    '5': ('TYPE_ROCK', 0x05),
    '6': ('TYPE_BUG', 0x06),
    '7': ('TYPE_GHOST', 0x07),
    '8': ('TYPE_STEEL', 0x08),
    '9': ('TYPE_MYSTERY', 0x09),
    '10': ('TYPE_FIRE', 0x0a),
    '11': ('TYPE_WATER', 0x0b),
    '12': ('TYPE_GRASS', 0x0c),
    '13': ('TYPE_ELECTRIC', 0x0d),
    '14': ('TYPE_PSYCHIC', 0x0e),
    '15': ('TYPE_ICE', 0x0f),
    '16': ('TYPE_DRAGON', 0x10),
    '17': ('TYPE_DARK', 0x11),
    '18': ('TYPE_ROOSTLESS', 0x13),
    '19': ('TYPE_BLANK', 0x14),
    '20': ('TYPE_FAIRY', 0x17),
    '21': ('TYPE_STELLAR', 0x18)
}

AI_FLAGS = {
    '1': 'AI_SCRIPT_CHECK_BAD_MOVE',
    '2': 'AI_SCRIPT_SEMI_SMART',
    '3': 'AI_SCRIPT_CHECK_GOOD_MOVE',
    '4': 'AI_SCRIPT_TRY_TO_FAINT',
    '5': 'AI_SCRIPT_CHECK_VIABILITY',
    '6': 'AI_SCRIPT_SETUP_FIRST_TURN',
    '7': 'AI_SCRIPT_RISKY',
    '8': 'AI_SCRIPT_PREFER_STRONGEST_MOVE',
    '9': 'AI_SCRIPT_PREFER_BATON_PASS',
    '10': 'AI_SCRIPT_DOUBLE_BATTLE'
}

ABILITY_OPTIONS = {
    '0': 'Hidden',
    '1': 'Ability_1',
    '2': 'Ability_2',
    '3': 'Random Ability 1 & 2',
    '4': 'Random Any Ability'
}

NATURES = [
    "HARDY", "LONELY", "BRAVE", "ADAMANT", "NAUGHTY",
    "BOLD", "DOCILE", "RELAXED", "IMPISH", "LAX",
    "TIMID", "HASTY", "SERIOUS", "JOLLY", "NAIVE",
    "MODEST", "MILD", "QUIET", "BASHFUL", "RASH",
    "CALM", "GENTLE", "SASSY", "CAREFUL", "QUIRKY"
]

def load_species():
    species = set()
    try:
        with open(SPECIES_PATH, 'r', encoding='utf-8') as f:
            for line in f:
                if '#define SPECIES_' in line:
                    species.add(line.split()[1])
        return species
    except Exception as e:
        print(f"Error loading species.h: {e}")
        return {'SPECIES_PIKACHU', 'SPECIES_CHARIZARD'}

def load_moves():
    moves = set()
    try:
        with open(MOVES_PATH, 'r', encoding='utf-8') as f:
            for line in f:
                if '#define MOVE_' in line:
                    moves.add(line.split()[1])
        return moves
    except Exception as e:
        print(f"Error loading moves.h: {e}")
        return {'MOVE_TACKLE', 'MOVE_THUNDERBOLT'}

def load_items():
    items = set()
    try:
        with open(ITEMS_PATH, 'r', encoding='utf-8') as f:
            for line in f:
                if '#define ITEM_' in line:
                    items.add(line.split()[1])
        return items
    except Exception as e:
        print(f"Error loading items.h: {e}")
        return {'ITEM_POTION', 'ITEM_FULL_RESTORE'}

VALID_SPECIES = load_species()
VALID_MOVES = load_moves()
VALID_ITEMS = load_items()

def read_file(path):
    with open(path, 'r', encoding='utf-8') as f:
        return f.readlines()

def write_file(path, content):
    with open(path, 'w', encoding='utf-8') as f:
        f.writelines(content)

def parse_trainers(lines):
    trainers = {}
    current_trainer = None
    
    for i, line in enumerate(lines):
        line = line.strip()
        
        if line.startswith('[') and '] = {' in line:
            trainer_id = line.split('[')[1].split(']')[0]
            current_trainer = {'id': trainer_id, 'start_line': i, 'data': []}
        elif current_trainer and line.startswith('.'):
            current_trainer['data'].append(line)
        elif line == '},' and current_trainer:
            current_trainer['end_line'] = i
            trainers[current_trainer['id']] = current_trainer
            current_trainer = None
    
    return trainers

def parse_opponents(lines):
    opponents = {}
    for line in lines:
        if '#define' in line and '0x' in line:
            parts = line.split()
            if len(parts) >= 3:
                opponents[parts[1]] = parts[2]
    return opponents

def add_trainer_definition(opponents_lines, trainer_name, trainer_id):
    # First check if definition already exists
    for line in opponents_lines:
        if f"#define {trainer_name} " in line:
            return opponents_lines
            
    for i, line in enumerate(opponents_lines):
        if '#define TRAINERS_COUNT' in line:
            opponents_lines.insert(i, f"#define {trainer_name} {trainer_id}\n")
            return opponents_lines
    return opponents_lines

def create_party_name(trainer_name):
    parts = trainer_name.split('_')
    return f"sParty_{'_'.join([parts[0].capitalize()] + [p.capitalize() for p in parts[1:]])}"

def select_party_type():
    print("\nSelect party type:")
    print("1. NoItemDefaultMoves (No item, default moves)")
    print("2. ItemDefaultMoves (With item, default moves)")
    print("3. NoItemCustomMoves (No item, custom moves)")
    print("4. ItemCustomMoves (With item, custom moves, abilities, natures, IVs/EVs)")
    
    while True:
        choice = input("Option (1-4): ").strip()
        if choice in ['1', '2', '3', '4']:
            return int(choice)
        print("Invalid option! Choose between 1-4")

def select_ai_flags():
    print("\nSelect AI Flags (multiple can be selected separated by comma):")
    for key, value in AI_FLAGS.items():
        print(f"{key}. {value}")
    
    selected = input("Options (ex: 2,3): ").strip().split(',')
    flags = []
    for opt in selected:
        if opt.strip() in AI_FLAGS:
            flags.append(AI_FLAGS[opt.strip()])
    
    if not flags:
        flags.append('AI_SCRIPT_CHECK_GOOD_MOVE')
    
    return ' | '.join(flags)

def select_items():
    print("\nAdd items to trainer (max 4, leave blank for none):")
    items = []
    for i in range(4):
        while True:
            item = input(f"Item {i+1} (ex: POTION): ").strip().upper()
            if not item:
                break
                
            item_name = f"ITEM_{item}"
            if item_name in VALID_ITEMS:
                items.append(item_name)
                break
            else:
                suggestions = get_close_matches(item_name, VALID_ITEMS, n=3, cutoff=0.6)
                print(f"\nError: Item '{item}' not found!")
                if suggestions:
                    print("Did you mean?")
                    for j, sug in enumerate(suggestions, 1):
                        print(f"{j}. {sug.replace('ITEM_', '')}")
                    
                    choice = input("Enter option number or correct name: ").strip()
                    if choice.isdigit() and 1 <= int(choice) <= len(suggestions):
                        items.append(suggestions[int(choice)-1])
                        break
                    else:
                        item = choice
    
    if not items:
        return "{}"
    else:
        return "{" + ", ".join(items) + "}"

def select_double_battle():
    choice = input("Is this a double battle? (y/n): ").strip().lower()
    return "TRUE" if choice == 'y' else "FALSE"

def select_ability():
    print("\nSelect ability:")
    for key, value in ABILITY_OPTIONS.items():
        print(f"{key}. {value}")
    choice = input("Option: ").strip()
    return ABILITY_OPTIONS.get(choice, 'Ability_1')

def select_nature():
    print("\nSelect nature:")
    for i, nature in enumerate(NATURES, 1):
        print(f"{i}. {nature}")
    choice = input("Option (1-25): ").strip()
    try:
        return NATURES[int(choice)-1] if 1 <= int(choice) <= 25 else "HARDY"
    except:
        return "HARDY"

def select_tera_type():
    print("\nSelect Tera Type:")
    for key, (name, _) in TERA_TYPES.items():
        print(f"{key}. {name}")
    choice = input("Option (0-21): ").strip()
    return TERA_TYPES.get(choice, ('TYPE_NORMAL', 0x00))[0]

def input_ivs():
    print("\nIVs (0-31 for each stat, space separated):")
    print("Format: HP ATK DEF SPE SPD SPC")
    while True:
        try:
            ivs = list(map(int, input("IVs: ").strip().split()))
            if len(ivs) == 6 and all(0 <= iv <= 31 for iv in ivs):
                return ", ".join(map(str, ivs))
            print("Please enter 6 values between 0-31 separated by space")
        except:
            print("Invalid input")

def input_evs():
    print("\nEVs (0-255 for each stat, space separated):")
    print("Format: HP ATK DEF SPE SPD SPC")
    while True:
        try:
            evs = list(map(int, input("EVs: ").strip().split()))
            if len(evs) == 6 and all(0 <= ev <= 255 for ev in evs):
                return ", ".join(map(str, evs))
            print("Please enter 6 values between 0-255 separated by space")
        except:
            print("Invalid input")

def validate_with_suggestions(input_str, valid_set, prefix):
    full_name = f"{prefix}_{input_str.upper()}"
    if full_name in valid_set:
        return full_name
    
    suggestions = get_close_matches(input_str.upper(), [x.replace(prefix+'_', '') for x in valid_set], n=3, cutoff=0.6)
    print(f"\nError: '{input_str}' not found!")
    if suggestions:
        print("Did you mean?")
        for i, sug in enumerate(suggestions, 1):
            print(f"{i}. {sug}")
        
        choice = input("Enter option number or correct name: ").strip()
        if choice.isdigit() and 1 <= int(choice) <= len(suggestions):
            return f"{prefix}_{suggestions[int(choice)-1]}"
        else:
            return validate_with_suggestions(choice, valid_set, prefix)
    
    return None

def convert_to_easy_text(name):
    text_array = []
    for char in name:
        upper_char = char.upper()
        if upper_char in CHAR_TO_DEFINE:
            text_array.append(CHAR_TO_DEFINE[upper_char])
        elif char == ' ':
            text_array.append("_SPACE")
        else:
            text_array.append("_SPACE")  # Replace unmapped chars with space
    
    text_array.append("_END")
    return "{" + ", ".join(text_array) + "}"

def input_trainer_names():
    print("\nTrainer name (for opponents.h):")
    print("Format: BUG_CATCHER_ROY (uppercase with underscores)")
    while True:
        define_name = input("Define name: ").strip().upper()
        if all(c.isalpha() or c == '_' for c in define_name):
            break
        print("Use only letters and underscores!")
    
    print("\nDisplay name (for .trainerName):")
    print("Format: Bug Catcher Roy")
    display_name = input("Display name: ").strip()
    
    trainer_name = convert_to_easy_text(display_name)
    
    return define_name, trainer_name

def add_pokemon_to_party(party_type):
    print("\nAdding new Pokémon:")
    
    while True:
        species = input("Species (ex: PIKACHU): ").strip().upper()
        valid_species = validate_with_suggestions(species, VALID_SPECIES, "SPECIES")
        if valid_species:
            break
    
    level = input("Level (ex: 12): ").strip()
    
    pokemon_data = {
        'species': valid_species,
        'level': level,
        'party_type': party_type
    }
    
    if party_type in [3, 4]:  # Custom moves
        moves = []
        for i in range(4):
            while True:
                move_input = input(f"Move {i+1} (leave blank for NONE): ").strip().upper()
                if not move_input:
                    moves.append("MOVE_NONE")
                    break
                valid_move = validate_with_suggestions(move_input, VALID_MOVES, "MOVE")
                if valid_move:
                    moves.append(valid_move)
                    break
        pokemon_data['moves'] = moves
    
    if party_type in [2, 4]:  # With item
        while True:
            item_input = input("Item (leave blank for NONE): ").strip().upper()
            if not item_input:
                pokemon_data['item'] = "ITEM_NONE"
                break
            valid_item = validate_with_suggestions(item_input, VALID_ITEMS, "ITEM")
            if valid_item:
                pokemon_data['item'] = valid_item
                break
    
    if party_type == 4:  # ItemCustomMoves (complete)
        pokemon_data['ability'] = select_ability()
        pokemon_data['nature'] = select_nature()
        pokemon_data['ivs'] = input_ivs()
        pokemon_data['evs'] = input_evs()
        pokemon_data['tera_type'] = select_tera_type()
    
    return pokemon_data

def add_new_trainer(trainers, opponents_lines, parties):
    print("\nAdding new trainer:")
    trainer_id = input("Numeric ID (ex: 3): ").strip()
    
    trainer_define_name, trainer_display_name = input_trainer_names()
    
    trainer_class = input("Class (ex: LASS): ").strip().upper()
    
    encounter_music = input("Encounter music (1-MALE, 2-FEMALE): ").strip()
    music_choice = "TRAINER_ENCOUNTER_MUSIC_FEMALE" if encounter_music == "2" else "TRAINER_ENCOUNTER_MUSIC_MALE"
    ai_flags = select_ai_flags()
    items = select_items()
    double_battle = select_double_battle()
    
    party_name = create_party_name(trainer_define_name)
    party_type = select_party_type()
    party = []
    
    party_struct = PARTY_TYPE_STRUCT_MAP[party_type]  # For trainer_parties.h
    party_union = PARTY_TYPE_UNION_MAP[party_type]    # For trainer_tables.c
    
    while True:
        print(f"\nCurrent party for {party_name} ({party_struct}):")
        for i, p in enumerate(party, 1):
            print(f"{i}. {p['species'].replace('SPECIES_', '')} Lv.{p['level']}")
            if 'nature' in p:
                print(f"   Nature: {p['nature']}, Ability: {p['ability']}")
        
        print("\n1. Add Pokémon")
        print("2. Finish party")
        choice = input("Choice: ").strip()
        
        if choice == "1":
            party.append(add_pokemon_to_party(party_type))
        elif choice == "2":
            break
    
    party_flags = []
    if party_type in [3, 4]:
        party_flags.append("PARTY_FLAG_CUSTOM_MOVES")
    if party_type in [2, 4]:
        party_flags.append("PARTY_FLAG_HAS_ITEM")
    
    trainers[trainer_define_name] = {
        'id': trainer_id,
        'data': [
            f".partyFlags = {' | '.join(party_flags) if party_flags else '0'},",
            f".trainerClass = CLASS_{trainer_class},",
            f".encounterMusic = {music_choice},",
            f".trainerPic = TRAINER_PIC_{trainer_class},",
            f".trainerName = {trainer_display_name},",
            f".items = {items},",
            f".doubleBattle = {double_battle},",
            f".aiFlags = {ai_flags},",
            f".partySize = NELEMS({party_name}),",
            f".party = {{.{party_union} = {party_name}}}"
        ],
        'party_name': party_name,
        'party_data': party,
        'party_struct': party_struct
    }
    
    opponents_lines = add_trainer_definition(opponents_lines, trainer_define_name, trainer_id)
    parties[party_name] = {
        'data': party,
        'struct': party_struct
    }
    
    print(f"\nTrainer added:")
    print(f"Define: {trainer_define_name} with ID {trainer_id}")
    print(f"Display name: {trainer_display_name}")
    print(f"Party created: {party_name} ({party_struct})")
    return opponents_lines

def save_all_changes(trainer_lines, party_lines, opponents_lines, trainers, parties):
    new_trainer_lines = []
    inside_stevebels_block = False
    found_array_start = False
    trainers_added = False
    
    for line in trainer_lines:
        if "#ifdef STEVEBELS_TRAINER_TABLE" in line:
            inside_stevebels_block = True
            new_trainer_lines.append(line)
            continue
        
        if inside_stevebels_block and not trainers_added:
            if "const struct Trainer gTrainers[] = {" in line:
                found_array_start = True
                new_trainer_lines.append(line)
                continue
            
            if found_array_start and line.strip() == "};":
                for trainer_name, trainer in trainers.items():
                    if not any(f"[{trainer_name}]" in l for l in new_trainer_lines):
                        new_trainer_lines.append(f"    [{trainer_name}] = {{\n")
                        for prop in trainer['data']:
                            new_trainer_lines.append(f"        {prop}\n")
                        new_trainer_lines.append("    },\n")
                trainers_added = True
        
        if "#endif" in line and inside_stevebels_block:
            inside_stevebels_block = False
        
        new_trainer_lines.append(line)
    
    new_party_lines = []
    inside_stevebels_block = False
    parties_added = False
    
    for line in party_lines:
        if "#ifdef STEVEBELS_TRAINER_TABLE" in line:
            inside_stevebels_block = True
            new_party_lines.append(line)
            continue
        
        if inside_stevebels_block and not parties_added:
            if line.strip() == "#endif":
                for party_name, party_info in parties.items():
                    if not any(f"{party_name}[]" in l for l in new_party_lines):
                        new_party_lines.append(f"\nstatic const struct {party_info['struct']} {party_name}[] = {{\n")
                        
                        for pokemon in party_info['data']:
                            new_party_lines.append("    {\n")
                            new_party_lines.append(f"        .lvl = {pokemon['level']},\n")
                            new_party_lines.append(f"        .species = {pokemon['species']},\n")
                            
                            if pokemon['party_type'] in [3, 4]:
                                new_party_lines.append(f"        .moves = {{{', '.join(pokemon['moves'])}}},\n")
                            
                            if pokemon['party_type'] in [2, 4]:
                                new_party_lines.append(f"        .heldItem = {pokemon.get('item', 'ITEM_NONE')},\n")
                            
                            if pokemon['party_type'] == 4:
                                new_party_lines.append(f"        .ability = {pokemon['ability']},\n")
                                new_party_lines.append(f"        .nature = NATURE_{pokemon['nature']},\n")
                                new_party_lines.append(f"        .ivSpread = {{{pokemon['ivs']}}},\n")
                                new_party_lines.append(f"        .evSpread = {{{pokemon['evs']}}},\n")
                                new_party_lines.append(f"        .teraType = {pokemon['tera_type']},\n")
                            
                            new_party_lines.append("    },\n")
                        new_party_lines.append("};\n")
                parties_added = True
        
        new_party_lines.append(line)
    
    write_file(TRAINER_DATA_PATH, new_trainer_lines)
    write_file(TRAINER_PARTIES_PATH, new_party_lines)
    write_file(OPPONENTS_PATH, opponents_lines)
    print("\nChanges saved successfully!")

def main():
    print(f"\nPokémon Trainer Editor")
    trainer_lines = read_file(TRAINER_DATA_PATH)
    party_lines = read_file(TRAINER_PARTIES_PATH)
    opponents_lines = read_file(OPPONENTS_PATH)
    
    trainers = parse_trainers(trainer_lines)
    opponents_defs = parse_opponents(opponents_lines)
    new_parties = {}
    
    while True:
        print("\n1. Add trainer")
        print("2. Save and exit")
        choice = input("Choice: ").strip()
        
        if choice == "1":
            opponents_lines = add_new_trainer(trainers, opponents_lines, new_parties)
        elif choice == "2":
            save_all_changes(trainer_lines, party_lines, opponents_lines, trainers, new_parties)
            break

if __name__ == "__main__":
    main()