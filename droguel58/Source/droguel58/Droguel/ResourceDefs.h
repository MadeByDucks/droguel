#pragma once









//OBJCLASS(1, ']', ILLOBJ, S_strange_obj, "illegal objects", "strange object")
//OBJCLASS(2, ')', WEAPON, S_weapon, "weapons", "weapon")
//OBJCLASS(3, '[', ARMOR, S_armor, "armor", "suit or piece of armor")
//OBJCLASS(4, '=', RING, S_ring, "rings", "ring")
//OBJCLASS(5, '"', AMULET, S_amulet, "amulets", "amulet")
//OBJCLASS(6, '(', TOOL, S_tool, "tools","useful item (pick-axe, key, lamp...)")
//OBJCLASS(7, '%', FOOD, S_food, "food", "piece of food")
//OBJCLASS(8, '!', POTION, S_potion, "potions", "potion")
//OBJCLASS(9, '?', SCROLL, S_scroll, "scrolls", "scroll")
//OBJCLASS(10, '+', SPBOOK, S_book, "spellbooks", "spellbook")
//OBJCLASS(11, '/', WAND, S_wand, "wands", "wand")
//OBJCLASS2(12, '$', COIN, GOLD_SYM, S_coin, "coins", "pile of coins")
//OBJCLASS(13, '*', GEM, S_gem, "rocks", "gem or rock")
//OBJCLASS(14, '`', ROCK, S_rock, "large stones", "boulder or statue")
//OBJCLASS(15, '0', BALL, S_ball, "iron balls", "iron ball")
//OBJCLASS(16, '_', CHAIN, S_chain, "chains", "iron chain")
//OBJCLASS(17, '.', VENOM, S_venom, "venoms", "splash of venom")



//MONSYM(1, 'a', ANT, S_ANT, "ant or other insect")
//MONSYM(2, 'b', BLOB, S_BLOB, "blob")
//MONSYM(3, 'c', COCKATRICE, S_COCKATRICE, "cockatrice")
//MONSYM(4, 'd', DOG, S_DOG, "dog or other canine")
//MONSYM(5, 'e', EYE, S_EYE, "eye or sphere")
//MONSYM(6, 'f', FELINE, S_FELINE, "cat or other feline")
//MONSYM(7, 'g', GREMLIN, S_GREMLIN, "gremlin")
//// small humanoids: hobbit, dwarf 
//MONSYM(8, 'h', HUMANOID, S_HUMANOID, "humanoid")
//// minor demons 
//MONSYM(9, 'i', IMP, S_IMP, "imp or minor demon")
//MONSYM(10, 'j', JELLY, S_JELLY, "jelly")
//MONSYM(11, 'k', KOBOLD, S_KOBOLD, "kobold")
//MONSYM(12, 'l', LEPRECHAUN, S_LEPRECHAUN, "leprechaun")
//MONSYM(13, 'm', MIMIC, S_MIMIC, "mimic")
//MONSYM(14, 'n', NYMPH, S_NYMPH, "nymph")
//MONSYM(15, 'o', ORC, S_ORC, "orc")
//MONSYM(16, 'p', PIERCER, S_PIERCER, "piercer")
//// quadruped excludes horses 
//MONSYM(17, 'q', QUADRUPED, S_QUADRUPED, "quadruped")
//MONSYM(18, 'r', RODENT, S_RODENT, "rodent")
//MONSYM(19, 's', SPIDER, S_SPIDER, "arachnid or centipede")
//MONSYM(20, 't', TRAPPER, S_TRAPPER, "trapper or lurker above")
//// unicorn, horses 
//MONSYM(21, 'u', UNICORN, S_UNICORN, "unicorn or horse")
//MONSYM(22, 'v', VORTEX, S_VORTEX, "vortex")
//MONSYM(23, 'w', WORM, S_WORM, "worm")
//MONSYM(24, 'x', XAN, S_XAN, "xan or other mythical/fantastic insect")
//// yellow light, black light 
//MONSYM(25, 'y', LIGHT, S_LIGHT, "light")
//MONSYM(26, 'z', ZRUTY, S_ZRUTY, "zruty")
//MONSYM(27, 'A', ANGEL, S_ANGEL, "angelic being")
//MONSYM(28, 'B', BAT, S_BAT, "bat or bird")
//MONSYM(29, 'C', CENTAUR, S_CENTAUR, "centaur")
//MONSYM(30, 'D', DRAGON, S_DRAGON, "dragon")
//// elemental includes invisible stalker 
//MONSYM(31, 'E', ELEMENTAL, S_ELEMENTAL, "elemental")
//MONSYM(32, 'F', FUNGUS, S_FUNGUS, "fungus or mold")
//MONSYM(33, 'G', GNOME, S_GNOME, "gnome")
//// large humanoid: giant, ettin, minotaur 
//MONSYM(34, 'H', GIANT, S_GIANT, "giant humanoid")
//MONSYM(35, 'I', INVISIBLE, S_invisible, "invisible monster")
//MONSYM(36, 'J', JABBERWOCK, S_JABBERWOCK, "jabberwock")
//MONSYM(37, 'K', KOP, S_KOP, "Keystone Kop")
//MONSYM(38, 'L', LICH, S_LICH, "lich")
//MONSYM(39, 'M', MUMMY, S_MUMMY, "mummy")
//MONSYM(40, 'N', NAGA, S_NAGA, "naga")
//MONSYM(41, 'O', OGRE, S_OGRE, "ogre")
//MONSYM(42, 'P', PUDDING, S_PUDDING, "pudding or ooze")
//MONSYM(43, 'Q', QUANTMECH, S_QUANTMECH, "quantum mechanic")
//MONSYM(44, 'R', RUSTMONST, S_RUSTMONST, "rust monster or disenchanter")
//MONSYM(45, 'S', SNAKE, S_SNAKE, "snake")
//MONSYM(46, 'T', TROLL, S_TROLL, "troll")
//// umber hulk 
//MONSYM(47, 'U', UMBER, S_UMBER, "umber hulk")
//MONSYM(48, 'V', VAMPIRE, S_VAMPIRE, "vampire")
//MONSYM(49, 'W', WRAITH, S_WRAITH, "wraith")
//MONSYM(50, 'X', XORN, S_XORN, "xorn")
//// apelike creature includes owlbear, monkey 
//MONSYM(51, 'Y', YETI, S_YETI, "apelike creature")
//MONSYM(52, 'Z', ZOMBIE, S_ZOMBIE, "zombie")
//MONSYM(53, '@', HUMAN, S_HUMAN, "human or elf")
//// space symbol
//MONSYM(54, ' ', GHOST, S_GHOST, "ghost")
//MONSYM(55, '\'', GOLEM, S_GOLEM, "golem")
//MONSYM(56, '&', DEMON, S_DEMON, "major demon")
//// fish 
//MONSYM(57, ';', EEL, S_EEL, "sea monster")
//// reptiles 
//MONSYM(58, ':', LIZARD, S_LIZARD, "lizard")
//MONSYM(59, '~', WORM_TAIL, S_WORM_TAIL, "long worm tail")
//MONSYM(60, ']', MIMIC_DEF, S_MIMIC_DEF, "mimic")



//PCHAR2(0, ' ', S_stone, "dark part of a room", "stone", NO_COLOR)
//PCHAR2(1, '|', S_vwall, "vertical wall", "wall", CLR_GRAY)
//PCHAR2(2, '-', S_hwall, "horizontal wall", "wall", CLR_GRAY)
//PCHAR2(3, '-', S_tlcorn, "top left corner wall", "wall", CLR_GRAY)
//PCHAR2(4, '-', S_trcorn, "top right corner wall", "wall", CLR_GRAY)
//PCHAR2(5, '-', S_blcorn, "bottom left corner wall", "wall", CLR_GRAY)
//PCHAR2(6, '-', S_brcorn, "bottom right corner wall", "wall", CLR_GRAY)
//PCHAR2(7, '-', S_crwall, "cross wall", "wall", CLR_GRAY)
//PCHAR2(8, '-', S_tuwall, "tuwall", "wall", CLR_GRAY)
//PCHAR2(9, '-', S_tdwall, "tdwall", "wall", CLR_GRAY)
//PCHAR2(10, '|', S_tlwall, "tlwall", "wall", CLR_GRAY)
//PCHAR2(11, '|', S_trwall, "trwall", "wall", CLR_GRAY)
//// start cmap A                                                      
//PCHAR2(12, '.', S_ndoor, "no door", "doorway", CLR_GRAY)
//PCHAR2(13, '-', S_vodoor, "vertical open door", "open door", CLR_BROWN)
//PCHAR2(14, '|', S_hodoor, "horizontal open door", "open door", CLR_BROWN)
//PCHAR2(15, '+', S_vcdoor, "vertical closed door","closed door", CLR_BROWN)
//PCHAR2(16, '+', S_hcdoor, "horizontal closed door","closed door", CLR_BROWN)
//PCHAR(17, '#', S_bars, "iron bars", HI_METAL)
//PCHAR(18, '#', S_tree, "tree", CLR_GREEN)
//PCHAR(19, '.', S_room, "floor of a room", CLR_GRAY)
//PCHAR(20, '.', S_darkroom, "dark part of a room", CLR_BLACK)
//PCHAR2(21, '`', S_engroom, "engraving in a room", "engraving",
//CLR_BRIGHT_BLUE)
//PCHAR2(22, '#', S_corr, "dark corridor", "corridor", CLR_GRAY)
//PCHAR(23, '#', S_litcorr, "lit corridor", CLR_GRAY)
//PCHAR2(24, '#', S_engrcorr, "engraving in a corridor", "engraving",
//CLR_BRIGHT_BLUE)
//PCHAR2(25, '<', S_upstair, "up stairs", "staircase up", CLR_GRAY)
//PCHAR2(26, '>', S_dnstair, "down stairs", "staircase down", CLR_GRAY)
//PCHAR2(27, '<', S_upladder, "up ladder", "ladder up", CLR_BROWN)
//PCHAR2(28, '>', S_dnladder, "down ladder", "ladder down", CLR_BROWN)
//PCHAR(29, '<', S_brupstair, "branch staircase up", CLR_YELLOW)
//PCHAR(30, '>', S_brdnstair, "branch staircase down", CLR_YELLOW)
//PCHAR(31, '<', S_brupladder, "branch ladder up", CLR_YELLOW)
//PCHAR(32, '>', S_brdnladder, "branch ladder down", CLR_YELLOW)
//// end cmap A 
//PCHAR(33, '_', S_altar, "altar", CLR_GRAY)
//// start cmap B 
//PCHAR(34, '|', S_grave, "grave", CLR_WHITE)
//PCHAR2(35, '\\', S_throne, "throne", "opulent throne", HI_GOLD)
//PCHAR(36, '{', S_sink, "sink", CLR_WHITE)
//PCHAR(37, '{', S_fountain, "fountain", CLR_BRIGHT_BLUE)
//PCHAR2(38, '}', S_pool, "pool", "water", CLR_BLUE)
//PCHAR(39, '.', S_ice, "ice", CLR_CYAN)
//PCHAR(40, '}', S_lava, "molten lava", CLR_RED)
//PCHAR(41, '}', S_lavawall, "wall of lava", CLR_ORANGE)
//PCHAR2(42, '.', S_vodbridge, "vertical open drawbridge","lowered drawbridge", CLR_BROWN)
//PCHAR2(43, '.', S_hodbridge, "horizontal open drawbridge","lowered drawbridge", CLR_BROWN)
//PCHAR2(44, '#', S_vcdbridge, "vertical closed drawbridge","raised drawbridge", CLR_BROWN)
//PCHAR2(45, '#', S_hcdbridge, "horizontal closed drawbridge","raised drawbridge", CLR_BROWN)
//PCHAR(46, ' ', S_air, "air", CLR_CYAN)
//PCHAR(47, '#', S_cloud, "cloud", CLR_GRAY)
//PCHAR(48, '}', S_water, "water", CLR_BRIGHT_BLUE)
//// end dungeon characters                                                                                                        
//// begin traps                                                                                                                   
//PCHAR(49, '^', S_arrow_trap, "arrow trap", HI_METAL)
//PCHAR(50, '^', S_dart_trap, "dart trap", HI_METAL)
//PCHAR(51, '^', S_falling_rock_trap, "falling rock trap", CLR_GRAY)
//PCHAR(52, '^', S_squeaky_board, "squeaky board", CLR_BROWN)
//PCHAR(53, '^', S_bear_trap, "bear trap", HI_METAL)
//PCHAR(54, '^', S_land_mine, "land mine", CLR_RED)
//PCHAR(55, '^', S_rolling_boulder_trap, "rolling boulder trap", CLR_GRAY)
//PCHAR(56, '^', S_sleeping_gas_trap, "sleeping gas trap", HI_ZAP)
//PCHAR(57, '^', S_rust_trap, "rust trap", CLR_BLUE)
//PCHAR(58, '^', S_fire_trap, "fire trap", CLR_ORANGE)
//PCHAR(59, '^', S_pit, "pit", CLR_BLACK)
//PCHAR(60, '^', S_spiked_pit, "spiked pit", CLR_BLACK)
//PCHAR(61, '^', S_hole, "hole", CLR_BROWN)
//PCHAR(62, '^', S_trap_door, "trap door", CLR_BROWN)
//PCHAR(63, '^', S_teleportation_trap, "teleportation trap", CLR_MAGENTA)
//PCHAR(64, '^', S_level_teleporter, "level teleporter", CLR_MAGENTA)
//PCHAR(65, '^', S_magic_portal, "magic portal", CLR_BRIGHT_MAGENTA)
//PCHAR(66, '"', S_web, "web", CLR_GRAY)
//PCHAR(67, '^', S_statue_trap, "statue trap", CLR_GRAY)
//PCHAR(68, '^', S_magic_trap, "magic trap", HI_ZAP)
//PCHAR2(69, '^', S_anti_magic_trap, "anti magic trap", "anti-magic field",
//HI_ZAP)
//PCHAR(70, '^', S_polymorph_trap, "polymorph trap", CLR_BRIGHT_GREEN)
//PCHAR(71, '~', S_vibrating_square, "vibrating square", CLR_MAGENTA)
//PCHAR(72, '^', S_trapped_door, "trapped door", CLR_ORANGE)
//PCHAR(73, '^', S_trapped_chest, "trapped chest", CLR_ORANGE)
//// end traps                                                       
//// end cmap B                                                                
//// begin special effects                                                                                                               
//// zap colors are changed by reset_glyphmap() to match type of beam                                                                  
//PCHAR2(74, '|', S_vbeam, "vertical beam", "", CLR_GRAY)
//PCHAR2(75, '-', S_hbeam, "horizontal beam", "", CLR_GRAY)
//PCHAR2(76, '\\', S_lslant, "left slant beam", "", CLR_GRAY)
//PCHAR2(77, '/', S_rslant, "right slant beam", "", CLR_GRAY)
//// start cmap C 
//PCHAR2(78, '*', S_digbeam, "dig beam", "", CLR_WHITE)
//PCHAR2(79, '!', S_flashbeam, "flash beam", "", CLR_WHITE)
//PCHAR2(80, ')', S_boomleft, "boom left", "", HI_WOOD)
//PCHAR2(81, '(', S_boomright, "boom right", "", HI_WOOD)
//// 4 magic shield symbols                                          
//PCHAR2(82, '0', S_ss1, "shield1", "", HI_ZAP)
//PCHAR2(83, '#', S_ss2, "shield2", "", HI_ZAP)
//PCHAR2(84, '@', S_ss3, "shield3", "", HI_ZAP)
//PCHAR2(85, '*', S_ss4, "shield4", "", HI_ZAP)
//PCHAR(86, '#', S_poisoncloud, "poison cloud", CLR_BRIGHT_GREEN)
//PCHAR(87, '?', S_goodpos, "valid position", CLR_BRIGHT_GREEN)






















//monster symbol
enum SYSMON
{
    S_ANT,
    S_BLOB,
    S_COCKATRICE,
    S_DOG,
    S_EYE,
    S_FELINE,
    S_GREMLIN,
    // small humanoids: hobbit, dwarf
    S_HUMANOID,
    // minor demons
    S_IMP,
    S_JELLY,
    S_KOBOLD,
    S_LEPRECHAUN,
    S_MIMIC,
    S_NYMPH,
    S_ORC,
    S_PIERCER,
    // quadruped excludes horses
    S_QUADRUPED,
    S_RODENT,
    S_SPIDER,
    S_TRAPPER,
    // unicorn, horses
    S_UNICORN,
    S_VORTEX,
    S_WORM,
    S_XAN,
    // yellow light, black light
    S_LIGHT,
    S_ZRUTY,
    S_ANGEL,
    S_BAT,
    S_CENTAUR,
    S_DRAGON,
    // elemental includes invisible stalker
    S_ELEMENTAL,
    S_FUNGUS,
    S_GNOME,
    // large humanoid: giant, ettin, minotaur
    S_GIANT,
    S_invisible,
    S_JABBERWOCK,
    S_KOP,
    S_LICH,
    S_MUMMY,
    S_NAGA,
    S_OGRE,
    S_PUDDING,
    S_QUANTMECH,
    S_RUSTMONST,
    S_SNAKE,
    S_TROLL,
    // umber hulk
    S_UMBER,
    S_VAMPIRE,
    S_WRAITH,
    S_XORN,
    // apelike creature includes owlbear, monkey
    S_YETI,
    S_ZOMBIE,
    S_HUMAN,
    // space symbol
    S_GHOST,
    S_GOLEM,
    S_DEMON,
    // fish
    S_EEL,
    // reptiles
    S_LIZARD,
    S_WORM_TAIL,
    S_MIMIC_DEF,
};

#define WT_HUMAN 1450U
#define WT_ELF 800U
#define WT_DRAGON 4500U


#define VERY_SLOW 3
#define SLOW_SPEED 9
#define NORMAL_SPEED 12 // movement rates 
#define FAST_SPEED 15
#define VERY_FAST 24


// for mons[].geno (constant during game) 
#define G_UNIQ          0x1000 // generated only once 
#define G_NOHELL        0x0800 // not generated in "hell" 
#define G_HELL          0x0400 // generated only in "hell" 
#define G_NOGEN         0x0200 // generated only specially 
#define G_SGROUP        0x0080 // appear in small groups normally 
#define G_LGROUP        0x0040 // appear in large groups normally 
#define G_GENO          0x0020 // can be genocided 
#define G_NOCORPSE      0x0010 // no corpse left ever 
#define G_FREQ          0x0007 // creation frequency mask 
// note: G_IGNORE controls handling of mvitals[].mvflags bits but is
//   passed to mkclass() as if it dealt with mons[].geno bits 
#define G_IGNORE        0x8000 // for mkclass(), ignore G_GENOD|G_EXTINCT 
// for gm.mvitals[].mvflags (variant during game), along with G_NOCORPSE 
#define G_KNOWN         0x04 // have been encountered 
#define G_GENOD         0x02 // have been genocided 
#define G_EXTINCT       0x01 // population control; create no more 
#define G_GONE          (G_GENOD | G_EXTINCT)


#define AT_ANY (-1) // fake attack; dmgtype_fromattack wildcard 
#define AT_NONE 0   // passive monster (ex. acid blob) 
#define AT_CLAW 1   // claw (punch, hit, etc.) 
#define AT_BITE 2   // bite 
#define AT_KICK 3   // kick 
#define AT_BUTT 4   // head butt (ex. a unicorn) 
#define AT_TUCH 5   // touches 
#define AT_STNG 6   // sting 
#define AT_HUGS 7   // crushing bearhug 
#define AT_SPIT 10  // spits substance - ranged 
#define AT_ENGL 11  // engulf (swallow or by a cloud) 
#define AT_BREA 12  // breath - ranged 
#define AT_EXPL 13  // explodes - proximity 
#define AT_BOOM 14  // explodes when killed 
#define AT_GAZE 15  // gaze - ranged 
#define AT_TENT 16  // tentacles 
#define AT_WEAP 254 // uses weapon 
#define AT_MAGC 255 // uses magic spell(s) 
#define AT_EMPTY 256 //droguel add


#define AD_ANY (-1) // fake damage; attacktype_fordmg wildcard 
#define AD_PHYS 0   // ordinary physical 
#define AD_MAGM 1   // magic missiles 
#define AD_FIRE 2   // fire damage 
#define AD_COLD 3   // frost damage 
#define AD_SLEE 4   // sleep ray 
#define AD_DISN 5   // disintegration (death ray) 
#define AD_ELEC 6   // shock damage 
#define AD_DRST 7   // drains str (poison) 
#define AD_ACID 8   // acid damage 
#define AD_SPC1 9   // for extension of buzz() 
#define AD_SPC2 10  // for extension of buzz() 
#define AD_BLND 11  // blinds (yellow light) 
#define AD_STUN 12  // stuns 
#define AD_SLOW 13  // slows 
#define AD_PLYS 14  // paralyses 
#define AD_DRLI 15  // drains life levels (Vampire) 
#define AD_DREN 16  // drains magic energy 
#define AD_LEGS 17  // damages legs (xan) 
#define AD_STON 18  // petrifies (Medusa, cockatrice) 
#define AD_STCK 19  // sticks to you (mimic) 
#define AD_SGLD 20  // steals gold (leppie) 
#define AD_SITM 21  // steals item (nymphs) 
#define AD_SEDU 22  // seduces & steals multiple items 
#define AD_TLPT 23  // teleports you (Quantum Mech.) 
#define AD_RUST 24  // rusts armour (Rust Monster)
#define AD_CONF 25  // confuses (Umber Hulk) 
#define AD_DGST 26  // digests opponent (trapper, etc.) 
#define AD_HEAL 27  // heals opponent's wounds (nurse) 
#define AD_WRAP 28  // special "stick" for eels 
#define AD_WERE 29  // confers lycanthropy 
#define AD_DRDX 30  // drains dexterity (quasit) 
#define AD_DRCO 31  // drains constitution 
#define AD_DRIN 32  // drains intelligence (mind flayer) 
#define AD_DISE 33  // confers diseases 
#define AD_DCAY 34  // decays organics (brown Pudding) 
#define AD_SSEX 35  // Succubus seduction (extended) 
#define AD_HALU 36  // causes hallucination 
#define AD_DETH 37  // for Death only 
#define AD_PEST 38  // for Pestilence only 
#define AD_FAMN 39  // for Famine only 
#define AD_SLIM 40  // turns you into green slime 
#define AD_ENCH 41  // remove enchantment (disenchanter) 
#define AD_CORR 42  // corrode armor (black pudding) 
#define AD_POLY 43  // polymorph the target (genetic engineer) 
#define AD_CLRC 240 // random clerical spell 
#define AD_SPEL 241 // random magic spell 
#define AD_RBRE 242 // random breath weapon 
#define AD_SAMU 252 // hits, may steal Amulet (Wizard) 
#define AD_CURS 253 // random curse (ex. gremlin) 
#define AD_EMPTY 254 //droguel addition


#define MR_FIRE         0x01 // resists fire 
#define MR_COLD         0x02 // resists cold 
#define MR_SLEEP        0x04 // resists sleep 
#define MR_DISINT       0x08 // resists disintegration 
#define MR_ELEC         0x10 // resists electricity 
#define MR_POISON       0x20 // resists poison 
#define MR_ACID         0x40 // resists acid 
#define MR_STONE        0x80 // resists petrification 
// other resistances: magic, sickness 
// other conveyances: teleport, teleport control, telepathy 

// individual resistances 
#define MR2_SEE_INVIS   0x0100 // see invisible 
#define MR2_LEVITATE    0x0200 // levitation 
#define MR2_WATERWALK   0x0400 // water walking 
#define MR2_MAGBREATH   0x0800 // magical breathing 
#define MR2_DISPLACED   0x1000 // displaced 
#define MR2_STRENGTH    0x2000 // gauntlets of power 
#define MR2_FUMBLING    0x4000 // clumsy 

#define M1_FLY          0x00000001L // can fly or float 
#define M1_SWIM         0x00000002L // can traverse water 
#define M1_AMORPHOUS    0x00000004L // can flow under doors 
#define M1_WALLWALK     0x00000008L // can phase thru rock 
#define M1_CLING        0x00000010L // can cling to ceiling 
#define M1_TUNNEL       0x00000020L // can tunnel thru rock 
#define M1_NEEDPICK     0x00000040L // needs pick to tunnel 
#define M1_CONCEAL      0x00000080L // hides under objects 
#define M1_HIDE         0x00000100L // mimics, blends in with ceiling 
#define M1_AMPHIBIOUS   0x00000200L // can survive underwater 
#define M1_BREATHLESS   0x00000400L // doesn't need to breathe 
#define M1_NOTAKE       0x00000800L // cannot pick up objects 
#define M1_NOEYES       0x00001000L // no eyes to gaze into or blind 
#define M1_NOHANDS      0x00002000L // no hands to handle things 
#define M1_NOLIMBS      0x00006000L // no arms/legs to kick/wear on 
#define M1_NOHEAD       0x00008000L // no head to behead 
#define M1_MINDLESS     0x00010000L // has no mind--golem, zombie, mold 
#define M1_HUMANOID     0x00020000L // has humanoid head/arms/torso 
#define M1_ANIMAL       0x00040000L // has animal body 
#define M1_SLITHY       0x00080000L // has serpent body 
#define M1_UNSOLID      0x00100000L // has no solid or liquid body 
#define M1_THICK_HIDE   0x00200000L // has thick hide or scales 
#define M1_OVIPAROUS    0x00400000L // can lay eggs 
#define M1_REGEN        0x00800000L // regenerates hit points 
#define M1_SEE_INVIS    0x01000000L // can see invisible creatures 
#define M1_TPORT        0x02000000L // can teleport 
#define M1_TPORT_CNTRL  0x04000000L // controls where it teleports to 
#define M1_ACID         0x08000000L // acidic to eat 
#define M1_POIS         0x10000000L // poisonous to eat 
#define M1_CARNIVORE    0x20000000L // eats corpses 
#define M1_HERBIVORE    0x40000000L // eats fruits 
#define M1_OMNIVORE     0x60000000L // eats both 
#define M1_METALLIVORE  0x80000000L // eats metal 


#define M2_NOPOLY       0x00000001L // players mayn't poly into one 
#define M2_UNDEAD       0x00000002L // is walking dead 
#define M2_WERE         0x00000004L // is a lycanthrope 
#define M2_HUMAN        0x00000008L // is a human 
#define M2_ELF          0x00000010L // is an elf 
#define M2_DWARF        0x00000020L // is a dwarf 
#define M2_GNOME        0x00000040L // is a gnome 
#define M2_ORC          0x00000080L // is an orc 
#define M2_DEMON        0x00000100L // is a demon 
#define M2_MERC         0x00000200L // is a guard or soldier 
#define M2_LORD         0x00000400L // is a lord to its kind 
#define M2_PRINCE       0x00000800L // is an overlord to its kind 
#define M2_MINION       0x00001000L // is a minion of a deity 
#define M2_GIANT        0x00002000L // is a giant 
#define M2_SHAPESHIFTER 0x00004000L // is a shapeshifting species 
#define M2_MALE         0x00010000L // always male 
#define M2_FEMALE       0x00020000L // always female 
#define M2_NEUTER       0x00040000L // neither male nor female 
#define M2_PNAME        0x00080000L // monster name is a proper name 
#define M2_HOSTILE      0x00100000L // always starts hostile 
#define M2_PEACEFUL     0x00200000L // always starts peaceful 
#define M2_DOMESTIC     0x00400000L // can be tamed by feeding 
#define M2_WANDER       0x00800000L // wanders randomly 
#define M2_STALK        0x01000000L // follows you to other levels 
#define M2_NASTY        0x02000000L // extra-nasty monster (more xp) 
#define M2_STRONG       0x04000000L // strong (or big) monster 
#define M2_ROCKTHROW    0x08000000L // throws boulders 
#define M2_GREEDY       0x10000000L // likes gold 
#define M2_JEWELS       0x20000000L // likes gems 
#define M2_COLLECT      0x40000000L // picks up weapons and food 
#define M2_MAGIC        0x80000000L // picks up magic items 


#define M3_WANTSAMUL    0x0001 // would like to steal the amulet 
#define M3_WANTSBELL    0x0002 // wants the bell 
#define M3_WANTSBOOK    0x0004 // wants the book 
#define M3_WANTSCAND    0x0008 // wants the candelabrum 
#define M3_WANTSARTI    0x0010 // wants the quest artifact 
#define M3_WANTSALL     0x001f // wants any major artifact 
#define M3_WAITFORU     0x0040 // waits to see you or get attacked 
#define M3_CLOSE        0x0080 // lets you close unless attacked 

#define M3_COVETOUS     0x001f // wants something 
#define M3_WAITMASK     0x00c0 // waiting... 

// Infravision is currently implemented for players only 
#define M3_INFRAVISION  0x0100 // has infravision 
#define M3_INFRAVISIBLE 0x0200 // visible by infravision 
#define M3_DISPLACES    0x0400 // moves monsters out of its way 

#define MZ_TINY         0 // < 2' 
#define MZ_SMALL        1 // 2-4' 
#define MZ_MEDIUM       2 // 4-7' 
#define MZ_HUMAN        MZ_MEDIUM // human-sized 
#define MZ_LARGE        3 // 7-12' 
#define MZ_HUGE         4 // 12-25' 
#define MZ_GIGANTIC     7 // off the scale 







enum ms_sounds {
    MS_SILENT = 0,   // makes no sound 
    MS_BARK = 1,   // if full moon, may howl 
    MS_MEW = 2,   // mews or hisses 
    MS_ROAR = 3,   // roars 
    MS_BELLOW = 4,   // adult male crocodiles; hatchlings 'chirp' 
    MS_GROWL = 5,   // growls 
    MS_SQEEK = 6,   // squeaks, as a rodent 
    MS_SQAWK = 7,   // squawks, as a bird 
    MS_CHIRP = 8,   // baby crocodile 
    MS_HISS = 9,   // hisses 
    MS_BUZZ = 10,   // buzzes (killer bee) 
    MS_GRUNT = 11,   // grunts (or speaks own language) 
    MS_NEIGH = 12,   // neighs, as an equine 
    MS_MOO = 13,   // minotaurs, rothes 
    MS_WAIL = 14,   // wails, as a tortured soul 
    MS_GURGLE = 15,   // gurgles, as liquid or through saliva 
    MS_BURBLE = 16,   // burbles (jabberwock) 
    MS_TRUMPET = 17,   // trumpets (elephant) 
    MS_ANIMAL = 17,   // up to here are animal noises 
    // FIXME? the grunt "speaks own language" case above
    //   shouldn't be classified as animal 
    MS_SHRIEK = 18,   // wakes up others 
    MS_BONES = 19,   // rattles bones (skeleton) 
    MS_LAUGH = 20,   // grins, smiles, giggles, and laughs 
    MS_MUMBLE = 21,   // says something or other 
    MS_IMITATE = 22,   // imitates others (leocrotta) 
    MS_WERE = 23,   // lycanthrope in human form 
    MS_ORC = 24,   // intelligent brutes 
    // from here onward, speech can be comprehended 
    MS_HUMANOID = 25,   // generic traveling companion 
    MS_ARREST = 26,   // "Stop in the name of the law!" (Kops) 
    MS_SOLDIER = 27,   // army and watchmen expressions 
    MS_GUARD = 28,   // "Please drop that gold and follow me." 
    MS_DJINNI = 29,   // "Thank you for freeing me!" 
    MS_NURSE = 30,   // "Take off your shirt, please." 
    MS_SEDUCE = 31,   // "Hello, sailor." (Nymphs) 
    MS_VAMPIRE = 32,   // vampiric seduction, Vlad's exclamations 
    MS_BRIBE = 33,   // asks for money, or berates you 
    MS_CUSS = 34,   // berates (demons) or intimidates (Wiz) 
    MS_RIDER = 35,   // astral level special monsters 
    MS_LEADER = 36,   // your class leader 
    MS_NEMESIS = 37,   // your nemesis 
    MS_GUARDIAN = 38,   // your leader's guards 
    MS_SELL = 39,   // demand payment, complain about shoplifters 
    MS_ORACLE = 40,   // do a consultation 
    MS_PRIEST = 41,   // ask for contribution; do cleansing 
    MS_SPELL = 42,   // spellcaster not matching any of the above 
    MS_BOAST = 43,   // giants 
    MS_GROAN = 44,   // zombies groan 
    MS_NONE = -1 //droguel addition
};


//The color scheme used is tailored for an IBM PC.  It consists of the
//standard 8 colors, followed by their bright counterparts.  There are
//exceptions, these are listed below.	Bright black doesn't mean very
//much, so it is used as the "default" foreground color of the screen.
#define CLR_BLACK 0
#define CLR_RED 1
#define CLR_GREEN 2
#define CLR_BROWN 3 //on IBM, low-intensity yellow is brown
#define CLR_BLUE 4
#define CLR_MAGENTA 5
#define CLR_CYAN 6
#define CLR_GRAY 7 //low-intensity white 
#define NO_COLOR 8
#define CLR_ORANGE 9
#define CLR_BRIGHT_GREEN 10
#define CLR_YELLOW 11
#define CLR_BRIGHT_BLUE 12
#define CLR_BRIGHT_MAGENTA 13
#define CLR_BRIGHT_CYAN 14
#define CLR_WHITE 15
#define CLR_MAX 16

 //The "half-way" point for tty-based color systems.  This is used in
 //the tty color setup code.  (IMHO, it should be removed - dean).
#define BRIGHT 8

//color aliases used in monsters.h and display.c
#define HI_DOMESTIC CLR_WHITE // for player + pets
#define HI_LORD CLR_MAGENTA // for high-end monsters
#define HI_OVERLORD CLR_BRIGHT_MAGENTA // for few uniques

//these can be configured
#define HI_OBJ CLR_MAGENTA
#define HI_METAL CLR_CYAN
#define HI_COPPER CLR_YELLOW
#define HI_SILVER CLR_GRAY
#define HI_GOLD CLR_YELLOW
#define HI_LEATHER CLR_BROWN
#define HI_CLOTH CLR_BROWN
#define HI_ORGANIC CLR_BROWN
#define HI_WOOD CLR_BROWN
#define HI_PAPER CLR_WHITE
#define HI_GLASS CLR_BRIGHT_CYAN
#define HI_MINERAL CLR_GRAY
#define DRAGON_SILVER CLR_BRIGHT_CYAN
#define HI_ZAP CLR_BRIGHT_BLUE





























//[misnamed] definition of a type of object; many objects are composites
//(liquid potion inside glass bottle, metal arrowhead on wooden shaft)
//and object definitions only specify one type on a best-fit basis 
enum obj_material_types {
    LIQUID = 1, // currently only for venom 
    WAX = 2,
    VEGGY = 3, // foodstuffs 
    FLESH = 4, //   ditto    
    PAPER = 5,
    CLOTH = 6,
    LEATHER = 7,
    WOOD = 8,
    BONE = 9,
    DRAGON_HIDE = 10, // not leather! 
    IRON = 11, // Fe - includes steel 
    METAL = 12, // Sn, &c. 
    COPPER = 13, // Cu - includes brass 
    SILVER = 14, // Ag 
    GOLD = 15, // Au 
    PLATINUM = 16, // Pt 
    MITHRIL = 17,
    PLASTIC = 18,
    GLASS = 19,
    GEMSTONE = 20,
    MINERAL = 21
};


// oc_dir: zap style for wands and spells 
#define NODIR     1 // non-directional 
#define IMMEDIATE 2 // directional beam that doesn't ricochet 
#define RAY       3 // beam that does bounce off walls 
// overloaded oc_dir: strike mode bit mask for weapons and weptools 
#define PIERCE   01 // pointed weapon punctures target 
#define SLASH    02 // sharp weapon cuts target 
#define WHACK    04 // blunt weapon bashes target 



//Much of this code was taken from you.h.  It is now
 // in a separate file so it can be included in objects.c.


enum p_skills
{
    //Code to denote that no skill is applicable 
    P_NONE = 0,

    //Weapon Skills -- Stephen White
    //Order matters and are used in macros.
    //Positive values denote hand-to-hand weapons or launchers.
    //Negative values denote ammunition or missiles.
    //Update weapon.c if you amend any skills.
    //Also used for oc_subtyp.
    P_DAGGER = 1,
    P_KNIFE = 2,
    P_AXE = 3,
    P_PICK_AXE = 4,
    P_SHORT_SWORD = 5,
    P_BROAD_SWORD = 6,
    P_LONG_SWORD = 7,
    P_TWO_HANDED_SWORD = 8,
    P_SABER = 9, //Curved sword, includes scimitar 
    P_CLUB = 10, //Heavy-shafted bludgeon 
    P_MACE = 11,
    P_MORNING_STAR = 12, //Spiked bludgeon 
    P_FLAIL = 13, //Two pieces hinged or chained together 
    P_HAMMER = 14, //Heavy head on the end 
    P_QUARTERSTAFF = 15, //Long-shafted bludgeon 
    P_POLEARMS = 16, //attack two or three steps away 
    P_SPEAR = 17, //includes javelin 
    P_TRIDENT = 18,
    P_LANCE = 19,
    P_BOW = 20, //launchers 
    P_SLING = 21,
    P_CROSSBOW = 22,
    P_DART = 23, //hand-thrown missiles 
    P_SHURIKEN = 24,
    P_BOOMERANG = 25,
    P_WHIP = 26, //flexible, one-handed 
    P_UNICORN_HORN = 27, //last weapon, two-handed 

    //Spell Skills added by Larry Stewart-Zerba 
    P_ATTACK_SPELL = 28,
    P_HEALING_SPELL = 29,
    P_DIVINATION_SPELL = 30,
    P_ENCHANTMENT_SPELL = 31,
    P_CLERIC_SPELL = 32,
    P_ESCAPE_SPELL = 33,
    P_MATTER_SPELL = 34,

    //Other types of combat 
    P_BARE_HANDED_COMBAT = 35, //actually weaponless; gloves are ok 
    P_TWO_WEAPON_COMBAT = 36, //pair of weapons, one in each hand 
    P_RIDING = 37, //How well you control your steed 

    P_NUM_SKILLS = 38
};


enum obj_armor_types {
    ARM_SUIT = 0,
    ARM_SHIELD = 1,        // needed for special wear function 
    ARM_HELM = 2,
    ARM_GLOVES = 3,
    ARM_BOOTS = 4,
    ARM_CLOAK = 5,
    ARM_SHIRT = 6
};


// Resistances to troubles 
enum prop_types {
    FIRE_RES = 1,
    COLD_RES = 2,
    SLEEP_RES = 3,
    DISINT_RES = 4,
    SHOCK_RES = 5,
    POISON_RES = 6,
    ACID_RES = 7,
    STONE_RES = 8,
    // note: for the first eight properties, MR_xxx == (1 << (xxx_RES - 1)) 
    DRAIN_RES = 9,
    SICK_RES = 10,
    INVULNERABLE = 11,
    ANTIMAGIC = 12,
    // Troubles 
    STUNNED = 13,
    CONFUSION = 14,
    BLINDED = 15,
    DEAF = 16,
    SICK = 17,
    STONED = 18,
    STRANGLED = 19,
    VOMITING = 20,
    GLIB = 21,
    SLIMED = 22,
    HALLUC = 23,
    HALLUC_RES = 24,
    FUMBLING = 25,
    WOUNDED_LEGS = 26,
    SLEEPY = 27,
    HUNGER = 28,
    // Vision and senses 
    SEE_INVIS = 29,
    TELEPAT = 30,
    WARNING = 31,
    WARN_OF_MON = 32,
    WARN_UNDEAD = 33,
    SEARCHING = 34,
    CLAIRVOYANT = 35,
    INFRAVISION = 36,
    DETECT_MONSTERS = 37,
    // Appearance and behavior 
    ADORNED = 38,
    INVIS = 39,
    DISPLACED = 40,
    STEALTH = 41,
    AGGRAVATE_MONSTER = 42,
    CONFLICT = 43,
    // Transportation 
    JUMPING = 44,
    TELEPORT = 45,
    TELEPORT_CONTROL = 46,
    LEVITATION = 47,
    FLYING = 48,
    WWALKING = 49,
    SWIMMING = 50,
    MAGICAL_BREATHING = 51,
    PASSES_WALLS = 52,
    // Physical attributes 
    SLOW_DIGESTION = 53,
    HALF_SPDAM = 54,
    HALF_PHDAM = 55,
    REGENERATION = 56,
    ENERGY_REGENERATION = 57,
    PROTECTION = 58,
    PROT_FROM_SHAPE_CHANGERS = 59,
    POLYMORPH = 60,
    POLYMORPH_CONTROL = 61,
    UNCHANGING = 62,
    FAST = 63,
    REFLECTING = 64,
    FREE_ACTION = 65,
    FIXED_ABIL = 66,
    LIFESAVED = 67
};











//skills
///* Much of this code was taken from you.h.  It is now
// * in a separate file so it can be included in objects.c.
// */
//
//enum p_skills {
//    /* Code to denote that no skill is applicable */
//    P_NONE = 0,
//
//    //Weapon Skills -- Stephen White
//    //Order matters and are used in macros.
//    //Positive values denote hand-to-hand weapons or launchers.
//    //Negative values denote ammunition or missiles.
//    //Update weapon.c if you amend any skills.
//    //Also used for oc_subtyp.
//    P_DAGGER = 1,
//    P_KNIFE = 2,
//    P_AXE = 3,
//    P_PICK_AXE = 4,
//    P_SHORT_SWORD = 5,
//    P_BROAD_SWORD = 6,
//    P_LONG_SWORD = 7,
//    P_TWO_HANDED_SWORD = 8,
//    P_SABER = 9, /* Curved sword, includes scimitar */
//    P_CLUB = 10, /* Heavy-shafted bludgeon */
//    P_MACE = 11,
//    P_MORNING_STAR = 12, /* Spiked bludgeon */
//    P_FLAIL = 13, /* Two pieces hinged or chained together */
//    P_HAMMER = 14, /* Heavy head on the end */
//    P_QUARTERSTAFF = 15, /* Long-shafted bludgeon */
//    P_POLEARMS = 16, /* attack two or three steps away */
//    P_SPEAR = 17, /* includes javelin */
//    P_TRIDENT = 18,
//    P_LANCE = 19,
//    P_BOW = 20, /* launchers */
//    P_SLING = 21,
//    P_CROSSBOW = 22,
//    P_DART = 23, /* hand-thrown missiles */
//    P_SHURIKEN = 24,
//    P_BOOMERANG = 25,
//    P_WHIP = 26, /* flexible, one-handed */
//    P_UNICORN_HORN = 27, /* last weapon, two-handed */
//
//    /* Spell Skills added by Larry Stewart-Zerba */
//    P_ATTACK_SPELL = 28,
//    P_HEALING_SPELL = 29,
//    P_DIVINATION_SPELL = 30,
//    P_ENCHANTMENT_SPELL = 31,
//    P_CLERIC_SPELL = 32,
//    P_ESCAPE_SPELL = 33,
//    P_MATTER_SPELL = 34,
//
//    /* Other types of combat */
//    P_BARE_HANDED_COMBAT = 35, /* actually weaponless; gloves are ok */
//    P_TWO_WEAPON_COMBAT = 36, /* pair of weapons, one in each hand */
//    P_RIDING = 37, /* How well you control your steed */
//
//    P_NUM_SKILLS = 38
//};
//
//#define P_MARTIAL_ARTS P_BARE_HANDED_COMBAT /* Role distinguishes */
//
//#define P_FIRST_WEAPON P_DAGGER
//#define P_LAST_WEAPON P_UNICORN_HORN
//
//#define P_FIRST_SPELL P_ATTACK_SPELL
//#define P_LAST_SPELL P_MATTER_SPELL
//
//#define P_LAST_H_TO_H P_RIDING
//#define P_FIRST_H_TO_H P_BARE_HANDED_COMBAT
//
///* These roles qualify for a martial arts bonus */
//#define martial_bonus() (Role_if(PM_SAMURAI) || Role_if(PM_MONK))
//
///*
// * These are the standard weapon skill levels.  It is important that
// * the lowest "valid" skill be be 1.  The code calculates the
// * previous amount to practice by calling  practice_needed_to_advance()
// * with the current skill-1.  To work out for the UNSKILLED case,
// * a value of 0 needed.
// */
//enum skill_levels {
//    P_ISRESTRICTED = 0, /* unskilled and can't be advanced */
//    P_UNSKILLED = 1, /* unskilled so far but can be advanced */
//    /* Skill levels Basic/Advanced/Expert had long been used by
//       Heroes of Might and Magic (tm) and its sequels... */
//    P_BASIC = 2,
//    P_SKILLED = 3,
//    P_EXPERT = 4,
//    /* when the skill system was adopted into nethack, levels beyond expert
//       were unnamed and just used numbers.  Devteam coined them Master and
//       Grand Master.  Sometime after that, Heroes of Might and Magic IV (tm)
//       was released and had two more levels which use these same names. */
//    P_MASTER = 5, /* Unarmed combat/martial arts only */
//    P_GRAND_MASTER = 6  /* ditto */
//};
//
//#define practice_needed_to_advance(level) ((level) * (level) *20)
//
/////* The hero's skill in various weapons. */
////struct skills {
////    xint16 skill;
////    xint16 max_skill;
////    unsigned short advance;
////};
//
//#define P_SKILL(type) (u.weapon_skills[type].skill)
//#define P_MAX_SKILL(type) (u.weapon_skills[type].max_skill)
//#define P_ADVANCE(type) (u.weapon_skills[type].advance)
//#define P_RESTRICTED(type) (u.weapon_skills[type].skill == P_ISRESTRICTED)
//
//#define P_SKILL_LIMIT 60 /* Max number of skill advancements */
//
/////* Initial skill matrix structure; used in u_init.c and weapon.c */
////struct def_skill {
////    xint16 skill;
////    xint16 skmax;
////};
//
//















////////////////////////////////////////////////////////////////////////////
// objects / items /////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


struct GeneralItem
{
    std::string name;
    std::string desc;

    //name
    //skill knife dagger ax
    //cost
    //num hands
    //weight
    //prob
    //damage s
    //damage l
    //material//
    //appearance
    //tile bitmap
    //glyph character



    int kn;
    int prob; //probability
    int wt;     //weight
    int cost;   //cost (zm)
    int sdam;   //damage to small monsters
    int ldam;   //damage to large monsters
    int hitbon;
    int metal;  //metal type (iron silver wood undefined mineral
    int sub_x;
    int color;  //color
    std::string sn; //??? name


    std::string inscription;     //can charge change good bad
    std::string modelNumber;    //joke
    std::string serialNumber;   //joke
};

struct ObjectProjectile
{
    std::string name;
    std::string desc;
    int kn;
    int prob;
    int wt;
    int cost;
    int sdam;
    int ldam;
    int hitbon;
    int metal;
    int sub_x;
    int color;
    std::string sn;
};

struct ObjectWeapon
{
    std::string name;
    std::string desc;
    int kn;
    int mg;
    int bi;
    int prob;
    int wt;
    int cost;
    int sdam;
    int ldam;
    int hitbon;
    int typ;
    int sub_p;
    int metal;
    int color;
    std::string sn;
};

struct ObjectBow
{
    std::string name;
    std::string desc;
    int kn;
    int prob;
    int wt;
    int cost;
    int hitbon;
    int metal;
    int sub_x;
    int color;
    std::string sn;
};

struct ObjectHelm
{
    std::string name;
    std::string desc;
    int kn;
    int mgc;
    int power;
    int prob;
    int delay;
    int wt;
    int cost;
    int ac;
    int can;
    int metal;
    int c;
    std::string sn;
};

struct ObjectDragonArmor
{
    std::string name;
    int mgc;
    int power;
    int cost;
    int ac;
    int color;
    std::string snam;
};

struct ObjectArmor
{
    std::string name;
    std::string desc;
    int kn;
    int mgc;
    int blk;
    int power;
    int prob;
    int delay;
    int wt;
    int cost;
    int ac;
    int can;
    int sub;
    int metal;
    int c;
    std::string sn;
};


struct ObjectCloak
{
    std::string name;
    std::string desc;
    int kn;
    int mgc;
    int power;
    int prob;
    int delay;
    int wt;
    int cost;
    int ac;
    int can;
    int metal;
    int c;
    std::string s;
};

struct ObjectShield
{
    std::string name;
    std::string desc;
    int kn;
    int mgc;
    int blk;
    int power;
    int prob;
    int delay;
    int wt;
    int cost;
    int ac;
    int can;
    int metal;
    int c;
    std::string sn;
};

struct ObjectGloves
{
    std::string name;
    std::string desc;
    int kn;
    int mgc;
    int power;
    int prob;
    int delay;
    int wt;
    int cost;
    int ac;
    int can;
    int metal;
    int c;
    std::string sn;
};


struct ObjectBoots
{
    std::string name;
    std::string desc;
    int kn;
    int mgc;
    int power;
    int prob;
    int delay;
    int wt;
    int cost;
    int ac;
    int can;
    int metal;
    int c;
    std::string sn;
};

struct ObjectRing
{
    std::string name;
    std::string stone;
    int power;
    int cost;
    int mgc;
    int spec;
    int mohs;
    int metal;
    int color;
    std::string sn;

};

struct ObjectAmulet
{
    std::string name;
    std::string desc;
    int power;
    int prob;
    std::string sn;
};

struct ObjectContainer
{
    std::string name;
    std::string desc;
    int kn;
    int mgc;
    int chg;
    int prob;
    int wt;
    int cost;
    int mat;
    int color;
    std::string sn;
};

struct ObjectTool
{
    std::string name;
    std::string desc;
    int kn;
    int mrg;
    int mgc;
    int chg;
    int prob;
    int wt;
    int cost;
    int mat;
    int color;
    std::string sn;
};

struct ObjectEyeware
{
    std::string name;
    std::string desc;
    int kn;
    int prop;
    int prob;
    int wt;
    int cost;
    int mat;
    int color;
    std::string sn;
};

struct ObjectWepTool
{
    std::string name;
    std::string desc;
    int kn;
    int mgc;
    int bi;
    int prob;
    int wt;
    int cost;
    int sdam;
    int ldam;
    int hitbon;
    int sub;
    int mat;
    int clr;
    std::string sn;
};

struct ObjectFood
{
    std::string name;
    int prob;
    int delay;
    int wt;
    int unk;
    int tin;
    int nutrition;
    int color;
    std::string sn;
};

struct ObjectPotion
{
    std::string name;
    std::string desc;
    int mgc;
    int power;
    int prob;
    int cost;
    int color;
    std::string sn;
};

struct ObjectScroll
{
    std::string name;
    std::string text;
    int mgc;
    int prob;
    int cost;
    std::string sn;
};

struct ObjectSpell
{
    std::string name;
    std::string desc;
    int sub;
    int prob;
    int delay;
    int level;
    int mgc;
    int dir;
    int color;
    std::string sn;
};

struct ObjectWand
{
    std::string name;
    std::string typ;
    int prob;
    int cost;
    int mgc;
    int dir;
    int metal;
    int color;
    std::string sn;
};

struct ObjectGem
{
    std::string name;
    std::string desc;
    int prob;
    int wt;
    int gval;
    int nutr;
    int mohs;
    int glass;
    int color;
    std::string sn;
};

struct ObjectCoin
{
    std::string name;
    int prob;
    int metal;
    int worth;
    std::string sn;
};

struct ObjectRock
{
    std::string name;
    std::string desc;
    int kn;
    int prob;
    int wt;
    int gval;
    int sdam;
    int ldam;
    int mgc;
    int nutr;
    int mohs;
    int glass;
    int color;
    std::string sn;
};




////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////



struct itemDef
{
    std::string itemName;
    std::string itemType;
};




////////////////////////////////////////////////////////////////////////////
// monsters ////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

class LVL
{
public:
    LVL() {};
    LVL(int bl, int mrs, int ac, int mr, int al)
    {
        base_level = bl;
        move_rate_speed = mrs;
        base_ac_armor_class = ac;
        base_mr_magic_resistance = mr;
        alignment = al;
    };
    int base_level;
    int move_rate_speed;
    int base_ac_armor_class;
    int base_mr_magic_resistance;
    int alignment;
};

class ATTK
{
public:
    ATTK() {};
    ATTK(int at, int dt, int nd, int ns)
    {
        attk_type = at;
        damage_type = dt;
        numdice = nd;
        numsides = ns;
    };
    int attk_type;
    int damage_type;
    int numdice;
    int numsides;
};

class SIZ
{
public:
    SIZ() {};
    SIZ(int wt, int nv, ms_sounds sd, int sz)
    {
        weight = wt;  //weight
        nut_val = nv; //nutritional value
        sound = sd;
        size = sz;
    };
    int weight;
    int nut_val;
    ms_sounds sound;
    int size;
};

class cmonster
{
public:
    //cmonster();
    //~cmonster();

    std::string namm;
    std::string namf;
    std::string namn;
    SYSMON symbol;
    LVL level;
    ATTK m_atk1;
    ATTK m_atk2;
    ATTK m_atk3;
    ATTK m_atk4;
    ATTK m_atk5;
    ATTK m_atk6;
    SIZ m_siz;
    int mr1; //magic resist
    int mr2; //magic resist
    long flg1;
    long flg2;
    long flg3;
    int dificulty;
    int color;
    std::string defmon;
};

