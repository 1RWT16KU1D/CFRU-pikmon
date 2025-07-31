import tkinter as tk
from tkinter import ttk, messagebox, scrolledtext
from pathlib import Path
import re
import os
from PIL import Image, ImageTk
from difflib import get_close_matches
from tkinter import filedialog

# Party type mappings
PARTY_TYPES = [
    ("NoItemDefaultMoves (No item, default moves)", 1),
    ("ItemDefaultMoves (With item, default moves)", 2),
    ("NoItemCustomMoves (No item, custom moves)", 3),
    ("ItemCustomMoves (With item, custom moves, abilities, natures, IVs/EVs)", 4)
]

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

TRAINER_PICS = {
    "ARCHIE": 0,
    "AQUA_GRUNT_M": 1,
    "AQUA_GRUNT_F": 2,
    "AROMA_LADY_RS": 3,
    "RUIN_MANIAC_RS": 4,
    "CAMERA_DUO": 5,
    "RS_TUBER_F": 6,
    "RS_TUBER_M": 7,
    "RS_COOLTRAINER_M": 8,
    "RS_COOLTRAINER_F": 9,
    "HEX_MANIAC": 10,
    "RS_LADY": 11,
    "RS_BEAUTY": 12,
    "RICH_BOY": 13,
    "RS_POKEMANIAC": 14,
    "RS_SWIMMER_M": 15,
    "RS_BLACK_BELT": 16,
    "GUITARIST": 17,
    "KINDLER": 18,
    "RS_CAMPER": 19,
    "BUG_MANIAC": 20,
    "RS_PSYCHIC_M": 21,
    "RS_PSYCHIC_F": 22,
    "RS_GENTLEMAN": 23,
    "SIDNEY": 24,
    "PHOEBE": 25,
    "ROXANNE": 26,
    "BRAWLY": 27,
    "LIZA_AND_TATE": 28,
    "SCHOOL_BOY": 29,
    "SCHOOL_GIRL": 30,
    "SR_AND_JR": 31,
    "POKEFAN_M": 32,
    "POKRFAN_F": 33,
    "EXPERT_M": 34,
    "EXPERT_F": 35,
    "RS_YOUNGSTER": 36,
    "STEVEN": 37,
    "RS_FISHERMAN": 38,
    "CYCLING_TRIATHLETE_M": 39,
    "CYCLING_TRIATHLETE_F": 40,
    "RUNNING_TRIATHLETE_M": 41,
    "RUNNING_TRIATHLETE_F": 42,
    "SWIMMING_TRIATHLETE_M": 43,
    "SWIMMING_TRIATHLETE_F": 44,
    "DRAGON_TAMER": 45,
    "RS_BIRDKEEPER": 46,
    "NINJA_BOY": 47,
    "RS_CRUSHGIRL": 48,
    "PARASOL_LADY": 49,
    "RS_SWIMMER_F": 50,
    "RS_PICNICKER": 51,
    "RS_TWINS": 52,
    "RS_SAILOR": 53,
    "COLLECTOR": 54,
    "RS_WALLY": 55,
    "RS_BRENDAN": 56,
    "RS_MAY": 57,
    "RS_BREEDER_M": 58,
    "RS_BREEDER_F": 59,
    "RS_RANGER_M": 60,
    "RS_RANGER_F": 61,
    "MAXIE": 62,
    "MAGMA_GRUNT_M": 63,
    "MAGMA_GRUNT_F": 64,
    "RS_LASS": 65,
    "RS_BUGCATCHER": 66,
    "RS_HIKER": 67,
    "RS_YOUNG_COUPLE": 68,
    "EXPERT_DUO": 69,
    "RS_SIS_AND_BRO": 70,
    "MATT": 71,
    "SHELLY": 72,
    "TABITHA": 73,
    "COURTNEY": 74,
    "WATTSON": 75,
    "FLANNERY": 76,
    "NORMAN": 77,
    "WINONA": 78,
    "WALLACE": 79,
    "GLACIA": 80,
    "DRAKE": 81,
    "YOUNGSTER": 82,
    "BUG_CATCHER": 83,
    "LASS": 84,
    "SAILOR": 85,
    "CAMPER": 86,
    "PICNICKER": 87,
    "POKEMANIAC": 88,
    "SUPER_NERD": 89,
    "HIKER": 90,
    "BIKER": 91,
    "BURGLAR": 92,
    "WORKER": 93,
    "FISHERMAN": 94,
    "SWIMMER_M": 95,
    "CUE_BALL": 96,
    "GAMBLER": 97,
    "BEAUTY": 98,
    "SWIMMER_F": 99,
    "PSYCHIC_M": 100,
    "ROCKER": 101,
    "JUGGLER": 102,
    "TAMER": 103,
    "BIRD_KEEPER": 104,
    "BLACK_BELT": 105,
    "BLUE": 106,
    "SCIENTIST_M": 107,
    "GIOVANNI": 108,
    "ROCKET_GRUNT_M": 109,
    "COOLTRAINER_M": 110,
    "COOLTRAINER_F": 111,
    "LORLEI": 112,
    "BRUNO": 113,
    "AGATHA": 114,
    "LANCE": 115,
    "BROCK": 116,
    "MISTY": 117,
    "LT_SURGE": 118,
    "ERIKA": 119,
    "KOGA": 120,
    "BLAINE": 121,
    "SABRINA": 122,
    "GENTLEMAN": 123,
    "BLUE_2": 124,
    "BLUE_3": 125,
    "CHANNELER": 126,
    "TWINS": 127,
    "COOL_COUPLE": 128,
    "YOUNG_COUPLE": 129,
    "CRUSH_KIN": 130,
    "SIS_AND_BRO": 131,
    "PROF_OAK": 132,
    "BRENDAN": 133,
    "MAY": 134,
    "PLAYER_M": 135,
    "PLAYER_F": 136,
    "ROCKET_GRUNT_F": 137,
    "PSYCHIC_F": 138,
    "CRUSH_GIRL": 139,
    "TUBER_F": 140,
    "PKMN_BREEDER_F": 141,
    "PKMN_RANGER_M": 142,
    "PKMN_RANGER_F": 143,
    "AROMA_LADY": 144,
    "RUIN_MANIAC": 145,
    "SELPHY": 146,
    "PAINTER": 147
}

# Tera Type options
TERA_TYPES = [
    "TYPE_NORMAL", "TYPE_FIGHTING", "TYPE_FLYING", "TYPE_POISON", "TYPE_GROUND",
    "TYPE_ROCK", "TYPE_BUG", "TYPE_GHOST", "TYPE_STEEL", "TYPE_MYSTERY",
    "TYPE_FIRE", "TYPE_WATER", "TYPE_GRASS", "TYPE_ELECTRIC", "TYPE_PSYCHIC",
    "TYPE_ICE", "TYPE_DRAGON", "TYPE_DARK", "TYPE_ROOSTLESS", "TYPE_BLANK",
    "TYPE_FAIRY", "TYPE_STELLAR"
]

AI_FLAGS = {
    'AI_SCRIPT_CHECK_BAD_MOVE': 1,
    'AI_SCRIPT_SEMI_SMART': 2,
    'AI_SCRIPT_CHECK_GOOD_MOVE': 4,
    'AI_SCRIPT_TRY_TO_FAINT': 8,
    'AI_SCRIPT_CHECK_VIABILITY': 16,
    'AI_SCRIPT_SETUP_FIRST_TURN': 32,
    'AI_SCRIPT_RISKY': 64,
    'AI_SCRIPT_PREFER_STRONGEST_MOVE': 128,
    'AI_SCRIPT_PREFER_BATON_PASS': 256,
    'AI_SCRIPT_DOUBLE_BATTLE': 512
}

AI_FLAGS_REVERSE = {v: k for k, v in AI_FLAGS.items()}

ABILITY_OPTIONS = [
    'Ability_Hidden', 'Ability_1', 'Ability_2', 'Ability_Random_1_2', 'Ability_RandomAll'
]

NATURES = [
    "HARDY", "LONELY", "BRAVE", "ADAMANT", "NAUGHTY",
    "BOLD", "DOCILE", "RELAXED", "IMPISH", "LAX",
    "TIMID", "HASTY", "SERIOUS", "JOLLY", "NAIVE",
    "MODEST", "MILD", "QUIET", "BASHFUL", "RASH",
    "CALM", "GENTLE", "SASSY", "CAREFUL", "QUIRKY"
]

# Opções de música de encontro
MUSIC_OPTIONS = [
    ("Standard Male", "TRAINER_ENCOUNTER_MUSIC_MALE"),
    ("Standard Female", "TRAINER_ENCOUNTER_MUSIC_FEMALE"),
    ("Girl/Tuber/Young Couple", "TRAINER_ENCOUNTER_MUSIC_GIRL"),
    ("Suspicious", "TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS"),
    ("Intense", "TRAINER_ENCOUNTER_MUSIC_INTENSE"),
    ("Cool", "TRAINER_ENCOUNTER_MUSIC_COOL"),
    ("Aqua", "TRAINER_ENCOUNTER_MUSIC_AQUA"),
    ("Magma", "TRAINER_ENCOUNTER_MUSIC_MAGMA"),
    ("Swimmer", "TRAINER_ENCOUNTER_MUSIC_SWIMMER"),
    ("Twins/Others", "TRAINER_ENCOUNTER_MUSIC_TWINS"),
    ("Elite Four", "TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR"),
    ("Hiker/Others", "TRAINER_ENCOUNTER_MUSIC_HIKER"),
    ("Interviewer", "TRAINER_ENCOUNTER_MUSIC_INTERVIEWER"),
    ("Rich Boy/Gentleman", "TRAINER_ENCOUNTER_MUSIC_RICH")
]

class TrainerEditorUI:
    def __init__(self, root):
        self.root = root
        self.BASE_DIR = None
        self.root.title("CFRU Trainer Editor")
        self.root.geometry("500x300")
        
        self.TRAINER_DATA_PATH = None
        self.TRAINER_PARTIES_PATH = None
        self.OPPONENTS_PATH = None
        self.SPECIES_PATH = None
        self.MOVES_PATH = None
        self.ITEMS_PATH = None
        self.TRAINER_CLASSES_PATH = None
        self.EASY_TEXT_PATH = None
        self.TRAINER_PIC_TABLES_PATH = None
        self.SPRITES_DIR = None
        
        
        # Define party_type_var before setting up UI
        self.party_type_var = tk.IntVar(value=4)
        self.party_type_var.trace('w', self.update_party_fields)
        
        self.show_folder_selection()
           
    def show_folder_selection(self):
        """Mostra a tela inicial para selecionar a pasta do projeto"""
        self.clear_main_window()
        
        title_label = ttk.Label(self.root, text="CFRU Trainer Editor", font=('Helvetica', 14, 'bold'))
        title_label.pack(pady=20)
        
        desc_label = ttk.Label(self.root, text="Select your CFRU project folder:")
        desc_label.pack(pady=10)
        
        btn_frame = ttk.Frame(self.root)
        btn_frame.pack(pady=20)
        
        ttk.Button(btn_frame, text="Select Folder", command=self.select_project_folder).pack(pady=5)
        ttk.Button(btn_frame, text="Exit", command=self.root.quit).pack(pady=5)
        
        # Centraliza a janela
        self.root.update_idletasks()
        width = self.root.winfo_width()
        height = self.root.winfo_height()
        x = (self.root.winfo_screenwidth() // 2) - (width // 2)
        y = (self.root.winfo_screenheight() // 2) - (height // 2)
        self.root.geometry(f'{width}x{height}+{x}+{y}')
        
    def select_project_folder(self):
        """Abre o diálogo para selecionar a pasta do projeto"""
        folder_path = filedialog.askdirectory(title="Select CFRU Project Folder")
        if folder_path:
            self.BASE_DIR = Path(folder_path)
            self.verify_project_structure()
            
    def verify_project_structure(self):
        """Verifica se a pasta selecionada tem a estrutura esperada do CFRU"""
        required_paths = [
            "src/Tables/trainer_tables.c",
            "src/Tables/trainer_parties.h",
            "include/constants/opponents.h",
            "include/constants/species.h",
            "include/constants/moves.h",
            "include/constants/items.h",
            "include/constants/trainer_classes.h",
            "include/easy_text.h",
            "src/Tables/trainer_pic_tables.c",
            "graphics/Other/PokeSprites"
        ]
        
        missing_paths = []
        for rel_path in required_paths:
            if not (self.BASE_DIR / rel_path).exists():
                missing_paths.append(rel_path)
        
        if missing_paths:
            messagebox.showerror(
                "Error", 
                f"The selected folder doesn't appear to be a valid CFRU project.\n\nMissing paths:\n- " + 
                "\n- ".join(missing_paths)
            )
            self.show_folder_selection()
        else:
            self.initialize_editor()
            
    def clear_main_window(self):
        """Remove todos os widgets da janela principal"""
        for widget in self.root.winfo_children():
            widget.destroy()
            
    def initialize_editor(self):
        """Inicializa o editor após a pasta ser selecionada"""
        self.clear_main_window()
        self.root.geometry("1200x800")
        
        # Define os paths agora que BASE_DIR está definido
        self.TRAINER_DATA_PATH = self.BASE_DIR / "src" / "Tables" / "trainer_tables.c"
        self.TRAINER_PARTIES_PATH = self.BASE_DIR / "src" / "Tables" / "trainer_parties.h"
        self.OPPONENTS_PATH = self.BASE_DIR / "include" / "constants" / "opponents.h"
        self.SPECIES_PATH = self.BASE_DIR / "include" / "constants" / "species.h"
        self.MOVES_PATH = self.BASE_DIR / "include" / "constants" / "moves.h"
        self.ITEMS_PATH = self.BASE_DIR / "include" / "constants" / "items.h"
        self.TRAINER_CLASSES_PATH = self.BASE_DIR / "include" / "constants" / "trainer_classes.h"
        self.EASY_TEXT_PATH = self.BASE_DIR / "include" / "easy_text.h"
        self.TRAINER_PIC_TABLES_PATH = self.BASE_DIR / "src" / "Tables" / "trainer_pic_tables.c"
        self.SPRITES_DIR = self.BASE_DIR / "graphics" / "Other" / "PokeSprites"
        
        # Restante da inicialização
        self.load_initial_data()
        self.setup_styles()
        
        self.party_type_var = tk.IntVar(value=4)
        self.party_type_var.trace('w', self.update_party_fields)
        
        self.setup_ui()
        self.populate_trainer_tree()
        
    def load_initial_data(self):
        """Carrega todos os dados iniciais necessários"""
        self.TRAINER_CLASSES = self.load_trainer_classes()
        self.VALID_SPECIES = self.load_file_defines(self.SPECIES_PATH, 'SPECIES_')  # Note o self.
        self.VALID_MOVES = self.load_file_defines(self.MOVES_PATH, 'MOVE_')         # Note o self.
        self.VALID_ITEMS = self.load_file_defines(self.ITEMS_PATH, 'ITEM_')         # Note o self.
        self.TEXT_DEFINITIONS, self.CHAR_TO_DEFINE = self.load_easy_text_definitions()
        
        self.trainer_lines = self.read_file(self.TRAINER_DATA_PATH)                  # Note o self.
        self.party_lines = self.read_file(self.TRAINER_PARTIES_PATH)                 # Note o self.
        self.opponents_lines = self.read_file(self.OPPONENTS_PATH)                   # Note o self.
        
        self.trainers = self.parse_trainers()
        self.parties = self.parse_trainer_parties()
        self.opponent_name_to_id, self.opponent_id_to_name = self.parse_opponents_with_ids()
        self.trainer_sprites = self.load_trainer_sprites()
        
        self.species_list = sorted([s.replace('SPECIES_', '') for s in self.VALID_SPECIES])
        self.items_list = sorted([i.replace('ITEM_', '') for i in self.VALID_ITEMS])
        self.moves_list = sorted([m.replace('MOVE_', '') for m in self.VALID_MOVES])
        
        self.current_editing_id = None
        self.new_parties = {}
        self.modified = False
        
    def parse_trainer_parties(self):
        """Analisa o arquivo de parties e retorna um dicionário com os dados"""
        parties = {}
        current_party = None
        current_pokemon = None
        i = 0
        n = len(self.party_lines)
        
        while i < n:
            line = self.party_lines[i].strip()
            
            # Encontra o início de uma party
            if line.startswith('static const struct TrainerMon') and '[] = {' in line:
                party_name = line.split('[] = {')[0].split()[-1]
                party_type = self.get_party_type_from_struct(line.split('struct ')[1].split()[0])
                current_party = {
                    'name': party_name,
                    'type': party_type,
                    'pokemons': []
                }
                i += 1
                continue
            
            # Processa os Pokémon da party
            elif current_party and line.startswith('{'):
                pokemon = {'party_type': current_party['type']}
                while i < n and not line.startswith('},'):
                    line = self.party_lines[i].strip()
                    
                    if '.lvl =' in line:
                        pokemon['level'] = line.split('=')[1].strip(' ,')
                    elif '.species =' in line:
                        pokemon['species'] = line.split('=')[1].strip(' ,')
                    elif '.heldItem =' in line:
                        pokemon['item'] = line.split('=')[1].strip(' ,')
                    elif '.moves = {' in line:
                        # Captura múltiplas linhas de movimentos se necessário
                        moves = []
                        if '{' in line and '}' in line:
                            # Movimentos na mesma linha
                            moves_part = line.split('{')[1].split('}')[0]
                            moves = [m.strip() for m in moves_part.split(',') if m.strip()]
                        else:
                            # Movimentos em múltiplas linhas
                            i += 1
                            while i < n and '}' not in self.party_lines[i]:
                                move_line = self.party_lines[i].strip().strip(',')
                                if move_line:
                                    moves.append(move_line)
                                i += 1
                        pokemon['moves'] = moves
                    elif '.ability =' in line:
                        pokemon['ability'] = line.split('=')[1].strip(' ,')
                    elif '.nature =' in line:
                        pokemon['nature'] = line.split('=')[1].strip(' ,')
                    elif '.ivSpread = {' in line:
                        # Captura IVs (mesmo padrão dos movimentos)
                        ivs = []
                        if '{' in line and '}' in line:
                            ivs_part = line.split('{')[1].split('}')[0]
                            ivs = [iv.strip() for iv in ivs_part.split(',') if iv.strip()]
                        else:
                            i += 1
                            while i < n and '}' not in self.party_lines[i]:
                                iv_line = self.party_lines[i].strip().strip(',')
                                if iv_line:
                                    ivs.append(iv_line)
                                i += 1
                        pokemon['ivs'] = ', '.join(ivs)
                    elif '.evSpread = {' in line:
                        # Captura EVs (mesmo padrão dos movimentos)
                        evs = []
                        if '{' in line and '}' in line:
                            evs_part = line.split('{')[1].split('}')[0]
                            evs = [ev.strip() for ev in evs_part.split(',') if ev.strip()]
                        else:
                            i += 1
                            while i < n and '}' not in self.party_lines[i]:
                                ev_line = self.party_lines[i].strip().strip(',')
                                if ev_line:
                                    evs.append(ev_line)
                                i += 1
                        pokemon['evs'] = ', '.join(evs)
                    elif '.teraType =' in line:
                        pokemon['tera_type'] = line.split('=')[1].strip(' ,')
                    
                    i += 1
                    if i < n:
                        line = self.party_lines[i].strip()
                
                if pokemon:
                    current_party['pokemons'].append(pokemon)
                i += 1
                continue
            
            # Finaliza a party quando encontrar o fechamento
            elif current_party and line.startswith('};'):
                parties[current_party['name']] = current_party
                current_party = None
            
            i += 1
        
        return parties
        
    def get_party_type_from_struct(self, struct_name):
        """Determina o tipo de party baseado no nome da estrutura"""
        if 'NoItemDefaultMoves' in struct_name:
            return 1
        elif 'ItemDefaultMoves' in struct_name:
            return 2
        elif 'NoItemCustomMoves' in struct_name:
            return 3
        elif 'ItemCustomMoves' in struct_name:
            return 4
        return 4  # Default

    def load_trainer_classes(self):
        """Carrega as classes de treinador, ignorando comentários e linhas vazias"""
        classes = []
        try:
            with open(self.TRAINER_CLASSES_PATH, 'r', encoding='utf-8') as f:  # Note o self.
                for line in f:
                    # Remove comentários e espaços em branco
                    line = line.split('//')[0].strip()
                    
                    if not line:
                        continue  # Ignora linhas vazias
                    
                    # Processa #define CLASS_XXX
                    if line.startswith('#define CLASS_'):
                        parts = line.split()
                        if len(parts) >= 2:
                            classes.append(parts[1])
                    
                    # Processa enum { CLASS_XXX, ... }
                    elif line.startswith('CLASS_'):
                        class_name = line.split('=')[0].split(',')[0].strip()
                        classes.append(class_name)
                    
                    # Processa enum { CLASS_XXX = value, ... }
                    elif 'enum' in line and '{' in line:
                        # Multilinha - continua lendo até encontrar }
                        while True:
                            line = f.readline()
                            if not line or '}' in line:
                                break
                            line = line.split('//')[0].strip()
                            if line.startswith('CLASS_'):
                                class_name = line.split('=')[0].split(',')[0].strip()
                                classes.append(class_name)
        
        except Exception as e:
            print(f"Error loading trainer classes: {e}")
            classes = list(CLASS_NAME_TO_ID.keys()) if 'CLASS_NAME_TO_ID' in globals() else []
        
        # Remove duplicatas e ordena
        return sorted(list(set(classes)))
    
    def load_file_defines(self, path, prefix):
        """Carrega defines de um arquivo com um prefixo específico"""
        defines = set()
        try:
            with open(path, 'r', encoding='utf-8') as f:  # path já vem com self.
                for line in f:
                    if f'#define {prefix}' in line:
                        defines.add(line.split()[1])
        except Exception as e:
            print(f"Error loading {path}: {e}")
            defines = {f'{prefix}EXAMPLE1', f'{prefix}EXAMPLE2'}  # Fallback
        return defines
    
    def load_easy_text_definitions(self):
        """Carrega definições de texto do arquivo easy_text.h"""
        text_map = {}
        char_to_define = {}
        try:
            with open(self.EASY_TEXT_PATH, 'r', encoding='utf-8') as f:  # Note o self.
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
    
    def load_trainer_sprites(self):
        """Carrega a tabela de sprites dos treinadores"""
        sprites = {}
        try:
            with open(self.TRAINER_PIC_TABLES_PATH, 'r', encoding='utf-8') as f:  # Note o self.
                content = f.read()
                matches = re.finditer(
                    r'\[([^\]]+)\]\s*=\s*\{([^,]+),\s*([^,]+),\s*([^\}]+)\}',
                    content
                )
                
                for match in matches:
                    trainer_class = match.group(1).strip()
                    sprite_name = match.group(2).strip()
                    sprites[trainer_class] = sprite_name
        
        except Exception as e:
            print(f"Error loading trainer sprites: {e}")
            sprites = {
                "YOUNGSTER": "trainers_sprites_front_0_SpriteTiles",
                "LASS": "trainers_sprites_front_1_SpriteTiles"
            }
        
        return sprites
    
    def read_file(self, path):
        """Lê um arquivo e retorna suas linhas"""
        try:
            with open(path, 'r', encoding='utf-8') as f:
                return f.readlines()
        except Exception as e:
            print(f"Error reading {path}: {e}")
            return []
    
    def parse_trainers(self):
        """Analisa o arquivo de treinadores"""
        trainers = {}
        current_trainer = None
        
        for i, line in enumerate(self.trainer_lines):
            line = line.strip()
            
            if line.startswith('[') and '] = {' in line:
                trainer_id = line.split('[')[1].split(']')[0]
                current_trainer = {
                    'id': trainer_id, 
                    'start_line': i, 
                    'data': [],
                    'party_name': None,
                    'party_type': None
                }
            elif current_trainer and line.startswith('.'):
                current_trainer['data'].append(line)
                # Captura o nome e tipo da party
                if '.party = {' in line:
                    party_line = line.split('=', 1)[1].strip()
                    if '.ItemCustomMoves = ' in party_line:
                        current_trainer['party_name'] = party_line.split('.ItemCustomMoves = ')[1].strip(' {},')
                        current_trainer['party_type'] = 4
                    elif '.NoItemCustomMoves = ' in party_line:
                        current_trainer['party_name'] = party_line.split('.NoItemCustomMoves = ')[1].strip(' {},')
                        current_trainer['party_type'] = 3
                    elif '.ItemDefaultMoves = ' in party_line:
                        current_trainer['party_name'] = party_line.split('.ItemDefaultMoves = ')[1].strip(' {},')
                        current_trainer['party_type'] = 2
                    elif '.NoItemDefaultMoves = ' in party_line:
                        current_trainer['party_name'] = party_line.split('.NoItemDefaultMoves = ')[1].strip(' {},')
                        current_trainer['party_type'] = 1
            elif line == '},' and current_trainer:
                current_trainer['end_line'] = i
                trainers[current_trainer['id']] = current_trainer
                current_trainer = None
        
        return trainers
    
    def parse_opponents_with_ids(self):
        """Analisa o arquivo de oponentes retornando mapeamentos nome->id e id->nome"""
        name_to_id = {}
        id_to_name = {}
        
        for line in self.opponents_lines:
            line = line.strip()
            if line.startswith('#define') and not line.startswith('//'):
                parts = line.split()
                if len(parts) >= 3:
                    name = parts[1]
                    try:
                        value = parts[2].split('//')[0].strip()
                        if value.startswith('0x'):
                            trainer_id = int(value[2:], 16)
                        else:
                            trainer_id = int(value)
                        
                        name_to_id[name] = trainer_id
                        id_to_name[trainer_id] = name
                    except ValueError:
                        continue
        return name_to_id, id_to_name

    def easy_text_to_normal(self, easy_text):
        """Converte texto no formato easy_text para texto normal"""
        if not easy_text or easy_text == "{}":
            return ""
        
        chars = easy_text.strip('{}').split(',')
        normal_text = []
        
        for char_def in chars:
            char_def = char_def.strip()
            if char_def in self.TEXT_DEFINITIONS:
                for char, define in self.CHAR_TO_DEFINE.items():
                    if define == char_def:
                        normal_text.append(char)
                        break
            elif char_def == '_SPACE':
                normal_text.append(' ')
            elif char_def == '_END':
                break
        
        return ''.join(normal_text)

    def convert_to_easy_text(self, text):
        """Converte texto normal para o formato easy_text"""
        text_array = []
        for char in text.upper():
            if char in self.CHAR_TO_DEFINE:
                text_array.append(self.CHAR_TO_DEFINE[char])
            elif char == ' ':
                text_array.append("_SPACE")
            else:
                text_array.append("_SPACE")  # Substitui caracteres não mapeados por espaço
        
        text_array.append("_END")
        return "{" + ", ".join(text_array) + "}"

    def save_files(self):
        """Salva todas as alterações nos arquivos"""
        try:
            # Debug - mostra o que será salvo
            self.print_opponents_changes()
            
            self.save_trainer_data_file()
            self.save_opponents_file()
            self.save_parties_file()
            self.modified = False
            messagebox.showinfo("Success", "All files saved successfully!")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to save files: {str(e)}")
            
    def print_opponents_changes(self):
        """Método auxiliar para debug - mostra as alterações que serão salvas"""
        print("\nOpponents to be saved:")
        for name, id in self.opponent_name_to_id.items():
            print(f"{name}: {id}")
        print(f"Max ID: {max(self.opponent_name_to_id.values()) if self.opponent_name_to_id else 0}")

    def save_trainer_data_file(self):
        """Salva as alterações no arquivo trainer_tables.c com o nome do treinador nos colchetes"""
        new_lines = []
        i = 0
        n = len(self.trainer_lines)
        inside_stevebels_block = False
        trainers_added = False
        
        while i < n:
            line = self.trainer_lines[i]
            
            # Verifica se estamos entrando no bloco STEVEBELS
            if "#ifdef STEVEBELS_TRAINER_TABLE" in line:
                inside_stevebels_block = True
                new_lines.append(line)
                i += 1
                continue
            
            # Dentro do bloco STEVEBELS, adicionamos os novos treinadores antes do }; ou #endif
            if inside_stevebels_block and not trainers_added:
                if line.strip() in ["};", "#endif"]:
                    # Adiciona todos os novos treinadores antes do fechamento
                    for name, trainer in self.trainers.items():
                        # Verifica se o treinador já foi processado
                        processed = any(f"[{name}]" in l for l in new_lines)
                        
                        if not processed:
                            # Adiciona com o nome do define entre colchetes
                            new_lines.append(f"\t[{name}] = {{\n")
                            for data_line in trainer['data']:
                                new_lines.append(f"\t    {data_line}\n")
                            new_lines.append("\t},\n")
                    
                    trainers_added = True
            
            # Verifica se é o início de uma definição de treinador fora do bloco STEVEBELS
            if line.strip().startswith('[') and '] = {' in line and not inside_stevebels_block:
                trainer_id = line.split('[')[1].split(']')[0].strip()
                trainer_name = None
                
                # Encontra o nome do treinador correspondente ao ID
                for name, data in self.trainers.items():
                    if data['id'] == trainer_id:
                        trainer_name = name
                        break
                
                # Se encontrou o treinador nos dados modificados
                if trainer_name in self.trainers:
                    trainer = self.trainers[trainer_name]
                    
                    # Adiciona a nova definição do treinador com o nome entre colchetes
                    new_lines.append(f"[{trainer_name}] = {{\n")
                    
                    # Adiciona todos os campos do treinador
                    for data_line in trainer['data']:
                        new_lines.append(f"    {data_line}\n")
                    
                    new_lines.append("},\n")
                    
                    # Avança até o final da definição atual no arquivo original
                    while i < n and not self.trainer_lines[i].strip().startswith('},'):
                        i += 1
                    i += 1  # Pula a linha '},'
                    continue
            
            # Adiciona a linha original se não for parte de um treinador modificado
            new_lines.append(line)
            i += 1
        
        # Escreve o arquivo com as alterações
        try:
            with open(self.TRAINER_DATA_PATH, 'w', encoding='utf-8') as f:
                f.writelines(new_lines)
        except Exception as e:
            messagebox.showerror("Error", f"Failed to save {TRAINER_DATA_PATH}: {str(e)}")
            raise

    def save_opponents_file(self):
        """Salva as alterações no arquivo opponents.h"""
        try:
            # Encontra a posição do TRAINERS_COUNT
            trainers_count_pos = -1
            for i, line in enumerate(self.opponents_lines):
                if "#define TRAINERS_COUNT" in line:
                    trainers_count_pos = i
                    break
            
            if trainers_count_pos == -1:
                # Se não encontrar, procura o final do arquivo
                trainers_count_pos = len(self.opponents_lines) - 1
                while trainers_count_pos > 0 and not self.opponents_lines[trainers_count_pos].strip():
                    trainers_count_pos -= 1
            
            # Cria as novas linhas mantendo a ordem original
            new_lines = []
            inserted_new_defs = False
            
            for i, line in enumerate(self.opponents_lines):
                # Insere as novas definições antes do TRAINERS_COUNT
                if i == trainers_count_pos and not inserted_new_defs:
                    # Adiciona todas as novas definições
                    for name, trainer_id in self.opponent_name_to_id.items():
                        # Verifica se já não existe no arquivo
                        if not any(f"#define {name} " in l for l in self.opponents_lines):
                            new_lines.append(f"#define {name} {trainer_id}\n")
                    inserted_new_defs = True
                
                # Mantém a linha original (exceto TRAINERS_COUNT se precisarmos atualizar)
                if "#define TRAINERS_COUNT" in line:
                    # Atualiza o TRAINERS_COUNT para o maior ID + 1
                    max_id = max(self.opponent_name_to_id.values()) if self.opponent_name_to_id else 0
                    new_lines.append(f"#define TRAINERS_COUNT ({max_id + 1})\n")
                else:
                    new_lines.append(line)
            
            # Se não encontrou TRAINERS_COUNT mas temos definições para adicionar
            if not inserted_new_defs and self.opponent_name_to_id:
                # Adiciona no final antes do #endif
                for i, line in enumerate(new_lines):
                    if "#endif" in line:
                        for name, trainer_id in self.opponent_name_to_id.items():
                            if not any(f"#define {name} " in l for l in self.opponents_lines):
                                new_lines.insert(i, f"#define {name} {trainer_id}\n")
                        break
            
            # Escreve o arquivo
            with open(self.OPPONENTS_PATH, 'w', encoding='utf-8') as f:
                f.writelines(new_lines)
                
        except Exception as e:
            messagebox.showerror("Error", f"Failed to save {self.OPPONENTS_PATH}: {str(e)}")
            raise

    def save_parties_file(self):
        """Salva as alterações no arquivo trainer_parties.h"""
        new_party_lines = []
        inside_stevebels_block = False
        parties_added = False
        
        for line in self.party_lines:
            if "#ifdef STEVEBELS_TRAINER_TABLE" in line:
                inside_stevebels_block = True
                new_party_lines.append(line)
                continue
            
            if inside_stevebels_block and not parties_added:
                if line.strip() == "#endif":
                    for party_name, party_info in self.new_parties.items():
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
        
        # Escreve o arquivo
        try:
            with open(self.TRAINER_PARTIES_PATH, 'w', encoding='utf-8') as f:
                f.writelines(new_party_lines)
        except Exception as e:
            messagebox.showerror("Error", f"Failed to save {TRAINER_PARTIES_PATH}: {str(e)}")
            raise

    def setup_styles(self):
        """Configura os estilos visuais"""
        style = ttk.Style()
        style.configure("Title.TLabel", font=('Helvetica', 10, 'bold'))
        style.configure("Section.TFrame", relief=tk.GROOVE, borderwidth=2)
        style.configure("Section.TLabel", font=('Helvetica', 9, 'bold'))
    
    def setup_ui(self):
        """Configura a interface do usuário"""
        self.main_paned = ttk.PanedWindow(self.root, orient=tk.HORIZONTAL)
        self.main_paned.pack(fill=tk.BOTH, expand=True)
        
        # Painel esquerdo (lista de treinadores)
        self.left_frame = ttk.Frame(self.main_paned, width=300)
        self.main_paned.add(self.left_frame)
        self.setup_trainer_list()
        
        # Painel direito (detalhes do treinador)
        self.right_frame = ttk.Frame(self.main_paned)
        self.main_paned.add(self.right_frame)
        self.setup_trainer_details()
        
        # Botões inferiores
        self.setup_bottom_buttons()
        
        self.populate_trainer_tree()

    def setup_trainer_list(self):
        """Configura o painel esquerdo com a lista de treinadores"""
        # Frame de título
        title_frame = ttk.Frame(self.left_frame)
        title_frame.pack(fill=tk.X, pady=5)
        ttk.Label(title_frame, text="Trainer List", style="Title.TLabel").pack()
        
        # Treeview para lista de treinadores
        tree_frame = ttk.Frame(self.left_frame)
        tree_frame.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        self.trainer_tree = ttk.Treeview(tree_frame, columns=("ID", "Trainer"), show="headings")
        self.trainer_tree.heading("ID", text="ID")
        self.trainer_tree.heading("Trainer", text="Trainer")
        self.trainer_tree.column("ID", width=50)
        self.trainer_tree.column("Trainer", width=200)
        
        # Configura bind para seleção
        self.trainer_tree.bind('<<TreeviewSelect>>', self.on_trainer_selected)
        
        scrollbar = ttk.Scrollbar(tree_frame, orient="vertical", command=self.trainer_tree.yview)
        self.trainer_tree.configure(yscrollcommand=scrollbar.set)
        
        self.trainer_tree.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        
        # Botões de ação
        btn_frame = ttk.Frame(self.left_frame)
        btn_frame.pack(fill=tk.X, padx=5, pady=5)
        
        ttk.Button(btn_frame, text="Add", command=self.add_trainer).pack(side=tk.LEFT, padx=2)
        ttk.Button(btn_frame, text="Remove", command=self.remove_trainer).pack(side=tk.LEFT, padx=2)
        ttk.Button(btn_frame, text="Refresh", command=self.refresh_data).pack(side=tk.LEFT, padx=2)

    def setup_trainer_details(self):
        """Configura o painel direito com as abas de detalhes"""
        notebook = ttk.Notebook(self.right_frame)
        notebook.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Aba Trainer Data
        data_frame = ttk.Frame(notebook)
        notebook.add(data_frame, text="Trainer Data")
        self.setup_trainer_data_tab(data_frame)
        
        # Aba Items
        items_frame = ttk.Frame(notebook)
        notebook.add(items_frame, text="Items")
        self.setup_items_tab(items_frame)
        
        # Aba Options
        options_frame = ttk.Frame(notebook)
        notebook.add(options_frame, text="Options")
        self.setup_options_tab(options_frame)
        
        # Aba Party
        party_frame = ttk.Frame(notebook)
        notebook.add(party_frame, text="Party")
        self.setup_party_tab(party_frame)

    def setup_trainer_data_tab(self, parent):
        """Configura a aba de dados do treinador"""
        # Frame para sprite
        sprite_frame = ttk.LabelFrame(parent, text="Sprite", style="Section.TFrame")
        sprite_frame.grid(row=0, column=0, padx=5, pady=5, sticky="nsew")
        
        # Canvas para mostrar o sprite
        self.sprite_canvas = tk.Canvas(sprite_frame, width=64, height=64, bg="gray")
        self.sprite_canvas.pack(pady=5)
        
        # Combobox para selecionar sprite
        self.trainer_pic_combo = ttk.Combobox(
            sprite_frame, 
            values=list(TRAINER_PICS.keys()),
            state="readonly"
        )
        self.trainer_pic_combo.pack(pady=5)
        self.trainer_pic_combo.bind("<<ComboboxSelected>>", self.update_trainer_pic)
        
        # Frame para dados básicos
        data_frame = ttk.LabelFrame(parent, text="Trainer Info", style="Section.TFrame")
        data_frame.grid(row=0, column=1, padx=5, pady=5, sticky="nsew")
        
        # Frame para dados básicos
        data_frame = ttk.LabelFrame(parent, text="Trainer Info", style="Section.TFrame")
        data_frame.grid(row=0, column=1, padx=5, pady=5, sticky="nsew")
        
        # Trainer ID
        ttk.Label(data_frame, text="Trainer ID:").grid(row=0, column=0, sticky="w", padx=5, pady=2)
        self.trainer_id_entry = ttk.Entry(data_frame)
        self.trainer_id_entry.grid(row=0, column=1, sticky="ew", padx=5, pady=2)
        
        # Define Name
        ttk.Label(data_frame, text="Define Name:").grid(row=1, column=0, sticky="w", padx=5, pady=2)
        self.define_name_entry = ttk.Entry(data_frame)
        self.define_name_entry.grid(row=1, column=1, sticky="ew", padx=5, pady=2)
        
        # Display Name
        ttk.Label(data_frame, text="Display Name:").grid(row=2, column=0, sticky="w", padx=5, pady=2)
        self.display_name_entry = ttk.Entry(data_frame)
        self.display_name_entry.grid(row=2, column=1, sticky="ew", padx=5, pady=2)
        
        # Class Name
        ttk.Label(data_frame, text="Class Name:").grid(row=3, column=0, sticky="w", padx=5, pady=2)
        self.class_name_combo = ttk.Combobox(data_frame, values=self.TRAINER_CLASSES)
        self.class_name_combo.grid(row=3, column=1, sticky="ew", padx=5, pady=2)
        self.class_name_combo.bind("<<ComboboxSelected>>", self.on_class_selected)
        
        # Gênero
        ttk.Label(data_frame, text="Gender:").grid(row=4, column=0, sticky="w", padx=5, pady=2)
        self.gender_var = tk.StringVar(value="1")  # 1 = Male, 2 = Female
        ttk.Radiobutton(data_frame, text="Male", variable=self.gender_var, value="1").grid(row=4, column=1, sticky="w")
        ttk.Radiobutton(data_frame, text="Female", variable=self.gender_var, value="2").grid(row=5, column=1, sticky="w")
        
        parent.grid_columnconfigure(1, weight=1)
        
    def update_trainer_pic(self, event=None):
        """Atualiza a visualização do sprite quando selecionado"""
        selected_pic = self.trainer_pic_combo.get()
        if selected_pic:
            # Atualiza o campo trainerPic nos dados
            if self.current_editing_id:
                for name, data in self.trainers.items():
                    if data['id'] == self.current_editing_id:
                        # Atualiza a linha do trainerPic nos dados
                        for i, line in enumerate(data['data']):
                            if '.trainerPic' in line:
                                data['data'][i] = f".trainerPic = TRAINER_PIC_{selected_pic},"
                                break
    
    def setup_items_tab(self, parent):
        """Configura a aba de itens"""
        items_frame = ttk.LabelFrame(parent, text="Held Items", style="Section.TFrame")
        items_frame.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Cria 4 comboboxes para itens
        self.item_combos = []
        for i in range(4):
            ttk.Label(items_frame, text=f"Item {i+1}:").grid(row=i, column=0, padx=5, pady=2, sticky="w")
            combo = ttk.Combobox(items_frame, values=self.items_list)
            combo.grid(row=i, column=1, padx=5, pady=2, sticky="ew")
            self.item_combos.append(combo)
        
        items_frame.grid_columnconfigure(1, weight=1)
    
    def setup_options_tab(self, parent):
        """Configura a aba de opções"""
        # Music
        ttk.Label(parent, text="Music:").grid(row=0, column=0, sticky="w", padx=5, pady=2)
        self.music_combo = ttk.Combobox(parent, values=[opt[1] for opt in MUSIC_OPTIONS])
        self.music_combo.grid(row=0, column=1, sticky="ew", padx=5, pady=2)
        
        # AI Flags (usando os nomes definidos)
        ttk.Label(parent, text="AI Flags:").grid(row=1, column=0, sticky="w", padx=5, pady=2)
        ai_frame = ttk.Frame(parent)
        ai_frame.grid(row=1, column=1, sticky="ew", padx=5, pady=2)
        
        self.ai_flag_vars = {}
        row_num = 0
        col_num = 0
        for flag_name in AI_FLAGS:
            var = tk.BooleanVar()
            cb = ttk.Checkbutton(ai_frame, text=flag_name, variable=var)
            cb.grid(row=row_num, column=col_num, sticky="w", padx=5)
            self.ai_flag_vars[flag_name] = var
            
            col_num += 1
            if col_num > 2:
                col_num = 0
                row_num += 1
        
        # Double Battle
        self.double_battle_var = tk.BooleanVar()
        ttk.Checkbutton(parent, text="Double Battle", variable=self.double_battle_var).grid(
            row=2, column=0, columnspan=2, sticky="w", padx=5, pady=2)
        
        parent.grid_columnconfigure(1, weight=1)
    
    def setup_party_tab(self, parent):
        """Configura a aba de Pokémon"""
        main_frame = ttk.Frame(parent)
        main_frame.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Frame superior com Party Type
        top_frame = ttk.Frame(main_frame)
        top_frame.pack(fill=tk.X, padx=5, pady=5)
        
        ttk.Label(top_frame, text="Party Type:").pack(side=tk.LEFT, padx=5)
        
        # Combobox para selecionar o tipo de party
        self.party_type_combo = ttk.Combobox(top_frame, values=[pt[0] for pt in PARTY_TYPES])
        self.party_type_combo.pack(side=tk.LEFT, fill=tk.X, expand=True, padx=5)
        self.party_type_combo.bind("<<ComboboxSelected>>", self.on_party_type_selected)
        
        # Frame principal com Treeview e detalhes
        center_frame = ttk.Frame(main_frame)
        center_frame.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Treeview para Pokémon
        tree_frame = ttk.Frame(center_frame)
        tree_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        
        self.party_tree = ttk.Treeview(tree_frame, columns=("Species", "Level", "Item"), show="headings")
        self.party_tree.heading("Species", text="Species")
        self.party_tree.heading("Level", text="Level")
        self.party_tree.heading("Item", text="Item")
        
        scrollbar = ttk.Scrollbar(tree_frame, orient="vertical", command=self.party_tree.yview)
        self.party_tree.configure(yscrollcommand=scrollbar.set)
        
        self.party_tree.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        
        # Frame de edição do Pokémon
        edit_frame = ttk.LabelFrame(center_frame, text="Pokémon Details", style="Section.TFrame")
        edit_frame.pack(side=tk.RIGHT, fill=tk.Y, padx=5)
        
        # Frame rolável para os detalhes
        canvas = tk.Canvas(edit_frame)
        scrollbar = ttk.Scrollbar(edit_frame, orient="vertical", command=canvas.yview)
        scrollable_frame = ttk.Frame(canvas)
        
        scrollable_frame.bind(
            "<Configure>",
            lambda e: canvas.configure(
                scrollregion=canvas.bbox("all")
            )
        )
        
        canvas.create_window((0, 0), window=scrollable_frame, anchor="nw")
        canvas.configure(yscrollcommand=scrollbar.set)
        
        canvas.pack(side="left", fill="both", expand=True)
        scrollbar.pack(side="right", fill="y")
        
        # Species
        ttk.Label(scrollable_frame, text="Species:").grid(row=0, column=0, sticky="w", padx=5, pady=2)
        self.poke_species_combo = ttk.Combobox(scrollable_frame, values=self.species_list)
        self.poke_species_combo.grid(row=0, column=1, sticky="ew", padx=5, pady=2)
        
        # Level
        ttk.Label(scrollable_frame, text="Level:").grid(row=1, column=0, sticky="w", padx=5, pady=2)
        self.poke_level_entry = ttk.Entry(scrollable_frame)
        self.poke_level_entry.grid(row=1, column=1, sticky="ew", padx=5, pady=2)
        
        # Held Item
        ttk.Label(scrollable_frame, text="Held Item:").grid(row=2, column=0, sticky="w", padx=5, pady=2)
        self.poke_item_combo = ttk.Combobox(scrollable_frame, values=self.items_list)
        self.poke_item_combo.grid(row=2, column=1, sticky="ew", padx=5, pady=2)
        
        # Moves (só aparece para tipos 3 e 4)
        self.move_labels = []
        self.move_combos = []
        for i in range(4):
            label = ttk.Label(scrollable_frame, text=f"Move {i+1}:")
            label.grid(row=3+i, column=0, sticky="w", padx=5, pady=2)
            combo = ttk.Combobox(scrollable_frame, values=self.moves_list)
            combo.grid(row=3+i, column=1, sticky="ew", padx=5, pady=2)
            self.move_labels.append(label)
            self.move_combos.append(combo)
        
        # Ability (só aparece para tipo 4)
        self.ability_label = ttk.Label(scrollable_frame, text="Ability:")
        self.ability_label.grid(row=7, column=0, sticky="w", padx=5, pady=2)
        self.ability_combo = ttk.Combobox(scrollable_frame, values=ABILITY_OPTIONS)
        self.ability_combo.grid(row=7, column=1, sticky="ew", padx=5, pady=2)
        self.ability_combo.set("Ability_1")
        
        # Nature (só aparece para tipo 4)
        self.nature_label = ttk.Label(scrollable_frame, text="Nature:")
        self.nature_label.grid(row=8, column=0, sticky="w", padx=5, pady=2)
        self.nature_combo = ttk.Combobox(scrollable_frame, values=NATURES)
        self.nature_combo.grid(row=8, column=1, sticky="ew", padx=5, pady=2)
        self.nature_combo.set("HARDY")
        
        # IVs (só aparece para tipo 4)
        self.iv_label = ttk.Label(scrollable_frame, text="IVs (0-31):")
        self.iv_label.grid(row=9, column=0, sticky="w", padx=5, pady=2)
        self.iv_entry = ttk.Entry(scrollable_frame)
        self.iv_entry.grid(row=9, column=1, sticky="ew", padx=5, pady=2)
        self.iv_entry.insert(0, "31,31,31,31,31,31")
        
        # EVs (só aparece para tipo 4)
        self.ev_label = ttk.Label(scrollable_frame, text="EVs (0-255):")
        self.ev_label.grid(row=10, column=0, sticky="w", padx=5, pady=2)
        self.ev_entry = ttk.Entry(scrollable_frame)
        self.ev_entry.grid(row=10, column=1, sticky="ew", padx=5, pady=2)
        self.ev_entry.insert(0, "85,85,85,85,85,85")
        
        # Tera Type (só aparece para tipo 4)
        self.tera_label = ttk.Label(scrollable_frame, text="Tera Type:")
        self.tera_label.grid(row=11, column=0, sticky="w", padx=5, pady=2)
        self.tera_combo = ttk.Combobox(scrollable_frame, values=TERA_TYPES)
        self.tera_combo.grid(row=11, column=1, sticky="ew", padx=5, pady=2)
        self.tera_combo.set("TYPE_NORMAL")
        
        # Configura o grid para expandir
        scrollable_frame.grid_columnconfigure(1, weight=1)
        
        # Botões de ação
        btn_frame = ttk.Frame(main_frame)
        btn_frame.pack(fill=tk.X, padx=5, pady=5)
        
        ttk.Button(btn_frame, text="+ Add", command=self.add_pokemon).pack(side=tk.LEFT, padx=2)
        ttk.Button(btn_frame, text="- Remove", command=self.remove_pokemon).pack(side=tk.LEFT, padx=2)
        ttk.Button(btn_frame, text="Edit", command=self.edit_pokemon).pack(side=tk.LEFT, padx=2)
        
        # Define o tipo de party padrão
        self.party_type_combo.current(3)  # ItemCustomMoves
        self.update_party_fields()
    
    def setup_bottom_buttons(self):
        """Configura os botões inferiores"""
        btn_frame = ttk.Frame(self.root)
        btn_frame.pack(fill=tk.X, pady=5)
        
        ttk.Button(btn_frame, text="Save Trainer", command=self.save_trainer).pack(side=tk.LEFT, padx=5)
        ttk.Button(btn_frame, text="Save All Files", command=self.save_files).pack(side=tk.LEFT, padx=5)
        ttk.Button(btn_frame, text="Cancel", command=self.root.quit).pack(side=tk.RIGHT, padx=5)
    
    def on_party_type_selected(self, event):
        """Atualiza o tipo de party quando selecionado no combobox"""
        selected = self.party_type_combo.current()
        if selected >= 0:
            self.party_type_var.set(PARTY_TYPES[selected][1])
    
    def update_party_fields(self, *args):
        """Atualiza os campos visíveis com base no tipo de party selecionado"""
        party_type = self.party_type_var.get()
        
        # Atualiza a visibilidade dos campos
        show_moves = party_type in [3, 4]
        show_item = party_type in [2, 4]
        show_advanced = party_type == 4
        
        # Atualiza os campos de movimento
        for label, combo in zip(self.move_labels, self.move_combos):
            label.grid_remove()
            combo.grid_remove()
        
        if show_moves:
            for i, (label, combo) in enumerate(zip(self.move_labels, self.move_combos)):
                label.grid(row=3+i, column=0, sticky="w", padx=5, pady=2)
                combo.grid(row=3+i, column=1, sticky="ew", padx=5, pady=2)
        
        # Atualiza o campo de item
        if show_item:
            self.poke_item_combo.grid(row=2, column=0, columnspan=2, sticky="ew", padx=5, pady=2)
        else:
            self.poke_item_combo.grid_remove()
        
        # Atualiza os campos avançados
        self.ability_label.grid_remove()
        self.ability_combo.grid_remove()
        self.nature_label.grid_remove()
        self.nature_combo.grid_remove()
        self.iv_label.grid_remove()
        self.iv_entry.grid_remove()
        self.ev_label.grid_remove()
        self.ev_entry.grid_remove()
        self.tera_label.grid_remove()
        self.tera_combo.grid_remove()
        
        if show_advanced:
            self.ability_label.grid(row=7, column=0, sticky="w", padx=5, pady=2)
            self.ability_combo.grid(row=7, column=1, sticky="ew", padx=5, pady=2)
            self.nature_label.grid(row=8, column=0, sticky="w", padx=5, pady=2)
            self.nature_combo.grid(row=8, column=1, sticky="ew", padx=5, pady=2)
            self.iv_label.grid(row=9, column=0, sticky="w", padx=5, pady=2)
            self.iv_entry.grid(row=9, column=1, sticky="ew", padx=5, pady=2)
            self.ev_label.grid(row=10, column=0, sticky="w", padx=5, pady=2)
            self.ev_entry.grid(row=10, column=1, sticky="ew", padx=5, pady=2)
            self.tera_label.grid(row=11, column=0, sticky="w", padx=5, pady=2)
            self.tera_combo.grid(row=11, column=1, sticky="ew", padx=5, pady=2)
    
    def update_sprite_preview(self, event=None):
        """Atualiza a visualização do sprite quando selecionado"""
        selected_class = self.sprite_combo.get()
        if selected_class in self.trainer_sprites:
            sprite_name = self.trainer_sprites[selected_class]
            sprite_path = SPRITES_DIR / f"{sprite_name}.png"
            
            try:
                img = Image.open(sprite_path)
                img = img.resize((64, 64), Image.Resampling.LANCZOS)
                self.sprite_img = ImageTk.PhotoImage(img)
                self.sprite_canvas.create_image(0, 0, anchor=tk.NW, image=self.sprite_img)
            except Exception as e:
                print(f"Error loading sprite image: {e}")
                self.sprite_canvas.create_text(32, 32, text="Sprite\nNot Found", fill="white")
    
    def on_class_selected(self, event):
        """Quando uma classe é selecionada, atualiza o sprite e o ID"""
        selected_class = self.class_name_combo.get()
        
        # Atualiza o ID decimal
        class_id = self.get_class_id(selected_class)
        if class_id is not None:
            self.class_id_entry.config(state='normal')
            self.class_id_entry.delete(0, tk.END)
            self.class_id_entry.insert(0, str(class_id))
            self.class_id_entry.config(state='readonly')
        
        # Atualiza o sprite
        if selected_class in self.trainer_sprites:
            self.sprite_combo.set(selected_class)
            self.update_sprite_preview()
    
    def get_class_id(self, class_name):
        """Obtém o ID numérico de uma classe de treinador"""
        # Primeiro tenta encontrar no arquivo de classes
        try:
            with open(TRAINER_CLASSES_PATH, 'r', encoding='utf-8') as f:
                content = f.read()
                pattern = rf"{class_name}\s*=\s*(\d+)"
                match = re.search(pattern, content)
                if match:
                    return int(match.group(1))
        except:
            pass
        
        # Se não encontrou, usa o mapeamento manual
        if 'CLASS_NAME_TO_ID' in globals() and class_name in CLASS_NAME_TO_ID:
            return CLASS_NAME_TO_ID[class_name]
        
        return None
    
    def populate_trainer_tree(self):
        """Popula a lista de treinadores"""
        for item in self.trainer_tree.get_children():
            self.trainer_tree.delete(item)
        
        for name, data in self.trainers.items():
            display_name = ""
            
            for line in data['data']:
                if '.trainerName' in line:
                    display_name = line.split('=')[1].strip(' ,')
                    display_name = self.easy_text_to_normal(display_name)
                    break
            
            self.trainer_tree.insert('', tk.END, values=(data['id'], display_name))
    
    def on_trainer_selected(self, event):
        """Quando um treinador é selecionado na lista"""
        selected = self.trainer_tree.selection()
        if not selected:
            return
        
        item = self.trainer_tree.item(selected[0])
        trainer_id = item["values"][0]
        
        for name, data in self.trainers.items():
            if data['id'] == trainer_id:
                self.current_editing_id = trainer_id
                self.load_trainer_data(name, data)
                break
    
    def load_trainer_data(self, name, data):
        """Carrega os dados do treinador nos campos, incluindo a party"""
        self.clear_editor_fields()
        
        # Preenche campos básicos
        self.define_name_entry.insert(0, name)
        self.trainer_id_entry.insert(0, data['id'])
        
        # Extrai informações adicionais
        party_name = None
        party_type = None
        for line in data['data']:
            if '.trainerClass' in line:
                trainer_class = line.split('=')[1].strip(' ,').replace('CLASS_', '')
                self.class_name_combo.set(trainer_class)
            elif '.trainerName' in line:
                display_name = line.split('=')[1].strip(' ,')
                normal_name = self.easy_text_to_normal(display_name)
                self.display_name_entry.insert(0, normal_name)
            elif '.encounterMusic' in line:
                music = line.split('=')[1].strip(' ,')
                self.music_combo.set(music)
            elif '.doubleBattle' in line:
                self.double_battle_var.set("TRUE" in line)
            elif '.aiFlags' in line:
                flags = line.split('=')[1].strip(' ,')
                self.load_ai_flags(flags)
            elif '.items' in line:
                items = re.findall(r'ITEM_\w+', line)
                for i, item in enumerate(items[:4]):
                    if i < len(self.item_combos):
                        self.item_combos[i].set(item.replace('ITEM_', ''))
            elif '.party = {' in line:
                party_line = line.split('=', 1)[1].strip()
                if '.ItemCustomMoves = ' in party_line:
                    party_name = party_line.split('.ItemCustomMoves = ')[1].strip(' {},')
                    party_type = 4
                elif '.NoItemCustomMoves = ' in party_line:
                    party_name = party_line.split('.NoItemCustomMoves = ')[1].strip(' {},')
                    party_type = 3
                elif '.ItemDefaultMoves = ' in party_line:
                    party_name = party_line.split('.ItemDefaultMoves = ')[1].strip(' {},')
                    party_type = 2
                elif '.NoItemDefaultMoves = ' in party_line:
                    party_name = party_line.split('.NoItemDefaultMoves = ')[1].strip(' {},')
                    party_type = 1
        
        # Carrega a party se encontrou o nome
        if party_name:
            self.load_party_data(party_name, party_type)
                
    def load_party_data(self, party_name, party_type=None):
        """Carrega os dados da party na interface"""
        # Limpa a treeview atual
        for item in self.party_tree.get_children():
            self.party_tree.delete(item)
        
        # Encontra a party nos dados carregados
        party_data = None
        if party_name in self.parties:
            party_data = self.parties[party_name]
        elif party_name in self.new_parties:
            party_data = self.new_parties[party_name]
        
        if not party_data:
            print(f"Party '{party_name}' not found in loaded data")
            return
        
        # Se party_type não foi especificado, tenta determinar do party_data
        if party_type is None:
            party_type = self.get_party_type_from_struct(party_data['type'])
        
        # Atualiza o combobox de party type
        for i, (desc, pt) in enumerate(PARTY_TYPES):
            if pt == party_type:
                self.party_type_combo.current(i)
                self.party_type_var.set(party_type)
                break
        
        # Adiciona cada Pokémon ao treeview
        for pokemon in party_data.get('pokemons', []):
            species = pokemon.get('species', 'SPECIES_NONE').replace('SPECIES_', '')
            level = pokemon.get('level', '0')
            item = pokemon.get('item', 'ITEM_NONE').replace('ITEM_', '')
            
            # Adiciona ao treeview
            self.party_tree.insert('', tk.END, values=(species, level, item))
        
        # Atualiza os campos visíveis
        self.update_party_fields()
        
        # Se houver Pokémon selecionado, carrega seus detalhes
        if self.party_tree.get_children():
            self.party_tree.selection_set(self.party_tree.get_children()[0])
            self.edit_pokemon()
    
    def load_ai_flags(self, flags_str):
        """Carrega as flags AI nos checkboxes usando os nomes das flags"""
        try:
            # Extrai os nomes das flags da string
            flag_names = [f.strip() for f in flags_str.split('|')]
            
            # Verifica cada flag pelo nome
            for flag_name in self.ai_flag_vars:
                self.ai_flag_vars[flag_name].set(flag_name in flag_names)
        except:
            # Fallback para o método antigo se a string não estiver no formato esperado
            try:
                if 'x' in flags_str:
                    flags_value = int(flags_str.split('x')[-1], 16)
                else:
                    flags_value = int(flags_str)
                
                for flag_name in self.ai_flag_vars:
                    flag_value = AI_FLAGS.get(flag_name, 0)
                    if flag_value > 0:
                        self.ai_flag_vars[flag_name].set(bool(flags_value & flag_value))
            except ValueError:
                pass
    
    def clear_editor_fields(self):
        """Limpa todos os campos do editor"""
        self.define_name_entry.delete(0, tk.END)
        self.trainer_id_entry.delete(0, tk.END)
        self.display_name_entry.delete(0, tk.END)
        self.class_name_combo.set('')
        self.gender_var.set("1")
        self.music_combo.set('')
        self.double_battle_var.set(False)
        
        for var in self.ai_flag_vars.values():
            var.set(False)
        
        for combo in self.item_combos:
            combo.set('')
        
        for item in self.party_tree.get_children():
            self.party_tree.delete(item)
        
        self.poke_species_combo.set('')
        self.poke_level_entry.delete(0, tk.END)
        self.poke_item_combo.set('')
        self.iv_entry.delete(0, tk.END)
        self.iv_entry.insert(0, "31,31,31,31,31,31")
        self.ev_entry.delete(0, tk.END)
        self.ev_entry.insert(0, "85,85,85,85,85,85")
        self.nature_combo.set("HARDY")
        self.ability_combo.set("Ability_1")
        self.tera_combo.set("TYPE_NORMAL")
        
        for combo in self.move_combos:
            combo.set('')
    
    def refresh_data(self):
        """Recarrega todos os dados dos arquivos"""
        self.load_initial_data()
        self.populate_trainer_tree()
        messagebox.showinfo("Info", "Data refreshed from files")
    
    def add_trainer(self):
        """Prepara a interface para adicionar um novo treinador"""
        self.current_editing_id = None
        self.clear_editor_fields()
        
        # Define um ID padrão baseado no maior ID existente + 1
        max_id = max([int(data['id']) for data in self.trainers.values()] + [0])
        self.trainer_id_entry.delete(0, tk.END)
        self.trainer_id_entry.insert(0, str(max_id + 1))
    
    def remove_trainer(self):
        """Remove o treinador selecionado"""
        selected = self.trainer_tree.selection()
        if not selected:
            messagebox.showerror("Error", "Please select a trainer first")
            return
        
        item = self.trainer_tree.item(selected[0])
        trainer_id = item["values"][0]
        
        if messagebox.askyesno("Confirm", f"Delete trainer {trainer_id}?"):
            for name, data in list(self.trainers.items()):
                if data['id'] == trainer_id:
                    del self.trainers[name]
                    break
            
            self.populate_trainer_tree()
            messagebox.showinfo("Success", "Trainer deleted successfully")
            self.modified = True
    
    def add_pokemon(self):
        """Adiciona um novo Pokémon ao time"""
        species = self.poke_species_combo.get()
        level = self.poke_level_entry.get()
        item = self.poke_item_combo.get()
        
        if not species or not level.isdigit():
            messagebox.showerror("Error", "Species and Level are required")
            return
        
        # Verifica se o item é necessário para o tipo de party selecionado
        party_type = self.party_type_var.get()
        if party_type in [2, 4] and not item:
            item = "NONE"
        
        self.party_tree.insert('', tk.END, values=(
            species.upper(),
            level,
            item.upper() if item else "NONE"
        ))
        
        # Limpa os campos após adicionar
        self.poke_species_combo.set('')
        self.poke_level_entry.delete(0, tk.END)
        self.poke_item_combo.set('')
        
        for combo in self.move_combos:
            combo.set('')
    
    def edit_pokemon(self):
        """Edita o Pokémon selecionado"""
        selected = self.party_tree.selection()
        if not selected:
            return
        
        item = self.party_tree.item(selected[0])
        values = item['values']
        party_type = self.party_type_var.get()
        
        # Carrega dados básicos
        self.poke_species_combo.set(values[0])
        self.poke_level_entry.delete(0, tk.END)
        self.poke_level_entry.insert(0, values[1])
        self.poke_item_combo.set(values[2] if len(values) > 2 else "NONE")
        
        # Se estiver editando um Pokémon existente, carrega os dados extras
        party_name = None
        if self.current_editing_id:
            for name, data in self.trainers.items():
                if data['id'] == self.current_editing_id and 'party_name' in data:
                    party_name = data['party_name']
                    break
        
        if party_name:
            party_data = self.parties.get(party_name) or self.new_parties.get(party_name)
            if party_data:
                pokemon_index = self.party_tree.index(selected[0])
                if pokemon_index < len(party_data['pokemons']):
                    pokemon = party_data['pokemons'][pokemon_index]
                    
                    # Carrega movimentos
                    if party_type in [3, 4] and 'moves' in pokemon:
                        moves = pokemon['moves']
                        for i in range(min(4, len(moves))):
                            self.move_combos[i].set(moves[i].replace('MOVE_', ''))
                    
                    # Carrega dados avançados
                    if party_type == 4:
                        if 'ability' in pokemon:
                            self.ability_combo.set(pokemon['ability'])
                        if 'nature' in pokemon:
                            self.nature_combo.set(pokemon['nature'].replace('NATURE_', ''))
                        if 'ivs' in pokemon:
                            self.iv_entry.delete(0, tk.END)
                            self.iv_entry.insert(0, pokemon['ivs'])
                        if 'evs' in pokemon:
                            self.ev_entry.delete(0, tk.END)
                            self.ev_entry.insert(0, pokemon['evs'])
                        if 'tera_type' in pokemon:
                            self.tera_combo.set(pokemon['tera_type'])
    
    def remove_pokemon(self):
        """Remove o Pokémon selecionado"""
        selected = self.party_tree.selection()
        if selected:
            self.party_tree.delete(selected[0])
    
    def save_trainer(self):
        """Salva o treinador atual"""
        if not self.validate_inputs():
            return
        
        define_name = self.define_name_entry.get()
        trainer_id = int(self.trainer_id_entry.get())
        
        # Verifica se é uma edição de treinador existente
        is_existing = self.current_editing_id is not None
        
        # Mantém a party existente se estiver editando
        party_name = f"sParty_{define_name.title().replace('_', '')}"
        if is_existing and define_name in self.trainers:
            old_party = self.trainers[define_name].get('party_name')
            if old_party and old_party in self.parties:
                party_name = old_party
        
        # Determina o tipo de party
        party_type = self.party_type_var.get()
        
        # Prepara os dados do party
        party_data = []
        for child in self.party_tree.get_children():
            values = self.party_tree.item(child)['values']
            pokemon = {
                'species': f"SPECIES_{values[0].upper()}",
                'level': values[1],
                'party_type': party_type
            }
            
            # Adiciona item se necessário
            if party_type in [2, 4]:
                pokemon['item'] = f"ITEM_{values[2].upper()}" if len(values) > 2 and values[2] else "ITEM_NONE"
            
            # Adiciona moves se necessário
            if party_type in [3, 4]:
                moves = [combo.get() for combo in self.move_combos]
                pokemon['moves'] = [f"MOVE_{m.upper()}" if m else "MOVE_NONE" for m in moves]
            
            # Adiciona dados avançados se necessário
            if party_type == 4:
                pokemon.update({
                    'ability': self.ability_combo.get(),
                    'nature': self.nature_combo.get(),
                    'ivs': self.iv_entry.get(),
                    'evs': self.ev_entry.get(),
                    'tera_type': self.tera_combo.get()
                })
            
            party_data.append(pokemon)
        
        # Prepara as flags do party
        party_flags = []
        if party_type in [3, 4]:
            party_flags.append("PARTY_FLAG_CUSTOM_MOVES")
        if party_type in [2, 4]:
            party_flags.append("PARTY_FLAG_HAS_ITEM")
        
        trainer_data = {
            'id': trainer_id,
            'data': [
                f".partyFlags = {' | '.join(party_flags) if party_flags else '0'},",
                f".trainerClass = {self.class_name_combo.get().upper()},",
                f".encounterMusic = {self.music_combo.get()},",
                f".trainerPic = TRAINER_PIC_{self.trainer_pic_combo.get()},",
                f".trainerName = {self.convert_to_easy_text(self.display_name_entry.get())},",
                f".items = {{{', '.join([f'ITEM_{combo.get().upper()}' if combo.get() else 'ITEM_NONE' for combo in self.item_combos])}}},",
                f".doubleBattle = {'TRUE' if self.double_battle_var.get() else 'FALSE'},",
                f".aiFlags = {self.get_ai_flags_value()},  // Flags: {hex(self.calculate_ai_flags_numeric())}",
                f".partySize = NELEMS({party_name}),",
                f".party = {{.{PARTY_TYPE_UNION_MAP[party_type]} = {party_name}}}"
            ],
            'party_name': party_name,
            'party_data': party_data,
            'party_struct': PARTY_TYPE_STRUCT_MAP[party_type]
        }
        
        # Adiciona/atualiza nos dados
        self.trainers[define_name] = trainer_data
        self.new_parties[party_name] = {
            'data': party_data,
            'struct': PARTY_TYPE_STRUCT_MAP[party_type]
        }
        self.opponent_name_to_id[define_name] = trainer_id
        self.opponent_id_to_name[trainer_id] = define_name
        
        self.modified = True
        self.populate_trainer_tree()
        messagebox.showinfo("Success", "Trainer saved to memory. Don't forget to save files!")
    
    def calculate_ai_flags_numeric(self):
        """Calcula o valor numérico das flags para referência"""
        flags_value = 0
        for flag_name, var in self.ai_flag_vars.items():
            if var.get():
                flags_value |= AI_FLAGS.get(flag_name, 0)
        return flags_value
    
    def get_ai_flags_value(self):
        """Retorna as flags AI como uma string com os nomes das flags"""
        active_flags = []
        
        for flag_name, var in self.ai_flag_vars.items():
            if var.get():
                active_flags.append(flag_name)
        
        if not active_flags:
            return "0"
        
        return " | ".join(active_flags)
    
    def validate_inputs(self):
        """Valida os campos de entrada"""
        if not self.define_name_entry.get():
            messagebox.showerror("Error", "Define Name is required")
            return False
        
        if not self.trainer_id_entry.get().isdigit():
            messagebox.showerror("Error", "Trainer ID must be a number")
            return False
        
        if not self.class_name_combo.get():
            messagebox.showerror("Error", "Trainer Class is required")
            return False
        
        if not self.party_tree.get_children():
            messagebox.showerror("Error", "Trainer must have at least one Pokémon")
            return False
        
        return True

if __name__ == "__main__":
    root = tk.Tk()
    app = TrainerEditorUI(root)
    root.mainloop()