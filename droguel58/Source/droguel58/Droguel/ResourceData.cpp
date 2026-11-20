#include "ResourceData.h"
#include <string>
//#include "sqlite3.h"
#include "dpUtilFile.h"
#include "ResourceDefs.h"


std::string NoDes = "";


ResourceData::ResourceData()
{
}

ResourceData::~ResourceData()
{
}



////////////////////////////////////////////////////////////////////////////////
// monsters ////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void ResourceData::addMonster(std::vector<cmonster>& ml, std::string namm, std::string namf, std::string namn, SYSMON symbol, LVL level, long geno,
    ATTK at1, ATTK at2, ATTK at3, ATTK at4, ATTK at5, ATTK at6, SIZ sizrec,
    int mr1, int mr2, long flg1, long flg2, long flg3, int dificulty, int color, std::string defmon)
{
    //printf("%s\n", namn.c_str());
    cmonster rec;
    rec.namm = namm;
    rec.namf = namf;
    rec.namn = namn;
    rec.symbol = symbol;
    rec.level = level;
    rec.m_atk1 = at1;
    rec.m_atk2 = at2;
    rec.m_atk3 = at3;
    rec.m_atk4 = at4;
    rec.m_atk5 = at5;
    rec.m_atk6 = at6;
    rec.m_siz = sizrec;
    rec.mr1 = mr1;
    rec.mr2 = mr2;
    rec.flg1 = flg1;
    rec.flg2 = flg2;
    rec.flg3 = flg3;
    rec.dificulty = dificulty;
    rec.color = color;
    rec.defmon = defmon;
    ml.push_back(rec);
}

////////////////////////////////////////////////////////////////////////////////
// other    ////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void ResourceData::addProjectile(std::vector<ObjectProjectile>& projectileList, std::string name, std::string desc, int kn, int prob, int wt, int cost, int sdam, int ldam, int hitbon, int metal, int sub_x, int color, std::string sn)
{
    ObjectProjectile rec;
    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.prob = prob;
    rec.wt = wt;
    rec.cost = cost;
    rec.sdam = sdam;
    rec.ldam = ldam;
    rec.hitbon = hitbon;
    rec.metal = metal;
    rec.sub_x = sub_x;
    rec.color = color;
    rec.sn = sn;
    projectileList.push_back(rec);
}

void ResourceData::addWeapon(std::vector<ObjectWeapon>& weaponList, std::string name, std::string desc, int kn, int mg, int bi, int prob, int wt, int cost, int sdam, int ldam, int hitbon, int typ, int sub_x, int metal, int color, std::string sn)
{
    ObjectWeapon rec;
    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.mg = mg;
    rec.bi = bi;
    rec.prob = prob;
    rec.wt = wt;
    rec.cost = cost;
    rec.sdam = sdam;
    rec.ldam = ldam;
    rec.hitbon = hitbon;
    rec.typ = typ;
    rec.sub_p = sub_x;
    rec.metal = metal;
    rec.color = color;
    rec.sn = sn;
    weaponList.push_back(rec);
}

void ResourceData::addBow(std::vector<ObjectBow>& bowList, std::string name, std::string desc, int kn, int prob, int wt, int cost, int hitbon, int metal, int sub_x, int color, std::string sn)
{
    ObjectBow rec;
    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.prob = prob;
    rec.wt = wt;
    rec.cost = cost;
    rec.hitbon = hitbon;
    rec.metal = metal;
    rec.sub_x = sub_x;
    rec.color = color;
    rec.sn = sn;
    bowList.push_back(rec);
}

void ResourceData::addHelm(std::vector<ObjectHelm>& helmList, std::string name, std::string desc, int kn, int mgc, int power, int prob, int delay, int wt, int cost, int ac, int can, int metal, int c, std::string sn)
{
    ObjectHelm rec;
    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.mgc = mgc;
    rec.power = power;
    rec.prob = prob;
    rec.delay = delay;
    rec.wt = wt;
    rec.cost = cost;
    rec.ac = ac;
    rec.can = can;
    rec.metal = metal;
    rec.c = c;
    rec.sn = sn;
    helmList.push_back(rec);
}

void ResourceData::addDragonArmor(std::vector<ObjectDragonArmor>& dragonArmorList, std::string name, int mgc, int power, int cost, int ac, int color, std::string snam)
{
    ObjectDragonArmor rec;
    rec.name = name;
    rec.mgc = mgc;
    rec.power = power;
    rec.cost = cost;
    rec.ac = ac;
    rec.color = color;
    rec.snam = snam;
    dragonArmorList.push_back(rec);
}

void ResourceData::addArmor(std::vector<ObjectArmor>& armorList, std::string name, std::string desc, int kn, int mgc, int blk, int power, int prob, int delay, int wt,
    int cost, int ac, int can, int sub, int metal, int c, std::string sn)
{
    ObjectArmor rec;
    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.mgc = mgc;
    rec.blk = blk;
    rec.power = power;
    rec.prob = prob;
    rec.delay = delay;
    rec.wt = wt;
    rec.cost = cost;
    rec.ac = ac;
    rec.can = can;
    rec.sub = sub;
    rec.metal = metal;
    rec.c = c;
    rec.sn = sn;
    armorList.push_back(rec);
}

void ResourceData::addCloak(std::vector<ObjectCloak>& cloakList, std::string name, std::string desc, int kn, int mgc, int power, int prob, int delay, int wt, int cost, int ac,
    int can, int metal, int c, std::string sn)
{
    ObjectCloak rec;
    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.mgc = mgc;
    rec.power = power;
    rec.prob = prob;
    rec.delay = delay;
    rec.wt = wt;
    rec.cost = cost;
    rec.ac = ac;
    rec.can = can;
    rec.metal = metal;
    rec.c = c;
    rec.s = sn;
    cloakList.push_back(rec);
}

void ResourceData::addShield(std::vector<ObjectShield>& shieldList, std::string name, std::string desc, int kn, int mgc, int blk, int power, int prob, int delay, int wt, int cost,
    int ac, int can, int metal, int c, std::string sn)
{
    ObjectShield rec;
    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.mgc = mgc;
    rec.blk = blk;
    rec.power = power;
    rec.prob = prob;
    rec.delay = delay;
    rec.wt = wt;
    rec.cost = cost;
    rec.ac = ac;
    rec.can = can;
    rec.metal = metal;
    rec.c = c;
    rec.sn = sn;
    shieldList.push_back(rec);
}

void ResourceData::addGloves(std::vector<ObjectGloves>& glovesList, std::string name, std::string desc, int kn, int mgc, int power, int prob, int delay, int wt, int cost, int ac, int can, int metal, int c, std::string sn)
{
    ObjectGloves rec;
    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.mgc = mgc;
    rec.power = power;
    rec.prob = prob;
    rec.delay = delay;
    rec.wt = wt;
    rec.cost = cost;
    rec.ac = ac;
    rec.can = can;
    rec.metal = metal;
    rec.c = c;
    rec.sn = sn;
    glovesList.push_back(rec);
}

void ResourceData::addBoots(std::vector<ObjectBoots>& bootsList, std::string name, std::string desc, int kn, int mgc, int power, int prob, int delay, int wt, int cost, int ac, int can, int metal, int c, std::string sn)
{
    ObjectBoots rec;
    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.mgc = mgc;
    rec.power = power;
    rec.prob = prob;
    rec.delay = delay;
    rec.wt = wt;
    rec.cost = cost;
    rec.ac = ac;
    rec.can = can;
    rec.metal = metal;
    rec.c = c;
    rec.sn = sn;
    bootsList.push_back(rec);
}

void ResourceData::addRing(std::vector<ObjectRing>& ringList, std::string name, std::string stone, int power, int cost, int mgc, int spec, int mohs, int metal, int color, std::string sn)
{
    ObjectRing rec;
    rec.name = name;
    rec.stone = stone;
    rec.power = power;
    rec.cost = cost;
    rec.mgc = mgc;
    rec.spec = spec;
    rec.mohs = mohs;
    rec.metal = metal;
    rec.color = color;
    rec.sn = sn;
    ringList.push_back(rec);
}

void ResourceData::addAmulet(std::vector<ObjectAmulet>& amuletList, std::string name, std::string desc, int power, int prob, std::string sn)
{
    ObjectAmulet rec;
    rec.name = name;
    rec.desc = desc;
    rec.power = power;
    rec.prob = prob;
    rec.sn = sn;
    amuletList.push_back(rec);
}

void ResourceData::addContainer(std::vector<ObjectContainer>& containerList, std::string name, std::string desc, int kn, int mgc, int chg, int prob, int wt, int cost, int mat, int color, std::string sn)
{
    ObjectContainer rec;
    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.mgc = mgc;
    rec.chg = chg;
    rec.prob = prob;
    rec.wt = wt;
    rec.cost = cost;
    rec.mat = mat;
    rec.color = color;
    rec.sn = sn;
    containerList.push_back(rec);
}

void ResourceData::addTool(std::vector<ObjectTool>& toolList, std::string name, std::string desc, int kn, int mrg, int mgc, int chg, int prob, int wt, int cost, int mat, int color, std::string sn)
{
    ObjectTool rec;
    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.mrg = mrg;
    rec.mgc = mgc;
    rec.chg = chg;
    rec.prob = prob;
    rec.wt = wt;
    rec.cost = cost;
    rec.mat = mat;
    rec.color = color;
    rec.sn = sn;
    toolList.push_back(rec);
}

void ResourceData::addEyeware(std::vector<ObjectEyeware>& eyewareList, std::string name, std::string desc, int kn, int prop, int prob, int wt, int cost, int mat, int color, std::string sn)
{
    ObjectEyeware rec;
    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.prop = prop;
    rec.prob = prob;
    rec.wt = wt;
    rec.cost = cost;
    rec.mat = mat;
    rec.color = color;
    rec.sn = sn;

    eyewareList.push_back(rec);

}

void ResourceData::addWepTool(std::vector<ObjectWepTool>& weptoolList, std::string name, std::string desc, int kn, int mgc, int bi, int prob, int wt, int cost, int sdam, int ldam, int hitbon, int sub, int mat, int clr, std::string sn)
{
    ObjectWepTool rec;

    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.mgc = mgc;
    rec.bi = bi;
    rec.prob = prob;
    rec.wt = wt;
    rec.cost = cost;
    rec.sdam = sdam;
    rec.ldam = ldam;
    rec.hitbon = hitbon;
    rec.sub = sub;
    rec.mat = mat;
    rec.clr = clr;
    rec.sn = sn;
    weptoolList.push_back(rec);

}

void ResourceData::addFood(std::vector<ObjectFood>& foodList, std::string name, int prob, int delay, int wt, int unk, int tin, int nutrition, int color, std::string sn)
{
    ObjectFood rec;

    rec.name = name;
    rec.prob = prob;
    rec.delay = delay;
    rec.wt = wt;
    rec.unk = unk;
    rec.tin = tin;
    rec.nutrition = nutrition;
    rec.color = color;
    rec.sn = sn;
    foodList.push_back(rec);

}

void ResourceData::addPotion(std::vector<ObjectPotion>& potionList, std::string name, std::string desc, int mgc, int power, int prob, int cost, int color, std::string sn)
{
    ObjectPotion rec;
    rec.name = name;
    rec.desc = desc;
    rec.mgc = mgc;
    rec.power = power;
    rec.prob = prob;
    rec.cost = cost;
    rec.color = color;
    rec.sn = sn;

    potionList.push_back(rec);

}

void ResourceData::addScroll(std::vector<ObjectScroll>& scrollList, std::string name, std::string text, int mgc, int prob, int cost, std::string sn)
{
    ObjectScroll rec;
    rec.name = name;
    rec.text = text;
    rec.mgc = mgc;
    rec.prob = prob;
    rec.cost = cost;
    rec.sn = sn;
    scrollList.push_back(rec);
}

void ResourceData::addSpell(std::vector<ObjectSpell>& spellList, std::string name, std::string desc, int sub, int prob, int delay, int level, int mgc, int dir, int color, std::string sn)
{
    ObjectSpell rec;
    rec.name = name;
    rec.desc = desc;
    rec.sub = sub;
    rec.prob = prob;
    rec.delay = delay;
    rec.level = level;
    rec.mgc = mgc;
    rec.dir = dir;
    rec.color = color;
    rec.sn = sn;
    spellList.push_back(rec);
}

void ResourceData::addWand(std::vector<ObjectWand>& wandList, std::string name, std::string typ, int prob, int cost, int mgc, int dir, int metal, int color, std::string sn)
{
    ObjectWand rec;
    rec.name = name;
    rec.typ = typ;
    rec.prob = prob;
    rec.cost = cost;
    rec.mgc = mgc;
    rec.dir = dir;
    rec.metal = metal;
    rec.color = color;
    rec.sn = sn;
    wandList.push_back(rec);
}

void ResourceData::addGem(std::vector<ObjectGem>& gemList, std::string name, std::string desc, int prob, int wt, int gval, int nutr, int mohs, int glass, int color, std::string sn)
{
    ObjectGem rec;
    rec.name = name;
    rec.desc = desc;
    rec.prob = prob;
    rec.wt = wt;
    rec.gval = gval;
    rec.nutr = nutr;
    rec.mohs = mohs;
    rec.glass = glass;
    rec.color = color;
    rec.sn = sn;
    gemList.push_back(rec);
}

void ResourceData::addCoin(std::vector<ObjectCoin>& coinList, std::string name, int prob, int metal, int worth, std::string sn)
{
    ObjectCoin rec;
    rec.name = name;
    rec.prob = prob;
    rec.metal = metal;
    rec.worth = worth;
    rec.sn = sn;
    coinList.push_back(rec);
}

void ResourceData::addRock(std::vector<ObjectRock>& rockList, std::string name, std::string desc, int kn, int prob, int wt, int gval, int sdam, int ldam, int mgc, int nutr, int mohs, int glass, int color, std::string sn)
{
    ObjectRock rec;
    rec.name = name;
    rec.desc = desc;
    rec.kn = kn;
    rec.prob = prob;
    rec.wt = wt;
    rec.gval = gval;
    rec.sdam = sdam;
    rec.ldam = ldam;
    rec.mgc = mgc;
    rec.nutr = nutr;
    rec.mohs = mohs;
    rec.glass = glass;
    rec.color = color;
    rec.sn = sn;
    rockList.push_back(rec);
}



////////////////////////////////////////////////////////////////////////////////
// categories //////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void ResourceData::insertCharCat(std::string ascii, std::string desc)
{
}

void ResourceData::insertMonster(std::string ascii, std::string fname, std::string desc)
{
}

void ResourceData::loadCategories()
{
    //https:nethackwiki.com/wiki/Monster

    /////
    insertCharCat("a", "ants or other insects");
    insertMonster("a", "Giant ant.png", "giant ant");
    insertMonster("a", "Killer bee.png", "killer bee");
    insertMonster("a", "Soldier ant.png", "soldier ant");
    insertMonster("a", "Fire ant.png", "fire ant");
    insertMonster("a", "Giant beetle.png", "giant beetle");
    insertMonster("a", "Queen bee.png", "queen bee");
    /////
    insertCharCat("b", "blobs");
    insertMonster("b", "Acid blob.png", "acid blob");
    insertMonster("b", "Quivering blob.png", "quivering blob");
    insertMonster("b", "Gelatinous cube.png", "gelatinous cube");
    /////
    insertCharCat("c", "cockatrices");
    insertMonster("c", "Chickatrice.png", "chickatrice");
    insertMonster("c", "Cockatrice.png", "cockatrice");
    insertMonster("c", "Pyrolisk.png", "pyrolisk");
    /////
    insertCharCat("d", "canines");
    insertMonster("d", "Jackal.png", "jackal");
    insertMonster("d", "Fox.png", "fox");
    insertMonster("d", "Coyote.png", "coyote");
    insertMonster("d", "Werejackal were.png", "werejackal");
    insertMonster("d", "Little dog.png", "little dog");
    insertMonster("d", "Dog.png", "dog");
    insertMonster("d", "Large dog.png", "large dog");
    insertMonster("d", "Dingo.png", "dingo");
    insertMonster("d", "Wolf.png", "wolf");
    insertMonster("d", "Werewolf were.png", "werewolf");
    insertMonster("d", "Warg.png", "warg");
    insertMonster("d", "Winter wolf cub.png", "winter wolf cub");
    insertMonster("d", "Winter wolf.png", "winter wolf");
    insertMonster("d", "Hell hound pup.png", "hell hound pup");
    insertMonster("d", "Hell hound.png", "hell hound");
    /////
    insertCharCat("e", "eyes and spheres");
    insertMonster("e", "Gas spore.png", "gas spore");
    insertMonster("e", "Floating eye.png", "floating eye");
    insertMonster("e", "Freezing sphere.png", "freezing sphere");
    insertMonster("e", "Flaming sphere.png", "flaming sphere");
    insertMonster("e", "Shocking sphere.png", "shocking sphere");
    /////
    insertCharCat("f", "felines");
    insertMonster("f", "Kitten.png", "kitten");
    insertMonster("f", "Housecat.png", "housecat");
    insertMonster("f", "Jaguar.png", "jaguar");
    insertMonster("f", "Lynx.png", "lynx");
    insertMonster("f", "Panther.png", "panther");
    insertMonster("f", "Large cat.png", "large cat");
    insertMonster("f", "Tiger.png", "tiger");
    /////
    insertCharCat("g", "gremlins and gargoyles");
    insertMonster("g", "Gremlin.png", "gremlin");
    insertMonster("g", "Gargoyle.png", "gargoyle");
    insertMonster("g", "Winged gargoyle.png", "winged gargoyle");
    /////
    insertCharCat("h", "humanoids");
    insertMonster("h", "Hobbit.png", "hobbit");
    insertMonster("h", "Dwarf.png", "dwarf");
    insertMonster("h", "Bugbear.png", "bugbear");
    insertMonster("h", "Dwarf lord.png", "dwarf lord");
    insertMonster("h", "Dwarf king.png", "dwarf king");
    insertMonster("h", "Mind flayer.png", "mind flayer");
    insertMonster("h", "Master mind flayer.png", "master mind flayer");
    /////
    insertCharCat("i", "minor demons");
    insertMonster("i", "Manes.png", "manes");
    insertMonster("i", "Homunculus.png", "homunculus");
    insertMonster("i", "Imp.png", "imp");
    insertMonster("i", "Lemure.png", "lemure");
    insertMonster("i", "Quasit.png", "quasit");
    insertMonster("i", "Tengu.png", "tengu");
    /////
    insertCharCat("j", "jellies");
    insertMonster("j", "Blue jelly.png", "blue jelly");
    insertMonster("j", "Spotted jelly.png", "spotted jelly");
    insertMonster("j", "Ochre jelly.png", "ochre jelly");
    /////
    insertCharCat("k", "kobolds");
    insertMonster("k", "Kobold.png", "kobold");
    insertMonster("k", "Large kobold.png", "large kobold");
    insertMonster("k", "Kobold lord.png", "kobold lord");
    insertMonster("k", "Kobold shaman.png", "kobold shaman");
    /////
    insertCharCat("l", "leprechauns");
    insertMonster("l", "Leprechaun.png", "leprechaun");
    /////
    insertCharCat("m", "mimics");
    insertMonster("m", "Small mimic.png", "small mimic");
    insertMonster("m", "Large mimic.png", "large mimic");
    insertMonster("m", "Giant mimic.png", "giant mimic");
    /////
    insertCharCat("n", "nymphs");
    insertMonster("n", "Wood nymph.png", "wood nymph");
    insertMonster("n", "Water nymph.png", "water nymph");
    insertMonster("n", "Mountain nymph.png", "mountain nymph");
    /////
    insertCharCat("o", "orcs");
    insertMonster("o", "Goblin.png", "goblin");
    insertMonster("o", "Hobgoblin.png", "hobgoblin");
    insertMonster("o", "Orc.png", "orc");
    insertMonster("o", "Hill orc.png", "hill orc");
    insertMonster("o", "Mordor orc.png", "Mordor orc");
    insertMonster("o", "Uruk - hai.png", "Uruk - hai");
    insertMonster("o", "Orc shaman.png", "orc shaman");
    insertMonster("o", "Orc - captain.png", "orc - captain");
    /////
    insertCharCat("p", "piercers");
    insertMonster("p", "Rock piercer.png", "rock piercer");
    insertMonster("p", "Iron piercer.png", "iron piercer");
    insertMonster("p", "Glass piercer.png", "glass piercer");
    /////
    insertCharCat("q", "quadrupeds");
    insertMonster("q", "Rothe.png", "rothe");
    insertMonster("q", "Mumak.png", "mumak");
    insertMonster("q", "Leocrotta.png", "leocrotta");
    insertMonster("q", "Wumpus.png", "wumpus");
    insertMonster("q", "Titanothere.png", "titanothere");
    insertMonster("q", "Baluchitherium.png", "baluchitherium");
    insertMonster("q", "Mastodon.png", "mastodon");
    /////
    insertCharCat("r", "rodents");
    insertMonster("r", "Sewer rat.png", "sewer rat");
    insertMonster("r", "Giant rat.png", "giant rat");
    insertMonster("r", "Rabid rat.png", "rabid rat");
    insertMonster("r", "Wererat were.png", "wererat");
    insertMonster("r", "Rock mole.png", "rock mole");
    insertMonster("r", "Woodchuck.png", "woodchuck");
    /////
    insertCharCat("s", "spiders or centipedes");
    insertMonster("s", "Cave spider.png", "cave spider");
    insertMonster("s", "Centipede.png", "centipede");
    insertMonster("s", "Giant spider.png", "giant spider");
    insertMonster("s", "Scorpion.png", "scorpion");
    /////
    insertCharCat("t", "trappers or lurkers above");
    insertMonster("t", "Lurker above.png", "lurker above");
    insertMonster("t", "Trapper.png", "trapper");
    /////
    insertCharCat("u", "horses and unicorns");
    insertMonster("u", "White unicorn.png", "white unicorn");
    insertMonster("u", "Gray unicorn.png", "gray unicorn");
    insertMonster("u", "Black unicorn.png", "black unicorn");
    insertMonster("u", "Pony.png", "pony");
    insertMonster("u", "Horse.png", "horse");
    insertMonster("u", "Warhorse.png", "warhorse");
    /////
    insertCharCat("v", "vortices");
    insertMonster("v", "Fog cloud.png", "fog cloud");
    insertMonster("v", "Dust vortex.png", "dust vortex");
    insertMonster("v", "Ice vortex.png", "ice vortex");
    insertMonster("v", "Energy vortex.png", "energy vortex");
    insertMonster("v", "Steam vortex.png", "steam vortex");
    insertMonster("v", "Fire vortex.png", "fire vortex");
    /////
    insertCharCat("w", "worms");
    insertMonster("w", "Baby long worm.png", "baby long worm");
    insertMonster("w", "Baby purple worm.png", "baby purple worm");
    insertMonster("w", "Long worm.png", "long worm");
    insertMonster("w", "Purple worm.png", "purple worm");
    /////
    insertCharCat("x", "mythical / fantastic insects");
    insertMonster("x", "Grid bug.png", "grid bug");
    insertMonster("x", "Xan.png", "xan");
    /////
    insertCharCat("y", "lights");
    insertMonster("y", "Yellow light.png", "yellow light");
    insertMonster("y", "Black light.png", "black light");
    /////
    insertCharCat("z", "zruties");
    insertMonster("z", "Zruty.png", "zruty");
    /////
    insertCharCat("A", "angelic beings");
    insertMonster("A", "Couatl.png", "couatl");
    insertMonster("A", "Aleax.png", "Aleax");
    insertMonster("A", "Angel.png", "Angel");
    insertMonster("A", "Ki - rin.png", "ki - rin");
    insertMonster("A", "Archon.png", "Archon");
    /////
    insertCharCat("B", "bats and birds");
    insertMonster("B", "Bat.png", "bat");
    insertMonster("B", "Giant bat.png", "giant bat");
    insertMonster("B", "Raven.png", "raven");
    insertMonster("B", "Vampire bat.png", "vampire bat");
    /////
    insertCharCat("C", "centaurs");
    insertMonster("C", "Plains centaur.png", "plains centaur");
    insertMonster("C", "Forest centaur.png", "forest centaur");
    insertMonster("C", "Mountain centaur.png", "mountain centaur");
    /////
    insertCharCat("D", "dragons");
    insertMonster("D", "Baby gray dragon.png", "baby gray dragon");
    insertMonster("D", "Baby silver dragon.png", "baby silver dragon");
    insertMonster("D", "Baby red dragon.png", "baby red dragon");
    insertMonster("D", "Baby white dragon.png", "baby white dragon");
    insertMonster("D", "Baby orange dragon.png", "baby orange dragon");
    insertMonster("D", "Baby black dragon.png", "baby black dragon");
    insertMonster("D", "Baby blue dragon.png", "baby blue dragon");
    insertMonster("D", "Baby green dragon.png", "baby green dragon");
    insertMonster("D", "Baby yellow dragon.png", "baby yellow dragon");
    insertMonster("D", "Gray dragon.png", "gray dragon");
    insertMonster("D", "Silver dragon.png", "silver dragon");
    insertMonster("D", "Red dragon.png", "red dragon");
    insertMonster("D", "White dragon.png", "white dragon");
    insertMonster("D", "Orange dragon.png", "orange dragon");
    insertMonster("D", "Black dragon.png", "black dragon");
    insertMonster("D", "Blue dragon.png", "blue dragon");
    insertMonster("D", "Green dragon.png", "green dragon");
    insertMonster("D", "Yellow dragon.png", "yellow dragon");
    /////
    insertCharCat("E", "elementals and stalkers");
    insertMonster("E", "Stalker.png", "stalker");
    insertMonster("E", "Air elemental.png", "air elemental");
    insertMonster("E", "Fire elemental.png", "fire elemental");
    insertMonster("E", "Earth elemental.png", "earth elemental");
    insertMonster("E", "Water elemental.png", "water elemental");
    /////
    insertCharCat("F", "fungi and molds");
    insertMonster("F", "Lichen.png", "lichen");
    insertMonster("F", "Brown mold.png", "brown mold");
    insertMonster("F", "Yellow mold.png", "yellow mold");
    insertMonster("F", "Green mold.png", "green mold");
    insertMonster("F", "Red mold.png", "red mold");
    insertMonster("F", "Shrieker.png", "shrieker");
    insertMonster("F", "Violet fungus.png", "violet fungus");
    /////
    insertCharCat("G", "gnomes");
    insertMonster("G", "Gnome.png", "gnome");
    insertMonster("G", "Gnome lord.png", "gnome lord");
    insertMonster("G", "Gnomish wizard.png", "gnomish wizard");
    insertMonster("G", "Gnome king.png", "gnome king");
    /////
    insertCharCat("H", "large humanoids");
    insertMonster("H", "Giant.png", "giant");
    insertMonster("H", "Stone giant.png", "stone giant");
    insertMonster("H", "Hill giant.png", "hill giant");
    insertMonster("H", "Fire giant.png", "fire giant");
    insertMonster("H", "Frost giant.png", "frost giant");
    insertMonster("H", "Storm giant.png", "storm giant");
    insertMonster("H", "Ettin.png", "ettin");
    insertMonster("H", "Titan.png", "titan");
    insertMonster("H", "Minotaur.png", "minotaur");
    /////
    insertCharCat("I", "");
    /////
    insertCharCat("J", "jabberwocks");
    insertMonster("J", "Jabberwock.png", "jabberwock");
    /////
    insertCharCat("K", "Keystone Kops");
    insertMonster("K", "Keystone Kop.png", "Keystone Kop");
    insertMonster("K", "Kop Sergeant.png", "Kop Sergeant");
    insertMonster("K", "Kop Lieutenant.png", "Kop Lieutenant");
    insertMonster("K", "Kop Kaptain.png", "Kop Kaptain");
    /////
    insertCharCat("L", "liches");
    insertMonster("L", "Lich.png", "lich");
    insertMonster("L", "Demilich.png", "demilich");
    insertMonster("L", "Master lich.png", "master lich");
    insertMonster("L", "Arch - lich.png", "arch - lich");
    /////
    insertCharCat("M", "mummies");
    insertMonster("M", "Kobold mummy.png", "kobold mummy");
    insertMonster("M", "Gnome mummy.png", "gnome mummy");
    insertMonster("M", "Orc mummy.png", "orc mummy");
    insertMonster("M", "Dwarf mummy.png", "dwarf mummy");
    insertMonster("M", "Elf mummy.png", "elf mummy");
    insertMonster("M", "Human mummy.png", "human mummy");
    insertMonster("M", "Ettin mummy.png", "ettin mummy");
    insertMonster("M", "Giant mummy.png", "giant mummy");
    /////
    insertCharCat("N", "nagas");
    insertMonster("N", "Red naga hatchling.png", "red naga hatchling");
    insertMonster("N", "Black naga hatchling.png", "black naga hatchling");
    insertMonster("N", "Golden naga hatchling.png", "golden naga hatchling");
    insertMonster("N", "Guardian naga hatchling.png", "guardian naga hatchling");
    insertMonster("N", "Red naga.png", "red naga");
    insertMonster("N", "Black naga.png", "black naga");
    insertMonster("N", "Golden naga.png", "golden naga");
    insertMonster("N", "Guardian naga.png", "guardian naga");
    /////
    insertCharCat("O", "ogres");
    insertMonster("O", "Ogre.png", "ogre");
    insertMonster("O", "Ogre lord.png", "ogre lord");
    insertMonster("O", "Ogre king.png", "ogre king");
    /////
    insertCharCat("P", "puddings and other amoeboids");
    insertMonster("P", "Gray ooze.png", "gray ooze");
    insertMonster("P", "Brown pudding.png", "brown pudding");
    insertMonster("P", "Black pudding.png", "black pudding");
    insertMonster("P", "Green slime.png", "green slime");
    /////
    insertCharCat("Q", "quantum mechanics");
    insertMonster("Q", "Quantum mechanic.png", "quantum mechanic");
    /////
    insertCharCat("R", "rust monsters and disenchanters");
    insertMonster("R", "Rust monster.png", "rust monster");
    insertMonster("R", "Disenchanter.png", "disenchanter");
    /////
    insertCharCat("S", "snakes");
    insertMonster("S", "Garter snake.png", "garter snake");
    insertMonster("S", "Snake.png", "snake");
    insertMonster("S", "Water moccasin.png", "water moccasin");
    insertMonster("S", "Pit viper.png", "pit viper");
    insertMonster("S", "Python.png", "python");
    insertMonster("S", "Cobra.png", "cobra");
    /////
    insertCharCat("T", "trolls");
    insertMonster("T", "Troll.png", "troll");
    insertMonster("T", "Ice troll.png", "ice troll");
    insertMonster("T", "Rock troll.png", "rock troll");
    insertMonster("T", "Water troll.png", "water troll");
    insertMonster("T", "Olog - hai.png", "Olog - hai");
    /////
    insertCharCat("U", "umber hulks");
    insertMonster("U", "Umber hulk.png", "umber hulk");
    /////
    insertCharCat("V", "vampires");
    insertMonster("V", "Vampire.png", "vampire");
    insertMonster("V", "Vampire lord.png", "vampire lord");
    insertMonster("V", "Vlad the Impaler.png", "Vlad the Impaler");
    /////
    insertCharCat("W", "wraiths");
    insertMonster("W", "Barrow wight.png", "barrow wight");
    insertMonster("W", "Wraith.png", "wraith");
    insertMonster("W", "Nazgul.png", "Nazgul");
    /////
    insertCharCat("X", "xorn");
    insertMonster("X", "Xorn.png", "xorn");
    /////
    insertCharCat("Y", "apelike creatures");
    insertMonster("Y", "Monkey.png", "monkey");
    insertMonster("Y", "Ape.png", "ape");
    insertMonster("Y", "Owlbear.png", "owlbear");
    insertMonster("Y", "Yeti.png", "yeti");
    insertMonster("Y", "Carnivorous ape.png", "carnivorous ape");
    insertMonster("Y", "Sasquatch.png", "sasquatch");
    /////
    insertCharCat("Z", "zombies");
    insertMonster("Z", "Kobold zombie.png", "kobold zombie");
    insertMonster("Z", "Gnome zombie.png", "gnome zombie");
    insertMonster("Z", "Orc zombie.png", "orc zombie");
    insertMonster("Z", "Dwarf zombie.png", "dwarf zombie");
    insertMonster("Z", "Elf zombie.png", "elf zombie");
    insertMonster("Z", "Human zombie.png", "human zombie");
    insertMonster("Z", "Ettin zombie.png", "ettin zombie");
    insertMonster("Z", "Giant zombie.png", "giant zombie");
    insertMonster("Z", "Ghoul.png", "ghoul");
    insertMonster("Z", "Skeleton.png", "skeleton");
    /////
    insertCharCat("'", "golems");
    insertMonster("'", "Straw golem.png", "straw golem");
    insertMonster("'", "Paper golem.png", "paper golem");
    insertMonster("'", "Rope golem.png", "rope golem");
    insertMonster("'", "Gold golem.png", "gold golem");
    insertMonster("'", "Leather golem.png", "leather golem");
    insertMonster("'", "Wood golem.png", "wood golem");
    insertMonster("'", "Flesh golem.png", "flesh golem");
    insertMonster("'", "Clay golem.png", "clay golem");
    insertMonster("'", "Stone golem.png", "stone golem");
    insertMonster("'", "Glass golem.png", "glass golem");
    insertMonster("'", "Iron golem.png", "iron golem");
    /////
    insertCharCat("@", "humans and elves");
    insertMonster("@", "Human.png", "human(monster)");
    insertMonster("@", "Wererat.png", "wererat");
    insertMonster("@", "Werejackal.png", "werejackal");
    insertMonster("@", "Werewolf.png", "werewolf");
    insertMonster("@", "Elf.png", "elf");
    insertMonster("@", "Woodland - elf.png", "Woodland - elf");
    insertMonster("@", "Green - elf.png", "Green - elf");
    insertMonster("@", "Grey - elf.png", "Grey - elf");
    insertMonster("@", "Elf - lord.png", "elf - lord");
    insertMonster("@", "Elvenking.png", "Elvenking");
    insertMonster("@", "Doppelganger.png", "doppelganger");
    insertMonster("@", "Nurse.png", "nurse");
    insertMonster("@", "Shopkeeper.png", "shopkeeper");
    insertMonster("@", "Guard.png", "guard");
    insertMonster("@", "Prisoner.png", "prisoner");
    insertMonster("@", "Oracle.png", "Oracle");
    insertMonster("@", "Aligned priest.png", "aligned priest");
    insertMonster("@", "High priest.png", "high priest");
    insertMonster("@", "Soldier.png", "soldier");
    insertMonster("@", "Sergeant.png", "sergeant");
    insertMonster("@", "Lieutenant.png", "lieutenant");
    insertMonster("@", "Captain.png", "captain");
    insertMonster("@", "Watchman.png", "watchman");
    insertMonster("@", "Watch captain.png", "watch captain");
    insertMonster("@", "Medusa.png", "Medusa");
    insertMonster("@", "Wizard of Yendor.png", "Wizard of Yendor");
    insertMonster("@", "Croesus.png", "Croesus");
    /////
    insertCharCat(" ", "ghosts and shades");
    insertMonster(" ", "Ghost.png", "ghost");
    insertMonster(" ", "Shade.png", "shade");
    /////
    insertCharCat("&", "major demons");
    insertMonster("&", "Water demon.png", "water demon");
    insertMonster("&", "Horned devil.png", "horned devil");
    insertMonster("&", "Succubus.png", "succubus");
    insertMonster("&", "Incubus.png", "incubus");
    insertMonster("&", "Erinys.png", "erinys");
    insertMonster("&", "Barbed devil.png", "barbed devil");
    insertMonster("&", "Marilith.png", "marilith");
    insertMonster("&", "Vrock.png", "vrock");
    insertMonster("&", "Hezrou.png", "hezrou");
    insertMonster("&", "Bone devil.png", "bone devil");
    insertMonster("&", "Ice devil.png", "ice devil");
    insertMonster("&", "Nalfeshnee.png", "nalfeshnee");
    insertMonster("&", "Pit fiend.png", "pit fiend");
    insertMonster("&", "Balrog.png", "balrog");
    insertMonster("&", "Juiblex.png", "Juiblex");
    insertMonster("&", "Yeenoghu.png", "Yeenoghu");
    insertMonster("&", "Orcus.png", "Orcus");
    insertMonster("&", "Geryon.png", "Geryon");
    insertMonster("&", "Dispater.png", "Dispater");
    insertMonster("&", "Baalzebub.png", "Baalzebub");
    insertMonster("&", "Asmodeus.png", "Asmodeus");
    insertMonster("&", "Demogorgon.png", "Demogorgon");
    insertMonster("&", "Death.png", "Death");
    insertMonster("&", "Pestilence.png", "Pestilence");
    insertMonster("&", "Famine.png", "Famine");
    insertMonster("&", "Mail daemon.png", "mail daemon");
    insertMonster("&", "Djinni.png", "djinni");
    insertMonster("&", "Sandestin.png", "sandestin");
    /////
    insertCharCat(";", "sea monsters");
    insertMonster(";", "Jellyfish.png", "jellyfish");
    insertMonster(";", "Piranha.png", "piranha");
    insertMonster(";", "Shark.png", "shark");
    insertMonster(";", "Giant eel.png", "giant eel");
    insertMonster(";", "Electric eel.png", "electric eel");
    insertMonster(";", "Kraken.png", "kraken");
    /////
    insertCharCat(":", "lizards");
    insertMonster(":", "Newt.png", "newt");
    insertMonster(":", "Gecko.png", "gecko");
    insertMonster(":", "Iguana.png", "iguana");
    insertMonster(":", "Baby crocodile.png", "baby crocodile");
    insertMonster(":", "Lizard.png", "lizard");
    insertMonster(":", "Chameleon.png", "chameleon");
    insertMonster(":", "Crocodile.png", "crocodile");
    insertMonster(":", "Salamander.png", "salamander");
    /////
    insertCharCat("@", "player monsters");
    insertMonster("@", "Archeologist.png", "archeologist");
    insertMonster("@", "Barbarian.png", "barbarian");
    insertMonster("@", "Caveman.png", "caveman");
    insertMonster("@", "Cavewoman.png", "cavewoman");
    insertMonster("@", "Healer.png", "healer");
    insertMonster("@", "Knight.png", "knight");
    insertMonster("@", "Monk.png", "monk");
    insertMonster("@", "Priest.png", "priest");
    insertMonster("@", "Priestess.png", "priestess");
    insertMonster("@", "Ranger.png", "ranger");
    insertMonster("@", "Rogue.png", "rogue");
    insertMonster("@", "Samurai.png", "samurai");
    insertMonster("@", "Tourist.png", "tourist");
    insertMonster("@", "Valkyrie.png", "valkyrie");
    insertMonster("@", "Wizard.png", "wizard");
    /////
    insertCharCat("@", "Quest leaders");
    insertMonster("@", "Lord Carnarvon.png", "Lord Carnarvon");
    insertMonster("@", "Pelias.png", "Pelias");
    insertMonster("@", "Shaman Karnov.png", "Shaman Karnov");
    insertMonster("@", "Hippocrates.png", "Hippocrates");
    insertMonster("@", "King Arthur.png", "King Arthur");
    insertMonster("@", "Grand Master.png", "Grand Master");
    insertMonster("@", "Arch Priest.png", "Arch Priest");
    insertMonster("@", "Orion.png", "Orion");
    insertMonster("@", "Master of Thieves.png", "Master of Thieves");
    insertMonster("@", "Lord Sato.png", "Lord Sato");
    insertMonster("@", "Twoflower.png", "Twoflower");
    insertMonster("@", "Norn.png", "Norn");
    insertMonster("@", "Neferet the Green.png", "Neferet the Green");
    /////
    insertCharCat("@", "Quest nemeses");
    insertMonster("&", "Minion of Huhetotl.png", "Minion of Huhetotl");
    insertMonster("@", "Thoth Amon.png", "Thoth Amon");
    insertMonster("D", "Chromatic Dragon.png", "Chromatic Dragon");
    insertMonster("H", "Cyclops.png", "Cyclops");
    insertMonster("D", "Ixoth.png", "Ixoth");
    insertMonster("@", "Master Kaen.png", "Master Kaen");
    insertMonster("&", "Nalzok.png", "Nalzok");
    insertMonster("s", "Scorpius.png", "Scorpius");
    insertMonster("@", "Master Assassin.png", "Master Assassin");
    insertMonster("@", "Ashikaga Takauji.png", "Ashikaga Takauji");
    insertMonster("H", "Lord Surtur.png", "Lord Surtur");
    insertMonster("@", "Dark One.png", "Dark One");
    /////
    insertCharCat("@", "Quest guardians");
    insertMonster("@", "Student.png", "student");
    insertMonster("@", "Chieftain.png", "chieftain");
    insertMonster("@", "Neanderthal.png", "neanderthal");
    insertMonster("@", "Attendant.png", "attendant");
    insertMonster("@", "Page.png", "page");
    insertMonster("@", "Abbot.png", "abbot");
    insertMonster("@", "Acolyte.png", "acolyte");
    insertMonster("@", "Hunter.png", "hunter");
    insertMonster("@", "Thug.png", "thug");
    insertMonster("@", "Ninja.png", "ninja");
    insertMonster("@", "Roshi.png", "roshi");
    insertMonster("@", "Guide.png", "guide");
    insertMonster("@", "Warrior.png", "warrior");
    insertMonster("@", "Apprentice.png", "apprentice");
}


////////////////////////////////////////////////////////////////////////////////
// monsters ////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void ResourceData::BuildMonsterList(std::vector<cmonster>& ml)
{
    buildMonsterList1(ml);
    buildMonsterList2(ml);
    buildMonsterList3(ml);
    buildMonsterList4(ml);
    buildMonsterList5(ml);
    buildMonsterList6(ml);
}

//--monster--
//     namemale                   - string
//     namefemale                 - string 
//     nameneutral                - string  
//     monster symbol             - single define
//
//--level--
//     base_level;                - int
//     move_rate_speed;           - int
//     base_ac_armor_class;       - int
//     base_mr_magic_resistance;  - int
//     alignment;                 - int
//
// genome - multi int/enum
//
//--attack-- vector
//     attk_type                  - enum
//     damage_type                - enum
//     numdice                    - int
//     numsides                   - int
//
//--size--
//    weight;                     - int
//    nut_val;                    - int
//    sound;                      - enum
//    size;                       - int
//
// magic resistance1              - int/multi
// magic resistance2              - int/multi
// flag1
// flag2
// flag3
// dificulty                      - int
// color                          - enum
// defmon                         - string



void ResourceData::buildMonsterList1(std::vector<cmonster>& ml)
{
    addMonster(ml,"", "", "giant ant", S_ANT, LVL(2, 18, 3, 0, 0), (G_GENO | G_SGROUP | 3), ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(10, 10, MS_SILENT, MZ_TINY), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE, 0, 4, CLR_BROWN, "GIANT_ANT");
    addMonster(ml,"", "", "killer bee", S_ANT, LVL(1, 18, -1, 0, 0), (G_GENO | G_LGROUP | 2), ATTK(AT_STNG, AD_DRST, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1, 5, MS_BUZZ, MZ_TINY), MR_POISON, MR_POISON, M1_ANIMAL | M1_FLY | M1_NOHANDS | M1_POIS, M2_HOSTILE | M2_FEMALE, 0, 5, CLR_YELLOW, "KILLER_BEE");
    addMonster(ml,"", "", "soldier ant", S_ANT, LVL(3, 18, 3, 0, 0), (G_GENO | G_SGROUP | 2), ATTK(AT_BITE, AD_PHYS, 2, 4), ATTK(AT_STNG, AD_DRST, 3, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(20, 5, MS_SILENT, MZ_TINY), MR_POISON, MR_POISON, M1_ANIMAL | M1_NOHANDS | M1_OVIPAROUS | M1_POIS | M1_CARNIVORE, M2_HOSTILE, 0, 6, CLR_BLUE, "SOLDIER_ANT");
    addMonster(ml,"", "", "fire ant", S_ANT, LVL(3, 18, 3, 10, 0), (G_GENO | G_SGROUP | 1), ATTK(AT_BITE, AD_PHYS, 2, 4), ATTK(AT_BITE, AD_FIRE, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(30, 10, MS_SILENT, MZ_TINY), MR_FIRE, MR_FIRE, M1_ANIMAL | M1_NOHANDS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 6, CLR_RED, "FIRE_ANT");
    addMonster(ml,"", "", "giant beetle", S_ANT, LVL(5, 6, 4, 0, 0), (G_GENO | 3), ATTK(AT_BITE, AD_PHYS, 3, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(200, 50, MS_SILENT, MZ_LARGE), MR_POISON, MR_POISON, M1_ANIMAL | M1_NOHANDS | M1_POIS | M1_CARNIVORE, M2_HOSTILE, 0, 6, CLR_BLACK, "GIANT_BEETLE");
    addMonster(ml,"", "", "queen bee", S_ANT, LVL(9, 24, -4, 0, 0), (G_GENO | G_NOGEN), ATTK(AT_STNG, AD_DRST, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1, 5, MS_BUZZ, MZ_TINY), MR_POISON, MR_POISON, M1_ANIMAL | M1_FLY | M1_NOHANDS | M1_OVIPAROUS | M1_POIS, M2_HOSTILE | M2_FEMALE | M2_PRINCE, 0, 12, HI_LORD, "QUEEN_BEE");
    addMonster(ml,"", "", "acid blob", S_BLOB, LVL(1, 3, 8, 0, 0), (G_GENO | 2), ATTK(AT_NONE, AD_ACID, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(30, 10, MS_SILENT, MZ_TINY), MR_SLEEP | MR_POISON | MR_ACID | MR_STONE, MR_ACID | MR_STONE, M1_BREATHLESS | M1_AMORPHOUS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_ACID, M2_WANDER | M2_NEUTER, 0, 2, CLR_GREEN, "ACID_BLOB");
    addMonster(ml,"", "", "quivering blob", S_BLOB, LVL(5, 1, 8, 0, 0), (G_GENO | 2), ATTK(AT_TUCH, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(200, 100, MS_SILENT, MZ_SMALL), MR_SLEEP | MR_POISON, MR_POISON, M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS, M2_WANDER | M2_HOSTILE | M2_NEUTER, 0, 6, CLR_WHITE, "QUIVERING_BLOB");
    addMonster(ml,"", "", "gelatinous cube", S_BLOB, LVL(6, 6, 8, 0, 0), (G_GENO | 2), ATTK(AT_TUCH, AD_PLYS, 2, 4), ATTK(AT_NONE, AD_PLYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(600, 150, MS_SILENT, MZ_LARGE), MR_FIRE | MR_COLD | MR_ELEC | MR_SLEEP | MR_POISON | MR_ACID | MR_STONE, MR_FIRE | MR_COLD | MR_ELEC | MR_SLEEP, M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_OMNIVORE | M1_ACID, M2_WANDER | M2_HOSTILE | M2_NEUTER, 0, 8, CLR_CYAN, "GELATINOUS_CUBE");
    addMonster(ml,"", "", "chickatrice", S_COCKATRICE, LVL(4, 4, 8, 30, 0), (G_GENO | G_SGROUP | 1), ATTK(AT_BITE, AD_PHYS, 1, 2), ATTK(AT_TUCH, AD_STON, 0, 0), ATTK(AT_NONE, AD_STON, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(10, 10, MS_HISS, MZ_TINY), MR_POISON | MR_STONE, MR_POISON | MR_STONE, M1_ANIMAL | M1_NOHANDS | M1_OMNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 7, CLR_BROWN, "CHICKATRICE");
    addMonster(ml,"", "", "cockatrice", S_COCKATRICE, LVL(5, 6, 6, 30, 0), (G_GENO | 5), ATTK(AT_BITE, AD_PHYS, 1, 3), ATTK(AT_TUCH, AD_STON, 0, 0), ATTK(AT_NONE, AD_STON, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(30, 30, MS_HISS, MZ_SMALL), MR_POISON | MR_STONE, MR_POISON | MR_STONE, M1_ANIMAL | M1_NOHANDS | M1_OMNIVORE | M1_OVIPAROUS, M2_HOSTILE, M3_INFRAVISIBLE, 8, CLR_YELLOW, "COCKATRICE");
    addMonster(ml,"", "", "pyrolisk", S_COCKATRICE, LVL(6, 6, 6, 30, 0), (G_GENO | 1), ATTK(AT_GAZE, AD_FIRE, 2, 6), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(30, 30, MS_HISS, MZ_SMALL), MR_POISON | MR_FIRE, MR_POISON | MR_FIRE, M1_ANIMAL | M1_NOHANDS | M1_OMNIVORE | M1_OVIPAROUS, M2_HOSTILE, M3_INFRAVISIBLE, 8, CLR_RED, "PYROLISK");
    addMonster(ml,"", "", "jackal", S_DOG, LVL(0, 12, 7, 0, 0), (G_GENO | G_SGROUP | 3), ATTK(AT_BITE, AD_PHYS, 1, 2), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(300, 250, MS_BARK, MZ_SMALL), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 1, CLR_BROWN, "JACKAL");
    addMonster(ml,"", "", "fox", S_DOG, LVL(0, 15, 7, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(300, 250, MS_BARK, MZ_SMALL), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 1, CLR_RED, "FOX");
    addMonster(ml,"", "", "coyote", S_DOG, LVL(1, 12, 7, 0, 0), (G_GENO | G_SGROUP | 1), ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(300, 250, MS_BARK, MZ_SMALL), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 2, CLR_BROWN, "COYOTE");
    addMonster(ml,"", "", "werejackal", S_DOG, LVL(2, 12, 7, 10, -7), (G_NOGEN | G_NOCORPSE), ATTK(AT_BITE, AD_WERE, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(300, 250, MS_BARK, MZ_SMALL), MR_POISON, 0, M1_NOHANDS | M1_POIS | M1_REGEN | M1_CARNIVORE, M2_NOPOLY | M2_WERE | M2_HOSTILE, M3_INFRAVISIBLE, 4, CLR_BROWN, "WEREJACKAL");
    addMonster(ml,"", "", "little dog", S_DOG, LVL(2, 18, 6, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(150, 150, MS_BARK, MZ_SMALL), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_DOMESTIC, M3_INFRAVISIBLE, 3, HI_DOMESTIC, "LITTLE_DOG");
    addMonster(ml,"", "", "dingo", S_DOG, LVL(4, 16, 5, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(400, 200, MS_BARK, MZ_MEDIUM), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 5, CLR_YELLOW, "DINGO");
    addMonster(ml,"", "", "dog", S_DOG, LVL(4, 16, 5, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(400, 200, MS_BARK, MZ_MEDIUM), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_DOMESTIC, M3_INFRAVISIBLE, 5, HI_DOMESTIC, "DOG");
    addMonster(ml,"", "", "large dog", S_DOG, LVL(6, 15, 4, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(800, 250, MS_BARK, MZ_MEDIUM), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_STRONG | M2_DOMESTIC, M3_INFRAVISIBLE, 7, HI_DOMESTIC, "LARGE_DOG");
    addMonster(ml,"", "", "wolf", S_DOG, LVL(5, 12, 4, 0, 0), (G_GENO | G_SGROUP | 2), ATTK(AT_BITE, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(500, 250, MS_BARK, MZ_MEDIUM), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 6, CLR_GRAY, "WOLF");
    addMonster(ml,"", "", "werewolf", S_DOG, LVL(5, 12, 4, 20, -7), (G_NOGEN | G_NOCORPSE), ATTK(AT_BITE, AD_WERE, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(500, 250, MS_BARK, MZ_MEDIUM), MR_POISON, 0, M1_NOHANDS | M1_POIS | M1_REGEN | M1_CARNIVORE, M2_NOPOLY | M2_WERE | M2_HOSTILE, M3_INFRAVISIBLE, 7, CLR_GRAY, "WEREWOLF");
    addMonster(ml,"", "", "winter wolf cub", S_DOG, LVL(5, 12, 4, 0, -5), (G_NOHELL | G_GENO | G_SGROUP | 2), ATTK(AT_BITE, AD_PHYS, 1, 8), ATTK(AT_BREA, AD_COLD, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(250, 200, MS_BARK, MZ_SMALL), MR_COLD, MR_COLD, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, 0, 7, CLR_CYAN, "WINTER_WOLF_CUB");
    addMonster(ml,"", "", "warg", S_DOG, LVL(7, 12, 4, 0, -5), (G_GENO | G_SGROUP | 2), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(850, 350, MS_BARK, MZ_MEDIUM), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 8, CLR_BLACK, "WARG");
    addMonster(ml,"", "", "winter wolf", S_DOG, LVL(7, 12, 4, 20, 0), (G_NOHELL | G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_BREA, AD_COLD, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(700, 300, MS_BARK, MZ_LARGE), MR_COLD, MR_COLD, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG, 0, 9, CLR_CYAN, "WINTER_WOLF");
    addMonster(ml,"", "", "hell hound pup", S_DOG, LVL(7, 12, 4, 20, -5), (G_HELL | G_GENO | G_SGROUP | 1), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_BREA, AD_FIRE, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(200, 200, MS_BARK, MZ_SMALL), MR_FIRE, MR_FIRE, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 9, CLR_RED, "HELL_HOUND_PUP");
    addMonster(ml,"", "", "hell hound", S_DOG, LVL(12, 14, 2, 20, 0), (G_HELL | G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 3, 6), ATTK(AT_BREA, AD_FIRE, 3, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(600, 300, MS_BARK, MZ_MEDIUM), MR_FIRE, MR_FIRE, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG, M3_INFRAVISIBLE, 14, CLR_RED, "HELL_HOUND");
    addMonster(ml,"", "", "Cerberus", S_DOG, LVL(12, 10, 2, 20, -7), (G_NOGEN | G_UNIQ | G_HELL), ATTK(AT_BITE, AD_PHYS, 3, 6), ATTK(AT_BITE, AD_PHYS, 3, 6), ATTK(AT_BITE, AD_PHYS, 3, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1000, 350, MS_BARK, MZ_LARGE), MR_FIRE, MR_FIRE, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_NOPOLY | M2_HOSTILE | M2_STRONG | M2_PNAME | M2_MALE, M3_INFRAVISIBLE, 14, CLR_RED, "CERBERUS");
    addMonster(ml,"", "", "gas spore", S_EYE, LVL(1, 3, 10, 0, 0), (G_NOCORPSE | G_GENO | 1), ATTK(AT_BOOM, AD_PHYS, 4, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(10, 10, MS_SILENT, MZ_SMALL), 0, 0, M1_FLY | M1_BREATHLESS | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS, M2_HOSTILE | M2_NEUTER, 0, 2, CLR_GRAY, "GAS_SPORE");
    addMonster(ml,"", "", "floating eye", S_EYE, LVL(2, 1, 9, 10, 0), (G_GENO | 5), ATTK(AT_NONE, AD_PLYS, 0, 70), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(10, 10, MS_SILENT, MZ_SMALL), 0, 0, M1_FLY | M1_AMPHIBIOUS | M1_NOLIMBS | M1_NOHEAD | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, M3_INFRAVISIBLE, 3, CLR_BLUE, "FLOATING_EYE");
    addMonster(ml,"", "", "freezing sphere", S_EYE, LVL(6, 13, 4, 0, 0), (G_NOCORPSE | G_NOHELL | G_GENO | 2), ATTK(AT_EXPL, AD_COLD, 4, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(10, 10, MS_SILENT, MZ_SMALL), MR_COLD, MR_COLD, M1_FLY | M1_BREATHLESS | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, M3_INFRAVISIBLE, 9, CLR_WHITE, "FREEZING_SPHERE");
    addMonster(ml,"", "", "flaming sphere", S_EYE, LVL(6, 13, 4, 0, 0), (G_NOCORPSE | G_GENO | 2), ATTK(AT_EXPL, AD_FIRE, 4, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(10, 10, MS_SILENT, MZ_SMALL), MR_FIRE, MR_FIRE, M1_FLY | M1_BREATHLESS | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, M3_INFRAVISIBLE, 9, CLR_RED, "FLAMING_SPHERE");
    addMonster(ml,"", "", "shocking sphere", S_EYE, LVL(6, 13, 4, 0, 0), (G_NOCORPSE | G_GENO | 2), ATTK(AT_EXPL, AD_ELEC, 4, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(10, 10, MS_SILENT, MZ_SMALL), MR_ELEC, MR_ELEC, M1_FLY | M1_BREATHLESS | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, M3_INFRAVISIBLE, 10, HI_ZAP, "SHOCKING_SPHERE");
    //addMonster(ml,"", "", "beholder", S_EYE, LVL(6, 3, 4, 0, -10), (G_GENO | 2), ATTK(AT_GAZE, AD_SLOW, 0, 0), ATTK(AT_GAZE, AD_SLEE, 2, 25), ATTK(AT_GAZE, AD_DISN, 0, 0), ATTK(AT_GAZE, AD_STON, 0, 0), ATTK(AT_GAZE, AD_CNCL, 2, 4), ATTK(AT_BITE, AD_PHYS, 2, 4), SIZ(10, 10, MS_SILENT, MZ_SMALL), MR_COLD, 0, M1_FLY | M1_BREATHLESS | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS, M2_NOPOLY | M2_HOSTILE | M2_NEUTER, M3_INFRAVISIBLE, 13, CLR_BROWN, "BEHOLDER");
    addMonster(ml,"", "", "kitten", S_FELINE, LVL(2, 18, 6, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(150, 150, MS_MEW, MZ_SMALL), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_WANDER | M2_DOMESTIC, M3_INFRAVISIBLE | M3_INFRAVISION, 3, HI_DOMESTIC, "KITTEN");
    addMonster(ml,"", "", "housecat", S_FELINE, LVL(4, 16, 5, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(200, 200, MS_MEW, MZ_SMALL), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_DOMESTIC, M3_INFRAVISIBLE | M3_INFRAVISION, 5, HI_DOMESTIC, "HOUSECAT");
    addMonster(ml,"", "", "jaguar", S_FELINE, LVL(4, 15, 6, 0, 0), (G_GENO | 2), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_BITE, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(600, 300, MS_GROWL, MZ_LARGE), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE | M3_INFRAVISION, 6, CLR_BROWN, "JAGUAR");
    addMonster(ml,"", "", "lynx", S_FELINE, LVL(5, 15, 6, 0, 0), (G_GENO | 1), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_BITE, AD_PHYS, 1, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(600, 300, MS_GROWL, MZ_SMALL), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE | M3_INFRAVISION, 7, CLR_CYAN, "LYNX");
    addMonster(ml,"", "", "panther", S_FELINE, LVL(5, 15, 6, 0, 0), (G_GENO | 1), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_BITE, AD_PHYS, 1, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(600, 300, MS_GROWL, MZ_LARGE), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE | M3_INFRAVISION, 7, CLR_BLACK, "PANTHER");
    addMonster(ml,"", "", "large cat", S_FELINE, LVL(6, 15, 4, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(250, 250, MS_MEW, MZ_SMALL), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_STRONG | M2_DOMESTIC, M3_INFRAVISIBLE | M3_INFRAVISION, 7, HI_DOMESTIC, "LARGE_CAT");
    addMonster(ml,"", "", "tiger", S_FELINE, LVL(6, 12, 6, 0, 0), (G_GENO | 2), ATTK(AT_CLAW, AD_PHYS, 2, 4), ATTK(AT_CLAW, AD_PHYS, 2, 4), ATTK(AT_BITE, AD_PHYS, 1, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(600, 300, MS_GROWL, MZ_LARGE), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE | M3_INFRAVISION, 8, CLR_YELLOW, "TIGER");
    addMonster(ml,"", "", "displacer beast", S_FELINE, LVL(12, 12, -10, 0, -3), (G_GENO | 1), ATTK(AT_CLAW, AD_PHYS, 4, 4), ATTK(AT_CLAW, AD_PHYS, 4, 4), ATTK(AT_BITE, AD_PHYS, 2, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(750, 400, MS_GROWL, MZ_LARGE), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE | M2_NASTY, M3_INFRAVISIBLE | M3_INFRAVISION | M3_DISPLACES, 14, CLR_BLUE, "DISPLACER_BEAST");
    addMonster(ml,"", "", "gremlin", S_GREMLIN, LVL(5, 12, 2, 25, -9), (G_GENO | 2), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_CURS, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(100, 20, MS_LAUGH, MZ_SMALL), MR_POISON, MR_POISON, M1_SWIM | M1_HUMANOID | M1_POIS, M2_STALK, M3_INFRAVISIBLE, 8, CLR_GREEN, "GREMLIN");
    addMonster(ml,"", "", "gargoyle", S_GREMLIN, LVL(6, 10, -4, 0, -9), (G_GENO | 2), ATTK(AT_CLAW, AD_PHYS, 2, 6), ATTK(AT_CLAW, AD_PHYS, 2, 6), ATTK(AT_BITE, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1000, 200, MS_GRUNT, MZ_HUMAN), MR_STONE, MR_STONE, M1_HUMANOID | M1_THICK_HIDE | M1_BREATHLESS, M2_HOSTILE | M2_STRONG, 0, 8, CLR_BROWN, "GARGOYLE");
    addMonster(ml,"", "", "winged gargoyle", S_GREMLIN, LVL(9, 15, -2, 0, -12), (G_GENO | 1), ATTK(AT_CLAW, AD_PHYS, 3, 6), ATTK(AT_CLAW, AD_PHYS, 3, 6), ATTK(AT_BITE, AD_PHYS, 3, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1200, 300, MS_GRUNT, MZ_HUMAN), MR_STONE, MR_STONE, M1_FLY | M1_HUMANOID | M1_THICK_HIDE | M1_BREATHLESS | M1_OVIPAROUS, M2_LORD | M2_HOSTILE | M2_STRONG | M2_MAGIC, 0, 11, HI_LORD, "WINGED_GARGOYLE");
    addMonster(ml,"", "", "hobbit", S_HUMANOID, LVL(1, 9, 10, 0, 6), (G_GENO | 2), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(500, 200, MS_HUMANOID, MZ_SMALL), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 2, CLR_GREEN, "HOBBIT");
    addMonster(ml,"", "", "dwarf", S_HUMANOID, LVL(2, 6, 10, 10, 4), (G_GENO | 3), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(900, 300, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_TUNNEL | M1_NEEDPICK | M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_DWARF | M2_STRONG | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 4, CLR_RED, "DWARF");
    addMonster(ml,"", "", "bugbear", S_HUMANOID, LVL(3, 9, 5, 0, -6), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1250, 250, MS_GROWL, MZ_LARGE), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 5, CLR_BROWN, "BUGBEAR");
    addMonster(ml, "dwarf lord", "dwarf lady", "dwarf leader", S_HUMANOID, LVL(4, 6, 10, 10, 5), (G_GENO | 2), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(900, 300, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_TUNNEL | M1_NEEDPICK | M1_HUMANOID | M1_OMNIVORE, M2_DWARF | M2_STRONG | M2_LORD | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 6, CLR_BLUE, "DWARF_LEADER");
    addMonster(ml, "dwarf king", "dwarf queen", "dwarf ruler", S_HUMANOID, LVL(6, 6, 10, 20, 6), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(900, 300, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_TUNNEL | M1_NEEDPICK | M1_HUMANOID | M1_OMNIVORE, M2_DWARF | M2_STRONG | M2_PRINCE | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 8, HI_LORD, "DWARF_RULER");
    addMonster(ml,"", "", "mind flayer", S_HUMANOID, LVL(9, 12, 5, 90, -8), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 1, 4), ATTK(AT_TENT, AD_DRIN, 2, 1), ATTK(AT_TENT, AD_DRIN, 2, 1), ATTK(AT_TENT, AD_DRIN, 2, 1), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1450, 400, MS_HISS, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_FLY | M1_SEE_INVIS | M1_OMNIVORE, M2_HOSTILE | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 13, CLR_BRIGHT_MAGENTA, "MIND_FLAYER");
    addMonster(ml,"", "", "master mind flayer", S_HUMANOID, LVL(13, 12, 0, 90, -8), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_TENT, AD_DRIN, 2, 1), ATTK(AT_TENT, AD_DRIN, 2, 1), ATTK(AT_TENT, AD_DRIN, 2, 1), ATTK(AT_TENT, AD_DRIN, 2, 1), ATTK(AT_TENT, AD_DRIN, 2, 1), SIZ(1450, 400, MS_HISS, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_FLY | M1_SEE_INVIS | M1_OMNIVORE, M2_HOSTILE | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 19, CLR_BRIGHT_MAGENTA, "MASTER_MIND_FLAYER");
    addMonster(ml,"", "", "manes", S_IMP, LVL(1, 3, 7, 0, -7), (G_GENO | G_LGROUP | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(100, 100, MS_SILENT, MZ_SMALL), MR_SLEEP | MR_POISON, 0, M1_POIS, M2_HOSTILE | M2_STALK, M3_INFRAVISIBLE | M3_INFRAVISION, 3, CLR_RED, "MANES");
    addMonster(ml,"", "", "homunculus", S_IMP, LVL(2, 12, 6, 10, -7), (G_GENO | 2), ATTK(AT_BITE, AD_SLEE, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(60, 100, MS_SILENT, MZ_TINY), MR_SLEEP | MR_POISON, MR_SLEEP | MR_POISON, M1_FLY | M1_POIS, M2_STALK, M3_INFRAVISIBLE | M3_INFRAVISION, 3, CLR_GREEN, "HOMUNCULUS");
    addMonster(ml,"", "", "imp", S_IMP, LVL(3, 12, 2, 20, -7), (G_GENO | 1), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(20, 10, MS_CUSS, MZ_TINY), 0, 0, M1_REGEN, M2_WANDER | M2_STALK, M3_INFRAVISIBLE | M3_INFRAVISION, 4, CLR_RED, "IMP");
    addMonster(ml,"", "", "lemure", S_IMP, LVL(3, 3, 7, 0, -7), (G_HELL | G_GENO | G_LGROUP | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(150, 100, MS_SILENT, MZ_MEDIUM), MR_SLEEP | MR_POISON, MR_SLEEP, M1_POIS | M1_REGEN, M2_HOSTILE | M2_WANDER | M2_STALK | M2_NEUTER, M3_INFRAVISIBLE | M3_INFRAVISION, 5, CLR_BROWN, "LEMURE");
    addMonster(ml,"", "", "quasit", S_IMP, LVL(3, 15, 2, 20, -7), (G_GENO | 2), ATTK(AT_CLAW, AD_DRDX, 1, 2), ATTK(AT_CLAW, AD_DRDX, 1, 2), ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(200, 200, MS_SILENT, MZ_SMALL), MR_POISON, MR_POISON, M1_REGEN, M2_STALK, M3_INFRAVISIBLE | M3_INFRAVISION, 7, CLR_BLUE, "QUASIT");
    addMonster(ml,"", "", "tengu", S_IMP, LVL(6, 13, 5, 30, 7), (G_GENO | 3), ATTK(AT_BITE, AD_PHYS, 1, 7), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(300, 200, MS_SQAWK, MZ_SMALL), MR_POISON, MR_POISON, M1_TPORT | M1_TPORT_CNTRL, M2_STALK, M3_INFRAVISIBLE | M3_INFRAVISION, 7, CLR_CYAN, "TENGU");
    addMonster(ml,"", "", "blue jelly", S_JELLY, LVL(4, 0, 8, 10, 0), (G_GENO | 2), ATTK(AT_NONE, AD_COLD, 0, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(50, 20, MS_SILENT, MZ_MEDIUM), MR_COLD | MR_POISON, MR_COLD | MR_POISON, M1_BREATHLESS | M1_AMORPHOUS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, 0, 5, CLR_BLUE, "BLUE_JELLY");
    addMonster(ml,"", "", "spotted jelly", S_JELLY, LVL(5, 0, 8, 10, 0), (G_GENO | 1), ATTK(AT_NONE, AD_ACID, 0, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(50, 20, MS_SILENT, MZ_MEDIUM), MR_ACID | MR_STONE, MR_ACID | MR_STONE, M1_BREATHLESS | M1_AMORPHOUS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_ACID | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, 0, 6, CLR_GREEN, "SPOTTED_JELLY");
    addMonster(ml,"", "", "ochre jelly", S_JELLY, LVL(6, 3, 8, 20, 0), (G_GENO | 2), ATTK(AT_ENGL, AD_ACID, 3, 6), ATTK(AT_NONE, AD_ACID, 3, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(50, 20, MS_SILENT, MZ_MEDIUM), MR_ACID | MR_STONE, MR_ACID | MR_STONE, M1_BREATHLESS | M1_AMORPHOUS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_ACID | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, 0, 8, CLR_BROWN, "OCHRE_JELLY");
    addMonster(ml,"", "", "kobold", S_KOBOLD, LVL(0, 6, 10, 0, -2), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(400, 100, MS_ORC, MZ_SMALL), MR_POISON, 0, M1_HUMANOID | M1_POIS | M1_OMNIVORE, M2_HOSTILE | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 1, CLR_BROWN, "KOBOLD");
    addMonster(ml,"", "", "large kobold", S_KOBOLD, LVL(1, 6, 10, 0, -3), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(450, 150, MS_ORC, MZ_SMALL), MR_POISON, 0, M1_HUMANOID | M1_POIS | M1_OMNIVORE, M2_HOSTILE | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 2, CLR_RED, "LARGE_KOBOLD");
    addMonster(ml, "kobold lord", "kobold lady", "kobold leader", S_KOBOLD, LVL(2, 6, 10, 0, -4), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(500, 200, MS_ORC, MZ_SMALL), MR_POISON, 0, M1_HUMANOID | M1_POIS | M1_OMNIVORE, M2_HOSTILE | M2_LORD | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 3, HI_LORD, "KOBOLD_LEADER");
    addMonster(ml,"", "", "kobold shaman", S_KOBOLD, LVL(2, 6, 6, 10, -4), (G_GENO | 1), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(450, 150, MS_ORC, MZ_SMALL), MR_POISON, 0, M1_HUMANOID | M1_POIS | M1_OMNIVORE, M2_HOSTILE | M2_MAGIC, M3_INFRAVISIBLE | M3_INFRAVISION, 4, HI_ZAP, "KOBOLD_SHAMAN");
    addMonster(ml,"", "", "leprechaun", S_LEPRECHAUN, LVL(5, 15, 8, 20, 0), (G_GENO | 4), ATTK(AT_CLAW, AD_SGLD, 1, 2), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(60, 30, MS_LAUGH, MZ_TINY), 0, 0, M1_HUMANOID | M1_TPORT, M2_HOSTILE | M2_GREEDY, M3_INFRAVISIBLE, 4, CLR_GREEN, "LEPRECHAUN");
    addMonster(ml,"", "", "small mimic", S_MIMIC, LVL(7, 3, 7, 0, 0), (G_GENO | 2), ATTK(AT_CLAW, AD_PHYS, 3, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(300, 200, MS_SILENT, MZ_MEDIUM), MR_ACID, 0, M1_BREATHLESS | M1_AMORPHOUS | M1_HIDE | M1_ANIMAL | M1_NOEYES | M1_NOHEAD | M1_NOLIMBS | M1_THICK_HIDE | M1_CARNIVORE, M2_HOSTILE, 0, 8, CLR_BROWN, "SMALL_MIMIC");
    addMonster(ml,"", "", "large mimic", S_MIMIC, LVL(8, 3, 7, 10, 0), (G_GENO | 1), ATTK(AT_CLAW, AD_STCK, 3, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(600, 400, MS_SILENT, MZ_LARGE), MR_ACID, 0, M1_CLING | M1_BREATHLESS | M1_AMORPHOUS | M1_HIDE | M1_ANIMAL | M1_NOEYES | M1_NOHEAD | M1_NOLIMBS | M1_THICK_HIDE | M1_CARNIVORE, M2_HOSTILE | M2_STRONG, 0, 9, CLR_RED, "LARGE_MIMIC");
    addMonster(ml,"", "", "giant mimic", S_MIMIC, LVL(9, 3, 7, 20, 0), (G_GENO | 1), ATTK(AT_CLAW, AD_STCK, 3, 6), ATTK(AT_CLAW, AD_STCK, 3, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(800, 500, MS_SILENT, MZ_LARGE), MR_ACID, 0, M1_CLING | M1_BREATHLESS | M1_AMORPHOUS | M1_HIDE | M1_ANIMAL | M1_NOEYES | M1_NOHEAD | M1_NOLIMBS | M1_THICK_HIDE | M1_CARNIVORE, M2_HOSTILE | M2_STRONG, 0, 11, HI_LORD, "GIANT_MIMIC");
    addMonster(ml,"", "", "wood nymph", S_NYMPH, LVL(3, 12, 9, 20, 0), (G_GENO | 2), ATTK(AT_CLAW, AD_SITM, 0, 0), ATTK(AT_CLAW, AD_SEDU, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(600, 300, MS_SEDUCE, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_TPORT, M2_HOSTILE | M2_FEMALE | M2_COLLECT, M3_INFRAVISIBLE, 5, CLR_GREEN, "WOOD_NYMPH");
    addMonster(ml,"", "", "water nymph", S_NYMPH, LVL(3, 12, 9, 20, 0), (G_GENO | 2), ATTK(AT_CLAW, AD_SITM, 0, 0), ATTK(AT_CLAW, AD_SEDU, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(600, 300, MS_SEDUCE, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_TPORT | M1_SWIM, M2_HOSTILE | M2_FEMALE | M2_COLLECT, M3_INFRAVISIBLE, 5, CLR_BLUE, "WATER_NYMPH");
    addMonster(ml,"", "", "mountain nymph", S_NYMPH, LVL(3, 12, 9, 20, 0), (G_GENO | 2), ATTK(AT_CLAW, AD_SITM, 0, 0), ATTK(AT_CLAW, AD_SEDU, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(600, 300, MS_SEDUCE, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_TPORT, M2_HOSTILE | M2_FEMALE | M2_COLLECT, M3_INFRAVISIBLE, 5, CLR_BROWN, "MOUNTAIN_NYMPH");
    addMonster(ml,"", "", "goblin", S_ORC, LVL(0, 6, 10, 0, -3), (G_GENO | 2), ATTK(AT_WEAP, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(400, 100, MS_ORC, MZ_SMALL), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_ORC | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 1, CLR_GRAY, "GOBLIN");
    addMonster(ml,"", "", "hobgoblin", S_ORC, LVL(1, 9, 10, 0, -4), (G_GENO | 2), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1000, 200, MS_ORC, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_ORC | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 3, CLR_BROWN, "HOBGOBLIN");
    addMonster(ml,"", "", "orc", S_ORC, LVL(1, 9, 10, 0, -3), (G_GENO | G_NOGEN | G_LGROUP), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(850, 150, MS_ORC, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_ORC | M2_STRONG | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 3, CLR_RED, "ORC");
    addMonster(ml,"", "", "hill orc", S_ORC, LVL(2, 9, 10, 0, -4), (G_GENO | G_LGROUP | 2), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1000, 200, MS_ORC, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE, M2_ORC | M2_STRONG | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 4, CLR_YELLOW, "HILL_ORC");
    addMonster(ml,"", "", "Mordor orc", S_ORC, LVL(3, 5, 10, 0, -5), (G_GENO | G_LGROUP | 1), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1200, 200, MS_ORC, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE, M2_ORC | M2_STRONG | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 5, CLR_BLUE, "MORDOR_ORC");
    addMonster(ml,"", "", "Uruk-hai", S_ORC, LVL(3, 7, 10, 0, -4), (G_GENO | G_LGROUP | 1), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1300, 300, MS_ORC, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE, M2_ORC | M2_STRONG | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 5, CLR_BLACK, "URUK_HAI");
    addMonster(ml,"", "", "orc shaman", S_ORC, LVL(3, 9, 5, 10, -5), (G_GENO | 1), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1000, 300, MS_ORC, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE, M2_ORC | M2_GREEDY | M2_JEWELS | M2_MAGIC, M3_INFRAVISIBLE | M3_INFRAVISION, 5, HI_ZAP, "ORC_SHAMAN");
    addMonster(ml,"", "", "orc-captain", S_ORC, LVL(5, 5, 10, 0, -5), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1350, 350, MS_ORC, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE, M2_ORC | M2_STRONG | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 7, HI_LORD, "ORC_CAPTAIN");
    addMonster(ml,"", "", "rock piercer", S_PIERCER, LVL(3, 1, 3, 0, 0), (G_GENO | 4), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(200, 200, MS_SILENT, MZ_SMALL), 0, 0, M1_CLING | M1_HIDE | M1_ANIMAL | M1_NOEYES | M1_NOLIMBS | M1_CARNIVORE | M1_NOTAKE, M2_HOSTILE, 0, 4, CLR_GRAY, "ROCK_PIERCER");
    addMonster(ml,"", "", "iron piercer", S_PIERCER, LVL(5, 1, 0, 0, 0), (G_GENO | 2), ATTK(AT_BITE, AD_PHYS, 3, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(400, 300, MS_SILENT, MZ_MEDIUM), 0, 0, M1_CLING | M1_HIDE | M1_ANIMAL | M1_NOEYES | M1_NOLIMBS | M1_CARNIVORE | M1_NOTAKE, M2_HOSTILE, 0, 6, CLR_CYAN, "IRON_PIERCER");
    addMonster(ml,"", "", "glass piercer", S_PIERCER, LVL(7, 1, 0, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 4, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(400, 300, MS_SILENT, MZ_MEDIUM), MR_ACID, 0, M1_CLING | M1_HIDE | M1_ANIMAL | M1_NOEYES | M1_NOLIMBS | M1_CARNIVORE | M1_NOTAKE, M2_HOSTILE, 0, 9, CLR_WHITE, "GLASS_PIERCER");
    addMonster(ml,"", "", "rothe", S_QUADRUPED, LVL(2, 9, 7, 0, 0), (G_GENO | G_SGROUP | 4), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_BITE, AD_PHYS, 1, 3), ATTK(AT_BITE, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(400, 100, MS_MOO, MZ_LARGE), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_OMNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 4, CLR_BROWN, "ROTHE");
    addMonster(ml,"", "", "mumak", S_QUADRUPED, LVL(5, 9, 0, 0, -2), (G_GENO | 1), ATTK(AT_BUTT, AD_PHYS, 4, 12), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2500, 500, MS_TRUMPET, MZ_LARGE), 0, 0, M1_ANIMAL | M1_THICK_HIDE | M1_NOHANDS | M1_HERBIVORE, M2_HOSTILE | M2_STRONG, M3_INFRAVISIBLE, 7, CLR_GRAY, "MUMAK");
    addMonster(ml,"", "", "leocrotta", S_QUADRUPED, LVL(6, 18, 4, 10, 0), (G_GENO | 2), ATTK(AT_CLAW, AD_PHYS, 2, 6), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_CLAW, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1200, 500, MS_IMITATE, MZ_LARGE), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_OMNIVORE, M2_HOSTILE | M2_STRONG, M3_INFRAVISIBLE, 8, CLR_RED, "LEOCROTTA");
    addMonster(ml,"", "", "wumpus", S_QUADRUPED, LVL(8, 3, 2, 10, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 3, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2500, 500, MS_BURBLE, MZ_LARGE), 0, 0, M1_CLING | M1_ANIMAL | M1_NOHANDS | M1_OMNIVORE, M2_HOSTILE | M2_STRONG, M3_INFRAVISIBLE, 9, CLR_CYAN, "WUMPUS");
    addMonster(ml,"", "", "titanothere", S_QUADRUPED, LVL(12, 12, 6, 0, 0), (G_GENO | 2), ATTK(AT_CLAW, AD_PHYS, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2650, 650, MS_BELLOW, MZ_LARGE), 0, 0, M1_ANIMAL | M1_THICK_HIDE | M1_NOHANDS | M1_HERBIVORE, M2_HOSTILE | M2_STRONG, M3_INFRAVISIBLE, 13, CLR_GRAY, "TITANOTHERE");
    addMonster(ml,"", "", "baluchitherium", S_QUADRUPED, LVL(14, 12, 5, 0, 0), (G_GENO | 2), ATTK(AT_CLAW, AD_PHYS, 5, 4), ATTK(AT_CLAW, AD_PHYS, 5, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(3800, 800, MS_BELLOW, MZ_LARGE), 0, 0, M1_ANIMAL | M1_THICK_HIDE | M1_NOHANDS | M1_HERBIVORE, M2_HOSTILE | M2_STRONG, M3_INFRAVISIBLE, 15, CLR_GRAY, "BALUCHITHERIUM");
    addMonster(ml,"", "", "mastodon", S_QUADRUPED, LVL(20, 12, 5, 0, 0), (G_GENO | 1), ATTK(AT_BUTT, AD_PHYS, 4, 8), ATTK(AT_BUTT, AD_PHYS, 4, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(3800, 800, MS_TRUMPET, MZ_LARGE), 0, 0, M1_ANIMAL | M1_THICK_HIDE | M1_NOHANDS | M1_HERBIVORE, M2_HOSTILE | M2_STRONG, M3_INFRAVISIBLE, 22, CLR_BLACK, "MASTODON");
    addMonster(ml,"", "", "sewer rat", S_RODENT, LVL(0, 12, 7, 0, 0), (G_GENO | G_SGROUP | 1), ATTK(AT_BITE, AD_PHYS, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(20, 12, MS_SQEEK, MZ_TINY), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 1, CLR_BROWN, "SEWER_RAT");
    addMonster(ml,"", "", "giant rat", S_RODENT, LVL(1, 10, 7, 0, 0), (G_GENO | G_SGROUP | 2), ATTK(AT_BITE, AD_PHYS, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(30, 30, MS_SQEEK, MZ_TINY), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 2, CLR_BROWN, "GIANT_RAT");
    addMonster(ml,"", "", "rabid rat", S_RODENT, LVL(2, 12, 6, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_DRCO, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(30, 5, MS_SQEEK, MZ_TINY), MR_POISON, 0, M1_ANIMAL | M1_NOHANDS | M1_POIS | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 4, CLR_BROWN, "RABID_RAT");
    addMonster(ml,"", "", "wererat", S_RODENT, LVL(2, 12, 6, 10, -7), (G_NOGEN | G_NOCORPSE), ATTK(AT_BITE, AD_WERE, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(40, 30, MS_SQEEK, MZ_TINY), MR_POISON, 0, M1_NOHANDS | M1_POIS | M1_REGEN | M1_CARNIVORE, M2_NOPOLY | M2_WERE | M2_HOSTILE, M3_INFRAVISIBLE, 4, CLR_BROWN, "WERERAT");
    addMonster(ml,"", "", "rock mole", S_RODENT, LVL(3, 3, 0, 20, 0), (G_GENO | 2), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(30, 30, MS_SILENT, MZ_SMALL), 0, 0, M1_TUNNEL | M1_ANIMAL | M1_NOHANDS | M1_METALLIVORE, M2_HOSTILE | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE, 4, CLR_GRAY, "ROCK_MOLE");
    addMonster(ml,"", "", "woodchuck", S_RODENT, LVL(3, 3, 0, 20, 0), (G_NOGEN | G_GENO), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(30, 30, MS_SILENT, MZ_SMALL), 0, 0, M1_TUNNEL | M1_ANIMAL | M1_NOHANDS | M1_SWIM | M1_HERBIVORE, M2_WANDER | M2_HOSTILE, M3_INFRAVISIBLE, 4, CLR_BROWN, "WOODCHUCK");
    addMonster(ml,"", "", "cave spider", S_SPIDER, LVL(1, 12, 3, 0, 0), (G_GENO | G_SGROUP | 2), ATTK(AT_BITE, AD_PHYS, 1, 2), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(50, 50, MS_SILENT, MZ_TINY), MR_POISON, MR_POISON, M1_CONCEAL | M1_ANIMAL | M1_NOHANDS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE, 0, 3, CLR_GRAY, "CAVE_SPIDER");
    addMonster(ml,"", "", "centipede", S_SPIDER, LVL(2, 4, 3, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_DRST, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(50, 50, MS_SILENT, MZ_TINY), MR_POISON, MR_POISON, M1_CONCEAL | M1_ANIMAL | M1_NOHANDS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE, 0, 4, CLR_YELLOW, "CENTIPEDE");
    addMonster(ml,"", "", "giant spider", S_SPIDER, LVL(5, 15, 4, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_DRST, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(200, 100, MS_SILENT, MZ_LARGE), MR_POISON, MR_POISON, M1_ANIMAL | M1_NOHANDS | M1_OVIPAROUS | M1_POIS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG, 0, 7, CLR_MAGENTA, "GIANT_SPIDER");
    addMonster(ml,"", "", "scorpion", S_SPIDER, LVL(5, 15, 3, 0, 0), (G_GENO | 2), ATTK(AT_CLAW, AD_PHYS, 1, 2), ATTK(AT_CLAW, AD_PHYS, 1, 2), ATTK(AT_STNG, AD_DRST, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(50, 100, MS_SILENT, MZ_SMALL), MR_POISON, MR_POISON, M1_CONCEAL | M1_ANIMAL | M1_NOHANDS | M1_OVIPAROUS | M1_POIS | M1_CARNIVORE, M2_HOSTILE, 0, 8, CLR_RED, "SCORPION");
    addMonster(ml,"", "", "lurker above", S_TRAPPER, LVL(10, 3, 3, 0, 0), (G_GENO | 2), ATTK(AT_ENGL, AD_WRAP, 1, 6), ATTK(AT_ENGL, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(800, 350, MS_SILENT, MZ_HUGE), 0, 0, M1_HIDE | M1_FLY | M1_ANIMAL | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_CARNIVORE, M2_HOSTILE | M2_STALK | M2_STRONG, 0, 12, CLR_GRAY, "LURKER_ABOVE");
    addMonster(ml,"", "", "trapper", S_TRAPPER, LVL(12, 3, 3, 0, 0), (G_GENO | 2), ATTK(AT_ENGL, AD_WRAP, 1, 8), ATTK(AT_ENGL, AD_PHYS, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(800, 350, MS_SILENT, MZ_HUGE), 0, 0, M1_HIDE | M1_ANIMAL | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_CARNIVORE, M2_HOSTILE | M2_STALK | M2_STRONG, 0, 14, CLR_GREEN, "TRAPPER");
    addMonster(ml,"", "", "pony", S_UNICORN, LVL(3, 16, 6, 0, 0), (G_GENO | 2), ATTK(AT_KICK, AD_PHYS, 1, 6), ATTK(AT_BITE, AD_PHYS, 1, 2), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1300, 250, MS_NEIGH, MZ_MEDIUM), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_HERBIVORE, M2_WANDER | M2_STRONG | M2_DOMESTIC, M3_INFRAVISIBLE, 4, CLR_BROWN, "PONY");
    addMonster(ml,"", "", "white unicorn", S_UNICORN, LVL(4, 24, 2, 70, 7), (G_GENO | 2), ATTK(AT_BUTT, AD_PHYS, 1, 12), ATTK(AT_KICK, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1300, 300, MS_NEIGH, MZ_LARGE), MR_POISON, MR_POISON, M1_NOHANDS | M1_HERBIVORE, M2_WANDER | M2_STRONG | M2_JEWELS, M3_INFRAVISIBLE, 6, CLR_WHITE, "WHITE_UNICORN");
    addMonster(ml,"", "", "gray unicorn", S_UNICORN, LVL(4, 24, 2, 70, 0), (G_GENO | 1), ATTK(AT_BUTT, AD_PHYS, 1, 12), ATTK(AT_KICK, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1300, 300, MS_NEIGH, MZ_LARGE), MR_POISON, MR_POISON, M1_NOHANDS | M1_HERBIVORE, M2_WANDER | M2_STRONG | M2_JEWELS, M3_INFRAVISIBLE, 6, CLR_GRAY, "GRAY_UNICORN");
    addMonster(ml,"", "", "black unicorn", S_UNICORN, LVL(4, 24, 2, 70, -7), (G_GENO | 1), ATTK(AT_BUTT, AD_PHYS, 1, 12), ATTK(AT_KICK, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1300, 300, MS_NEIGH, MZ_LARGE), MR_POISON, MR_POISON, M1_NOHANDS | M1_HERBIVORE, M2_WANDER | M2_STRONG | M2_JEWELS, M3_INFRAVISIBLE, 6, CLR_BLACK, "BLACK_UNICORN");
    addMonster(ml,"", "", "horse", S_UNICORN, LVL(5, 20, 5, 0, 0), (G_GENO | 2), ATTK(AT_KICK, AD_PHYS, 1, 8), ATTK(AT_BITE, AD_PHYS, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 300, MS_NEIGH, MZ_LARGE), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_HERBIVORE, M2_WANDER | M2_STRONG | M2_DOMESTIC, M3_INFRAVISIBLE, 7, CLR_BROWN, "HORSE");
    addMonster(ml,"", "", "warhorse", S_UNICORN, LVL(7, 24, 4, 0, 0), (G_GENO | 2), ATTK(AT_KICK, AD_PHYS, 1, 10), ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1800, 350, MS_NEIGH, MZ_LARGE), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_HERBIVORE, M2_WANDER | M2_STRONG | M2_DOMESTIC, M3_INFRAVISIBLE, 9, CLR_BROWN, "WARHORSE");
    addMonster(ml,"", "", "fog cloud", S_VORTEX, LVL(3, 1, 0, 0, 0), (G_GENO | G_NOCORPSE | 2), ATTK(AT_ENGL, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(0, 0, MS_SILENT, MZ_HUGE), MR_SLEEP | MR_POISON | MR_STONE, 0, M1_FLY | M1_BREATHLESS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_AMORPHOUS | M1_UNSOLID, M2_HOSTILE | M2_NEUTER, 0, 4, CLR_GRAY, "FOG_CLOUD");
    addMonster(ml,"", "", "dust vortex", S_VORTEX, LVL(4, 20, 2, 30, 0), (G_GENO | G_NOCORPSE | 2), ATTK(AT_ENGL, AD_BLND, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(0, 0, MS_SILENT, MZ_HUGE), MR_SLEEP | MR_POISON | MR_STONE, 0, M1_FLY | M1_BREATHLESS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS, M2_HOSTILE | M2_NEUTER, 0, 6, CLR_BROWN, "DUST_VORTEX");
    addMonster(ml,"", "", "ice vortex", S_VORTEX, LVL(5, 20, 2, 30, 0), (G_NOHELL | G_GENO | G_NOCORPSE | 1), ATTK(AT_ENGL, AD_COLD, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(0, 0, MS_SILENT, MZ_HUGE), MR_COLD | MR_SLEEP | MR_POISON | MR_STONE, 0, M1_FLY | M1_BREATHLESS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS, M2_HOSTILE | M2_NEUTER, M3_INFRAVISIBLE, 7, CLR_CYAN, "ICE_VORTEX");
}
void ResourceData::buildMonsterList2(std::vector<cmonster>& ml)
{
    addMonster(ml,"", "", "energy vortex", S_VORTEX, LVL(6, 20, 2, 30, 0), (G_GENO | G_NOCORPSE | 1), ATTK(AT_ENGL, AD_ELEC, 1, 6), ATTK(AT_ENGL, AD_DREN, 2, 6), ATTK(AT_NONE, AD_ELEC, 0, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(0, 0, MS_SILENT, MZ_HUGE), MR_ELEC | MR_SLEEP | MR_DISINT | MR_POISON | MR_STONE, 0, M1_FLY | M1_BREATHLESS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_UNSOLID, M2_HOSTILE | M2_NEUTER, 0, 9, HI_ZAP, "ENERGY_VORTEX");
    addMonster(ml,"", "", "steam vortex", S_VORTEX, LVL(7, 22, 2, 30, 0), (G_HELL | G_GENO | G_NOCORPSE | 2), ATTK(AT_ENGL, AD_FIRE, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(0, 0, MS_SILENT, MZ_HUGE), MR_FIRE | MR_SLEEP | MR_POISON | MR_STONE, 0, M1_FLY | M1_BREATHLESS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_UNSOLID, M2_HOSTILE | M2_NEUTER, M3_INFRAVISIBLE, 9, CLR_BLUE, "STEAM_VORTEX");
    addMonster(ml,"", "", "fire vortex", S_VORTEX, LVL(8, 22, 2, 30, 0), (G_HELL | G_GENO | G_NOCORPSE | 1), ATTK(AT_ENGL, AD_FIRE, 1, 10), ATTK(AT_NONE, AD_FIRE, 0, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(0, 0, MS_SILENT, MZ_HUGE), MR_FIRE | MR_SLEEP | MR_POISON | MR_STONE, 0, M1_FLY | M1_BREATHLESS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_UNSOLID, M2_HOSTILE | M2_NEUTER, M3_INFRAVISIBLE, 10, CLR_YELLOW, "FIRE_VORTEX");
    addMonster(ml,"", "", "baby long worm", S_WORM, LVL(5, 3, 5, 0, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(600, 250, MS_SILENT, MZ_LARGE), 0, 0, M1_ANIMAL | M1_SLITHY | M1_NOLIMBS | M1_CARNIVORE | M1_NOTAKE, M2_HOSTILE, 0, 6, CLR_BROWN, "BABY_LONG_WORM");
    addMonster(ml,"", "", "baby purple worm", S_WORM, LVL(8, 3, 5, 0, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(600, 250, MS_SILENT, MZ_LARGE), 0, 0, M1_ANIMAL | M1_SLITHY | M1_NOLIMBS | M1_CARNIVORE, M2_HOSTILE, 0, 9, CLR_MAGENTA, "BABY_PURPLE_WORM");
    addMonster(ml,"", "", "long worm", S_WORM, LVL(9, 3, 5, 10, 0), (G_GENO | 2), ATTK(AT_BITE, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_SILENT, MZ_GIGANTIC), 0, 0, M1_ANIMAL | M1_SLITHY | M1_NOLIMBS | M1_OVIPAROUS | M1_CARNIVORE | M1_NOTAKE, M2_HOSTILE | M2_STRONG | M2_NASTY, 0, 10, CLR_BROWN, "LONG_WORM");
    addMonster(ml,"", "", "purple worm", S_WORM, LVL(15, 9, 6, 20, 0), (G_GENO | 2), ATTK(AT_BITE, AD_PHYS, 2, 8), ATTK(AT_ENGL, AD_DGST, 1, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2700, 700, MS_SILENT, MZ_GIGANTIC), 0, 0, M1_ANIMAL | M1_SLITHY | M1_NOLIMBS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY, 0, 17, CLR_MAGENTA, "PURPLE_WORM");
    addMonster(ml,"", "", "grid bug", S_XAN, LVL(0, 12, 9, 0, 0), (G_GENO | G_SGROUP | G_NOCORPSE | 3), ATTK(AT_BITE, AD_ELEC, 1, 1), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(15, 10, MS_BUZZ, MZ_TINY), MR_ELEC | MR_POISON, 0, M1_ANIMAL | M1_NOHANDS, M2_HOSTILE, M3_INFRAVISIBLE, 1, CLR_MAGENTA, "GRID_BUG");
    addMonster(ml,"", "", "xan", S_XAN, LVL(7, 18, -4, 0, 0), (G_GENO | 3), ATTK(AT_STNG, AD_LEGS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(300, 300, MS_BUZZ, MZ_TINY), MR_POISON, MR_POISON, M1_FLY | M1_ANIMAL | M1_NOHANDS | M1_POIS, M2_HOSTILE, M3_INFRAVISIBLE, 9, CLR_RED, "XAN");
    addMonster(ml,"", "", "yellow light", S_LIGHT, LVL(3, 15, 0, 0, 0), (G_NOCORPSE | G_GENO | 4), ATTK(AT_EXPL, AD_BLND, 10, 20), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(0, 0, MS_SILENT, MZ_SMALL), MR_FIRE | MR_COLD | MR_ELEC | MR_DISINT | MR_SLEEP | MR_POISON | MR_ACID | MR_STONE, 0, M1_FLY | M1_BREATHLESS | M1_AMORPHOUS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_UNSOLID | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, M3_INFRAVISIBLE, 5, CLR_YELLOW, "YELLOW_LIGHT");
    addMonster(ml,"", "", "black light", S_LIGHT, LVL(5, 15, 0, 0, 0), (G_NOCORPSE | G_GENO | 2), ATTK(AT_EXPL, AD_HALU, 10, 12), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(0, 0, MS_SILENT, MZ_SMALL), MR_FIRE | MR_COLD | MR_ELEC | MR_DISINT | MR_SLEEP | MR_POISON | MR_ACID | MR_STONE, 0, M1_FLY | M1_BREATHLESS | M1_AMORPHOUS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_UNSOLID | M1_SEE_INVIS | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, 0, 7, CLR_BLACK, "BLACK_LIGHT");
    addMonster(ml,"", "", "zruty", S_ZRUTY, LVL(9, 8, 3, 0, 0), (G_GENO | 2), ATTK(AT_CLAW, AD_PHYS, 3, 4), ATTK(AT_CLAW, AD_PHYS, 3, 4), ATTK(AT_BITE, AD_PHYS, 3, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1200, 600, MS_SILENT, MZ_LARGE), 0, 0, M1_ANIMAL | M1_HUMANOID | M1_CARNIVORE, M2_HOSTILE | M2_STRONG, M3_INFRAVISIBLE, 11, CLR_BROWN, "ZRUTY");
    addMonster(ml,"", "", "couatl", S_ANGEL, LVL(8, 10, 5, 30, 7), (G_NOHELL | G_SGROUP | G_NOCORPSE | 1), ATTK(AT_BITE, AD_DRST, 2, 4), ATTK(AT_BITE, AD_PHYS, 1, 3), ATTK(AT_HUGS, AD_WRAP, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(900, 400, MS_HISS, MZ_LARGE), MR_POISON, 0, M1_FLY | M1_NOHANDS | M1_SLITHY | M1_POIS, M2_MINION | M2_STALK | M2_STRONG | M2_NASTY, M3_INFRAVISIBLE | M3_INFRAVISION, 11, CLR_GREEN, "COUATL");
    addMonster(ml,"", "", "Aleax", S_ANGEL, LVL(10, 8, 0, 30, 7), (G_NOHELL | G_NOCORPSE | 1), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_KICK, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_IMITATE, MZ_HUMAN), MR_COLD | MR_ELEC | MR_SLEEP | MR_POISON, 0, M1_HUMANOID | M1_SEE_INVIS, M2_MINION | M2_STALK | M2_NASTY | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 12, CLR_YELLOW, "ALEAX");
    addMonster(ml,"", "", "Angel", S_ANGEL, LVL(14, 10, -4, 55, 12), (G_NOHELL | G_NOCORPSE | 1), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_MAGC, AD_MAGM, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_CUSS, MZ_HUMAN), MR_COLD | MR_ELEC | MR_SLEEP | MR_POISON, 0, M1_FLY | M1_HUMANOID | M1_SEE_INVIS, M2_NOPOLY | M2_MINION | M2_STALK | M2_STRONG | M2_NASTY | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 19, CLR_WHITE, "ANGEL");
    addMonster(ml,"", "", "ki-rin", S_ANGEL, LVL(16, 18, -5, 90, 15), (G_NOHELL | G_NOCORPSE | 1), ATTK(AT_KICK, AD_PHYS, 2, 4), ATTK(AT_KICK, AD_PHYS, 2, 4), ATTK(AT_BUTT, AD_PHYS, 3, 6), ATTK(AT_MAGC, AD_SPEL, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SPELL, MZ_LARGE), MR_POISON, 0, M1_FLY | M1_NOHANDS | M1_SEE_INVIS, M2_NOPOLY | M2_MINION | M2_STALK | M2_STRONG | M2_NASTY | M2_LORD, M3_INFRAVISIBLE | M3_INFRAVISION, 21, HI_GOLD, "KI_RIN");
    addMonster(ml,"", "", "Archon", S_ANGEL, LVL(19, 16, -6, 80, 15), (G_NOHELL | G_NOCORPSE | 1), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_GAZE, AD_BLND, 2, 6), ATTK(AT_CLAW, AD_PHYS, 1, 8), ATTK(AT_MAGC, AD_SPEL, 4, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_CUSS, MZ_LARGE), MR_FIRE | MR_COLD | MR_ELEC | MR_SLEEP | MR_POISON, 0, M1_FLY | M1_HUMANOID | M1_SEE_INVIS | M1_REGEN, M2_NOPOLY | M2_MINION | M2_STALK | M2_STRONG | M2_NASTY | M2_LORD | M2_COLLECT | M2_MAGIC, M3_INFRAVISIBLE | M3_INFRAVISION, 26, HI_LORD, "ARCHON");
    addMonster(ml,"", "", "bat", S_BAT, LVL(0, 22, 8, 0, 0), (G_GENO | G_SGROUP | 1), ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(20, 20, MS_SQEEK, MZ_TINY), 0, 0, M1_FLY | M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_WANDER, M3_INFRAVISIBLE, 2, CLR_BROWN, "BAT");
    addMonster(ml,"", "", "giant bat", S_BAT, LVL(2, 22, 7, 0, 0), (G_GENO | 2), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(30, 30, MS_SQEEK, MZ_SMALL), 0, 0, M1_FLY | M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_WANDER | M2_HOSTILE, M3_INFRAVISIBLE, 3, CLR_RED, "GIANT_BAT");
    addMonster(ml,"", "", "raven", S_BAT, LVL(4, 20, 6, 0, 0), (G_GENO | 2), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_CLAW, AD_BLND, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(40, 20, MS_SQAWK, MZ_SMALL), 0, 0, M1_FLY | M1_ANIMAL | M1_NOHANDS | M1_OVIPAROUS | M1_CARNIVORE, M2_WANDER | M2_HOSTILE, M3_INFRAVISIBLE, 6, CLR_BLACK, "RAVEN");
    addMonster(ml,"", "", "vampire bat", S_BAT, LVL(5, 20, 6, 0, 0), (G_GENO | 2), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_BITE, AD_DRST, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(30, 20, MS_SQEEK, MZ_SMALL), MR_SLEEP | MR_POISON, 0, M1_FLY | M1_ANIMAL | M1_NOHANDS | M1_POIS | M1_REGEN | M1_OMNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 7, CLR_BLACK, "VAMPIRE_BAT");
    addMonster(ml,"", "", "plains centaur", S_CENTAUR, LVL(4, 18, 4, 0, 0), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_KICK, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2500, 500, MS_HUMANOID, MZ_LARGE), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_STRONG | M2_GREEDY | M2_COLLECT, M3_INFRAVISIBLE, 6, CLR_BROWN, "PLAINS_CENTAUR");
    addMonster(ml,"", "", "forest centaur", S_CENTAUR, LVL(5, 18, 3, 10, -1), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_KICK, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2550, 600, MS_HUMANOID, MZ_LARGE), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_STRONG | M2_GREEDY | M2_COLLECT, M3_INFRAVISIBLE, 8, CLR_GREEN, "FOREST_CENTAUR");
    addMonster(ml,"", "", "mountain centaur", S_CENTAUR, LVL(6, 20, 2, 10, -3), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 1, 10), ATTK(AT_KICK, AD_PHYS, 1, 6), ATTK(AT_KICK, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2550, 500, MS_HUMANOID, MZ_LARGE), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_STRONG | M2_GREEDY | M2_COLLECT, M3_INFRAVISIBLE, 9, CLR_CYAN, "MOUNTAIN_CENTAUR");
    addMonster(ml,"", "", "baby gray dragon", S_DRAGON, LVL(12, 9, 2, 10, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_ROAR, MZ_HUGE), 0, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_GREEDY | M2_JEWELS, 0, 13, CLR_GRAY, "BABY_GRAY_DRAGON");
    addMonster(ml,"", "", "baby gold dragon", S_DRAGON, LVL(12, 9, 2, 10, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_ROAR, MZ_HUGE), 0, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_GREEDY | M2_JEWELS, M3_INFRAVISIBLE, 13, HI_GOLD, "BABY_GOLD_DRAGON");
    addMonster(ml,"", "", "baby silver dragon", S_DRAGON, LVL(12, 9, 2, 10, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_ROAR, MZ_HUGE), 0, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_GREEDY | M2_JEWELS, 0, 13, DRAGON_SILVER, "BABY_SILVER_DRAGON");
    addMonster(ml,"", "", "baby shimmering dragon", S_DRAGON, LVL(12, 9, 2, 10, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_ROAR, MZ_HUGE), 0, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_GREEDY | M2_JEWELS, 0, 13, CLR_CYAN, "BABY_SHIMMERING_DRAGON");
    addMonster(ml,"", "", "baby red dragon", S_DRAGON, LVL(12, 9, 2, 10, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_ROAR, MZ_HUGE), MR_FIRE, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_GREEDY | M2_JEWELS, M3_INFRAVISIBLE, 13, CLR_RED, "BABY_RED_DRAGON");
    addMonster(ml,"", "", "baby white dragon", S_DRAGON, LVL(12, 9, 2, 10, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_ROAR, MZ_HUGE), MR_COLD, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_GREEDY | M2_JEWELS, 0, 13, CLR_WHITE, "BABY_WHITE_DRAGON");
    addMonster(ml,"", "", "baby orange dragon", S_DRAGON, LVL(12, 9, 2, 10, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_ROAR, MZ_HUGE), MR_SLEEP, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_GREEDY | M2_JEWELS, 0, 13, CLR_ORANGE, "BABY_ORANGE_DRAGON");
    addMonster(ml,"", "", "baby black dragon", S_DRAGON, LVL(12, 9, 2, 10, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_ROAR, MZ_HUGE), MR_DISINT, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_GREEDY | M2_JEWELS, 0, 13, CLR_BLACK, "BABY_BLACK_DRAGON");
    addMonster(ml,"", "", "baby blue dragon", S_DRAGON, LVL(12, 9, 2, 10, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_ROAR, MZ_HUGE), MR_ELEC, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_GREEDY | M2_JEWELS, 0, 13, CLR_BLUE, "BABY_BLUE_DRAGON");
    addMonster(ml,"", "", "baby green dragon", S_DRAGON, LVL(12, 9, 2, 10, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_ROAR, MZ_HUGE), MR_POISON, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_CARNIVORE | M1_POIS, M2_HOSTILE | M2_STRONG | M2_GREEDY | M2_JEWELS, 0, 13, CLR_GREEN, "BABY_GREEN_DRAGON");
    addMonster(ml,"", "", "baby yellow dragon", S_DRAGON, LVL(12, 9, 2, 10, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_ROAR, MZ_HUGE), MR_ACID | MR_STONE, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_CARNIVORE | M1_ACID, M2_HOSTILE | M2_STRONG | M2_GREEDY | M2_JEWELS, 0, 13, CLR_YELLOW, "BABY_YELLOW_DRAGON");
    addMonster(ml,"", "", "gray dragon", S_DRAGON, LVL(15, 9, -1, 20, 4), (G_GENO | 1), ATTK(AT_BREA, AD_MAGM, 4, 6), ATTK(AT_BITE, AD_PHYS, 3, 8), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_DRAGON, 1500, MS_ROAR, MZ_GIGANTIC), 0, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_SEE_INVIS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_MAGIC, 0, 20, CLR_GRAY, "GRAY_DRAGON");
    addMonster(ml,"", "", "gold dragon", S_DRAGON, LVL(15, 9, -1, 20, 4), (G_GENO | 1), ATTK(AT_BREA, AD_FIRE, 4, 6), ATTK(AT_BITE, AD_PHYS, 3, 8), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_DRAGON, 1500, MS_ROAR, MZ_GIGANTIC), MR_FIRE, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_SEE_INVIS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_MAGIC, M3_INFRAVISIBLE, 20, HI_GOLD, "GOLD_DRAGON");
    addMonster(ml,"", "", "silver dragon", S_DRAGON, LVL(15, 9, -1, 20, 4), (G_GENO | 1), ATTK(AT_BREA, AD_COLD, 4, 6), ATTK(AT_BITE, AD_PHYS, 3, 8), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_DRAGON, 1500, MS_ROAR, MZ_GIGANTIC), MR_COLD, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_SEE_INVIS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_MAGIC, 0, 20, DRAGON_SILVER, "SILVER_DRAGON");
    addMonster(ml,"", "", "shimmering dragon", S_DRAGON, LVL(15, 9, -1, 20, 4), (G_GENO | 1), ATTK(AT_BREA, AD_MAGM, 4, 6), ATTK(AT_BITE, AD_PHYS, 3, 8), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_DRAGON, 1500, MS_ROAR, MZ_GIGANTIC), 0, 0, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_SEE_INVIS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_MAGIC, 0, 20, CLR_CYAN, "SHIMMERING_DRAGON");
    addMonster(ml,"", "", "red dragon", S_DRAGON, LVL(15, 9, -1, 20, -4), (G_GENO | 1), ATTK(AT_BREA, AD_FIRE, 6, 6), ATTK(AT_BITE, AD_PHYS, 3, 8), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_DRAGON, 1500, MS_ROAR, MZ_GIGANTIC), MR_FIRE, MR_FIRE, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_SEE_INVIS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_MAGIC, M3_INFRAVISION | M3_INFRAVISIBLE, 20, CLR_RED, "RED_DRAGON");
    addMonster(ml,"", "", "white dragon", S_DRAGON, LVL(15, 9, -1, 20, -5), (G_GENO | 1), ATTK(AT_BREA, AD_COLD, 4, 6), ATTK(AT_BITE, AD_PHYS, 3, 8), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_DRAGON, 1500, MS_ROAR, MZ_GIGANTIC), MR_COLD, MR_COLD, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_SEE_INVIS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_MAGIC, 0, 20, CLR_WHITE, "WHITE_DRAGON");
    addMonster(ml,"", "", "orange dragon", S_DRAGON, LVL(15, 9, -1, 20, 5), (G_GENO | 1), ATTK(AT_BREA, AD_SLEE, 4, 25), ATTK(AT_BITE, AD_PHYS, 3, 8), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_DRAGON, 1500, MS_ROAR, MZ_GIGANTIC), MR_SLEEP, MR_SLEEP, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_SEE_INVIS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_MAGIC, 0, 20, CLR_ORANGE, "ORANGE_DRAGON");
    addMonster(ml,"", "", "black dragon", S_DRAGON, LVL(15, 9, -1, 20, -6), (G_GENO | 1), ATTK(AT_BREA, AD_DISN, 1, 255), ATTK(AT_BITE, AD_PHYS, 3, 8), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_DRAGON, 1500, MS_ROAR, MZ_GIGANTIC), MR_DISINT, MR_DISINT, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_SEE_INVIS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_MAGIC, 0, 20, CLR_BLACK, "BLACK_DRAGON");
    addMonster(ml,"", "", "blue dragon", S_DRAGON, LVL(15, 9, -1, 20, -7), (G_GENO | 1), ATTK(AT_BREA, AD_ELEC, 4, 6), ATTK(AT_BITE, AD_PHYS, 3, 8), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_DRAGON, 1500, MS_ROAR, MZ_GIGANTIC), MR_ELEC, MR_ELEC, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_SEE_INVIS | M1_OVIPAROUS | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_MAGIC, 0, 20, CLR_BLUE, "BLUE_DRAGON");
    addMonster(ml,"", "", "green dragon", S_DRAGON, LVL(15, 9, -1, 20, 6), (G_GENO | 1), ATTK(AT_BREA, AD_DRST, 4, 6), ATTK(AT_BITE, AD_PHYS, 3, 8), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_DRAGON, 1500, MS_ROAR, MZ_GIGANTIC), MR_POISON, MR_POISON, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_SEE_INVIS | M1_OVIPAROUS | M1_CARNIVORE | M1_POIS, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_MAGIC, 0, 20, CLR_GREEN, "GREEN_DRAGON");
    addMonster(ml,"", "", "yellow dragon", S_DRAGON, LVL(15, 9, -1, 20, 7), (G_GENO | 1), ATTK(AT_BREA, AD_ACID, 4, 6), ATTK(AT_BITE, AD_PHYS, 3, 8), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_DRAGON, 1500, MS_ROAR, MZ_GIGANTIC), MR_ACID | MR_STONE, MR_ACID | MR_STONE, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_SEE_INVIS | M1_OVIPAROUS | M1_CARNIVORE | M1_ACID, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_MAGIC, 0, 20, CLR_YELLOW, "YELLOW_DRAGON");
    addMonster(ml,"", "", "stalker", S_ELEMENTAL, LVL(8, 12, 3, 0, 0), (G_GENO | 3), ATTK(AT_CLAW, AD_PHYS, 4, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(900, 400, MS_SILENT, MZ_LARGE), 0, 0, M1_ANIMAL | M1_FLY | M1_SEE_INVIS, M2_WANDER | M2_STALK | M2_HOSTILE | M2_STRONG, M3_INFRAVISION, 9, CLR_WHITE, "STALKER");
    addMonster(ml,"", "", "air elemental", S_ELEMENTAL, LVL(8, 36, 2, 30, 0), (G_NOCORPSE | 1), ATTK(AT_ENGL, AD_PHYS, 1, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(0, 0, MS_SILENT, MZ_HUGE), MR_POISON | MR_STONE, 0, M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_BREATHLESS | M1_UNSOLID | M1_FLY, M2_STRONG | M2_NEUTER, 0, 10, CLR_CYAN, "AIR_ELEMENTAL");
    addMonster(ml,"", "", "fire elemental", S_ELEMENTAL, LVL(8, 12, 2, 30, 0), (G_NOCORPSE | 1), ATTK(AT_CLAW, AD_FIRE, 3, 6), ATTK(AT_NONE, AD_FIRE, 0, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(0, 0, MS_SILENT, MZ_HUGE), MR_FIRE | MR_POISON | MR_STONE, 0, M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_BREATHLESS | M1_UNSOLID | M1_FLY | M1_NOTAKE, M2_STRONG | M2_NEUTER, M3_INFRAVISIBLE, 10, CLR_YELLOW, "FIRE_ELEMENTAL");
    addMonster(ml,"", "", "earth elemental", S_ELEMENTAL, LVL(8, 6, 2, 30, 0), (G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 4, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2500, 0, MS_SILENT, MZ_HUGE), MR_FIRE | MR_COLD | MR_POISON | MR_STONE, 0, M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_BREATHLESS | M1_WALLWALK | M1_THICK_HIDE, M2_STRONG | M2_NEUTER, 0, 10, CLR_BROWN, "EARTH_ELEMENTAL");
    addMonster(ml,"", "", "water elemental", S_ELEMENTAL, LVL(8, 6, 2, 30, 0), (G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 5, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2500, 0, MS_SILENT, MZ_HUGE), MR_POISON | MR_STONE, 0, M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_BREATHLESS | M1_UNSOLID | M1_AMPHIBIOUS | M1_SWIM, M2_STRONG | M2_NEUTER, 0, 10, CLR_BLUE, "WATER_ELEMENTAL");
    addMonster(ml,"", "", "lichen", S_FUNGUS, LVL(0, 1, 9, 0, 0), (G_GENO | 4), ATTK(AT_TUCH, AD_STCK, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(20, 200, MS_SILENT, MZ_SMALL), 0, 0, M1_BREATHLESS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, 0, 1, CLR_BRIGHT_GREEN, "LICHEN");
    addMonster(ml,"", "", "brown mold", S_FUNGUS, LVL(1, 0, 9, 0, 0), (G_GENO | 1), ATTK(AT_NONE, AD_COLD, 0, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(50, 30, MS_SILENT, MZ_SMALL), MR_COLD | MR_POISON, MR_COLD | MR_POISON, M1_BREATHLESS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, 0, 2, CLR_BROWN, "BROWN_MOLD");
    addMonster(ml,"", "", "yellow mold", S_FUNGUS, LVL(1, 0, 9, 0, 0), (G_GENO | 2), ATTK(AT_NONE, AD_STUN, 0, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(50, 30, MS_SILENT, MZ_SMALL), MR_POISON, MR_POISON, M1_BREATHLESS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_POIS | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, 0, 2, CLR_YELLOW, "YELLOW_MOLD");
    addMonster(ml,"", "", "green mold", S_FUNGUS, LVL(1, 0, 9, 0, 0), (G_GENO | 1), ATTK(AT_NONE, AD_ACID, 0, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(50, 30, MS_SILENT, MZ_SMALL), MR_ACID | MR_STONE, MR_ACID | MR_STONE, M1_BREATHLESS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_ACID | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, 0, 2, CLR_GREEN, "GREEN_MOLD");
    addMonster(ml,"", "", "red mold", S_FUNGUS, LVL(1, 0, 9, 0, 0), (G_GENO | 1), ATTK(AT_NONE, AD_FIRE, 0, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(50, 30, MS_SILENT, MZ_SMALL), MR_FIRE | MR_POISON, MR_FIRE | MR_POISON, M1_BREATHLESS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, M3_INFRAVISIBLE, 2, CLR_RED, "RED_MOLD");
}
void ResourceData::buildMonsterList3(std::vector<cmonster>& ml)
{
    addMonster(ml,"", "", "shrieker", S_FUNGUS, LVL(3, 1, 7, 0, 0), (G_GENO | 1), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(100, 100, MS_SHRIEK, MZ_SMALL), MR_POISON, MR_POISON, M1_BREATHLESS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, 0, 2, CLR_MAGENTA, "SHRIEKER");
    addMonster(ml,"", "", "violet fungus", S_FUNGUS, LVL(3, 1, 7, 0, 0), (G_GENO | 2), ATTK(AT_TUCH, AD_PHYS, 1, 4), ATTK(AT_TUCH, AD_STCK, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(100, 100, MS_SILENT, MZ_SMALL), MR_POISON, MR_POISON, M1_BREATHLESS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_NOTAKE, M2_HOSTILE | M2_NEUTER, 0, 5, CLR_MAGENTA, "VIOLET_FUNGUS");
    addMonster(ml,"", "", "gnome", S_GNOME, LVL(1, 6, 10, 4, 0), (G_GENO | G_SGROUP | 1), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(650, 100, MS_ORC, MZ_SMALL), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_GNOME | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 3, CLR_BROWN, "GNOME");
    addMonster(ml, "gnome lord", "gnome lady", "gnome leader", S_GNOME, LVL(3, 8, 10, 4, 0), (G_GENO | 2), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(700, 120, MS_ORC, MZ_SMALL), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_GNOME | M2_LORD | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 4, CLR_BLUE, "GNOME_LEADER");
    addMonster(ml,"", "", "gnomish wizard", S_GNOME, LVL(3, 10, 4, 10, 0), (G_GENO | 1), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(700, 120, MS_ORC, MZ_SMALL), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_GNOME | M2_MAGIC, M3_INFRAVISIBLE | M3_INFRAVISION, 5, HI_ZAP, "GNOMISH_WIZARD");
    addMonster(ml, "gnome king", "gnome queen", "gnome ruler", S_GNOME, LVL(5, 10, 10, 20, 0), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(750, 150, MS_ORC, MZ_SMALL), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_GNOME | M2_PRINCE | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 6, HI_LORD, "GNOME_RULER");
    addMonster(ml,"", "", "giant", S_GIANT, LVL(6, 6, 0, 0, 2), (G_GENO | G_NOGEN | 1), ATTK(AT_WEAP, AD_PHYS, 2, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2250, 750, MS_BOAST, MZ_HUGE), 0, 0, M1_HUMANOID | M1_CARNIVORE, M2_GIANT | M2_STRONG | M2_ROCKTHROW | M2_NASTY | M2_COLLECT | M2_JEWELS, M3_INFRAVISIBLE | M3_INFRAVISION, 8, CLR_RED, "GIANT");
    addMonster(ml,"", "", "stone giant", S_GIANT, LVL(6, 6, 0, 0, 2), (G_GENO | G_SGROUP | 1), ATTK(AT_WEAP, AD_PHYS, 2, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2250, 750, MS_BOAST, MZ_HUGE), 0, 0, M1_HUMANOID | M1_CARNIVORE, M2_GIANT | M2_STRONG | M2_ROCKTHROW | M2_NASTY | M2_COLLECT | M2_JEWELS, M3_INFRAVISIBLE | M3_INFRAVISION, 8, CLR_GRAY, "STONE_GIANT");
    addMonster(ml,"", "", "hill giant", S_GIANT, LVL(8, 10, 6, 0, -2), (G_GENO | G_SGROUP | 1), ATTK(AT_WEAP, AD_PHYS, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2200, 700, MS_BOAST, MZ_HUGE), 0, 0, M1_HUMANOID | M1_CARNIVORE, M2_GIANT | M2_STRONG | M2_ROCKTHROW | M2_NASTY | M2_COLLECT | M2_JEWELS, M3_INFRAVISIBLE | M3_INFRAVISION, 10, CLR_CYAN, "HILL_GIANT");
    addMonster(ml,"", "", "fire giant", S_GIANT, LVL(9, 12, 4, 5, 2), (G_GENO | G_SGROUP | 1), ATTK(AT_WEAP, AD_PHYS, 2, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2250, 750, MS_BOAST, MZ_HUGE), MR_FIRE, MR_FIRE, M1_HUMANOID | M1_CARNIVORE, M2_GIANT | M2_STRONG | M2_ROCKTHROW | M2_NASTY | M2_COLLECT | M2_JEWELS, M3_INFRAVISIBLE | M3_INFRAVISION, 11, CLR_YELLOW, "FIRE_GIANT");
    addMonster(ml,"", "", "frost giant", S_GIANT, LVL(10, 12, 3, 10, -3), (G_NOHELL | G_GENO | G_SGROUP | 1), ATTK(AT_WEAP, AD_PHYS, 2, 12), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2250, 750, MS_BOAST, MZ_HUGE), MR_COLD, MR_COLD, M1_HUMANOID | M1_CARNIVORE, M2_GIANT | M2_STRONG | M2_ROCKTHROW | M2_NASTY | M2_COLLECT | M2_JEWELS, M3_INFRAVISIBLE | M3_INFRAVISION, 13, CLR_WHITE, "FROST_GIANT");
    addMonster(ml,"", "", "ettin", S_GIANT, LVL(10, 12, 3, 0, 0), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 2, 8), ATTK(AT_WEAP, AD_PHYS, 3, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1700, 500, MS_GRUNT, MZ_HUGE), 0, 0, M1_ANIMAL | M1_HUMANOID | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 13, CLR_BROWN, "ETTIN");
    addMonster(ml,"", "", "storm giant", S_GIANT, LVL(16, 12, 3, 10, -3), (G_GENO | G_SGROUP | 1), ATTK(AT_WEAP, AD_PHYS, 2, 12), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2250, 750, MS_BOAST, MZ_HUGE), MR_ELEC, MR_ELEC, M1_HUMANOID | M1_CARNIVORE, M2_GIANT | M2_STRONG | M2_ROCKTHROW | M2_NASTY | M2_COLLECT | M2_JEWELS, M3_INFRAVISIBLE | M3_INFRAVISION, 19, CLR_BLUE, "STORM_GIANT");
    addMonster(ml,"", "", "titan", S_GIANT, LVL(16, 18, -3, 70, 9), (1), ATTK(AT_WEAP, AD_PHYS, 2, 8), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2300, 900, MS_SPELL, MZ_HUGE), 0, 0, M1_FLY | M1_HUMANOID | M1_OMNIVORE, M2_STRONG | M2_ROCKTHROW | M2_NASTY | M2_COLLECT | M2_MAGIC, M3_INFRAVISIBLE | M3_INFRAVISION, 20, CLR_MAGENTA, "TITAN");
    addMonster(ml,"", "", "minotaur", S_GIANT, LVL(15, 15, 6, 0, 0), (G_GENO | G_NOGEN), ATTK(AT_CLAW, AD_PHYS, 3, 10), ATTK(AT_CLAW, AD_PHYS, 3, 10), ATTK(AT_BUTT, AD_PHYS, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 700, MS_MOO, MZ_LARGE), 0, 0, M1_ANIMAL | M1_HUMANOID | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY, M3_INFRAVISIBLE | M3_INFRAVISION, 17, CLR_BROWN, "MINOTAUR");
    addMonster(ml,"", "", "jabberwock", S_JABBERWOCK, LVL(15, 12, -2, 50, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 2, 10), ATTK(AT_BITE, AD_PHYS, 2, 10), ATTK(AT_CLAW, AD_PHYS, 2, 10), ATTK(AT_CLAW, AD_PHYS, 2, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1300, 600, MS_BURBLE, MZ_LARGE), 0, 0, M1_ANIMAL | M1_FLY | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_COLLECT, M3_INFRAVISIBLE, 18, CLR_ORANGE, "JABBERWOCK");
    addMonster(ml,"", "", "vorpal jabberwock", S_JABBERWOCK, LVL(20, 12, -2, 50, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 3, 10), ATTK(AT_BITE, AD_PHYS, 3, 10), ATTK(AT_CLAW, AD_PHYS, 3, 10), ATTK(AT_CLAW, AD_PHYS, 3, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1300, 600, MS_BURBLE, MZ_LARGE), 0, 0, M1_ANIMAL | M1_FLY | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY | M2_COLLECT, M3_INFRAVISIBLE, 25, HI_LORD, "VORPAL_JABBERWOCK");
    addMonster(ml,"", "", "Keystone Kop", S_KOP, LVL(1, 6, 10, 10, 9), (G_GENO | G_LGROUP | G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 200, MS_ARREST, MZ_HUMAN), 0, 0, M1_HUMANOID, M2_HUMAN | M2_WANDER | M2_HOSTILE | M2_MALE | M2_COLLECT, M3_INFRAVISIBLE, 3, CLR_BLUE, "KEYSTONE_KOP");
    addMonster(ml,"", "", "Kop Sergeant", S_KOP, LVL(2, 8, 10, 10, 10), (G_GENO | G_SGROUP | G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 200, MS_ARREST, MZ_HUMAN), 0, 0, M1_HUMANOID, M2_HUMAN | M2_WANDER | M2_HOSTILE | M2_STRONG | M2_MALE | M2_COLLECT, M3_INFRAVISIBLE, 4, CLR_BLUE, "KOP_SERGEANT");
    addMonster(ml,"", "", "Kop Lieutenant", S_KOP, LVL(3, 10, 10, 20, 11), (G_GENO | G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 200, MS_ARREST, MZ_HUMAN), 0, 0, M1_HUMANOID, M2_HUMAN | M2_WANDER | M2_HOSTILE | M2_STRONG | M2_MALE | M2_COLLECT, M3_INFRAVISIBLE, 5, CLR_CYAN, "KOP_LIEUTENANT");
    addMonster(ml,"", "", "Kop Kaptain", S_KOP, LVL(4, 12, 10, 20, 12), (G_GENO | G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 200, MS_ARREST, MZ_HUMAN), 0, 0, M1_HUMANOID, M2_HUMAN | M2_WANDER | M2_HOSTILE | M2_STRONG | M2_MALE | M2_COLLECT, M3_INFRAVISIBLE, 6, HI_LORD, "KOP_KAPTAIN");
    addMonster(ml,"", "", "lich", S_LICH, LVL(11, 6, 0, 30, -9), (G_GENO | G_NOCORPSE | 1), ATTK(AT_TUCH, AD_COLD, 1, 10), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1200, 100, MS_MUMBLE, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON, MR_COLD, M1_BREATHLESS | M1_HUMANOID | M1_POIS | M1_REGEN, M2_UNDEAD | M2_HOSTILE | M2_MAGIC, M3_INFRAVISION, 14, CLR_BROWN, "LICH");
    addMonster(ml,"", "", "demilich", S_LICH, LVL(14, 9, -2, 60, -12), (G_GENO | G_NOCORPSE | 1), ATTK(AT_TUCH, AD_COLD, 3, 4), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1200, 100, MS_MUMBLE, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON, MR_COLD, M1_BREATHLESS | M1_HUMANOID | M1_POIS | M1_REGEN, M2_UNDEAD | M2_HOSTILE | M2_MAGIC, M3_INFRAVISION, 18, CLR_RED, "DEMILICH");
    addMonster(ml,"", "", "master lich", S_LICH, LVL(17, 9, -4, 90, -15), (G_HELL | G_GENO | G_NOCORPSE | 1), ATTK(AT_TUCH, AD_COLD, 3, 6), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1200, 100, MS_MUMBLE, MZ_HUMAN), MR_FIRE | MR_COLD | MR_SLEEP | MR_POISON, MR_FIRE | MR_COLD, M1_BREATHLESS | M1_HUMANOID | M1_POIS | M1_REGEN, M2_UNDEAD | M2_HOSTILE | M2_MAGIC, M3_WANTSBOOK | M3_INFRAVISION, 21, HI_LORD, "MASTER_LICH");
    addMonster(ml,"", "", "arch-lich", S_LICH, LVL(25, 9, -6, 90, -15), (G_HELL | G_GENO | G_NOCORPSE | 1), ATTK(AT_TUCH, AD_COLD, 5, 6), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1200, 100, MS_MUMBLE, MZ_HUMAN), MR_FIRE | MR_COLD | MR_SLEEP | MR_ELEC | MR_POISON, MR_FIRE | MR_COLD, M1_BREATHLESS | M1_HUMANOID | M1_POIS | M1_REGEN, M2_UNDEAD | M2_HOSTILE | M2_MAGIC, M3_WANTSBOOK | M3_INFRAVISION, 29, HI_LORD, "ARCH_LICH");
    addMonster(ml,"", "", "kobold mummy", S_MUMMY, LVL(3, 8, 6, 20, -2), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(400, 50, MS_SILENT, MZ_SMALL), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_POIS, M2_UNDEAD | M2_HOSTILE, M3_INFRAVISION, 4, CLR_BROWN, "KOBOLD_MUMMY");
    addMonster(ml,"", "", "gnome mummy", S_MUMMY, LVL(4, 10, 6, 20, -3), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(650, 50, MS_SILENT, MZ_SMALL), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_POIS, M2_UNDEAD | M2_HOSTILE | M2_GNOME, M3_INFRAVISION, 5, CLR_RED, "GNOME_MUMMY");
    addMonster(ml,"", "", "orc mummy", S_MUMMY, LVL(5, 10, 5, 20, -4), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(850, 75, MS_SILENT, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_POIS, M2_UNDEAD | M2_HOSTILE | M2_STRONG | M2_ORC | M2_GREEDY | M2_JEWELS, M3_INFRAVISION, 6, CLR_GRAY, "ORC_MUMMY");
    addMonster(ml,"", "", "dwarf mummy", S_MUMMY, LVL(5, 10, 5, 20, -4), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(900, 150, MS_SILENT, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_POIS, M2_UNDEAD | M2_HOSTILE | M2_DWARF | M2_GREEDY | M2_JEWELS, M3_INFRAVISION, 6, CLR_RED, "DWARF_MUMMY");
    addMonster(ml,"", "", "elf mummy", S_MUMMY, LVL(6, 12, 4, 30, -5), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_ELF, 175, MS_SILENT, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_POIS, M2_UNDEAD | M2_HOSTILE | M2_ELF, M3_INFRAVISION, 7, CLR_GREEN, "ELF_MUMMY");
    addMonster(ml,"", "", "human mummy", S_MUMMY, LVL(6, 12, 4, 30, -5), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 2, 4), ATTK(AT_CLAW, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 200, MS_SILENT, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_POIS, M2_UNDEAD | M2_HOSTILE, M3_INFRAVISION, 7, CLR_GRAY, "HUMAN_MUMMY");
    addMonster(ml,"", "", "ettin mummy", S_MUMMY, LVL(7, 12, 4, 30, -6), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 2, 6), ATTK(AT_CLAW, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1700, 250, MS_SILENT, MZ_HUGE), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_POIS, M2_UNDEAD | M2_HOSTILE | M2_STRONG, M3_INFRAVISION, 8, CLR_BLUE, "ETTIN_MUMMY");
    addMonster(ml,"", "", "giant mummy", S_MUMMY, LVL(8, 14, 3, 30, -7), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 3, 4), ATTK(AT_CLAW, AD_PHYS, 3, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2050, 375, MS_SILENT, MZ_HUGE), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_POIS, M2_UNDEAD | M2_HOSTILE | M2_GIANT | M2_STRONG | M2_JEWELS, M3_INFRAVISION, 10, CLR_CYAN, "GIANT_MUMMY");
    addMonster(ml,"", "", "red naga hatchling", S_NAGA, LVL(3, 10, 6, 0, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(500, 100, MS_MUMBLE, MZ_LARGE), MR_FIRE | MR_POISON, MR_POISON, M1_NOLIMBS | M1_SLITHY | M1_THICK_HIDE | M1_NOTAKE | M1_OMNIVORE, M2_STRONG, M3_INFRAVISIBLE, 4, CLR_RED, "RED_NAGA_HATCHLING");
    addMonster(ml,"", "", "black naga hatchling", S_NAGA, LVL(3, 10, 6, 0, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(500, 100, MS_MUMBLE, MZ_LARGE), MR_POISON | MR_ACID | MR_STONE, MR_POISON, M1_NOLIMBS | M1_SLITHY | M1_THICK_HIDE | M1_ACID | M1_NOTAKE | M1_CARNIVORE, M2_STRONG, 0, 4, CLR_BLACK, "BLACK_NAGA_HATCHLING");
    addMonster(ml,"", "", "golden naga hatchling", S_NAGA, LVL(3, 10, 6, 0, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(500, 100, MS_MUMBLE, MZ_LARGE), MR_POISON, MR_POISON, M1_NOLIMBS | M1_SLITHY | M1_THICK_HIDE | M1_NOTAKE | M1_OMNIVORE, M2_STRONG, 0, 4, HI_GOLD, "GOLDEN_NAGA_HATCHLING");
    addMonster(ml,"", "", "guardian naga hatchling", S_NAGA, LVL(3, 10, 6, 0, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(500, 100, MS_MUMBLE, MZ_LARGE), MR_POISON, MR_POISON, M1_NOLIMBS | M1_SLITHY | M1_THICK_HIDE | M1_NOTAKE | M1_OMNIVORE, M2_STRONG, 0, 4, CLR_GREEN, "GUARDIAN_NAGA_HATCHLING");
    addMonster(ml,"", "", "red naga", S_NAGA, LVL(6, 12, 4, 0, -4), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 2, 4), ATTK(AT_BREA, AD_FIRE, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2600, 400, MS_MUMBLE, MZ_HUGE), MR_FIRE | MR_POISON, MR_FIRE | MR_POISON, M1_NOLIMBS | M1_SLITHY | M1_THICK_HIDE | M1_OVIPAROUS | M1_NOTAKE | M1_OMNIVORE, M2_STRONG, M3_INFRAVISIBLE, 8, CLR_RED, "RED_NAGA");
    addMonster(ml,"", "", "black naga", S_NAGA, LVL(8, 14, 2, 10, 4), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_SPIT, AD_ACID, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2600, 400, MS_MUMBLE, MZ_HUGE), MR_POISON | MR_ACID | MR_STONE, MR_POISON | MR_ACID | MR_STONE, M1_NOLIMBS | M1_SLITHY | M1_THICK_HIDE | M1_OVIPAROUS | M1_ACID | M1_NOTAKE | M1_CARNIVORE, M2_STRONG, 0, 10, CLR_BLACK, "BLACK_NAGA");
    addMonster(ml,"", "", "golden naga", S_NAGA, LVL(10, 14, 2, 70, 5), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_MAGC, AD_SPEL, 4, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2600, 400, MS_MUMBLE, MZ_HUGE), MR_POISON, MR_POISON, M1_NOLIMBS | M1_SLITHY | M1_THICK_HIDE | M1_OVIPAROUS | M1_NOTAKE | M1_OMNIVORE, M2_STRONG, 0, 13, HI_GOLD, "GOLDEN_NAGA");
    addMonster(ml,"", "", "guardian naga", S_NAGA, LVL(12, 16, 0, 50, 7), (G_GENO | 1), ATTK(AT_SPIT, AD_DRST, 1, 6), ATTK(AT_BITE, AD_PLYS, 1, 6), ATTK(AT_TUCH, AD_PHYS, 0, 0), ATTK(AT_HUGS, AD_WRAP, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2600, 400, MS_MUMBLE, MZ_HUGE), MR_POISON, MR_POISON, M1_NOLIMBS | M1_SLITHY | M1_THICK_HIDE | M1_OVIPAROUS | M1_POIS | M1_NOTAKE | M1_OMNIVORE, M2_STRONG, 0, 17, CLR_GREEN, "GUARDIAN_NAGA");
    addMonster(ml,"", "", "ogre", S_OGRE, LVL(5, 10, 5, 0, -3), (G_SGROUP | G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 2, 5), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1600, 500, MS_GRUNT, MZ_LARGE), 0, 0, M1_HUMANOID | M1_CARNIVORE, M2_STRONG | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 7, CLR_BROWN, "OGRE");
    addMonster(ml, "ogre lord", "ogre lady", "ogre leader", S_OGRE, LVL(7, 12, 3, 30, -5), (G_GENO | 2), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1700, 700, MS_GRUNT, MZ_LARGE), 0, 0, M1_HUMANOID | M1_CARNIVORE, M2_STRONG | M2_LORD | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 9, CLR_RED, "OGRE_LEADER");
    addMonster(ml, "ogre king", "ogre queen", "ogre tyrant", S_OGRE, LVL(9, 14, 4, 60, -7), (G_GENO | 2), ATTK(AT_WEAP, AD_PHYS, 3, 5), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1700, 750, MS_GRUNT, MZ_LARGE), 0, 0, M1_HUMANOID | M1_CARNIVORE, M2_STRONG | M2_PRINCE | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 11, HI_LORD, "OGRE_TYRANT");
    addMonster(ml,"", "", "gray ooze", S_PUDDING, LVL(3, 1, 8, 0, 0), (G_GENO | G_NOCORPSE | 2), ATTK(AT_BITE, AD_RUST, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(500, 250, MS_SILENT, MZ_MEDIUM), MR_FIRE | MR_COLD | MR_POISON | MR_ACID | MR_STONE, MR_FIRE | MR_COLD | MR_POISON, M1_BREATHLESS | M1_AMORPHOUS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_OMNIVORE | M1_ACID, M2_HOSTILE | M2_NEUTER, 0, 4, CLR_GRAY, "GRAY_OOZE");
    addMonster(ml,"", "", "brown pudding", S_PUDDING, LVL(5, 3, 8, 0, 0), (G_GENO | G_NOCORPSE | 1), ATTK(AT_BITE, AD_DCAY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(500, 250, MS_SILENT, MZ_MEDIUM), MR_COLD | MR_ELEC | MR_POISON | MR_ACID | MR_STONE, MR_COLD | MR_ELEC | MR_POISON, M1_BREATHLESS | M1_AMORPHOUS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_OMNIVORE | M1_ACID, M2_HOSTILE | M2_NEUTER, 0, 6, CLR_BROWN, "BROWN_PUDDING");
    addMonster(ml,"", "", "green slime", S_PUDDING, LVL(6, 6, 6, 0, 0), (G_HELL | G_GENO | G_NOCORPSE | 1), ATTK(AT_TUCH, AD_SLIM, 1, 4), ATTK(AT_NONE, AD_SLIM, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(400, 150, MS_SILENT, MZ_LARGE), MR_COLD | MR_ELEC | MR_POISON | MR_ACID | MR_STONE, MR_ACID | MR_STONE, M1_BREATHLESS | M1_AMORPHOUS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_OMNIVORE | M1_ACID | M1_POIS, M2_HOSTILE | M2_NEUTER, 0, 8, CLR_GREEN, "GREEN_SLIME");
    addMonster(ml,"", "", "black pudding", S_PUDDING, LVL(10, 6, 6, 0, 0), (G_GENO | G_NOCORPSE | 1), ATTK(AT_BITE, AD_CORR, 3, 8), ATTK(AT_NONE, AD_CORR, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(900, 250, MS_SILENT, MZ_LARGE), MR_COLD | MR_ELEC | MR_POISON | MR_ACID | MR_STONE, MR_COLD | MR_ELEC | MR_POISON, M1_BREATHLESS | M1_AMORPHOUS | M1_NOEYES | M1_NOLIMBS | M1_NOHEAD | M1_MINDLESS | M1_OMNIVORE | M1_ACID, M2_HOSTILE | M2_NEUTER, 0, 12, CLR_BLACK, "BLACK_PUDDING");
    addMonster(ml,"", "", "quantum mechanic", S_QUANTMECH, LVL(7, 12, 3, 10, 0), (G_GENO | 3), ATTK(AT_CLAW, AD_TLPT, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 20, MS_HUMANOID, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE | M1_POIS | M1_TPORT, M2_HOSTILE, M3_INFRAVISIBLE, 9, CLR_CYAN, "QUANTUM_MECHANIC");
    addMonster(ml,"", "", "genetic engineer", S_QUANTMECH, LVL(12, 12, 3, 10, 0), (G_GENO | 1), ATTK(AT_CLAW, AD_POLY, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 20, MS_HUMANOID, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE | M1_POIS | M1_TPORT, M2_HOSTILE | M2_NASTY, M3_INFRAVISIBLE, 14, CLR_GREEN, "GENETIC_ENGINEER");
    addMonster(ml,"", "", "rust monster", S_RUSTMONST, LVL(5, 18, 2, 0, 0), (G_GENO | 2), ATTK(AT_TUCH, AD_RUST, 0, 0), ATTK(AT_TUCH, AD_RUST, 0, 0), ATTK(AT_NONE, AD_RUST, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1000, 250, MS_SILENT, MZ_MEDIUM), 0, 0, M1_SWIM | M1_ANIMAL | M1_NOHANDS | M1_METALLIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 8, CLR_BROWN, "RUST_MONSTER");
    addMonster(ml,"", "", "disenchanter", S_RUSTMONST, LVL(12, 12, -10, 0, -3), (G_HELL | G_GENO | 2), ATTK(AT_CLAW, AD_ENCH, 4, 4), ATTK(AT_NONE, AD_ENCH, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(750, 200, MS_GROWL, MZ_LARGE), 0, 0, M1_ANIMAL | M1_CARNIVORE, M2_HOSTILE, M3_INFRAVISIBLE, 14, CLR_BLUE, "DISENCHANTER");
    addMonster(ml,"", "", "garter snake", S_SNAKE, LVL(1, 8, 8, 0, 0), (G_LGROUP | G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 1, 2), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(50, 60, MS_HISS, MZ_TINY), 0, 0, M1_SWIM | M1_CONCEAL | M1_NOLIMBS | M1_ANIMAL | M1_SLITHY | M1_OVIPAROUS | M1_CARNIVORE | M1_NOTAKE, 0, 0, 3, CLR_GREEN, "GARTER_SNAKE");
    addMonster(ml,"", "", "snake", S_SNAKE, LVL(4, 15, 3, 0, 0), (G_GENO | 2), ATTK(AT_BITE, AD_DRST, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(100, 80, MS_HISS, MZ_SMALL), MR_POISON, MR_POISON, M1_SWIM | M1_CONCEAL | M1_NOLIMBS | M1_ANIMAL | M1_SLITHY | M1_POIS | M1_OVIPAROUS | M1_CARNIVORE | M1_NOTAKE, M2_HOSTILE, 0, 6, CLR_BROWN, "SNAKE");
    addMonster(ml,"", "", "water moccasin", S_SNAKE, LVL(4, 15, 3, 0, 0), (G_GENO | G_NOGEN | G_LGROUP), ATTK(AT_BITE, AD_DRST, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(150, 80, MS_HISS, MZ_SMALL), MR_POISON, MR_POISON, M1_SWIM | M1_CONCEAL | M1_NOLIMBS | M1_ANIMAL | M1_SLITHY | M1_POIS | M1_CARNIVORE | M1_OVIPAROUS | M1_NOTAKE, M2_HOSTILE, 0, 7, CLR_RED, "WATER_MOCCASIN");
    addMonster(ml,"", "", "python", S_SNAKE, LVL(6, 3, 5, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_TUCH, AD_PHYS, 0, 0), ATTK(AT_HUGS, AD_WRAP, 1, 4), ATTK(AT_HUGS, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(250, 100, MS_HISS, MZ_LARGE), 0, 0, M1_SWIM | M1_NOLIMBS | M1_ANIMAL | M1_SLITHY | M1_CARNIVORE | M1_OVIPAROUS | M1_NOTAKE, M2_HOSTILE | M2_STRONG, M3_INFRAVISION, 8, CLR_MAGENTA, "PYTHON");
    addMonster(ml,"", "", "pit viper", S_SNAKE, LVL(6, 15, 2, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_DRST, 1, 4), ATTK(AT_BITE, AD_DRST, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(100, 60, MS_HISS, MZ_MEDIUM), MR_POISON, MR_POISON, M1_SWIM | M1_CONCEAL | M1_NOLIMBS | M1_ANIMAL | M1_SLITHY | M1_POIS | M1_CARNIVORE | M1_OVIPAROUS | M1_NOTAKE, M2_HOSTILE, M3_INFRAVISION, 9, CLR_BLUE, "PIT_VIPER");
    addMonster(ml,"", "", "cobra", S_SNAKE, LVL(6, 18, 2, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_DRST, 2, 4), ATTK(AT_SPIT, AD_BLND, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(250, 100, MS_HISS, MZ_MEDIUM), MR_POISON, MR_POISON, M1_SWIM | M1_CONCEAL | M1_NOLIMBS | M1_ANIMAL | M1_SLITHY | M1_POIS | M1_CARNIVORE | M1_OVIPAROUS | M1_NOTAKE, M2_HOSTILE, 0, 10, CLR_BLUE, "COBRA");
    addMonster(ml,"", "", "troll", S_TROLL, LVL(7, 12, 4, 0, -3), (G_GENO | 2), ATTK(AT_WEAP, AD_PHYS, 4, 2), ATTK(AT_CLAW, AD_PHYS, 4, 2), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(800, 350, MS_GRUNT, MZ_LARGE), 0, 0, M1_HUMANOID | M1_REGEN | M1_CARNIVORE, M2_STRONG | M2_STALK | M2_HOSTILE, M3_INFRAVISIBLE | M3_INFRAVISION, 9, CLR_BROWN, "TROLL");
    addMonster(ml,"", "", "ice troll", S_TROLL, LVL(9, 10, 2, 20, -3), (G_NOHELL | G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_CLAW, AD_COLD, 2, 6), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1000, 300, MS_GRUNT, MZ_LARGE), MR_COLD, MR_COLD, M1_HUMANOID | M1_REGEN | M1_CARNIVORE, M2_STRONG | M2_STALK | M2_HOSTILE, M3_INFRAVISIBLE | M3_INFRAVISION, 12, CLR_WHITE, "ICE_TROLL");
    addMonster(ml,"", "", "rock troll", S_TROLL, LVL(9, 12, 0, 0, -3), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 3, 6), ATTK(AT_CLAW, AD_PHYS, 2, 8), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1200, 300, MS_GRUNT, MZ_LARGE), 0, 0, M1_HUMANOID | M1_REGEN | M1_CARNIVORE, M2_STRONG | M2_STALK | M2_HOSTILE | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 12, CLR_CYAN, "ROCK_TROLL");
    addMonster(ml,"", "", "water troll", S_TROLL, LVL(11, 14, 4, 40, -3), (G_NOGEN | G_GENO), ATTK(AT_WEAP, AD_PHYS, 2, 8), ATTK(AT_CLAW, AD_PHYS, 2, 8), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1200, 350, MS_GRUNT, MZ_LARGE), 0, 0, M1_HUMANOID | M1_REGEN | M1_CARNIVORE | M1_SWIM, M2_STRONG | M2_STALK | M2_HOSTILE, M3_INFRAVISIBLE | M3_INFRAVISION, 13, CLR_BLUE, "WATER_TROLL");
    addMonster(ml,"", "", "Olog-hai", S_TROLL, LVL(13, 12, -4, 0, -7), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 3, 6), ATTK(AT_CLAW, AD_PHYS, 2, 8), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 400, MS_GRUNT, MZ_LARGE), 0, 0, M1_HUMANOID | M1_REGEN | M1_CARNIVORE, M2_STRONG | M2_STALK | M2_HOSTILE | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 16, HI_LORD, "OLOG_HAI");
    addMonster(ml,"", "", "umber hulk", S_UMBER, LVL(9, 6, 2, 25, 0), (G_GENO | 2), ATTK(AT_CLAW, AD_PHYS, 3, 4), ATTK(AT_CLAW, AD_PHYS, 3, 4), ATTK(AT_BITE, AD_PHYS, 2, 5), ATTK(AT_GAZE, AD_CONF, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1200, 500, MS_SILENT, MZ_LARGE), 0, 0, M1_TUNNEL | M1_CARNIVORE, M2_STRONG, M3_INFRAVISIBLE, 12, CLR_BROWN, "UMBER_HULK");
    addMonster(ml,"", "", "vampire", S_VAMPIRE, LVL(10, 12, 1, 25, -8), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_BITE, AD_DRLI, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_VAMPIRE, MZ_HUMAN), MR_SLEEP | MR_POISON, 0, M1_FLY | M1_BREATHLESS | M1_HUMANOID | M1_POIS | M1_REGEN, M2_UNDEAD | M2_STALK | M2_HOSTILE | M2_STRONG | M2_NASTY | M2_SHAPESHIFTER, M3_INFRAVISIBLE, 12, CLR_RED, "VAMPIRE");
    addMonster(ml, "vampire lord", "vampire lady", "vampire leader", S_VAMPIRE, LVL(12, 14, 0, 50, -9), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 8), ATTK(AT_BITE, AD_DRLI, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_VAMPIRE, MZ_HUMAN), MR_SLEEP | MR_POISON, 0, M1_FLY | M1_BREATHLESS | M1_HUMANOID | M1_POIS | M1_REGEN, M2_UNDEAD | M2_STALK | M2_HOSTILE | M2_STRONG | M2_NASTY | M2_LORD | M2_SHAPESHIFTER, M3_INFRAVISIBLE, 14, CLR_BLUE, "VAMPIRE_LEADER");
    addMonster(ml,"", "", "vampire mage", S_VAMPIRE, LVL(20, 14, -4, 50, -9), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_DRLI, 2, 8), ATTK(AT_BITE, AD_DRLI, 1, 8), ATTK(AT_MAGC, AD_SPEL, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_VAMPIRE, MZ_HUMAN), MR_SLEEP | MR_POISON, 0, M1_FLY | M1_BREATHLESS | M1_HUMANOID | M1_POIS | M1_REGEN, M2_UNDEAD | M2_STALK | M2_HOSTILE | M2_STRONG | M2_NASTY | M2_LORD | M2_MALE | M2_MAGIC | M2_SHAPESHIFTER, M3_INFRAVISIBLE, 26, HI_ZAP, "VAMPIRE_MAGE");
    addMonster(ml,"", "", "Vlad the Impaler", S_VAMPIRE, LVL(28, 26, -6, 80, -10), (G_NOGEN | G_NOCORPSE | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 2, 10), ATTK(AT_BITE, AD_DRLI, 1, 12), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_VAMPIRE, MZ_HUMAN), MR_SLEEP | MR_POISON, 0, M1_FLY | M1_BREATHLESS | M1_HUMANOID | M1_POIS | M1_REGEN, M2_NOPOLY | M2_UNDEAD | M2_STALK | M2_HOSTILE | M2_PNAME | M2_STRONG | M2_NASTY | M2_PRINCE | M2_MALE | M2_SHAPESHIFTER, M3_WAITFORU | M3_WANTSCAND | M3_INFRAVISIBLE, 32, HI_LORD, "VLAD_THE_IMPALER");
    addMonster(ml,"", "", "barrow wight", S_WRAITH, LVL(3, 12, 5, 5, -3), (G_GENO | G_NOCORPSE | 1), ATTK(AT_WEAP, AD_DRLI, 0, 0), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_TUCH, AD_COLD, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1200, 0, MS_SPELL, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_HUMANOID, M2_UNDEAD | M2_STALK | M2_HOSTILE | M2_COLLECT, 0, 8, CLR_GRAY, "BARROW_WIGHT");
    addMonster(ml,"", "", "wraith", S_WRAITH, LVL(6, 12, 4, 15, -6), (G_GENO | 2), ATTK(AT_TUCH, AD_DRLI, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(0, 0, MS_SILENT, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON | MR_STONE, 0, M1_BREATHLESS | M1_FLY | M1_HUMANOID | M1_UNSOLID, M2_UNDEAD | M2_STALK | M2_HOSTILE, 0, 8, CLR_BLACK, "WRAITH");
}
void ResourceData::buildMonsterList4(std::vector<cmonster>& ml)
{
    addMonster(ml,"", "", "Nazgul", S_WRAITH, LVL(13, 12, 0, 25, -17), (G_GENO | G_NOCORPSE | 1), ATTK(AT_WEAP, AD_DRLI, 1, 4), ATTK(AT_BREA, AD_SLEE, 2, 25), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 0, MS_SPELL, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_HUMANOID | M1_SEE_INVIS, M2_NOPOLY | M2_UNDEAD | M2_STALK | M2_STRONG | M2_HOSTILE | M2_MALE | M2_COLLECT, 0, 17, HI_LORD, "NAZGUL");
    addMonster(ml,"", "", "xorn", S_XORN, LVL(8, 9, -2, 20, 0), (G_GENO | 1), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_BITE, AD_PHYS, 4, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1200, 700, MS_ROAR, MZ_MEDIUM), MR_FIRE | MR_COLD | MR_STONE, MR_STONE, M1_BREATHLESS | M1_WALLWALK | M1_THICK_HIDE | M1_METALLIVORE, M2_HOSTILE | M2_STRONG, 0, 11, CLR_BROWN, "XORN");
    addMonster(ml,"", "", "monkey", S_YETI, LVL(2, 12, 6, 0, 0), (G_GENO | 1), ATTK(AT_CLAW, AD_SITM, 0, 0), ATTK(AT_BITE, AD_PHYS, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(100, 50, MS_GROWL, MZ_SMALL), 0, 0, M1_ANIMAL | M1_HUMANOID | M1_OMNIVORE, 0, M3_INFRAVISIBLE, 4, CLR_GRAY, "MONKEY");
    addMonster(ml,"", "", "ape", S_YETI, LVL(4, 12, 6, 0, 0), (G_GENO | G_SGROUP | 2), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1100, 500, MS_GROWL, MZ_LARGE), 0, 0, M1_ANIMAL | M1_HUMANOID | M1_OMNIVORE, M2_STRONG, M3_INFRAVISIBLE, 6, CLR_BROWN, "APE");
    addMonster(ml,"", "", "owlbear", S_YETI, LVL(5, 12, 5, 0, 0), (G_GENO | 3), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_HUGS, AD_PHYS, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1700, 700, MS_ROAR, MZ_LARGE), 0, 0, M1_ANIMAL | M1_HUMANOID | M1_CARNIVORE, M2_HOSTILE | M2_STRONG | M2_NASTY, M3_INFRAVISIBLE, 7, CLR_BROWN, "OWLBEAR");
    addMonster(ml,"", "", "yeti", S_YETI, LVL(5, 15, 6, 0, 0), (G_GENO | 2), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1600, 700, MS_GROWL, MZ_LARGE), MR_COLD, MR_COLD, M1_ANIMAL | M1_HUMANOID | M1_CARNIVORE, M2_HOSTILE | M2_STRONG, M3_INFRAVISIBLE, 7, CLR_WHITE, "YETI");
    addMonster(ml,"", "", "carnivorous ape", S_YETI, LVL(6, 12, 6, 0, 0), (G_GENO | 1), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_HUGS, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1250, 550, MS_GROWL, MZ_LARGE), 0, 0, M1_ANIMAL | M1_HUMANOID | M1_CARNIVORE, M2_HOSTILE | M2_STRONG, M3_INFRAVISIBLE, 8, CLR_BLACK, "CARNIVOROUS_APE");
    addMonster(ml,"", "", "sasquatch", S_YETI, LVL(7, 15, 6, 0, 2), (G_GENO | 1), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_KICK, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1550, 750, MS_GROWL, MZ_LARGE), 0, 0, M1_ANIMAL | M1_HUMANOID | M1_SEE_INVIS | M1_OMNIVORE, M2_STRONG, M3_INFRAVISIBLE, 9, CLR_GRAY, "SASQUATCH");
    addMonster(ml,"", "", "kobold zombie", S_ZOMBIE, LVL(0, 6, 10, 0, -2), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(400, 50, MS_GROAN, MZ_SMALL), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_POIS, M2_UNDEAD | M2_STALK | M2_HOSTILE, M3_INFRAVISION, 1, CLR_BROWN, "KOBOLD_ZOMBIE");
    addMonster(ml,"", "", "gnome zombie", S_ZOMBIE, LVL(1, 6, 10, 0, -2), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 5), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(650, 50, MS_GROAN, MZ_SMALL), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_POIS, M2_UNDEAD | M2_STALK | M2_HOSTILE | M2_GNOME, M3_INFRAVISION, 2, CLR_BROWN, "GNOME_ZOMBIE");
    addMonster(ml,"", "", "orc zombie", S_ZOMBIE, LVL(2, 6, 9, 0, -3), (G_GENO | G_SGROUP | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(850, 75, MS_GROAN, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_POIS, M2_UNDEAD | M2_STALK | M2_HOSTILE | M2_ORC, M3_INFRAVISION, 3, CLR_GRAY, "ORC_ZOMBIE");
    addMonster(ml,"", "", "dwarf zombie", S_ZOMBIE, LVL(2, 6, 9, 0, -3), (G_GENO | G_SGROUP | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(900, 150, MS_GROAN, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_POIS, M2_UNDEAD | M2_STALK | M2_HOSTILE | M2_DWARF, M3_INFRAVISION, 3, CLR_RED, "DWARF_ZOMBIE");
    addMonster(ml,"", "", "elf zombie", S_ZOMBIE, LVL(3, 6, 9, 0, -3), (G_GENO | G_SGROUP | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 7), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_ELF, 175, MS_GROAN, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID, M2_UNDEAD | M2_STALK | M2_HOSTILE | M2_ELF, M3_INFRAVISION, 4, CLR_GREEN, "ELF_ZOMBIE");
    addMonster(ml,"", "", "human zombie", S_ZOMBIE, LVL(4, 6, 8, 0, -3), (G_GENO | G_SGROUP | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 200, MS_GROAN, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID, M2_UNDEAD | M2_STALK | M2_HOSTILE, M3_INFRAVISION, 5, HI_DOMESTIC, "HUMAN_ZOMBIE");
    addMonster(ml,"", "", "ettin zombie", S_ZOMBIE, LVL(6, 8, 6, 0, -4), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 10), ATTK(AT_CLAW, AD_PHYS, 1, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1700, 250, MS_GROAN, MZ_HUGE), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID, M2_UNDEAD | M2_STALK | M2_HOSTILE | M2_STRONG, M3_INFRAVISION, 7, CLR_BLUE, "ETTIN_ZOMBIE");
    addMonster(ml,"", "", "ghoul", S_ZOMBIE, LVL(3, 6, 10, 0, -2), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PLYS, 1, 2), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(400, 50, MS_SILENT, MZ_SMALL), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_POIS | M1_OMNIVORE, M2_UNDEAD | M2_WANDER | M2_HOSTILE, M3_INFRAVISION, 5, CLR_BLACK, "GHOUL");
    addMonster(ml,"", "", "giant zombie", S_ZOMBIE, LVL(8, 8, 6, 0, -4), (G_GENO | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 2, 8), ATTK(AT_CLAW, AD_PHYS, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2050, 375, MS_GROAN, MZ_HUGE), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID, M2_UNDEAD | M2_STALK | M2_HOSTILE | M2_GIANT | M2_STRONG, M3_INFRAVISION, 9, CLR_CYAN, "GIANT_ZOMBIE");
    addMonster(ml,"", "", "skeleton", S_ZOMBIE, LVL(12, 8, 4, 0, 0), (G_NOCORPSE | G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_TUCH, AD_SLOW, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(300, 5, MS_BONES, MZ_HUMAN), MR_COLD | MR_SLEEP | MR_POISON | MR_STONE, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_THICK_HIDE, M2_UNDEAD | M2_WANDER | M2_HOSTILE | M2_STRONG | M2_COLLECT | M2_NASTY, M3_INFRAVISION, 14, CLR_WHITE, "SKELETON");
    addMonster(ml,"", "", "straw golem", S_GOLEM, LVL(3, 12, 10, 0, 0), (G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 2), ATTK(AT_CLAW, AD_PHYS, 1, 2), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(400, 0, MS_SILENT, MZ_LARGE), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID, M2_HOSTILE | M2_NEUTER, 0, 4, CLR_YELLOW, "STRAW_GOLEM");
    addMonster(ml,"", "", "paper golem", S_GOLEM, LVL(3, 12, 10, 0, 0), (G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(400, 0, MS_SILENT, MZ_LARGE), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID, M2_HOSTILE | M2_NEUTER, 0, 4, HI_PAPER, "PAPER_GOLEM");
    addMonster(ml,"", "", "rope golem", S_GOLEM, LVL(4, 9, 8, 0, 0), (G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_HUGS, AD_PHYS, 6, 1), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(450, 0, MS_SILENT, MZ_LARGE), MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID, M2_HOSTILE | M2_NEUTER, 0, 6, CLR_BROWN, "ROPE_GOLEM");
    addMonster(ml,"", "", "gold golem", S_GOLEM, LVL(5, 9, 6, 0, 0), (G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 2, 3), ATTK(AT_CLAW, AD_PHYS, 2, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(450, 0, MS_SILENT, MZ_LARGE), MR_SLEEP | MR_POISON | MR_ACID, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_THICK_HIDE, M2_HOSTILE | M2_NEUTER, 0, 6, HI_GOLD, "GOLD_GOLEM");
    addMonster(ml,"", "", "leather golem", S_GOLEM, LVL(6, 6, 6, 0, 0), (G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_CLAW, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(800, 0, MS_SILENT, MZ_LARGE), MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID, M2_HOSTILE | M2_NEUTER, 0, 7, HI_LEATHER, "LEATHER_GOLEM");
    addMonster(ml,"", "", "wood golem", S_GOLEM, LVL(7, 3, 4, 0, 0), (G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 3, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(900, 0, MS_SILENT, MZ_LARGE), MR_COLD | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_THICK_HIDE, M2_HOSTILE | M2_NEUTER, 0, 8, HI_WOOD, "WOOD_GOLEM");
    addMonster(ml,"", "", "flesh golem", S_GOLEM, LVL(9, 8, 9, 30, 0), (1), ATTK(AT_CLAW, AD_PHYS, 2, 8), ATTK(AT_CLAW, AD_PHYS, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1400, 600, MS_SILENT, MZ_LARGE), MR_FIRE | MR_COLD | MR_ELEC | MR_SLEEP | MR_POISON, MR_FIRE | MR_COLD | MR_ELEC | MR_SLEEP | MR_POISON, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID, M2_HOSTILE | M2_STRONG, 0, 10, CLR_RED, "FLESH_GOLEM");
    addMonster(ml,"", "", "clay golem", S_GOLEM, LVL(11, 7, 7, 40, 0), (G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 3, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1550, 0, MS_SILENT, MZ_LARGE), MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_THICK_HIDE, M2_HOSTILE | M2_STRONG, 0, 12, CLR_BROWN, "CLAY_GOLEM");
    addMonster(ml,"", "", "stone golem", S_GOLEM, LVL(14, 6, 5, 50, 0), (G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 3, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1900, 0, MS_SILENT, MZ_LARGE), MR_SLEEP | MR_POISON | MR_STONE, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_THICK_HIDE, M2_HOSTILE | M2_STRONG, 0, 15, CLR_GRAY, "STONE_GOLEM");
    addMonster(ml,"", "", "glass golem", S_GOLEM, LVL(16, 6, 1, 50, 0), (G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 2, 8), ATTK(AT_CLAW, AD_PHYS, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1800, 0, MS_SILENT, MZ_LARGE), MR_SLEEP | MR_POISON | MR_ACID, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_THICK_HIDE, M2_HOSTILE | M2_STRONG, 0, 18, CLR_CYAN, "GLASS_GOLEM");
    addMonster(ml,"", "", "iron golem", S_GOLEM, LVL(18, 6, 3, 60, 0), (G_NOCORPSE | 1), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_BREA, AD_DRST, 4, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2000, 0, MS_SILENT, MZ_LARGE), MR_FIRE | MR_COLD | MR_ELEC | MR_SLEEP | MR_POISON, 0, M1_BREATHLESS | M1_MINDLESS | M1_HUMANOID | M1_THICK_HIDE | M1_POIS, M2_HOSTILE | M2_STRONG | M2_COLLECT, 0, 22, HI_METAL, "IRON_GOLEM");
    addMonster(ml,"", "", "human", S_HUMAN, LVL(0, 12, 10, 0, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 2, HI_DOMESTIC, "HUMAN");
    addMonster(ml,"", "", "wererat", S_HUMAN, LVL(2, 12, 10, 10, -7), (1), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_WERE, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_POIS | M1_REGEN | M1_OMNIVORE, M2_NOPOLY | M2_WERE | M2_HOSTILE | M2_HUMAN | M2_COLLECT, M3_INFRAVISIBLE, 3, CLR_BROWN, "HUMAN_WERERAT");
    addMonster(ml,"", "", "werejackal", S_HUMAN, LVL(2, 12, 10, 10, -7), (1), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_WERE, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_POIS | M1_REGEN | M1_OMNIVORE, M2_NOPOLY | M2_WERE | M2_HOSTILE | M2_HUMAN | M2_COLLECT, M3_INFRAVISIBLE, 3, CLR_RED, "HUMAN_WEREJACKAL");
    addMonster(ml,"", "", "werewolf", S_HUMAN, LVL(5, 12, 10, 20, -7), (1), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_WERE, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_POIS | M1_REGEN | M1_OMNIVORE, M2_NOPOLY | M2_WERE | M2_HOSTILE | M2_HUMAN | M2_COLLECT, M3_INFRAVISIBLE, 6, CLR_ORANGE, "HUMAN_WEREWOLF");
    addMonster(ml,"", "", "elf", S_HUMAN, LVL(0, 12, 10, 2, -3), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_ELF, 350, MS_HUMANOID, MZ_HUMAN), MR_SLEEP, MR_SLEEP, M1_HUMANOID | M1_OMNIVORE | M1_SEE_INVIS, M2_NOPOLY | M2_ELF | M2_COLLECT, M3_INFRAVISION | M3_INFRAVISIBLE, 1, HI_DOMESTIC, "ELF");
    addMonster(ml,"", "", "Woodland-elf", S_HUMAN, LVL(4, 12, 10, 10, -5), (G_GENO | G_SGROUP | 2), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_ELF, 350, MS_HUMANOID, MZ_HUMAN), MR_SLEEP, MR_SLEEP, M1_HUMANOID | M1_OMNIVORE | M1_SEE_INVIS, M2_ELF | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 6, CLR_GREEN, "WOODLAND_ELF");
    addMonster(ml,"", "", "Green-elf", S_HUMAN, LVL(5, 12, 10, 10, -6), (G_GENO | G_SGROUP | 2), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_ELF, 350, MS_HUMANOID, MZ_HUMAN), MR_SLEEP, MR_SLEEP, M1_HUMANOID | M1_OMNIVORE | M1_SEE_INVIS, M2_ELF | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 7, CLR_BRIGHT_GREEN, "GREEN_ELF");
    addMonster(ml,"", "", "Grey-elf", S_HUMAN, LVL(6, 12, 10, 10, -7), (G_GENO | G_SGROUP | 2), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_ELF, 350, MS_HUMANOID, MZ_HUMAN), MR_SLEEP, MR_SLEEP, M1_HUMANOID | M1_OMNIVORE | M1_SEE_INVIS, M2_ELF | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 8, CLR_GRAY, "GREY_ELF");
    addMonster(ml, "elf-lord", "elf-lady", "elf-noble", S_HUMAN, LVL(8, 12, 10, 20, -9), (G_GENO | G_SGROUP | 2), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_ELF, 350, MS_HUMANOID, MZ_HUMAN), MR_SLEEP, MR_SLEEP, M1_HUMANOID | M1_OMNIVORE | M1_SEE_INVIS, M2_ELF | M2_STRONG | M2_LORD | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 11, CLR_BRIGHT_BLUE, "ELF_NOBLE");
    addMonster(ml, "Elvenking", "Elvenqueen", "elven monarch", S_HUMAN, LVL(9, 12, 10, 25, -10), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_ELF, 350, MS_HUMANOID, MZ_HUMAN), MR_SLEEP, MR_SLEEP, M1_HUMANOID | M1_OMNIVORE | M1_SEE_INVIS, M2_ELF | M2_STRONG | M2_PRINCE | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 11, HI_LORD, "ELVEN_MONARCH");
    addMonster(ml,"", "", "doppelganger", S_HUMAN, LVL(9, 12, 5, 20, 0), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 1, 12), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_IMITATE, MZ_HUMAN), MR_SLEEP, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_HOSTILE | M2_STRONG | M2_COLLECT | M2_SHAPESHIFTER, M3_INFRAVISIBLE, 11, HI_DOMESTIC, "DOPPELGANGER");
    addMonster(ml,"", "", "shopkeeper", S_HUMAN, LVL(12, 18, 0, 50, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 4, 4), ATTK(AT_WEAP, AD_PHYS, 4, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SELL, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT | M2_MAGIC, M3_INFRAVISIBLE, 15, HI_DOMESTIC, "SHOPKEEPER");
    addMonster(ml,"", "", "guard", S_HUMAN, LVL(12, 12, 10, 40, 10), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARD, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_MERC | M2_PEACEFUL | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 14, CLR_BLUE, "GUARD");
    addMonster(ml,"", "", "prisoner", S_HUMAN, LVL(12, 12, 10, 0, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_DJINNI, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE | M3_CLOSE, 14, HI_DOMESTIC, "PRISONER");
    addMonster(ml,"", "", "Oracle", S_HUMAN, LVL(12, 0, 0, 50, 0), (G_NOGEN | G_UNIQ), ATTK(AT_NONE, AD_MAGM, 0, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_ORACLE, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_FEMALE, M3_INFRAVISIBLE, 13, HI_ZAP, "ORACLE");
    addMonster(ml, "priest", "priestess", "aligned cleric", S_HUMAN, LVL(12, 12, 10, 50, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_KICK, AD_PHYS, 1, 4), ATTK(AT_MAGC, AD_CLRC, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_PRIEST, MZ_HUMAN), MR_ELEC, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_LORD | M2_PEACEFUL | M2_COLLECT, M3_INFRAVISIBLE, 15, CLR_WHITE, "ALIGNED_CLERIC");
    addMonster(ml, "high priest", "high priestess", "high cleric", S_HUMAN, LVL(25, 15, 7, 70, 0), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_KICK, AD_PHYS, 2, 8), ATTK(AT_MAGC, AD_CLRC, 2, 8), ATTK(AT_MAGC, AD_CLRC, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_PRIEST, MZ_HUMAN), MR_FIRE | MR_ELEC | MR_SLEEP | MR_POISON, 0, M1_HUMANOID | M1_SEE_INVIS | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_MINION | M2_PRINCE | M2_NASTY | M2_COLLECT | M2_MAGIC, M3_INFRAVISIBLE, 30, CLR_WHITE, "HIGH_CLERIC");
    addMonster(ml,"", "", "soldier", S_HUMAN, LVL(6, 10, 10, 0, -2), (G_SGROUP | G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SOLDIER, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_MERC | M2_STALK | M2_HOSTILE | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 8, CLR_GRAY, "SOLDIER");
    addMonster(ml,"", "", "sergeant", S_HUMAN, LVL(8, 10, 10, 5, -3), (G_SGROUP | G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SOLDIER, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_MERC | M2_STALK | M2_HOSTILE | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 10, CLR_RED, "SERGEANT");
    addMonster(ml,"", "", "nurse", S_HUMAN, LVL(11, 6, 0, 0, 0), (G_GENO | 3), ATTK(AT_CLAW, AD_HEAL, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_NURSE, MZ_HUMAN), MR_POISON, MR_POISON, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_HOSTILE, M3_INFRAVISIBLE, 13, HI_DOMESTIC, "NURSE");
    addMonster(ml,"", "", "lieutenant", S_HUMAN, LVL(10, 10, 10, 15, -4), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 3, 4), ATTK(AT_WEAP, AD_PHYS, 3, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SOLDIER, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_MERC | M2_STALK | M2_HOSTILE | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 12, CLR_GREEN, "LIEUTENANT");
    addMonster(ml,"", "", "captain", S_HUMAN, LVL(12, 10, 10, 15, -5), (G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 4, 4), ATTK(AT_WEAP, AD_PHYS, 4, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SOLDIER, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_MERC | M2_STALK | M2_HOSTILE | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 14, CLR_BLUE, "CAPTAIN");
    addMonster(ml,"", "", "watchman", S_HUMAN, LVL(6, 10, 10, 0, -2), (G_SGROUP | G_NOGEN | G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SOLDIER, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_MERC | M2_STALK | M2_PEACEFUL | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 8, CLR_GRAY, "WATCHMAN");
    addMonster(ml,"", "", "watch captain", S_HUMAN, LVL(10, 10, 10, 15, -4), (G_NOGEN | G_GENO | 1), ATTK(AT_WEAP, AD_PHYS, 3, 4), ATTK(AT_WEAP, AD_PHYS, 3, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SOLDIER, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_MERC | M2_STALK | M2_PEACEFUL | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 12, CLR_GREEN, "WATCH_CAPTAIN");
    addMonster(ml,"", "", "Medusa", S_HUMAN, LVL(20, 12, 2, 50, -15), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_CLAW, AD_PHYS, 1, 8), ATTK(AT_GAZE, AD_STON, 0, 0), ATTK(AT_BITE, AD_DRST, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HISS, MZ_LARGE), MR_POISON | MR_STONE, MR_POISON | MR_STONE, M1_FLY | M1_SWIM | M1_AMPHIBIOUS | M1_HUMANOID | M1_POIS | M1_OMNIVORE, M2_NOPOLY | M2_HOSTILE | M2_STRONG | M2_PNAME | M2_FEMALE, M3_WAITFORU | M3_INFRAVISIBLE, 25, CLR_BRIGHT_GREEN, "MEDUSA");
    addMonster(ml,"", "", "Wizard of Yendor", S_HUMAN, LVL(30, 12, -8, 100, -128), (G_NOGEN | G_UNIQ), ATTK(AT_CLAW, AD_SAMU, 2, 12), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_CUSS, MZ_HUMAN), MR_FIRE | MR_POISON, MR_FIRE | MR_POISON, M1_FLY | M1_BREATHLESS | M1_HUMANOID | M1_REGEN | M1_SEE_INVIS | M1_TPORT | M1_TPORT_CNTRL | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_HOSTILE | M2_STRONG | M2_NASTY | M2_PRINCE | M2_MALE | M2_MAGIC, M3_COVETOUS | M3_WAITFORU | M3_INFRAVISIBLE, 34, HI_OVERLORD, "WIZARD_OF_YENDOR");
    addMonster(ml,"", "", "Croesus", S_HUMAN, LVL(20, 15, 0, 40, 15), (G_UNIQ | G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARD, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_SEE_INVIS | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STALK | M2_HOSTILE | M2_STRONG | M2_NASTY | M2_PNAME | M2_PRINCE | M2_MALE | M2_GREEDY | M2_JEWELS | M2_COLLECT | M2_MAGIC, M3_INFRAVISIBLE, 22, HI_LORD, "CROESUS");
    //addMonster(ml,"", "", "Charon", S_HUMAN, LVL(76, 18, -5, 120, 0), (G_HELL | G_NOCORPSE | G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_TUCH, AD_PLYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_FERRY, MZ_HUMAN), MR_FIRE | MR_COLD | MR_POISON | MR_STONE, 0, M1_BREATHLESS | M1_SEE_INVIS | M1_HUMANOID, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_PNAME | M2_MALE | M2_GREEDY | M2_COLLECT, M3_INFRAVISIBLE, 38, CLR_WHITE, "CHARON");
    addMonster(ml,"", "", "ghost", S_GHOST, LVL(10, 3, -5, 50, -5), (G_NOCORPSE | G_NOGEN), ATTK(AT_TUCH, AD_PHYS, 1, 1), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 0, MS_SILENT, MZ_HUMAN), MR_COLD | MR_DISINT | MR_SLEEP | MR_POISON | MR_STONE, 0, M1_FLY | M1_BREATHLESS | M1_WALLWALK | M1_HUMANOID | M1_UNSOLID, M2_NOPOLY | M2_UNDEAD | M2_STALK | M2_HOSTILE, M3_INFRAVISION, 12, CLR_GRAY, "GHOST");
    addMonster(ml,"", "", "shade", S_GHOST, LVL(12, 10, 10, 0, 0), (G_NOCORPSE | G_NOGEN), ATTK(AT_TUCH, AD_PLYS, 2, 6), ATTK(AT_TUCH, AD_SLOW, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 0, MS_WAIL, MZ_HUMAN), MR_COLD | MR_DISINT | MR_SLEEP | MR_POISON | MR_STONE, 0, M1_FLY | M1_BREATHLESS | M1_WALLWALK | M1_HUMANOID | M1_UNSOLID | M1_SEE_INVIS, M2_NOPOLY | M2_UNDEAD | M2_WANDER | M2_STALK | M2_HOSTILE | M2_NASTY, M3_INFRAVISION, 14, CLR_BLACK, "SHADE");
    addMonster(ml,"", "", "water demon", S_DEMON, LVL(8, 12, -4, 30, -7), (G_NOCORPSE | G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 3), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_BITE, AD_PHYS, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_DJINNI, MZ_HUMAN), MR_FIRE | MR_POISON, 0, M1_HUMANOID | M1_POIS | M1_SWIM, M2_NOPOLY | M2_DEMON | M2_STALK | M2_HOSTILE | M2_NASTY | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 11, CLR_BLUE, "WATER_DEMON");
    addMonster(ml, "incubus", "succubus", "amorous demon", S_DEMON, LVL(6, 12, 0, 70, -9), (G_NOCORPSE | 1), ATTK(AT_BITE, AD_SSEX, 0, 0), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SEDUCE, MZ_HUMAN), MR_FIRE | MR_POISON, 0, M1_HUMANOID | M1_FLY | M1_POIS, M2_DEMON | M2_STALK | M2_HOSTILE | M2_NASTY, M3_INFRAVISIBLE | M3_INFRAVISION, 8, CLR_GRAY, "AMOROUS_DEMON");
    addMonster(ml,"", "", "horned devil", S_DEMON, LVL(6, 9, -5, 50, 11), (G_HELL | G_NOCORPSE | 2), ATTK(AT_WEAP, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_BITE, AD_PHYS, 2, 3), ATTK(AT_STNG, AD_PHYS, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SILENT, MZ_HUMAN), MR_FIRE | MR_POISON, 0, M1_POIS | M1_THICK_HIDE, M2_DEMON | M2_STALK | M2_HOSTILE | M2_NASTY, M3_INFRAVISIBLE | M3_INFRAVISION, 9, CLR_BROWN, "HORNED_DEVIL");
    addMonster(ml,"", "", "erinys", S_DEMON, LVL(7, 12, 2, 30, 10), (G_HELL | G_NOCORPSE | G_SGROUP | 2), ATTK(AT_WEAP, AD_DRST, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SILENT, MZ_HUMAN), MR_FIRE | MR_POISON, 0, M1_HUMANOID | M1_POIS, M2_NOPOLY | M2_DEMON | M2_STALK | M2_HOSTILE | M2_STRONG | M2_NASTY | M2_FEMALE | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 10, CLR_RED, "ERINYS");
    addMonster(ml,"", "", "barbed devil", S_DEMON, LVL(8, 12, 0, 35, 8), (G_HELL | G_NOCORPSE | G_SGROUP | 2), ATTK(AT_CLAW, AD_PHYS, 2, 4), ATTK(AT_CLAW, AD_STCK, 2, 4), ATTK(AT_STNG, AD_PHYS, 3, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SILENT, MZ_HUMAN), MR_FIRE | MR_POISON, 0, M1_POIS | M1_THICK_HIDE, M2_DEMON | M2_STALK | M2_HOSTILE | M2_NASTY, M3_INFRAVISIBLE | M3_INFRAVISION, 10, CLR_RED, "BARBED_DEVIL");
    addMonster(ml,"", "", "marilith", S_DEMON, LVL(7, 12, -6, 80, -12), (G_HELL | G_NOCORPSE | 1), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_CLAW, AD_PHYS, 2, 4), ATTK(AT_CLAW, AD_PHYS, 2, 4), ATTK(AT_CLAW, AD_PHYS, 2, 4), ATTK(AT_CLAW, AD_PHYS, 2, 4), SIZ(WT_HUMAN, 400, MS_CUSS, MZ_LARGE), MR_FIRE | MR_POISON, 0, M1_HUMANOID | M1_SLITHY | M1_SEE_INVIS | M1_POIS, M2_DEMON | M2_STALK | M2_HOSTILE | M2_NASTY | M2_FEMALE | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 11, CLR_RED, "MARILITH");
    addMonster(ml,"", "", "vrock", S_DEMON, LVL(8, 12, 0, 50, -9), (G_HELL | G_NOCORPSE | G_SGROUP | 2), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 8), ATTK(AT_CLAW, AD_PHYS, 1, 8), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SILENT, MZ_LARGE), MR_FIRE | MR_POISON, 0, M1_POIS, M2_DEMON | M2_STALK | M2_HOSTILE | M2_NASTY, M3_INFRAVISIBLE | M3_INFRAVISION, 11, CLR_GREEN, "VROCK");
    addMonster(ml,"", "", "hezrou", S_DEMON, LVL(9, 6, -2, 55, -10), (G_HELL | G_NOCORPSE | G_SGROUP | 2), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_CLAW, AD_PHYS, 1, 3), ATTK(AT_BITE, AD_PHYS, 4, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SILENT, MZ_LARGE), MR_FIRE | MR_POISON, 0, M1_HUMANOID | M1_POIS, M2_DEMON | M2_STALK | M2_HOSTILE | M2_NASTY, M3_INFRAVISIBLE | M3_INFRAVISION, 12, CLR_GREEN, "HEZROU");
    addMonster(ml,"", "", "bone devil", S_DEMON, LVL(9, 15, -1, 40, -9), (G_HELL | G_NOCORPSE | G_SGROUP | 2), ATTK(AT_WEAP, AD_PHYS, 3, 4), ATTK(AT_STNG, AD_DRST, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SILENT, MZ_LARGE), MR_FIRE | MR_POISON, 0, M1_POIS, M2_DEMON | M2_STALK | M2_HOSTILE | M2_NASTY | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 13, CLR_GRAY, "BONE_DEVIL");
    addMonster(ml,"", "", "ice devil", S_DEMON, LVL(11, 6, -4, 55, -12), (G_HELL | G_NOCORPSE | 2), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_BITE, AD_PHYS, 2, 4), ATTK(AT_STNG, AD_COLD, 3, 4), ATTK(AT_TUCH, AD_SLOW, 1, 1), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SILENT, MZ_LARGE), MR_FIRE | MR_COLD | MR_POISON, 0, M1_SEE_INVIS | M1_POIS, M2_DEMON | M2_STALK | M2_HOSTILE | M2_NASTY, M3_INFRAVISIBLE | M3_INFRAVISION, 14, CLR_WHITE, "ICE_DEVIL");
    addMonster(ml,"", "", "nalfeshnee", S_DEMON, LVL(11, 9, -1, 65, -11), (G_HELL | G_NOCORPSE | 1), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_CLAW, AD_PHYS, 1, 4), ATTK(AT_BITE, AD_PHYS, 2, 4), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SPELL, MZ_LARGE), MR_FIRE | MR_POISON, 0, M1_HUMANOID | M1_POIS, M2_DEMON | M2_STALK | M2_HOSTILE | M2_NASTY, M3_INFRAVISIBLE | M3_INFRAVISION, 15, CLR_RED, "NALFESHNEE");
    addMonster(ml,"", "", "pit fiend", S_DEMON, LVL(13, 6, -3, 65, -13), (G_HELL | G_NOCORPSE | 2), ATTK(AT_WEAP, AD_PHYS, 4, 2), ATTK(AT_WEAP, AD_PHYS, 4, 2), ATTK(AT_HUGS, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GROWL, MZ_LARGE), MR_FIRE | MR_POISON, 0, M1_SEE_INVIS | M1_POIS, M2_DEMON | M2_STALK | M2_HOSTILE | M2_NASTY | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 16, CLR_RED, "PIT_FIEND");
    addMonster(ml,"", "", "sandestin", S_DEMON, LVL(13, 12, 4, 60, -5), (G_HELL | G_NOCORPSE | 1), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 400, MS_CUSS, MZ_HUMAN), MR_STONE, 0, M1_HUMANOID, M2_NOPOLY | M2_STALK | M2_STRONG | M2_COLLECT | M2_SHAPESHIFTER, M3_INFRAVISIBLE | M3_INFRAVISION, 15, CLR_GRAY, "SANDESTIN");
    addMonster(ml,"", "", "balrog", S_DEMON, LVL(16, 5, -2, 75, -14), (G_HELL | G_NOCORPSE | 1), ATTK(AT_WEAP, AD_PHYS, 8, 4), ATTK(AT_WEAP, AD_PHYS, 4, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_SILENT, MZ_LARGE), MR_FIRE | MR_POISON, 0, M1_FLY | M1_SEE_INVIS | M1_POIS, M2_DEMON | M2_STALK | M2_HOSTILE | M2_STRONG | M2_NASTY | M2_COLLECT, M3_INFRAVISIBLE | M3_INFRAVISION, 20, CLR_RED, "BALROG");
    addMonster(ml,"", "", "Juiblex", S_DEMON, LVL(50, 3, -7, 65, -15), (G_HELL | G_NOCORPSE | G_NOGEN | G_UNIQ), ATTK(AT_ENGL, AD_DISE, 4, 10), ATTK(AT_SPIT, AD_ACID, 3, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 0, MS_GURGLE, MZ_LARGE), MR_FIRE | MR_POISON | MR_ACID | MR_STONE, 0, M1_AMPHIBIOUS | M1_AMORPHOUS | M1_NOHEAD | M1_FLY | M1_SEE_INVIS | M1_ACID | M1_POIS, M2_NOPOLY | M2_DEMON | M2_STALK | M2_HOSTILE | M2_PNAME | M2_NASTY | M2_LORD | M2_MALE, M3_WAITFORU | M3_WANTSAMUL | M3_INFRAVISION, 26, CLR_BRIGHT_GREEN, "JUIBLEX");
    addMonster(ml,"", "", "Yeenoghu", S_DEMON, LVL(56, 18, -5, 80, -15), (G_HELL | G_NOCORPSE | G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 3, 6), ATTK(AT_WEAP, AD_CONF, 2, 8), ATTK(AT_CLAW, AD_PLYS, 1, 6), ATTK(AT_MAGC, AD_MAGM, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(900, 500, MS_ORC, MZ_LARGE), MR_FIRE | MR_POISON, 0, M1_FLY | M1_SEE_INVIS | M1_POIS, M2_NOPOLY | M2_DEMON | M2_STALK | M2_HOSTILE | M2_PNAME | M2_NASTY | M2_LORD | M2_MALE | M2_COLLECT, M3_WANTSAMUL | M3_INFRAVISIBLE | M3_INFRAVISION, 31, HI_LORD, "YEENOGHU");
    addMonster(ml,"", "", "Orcus", S_DEMON, LVL(66, 9, -6, 85, -20), (G_HELL | G_NOCORPSE | G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 3, 6), ATTK(AT_CLAW, AD_PHYS, 3, 4), ATTK(AT_CLAW, AD_PHYS, 3, 4), ATTK(AT_MAGC, AD_SPEL, 8, 6), ATTK(AT_STNG, AD_DRST, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_ORC, MZ_HUGE), MR_FIRE | MR_POISON, 0, M1_FLY | M1_SEE_INVIS | M1_POIS, M2_NOPOLY | M2_DEMON | M2_STALK | M2_HOSTILE | M2_PNAME | M2_NASTY | M2_PRINCE | M2_MALE | M2_COLLECT, M3_WAITFORU | M3_WANTSBOOK | M3_WANTSAMUL | M3_INFRAVISIBLE | M3_INFRAVISION, 36, HI_LORD, "ORCUS");
    addMonster(ml,"", "", "Geryon", S_DEMON, LVL(72, 3, -3, 75, 15), (G_HELL | G_NOCORPSE | G_NOGEN | G_UNIQ), ATTK(AT_CLAW, AD_PHYS, 3, 6), ATTK(AT_CLAW, AD_PHYS, 3, 6), ATTK(AT_STNG, AD_DRST, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_BRIBE, MZ_HUGE), MR_FIRE | MR_POISON, 0, M1_FLY | M1_SEE_INVIS | M1_POIS | M1_SLITHY, M2_NOPOLY | M2_DEMON | M2_STALK | M2_HOSTILE | M2_PNAME | M2_NASTY | M2_PRINCE | M2_MALE, M3_WANTSAMUL | M3_INFRAVISIBLE | M3_INFRAVISION, 36, HI_LORD, "GERYON");
    addMonster(ml,"", "", "Dispater", S_DEMON, LVL(78, 15, -2, 80, 15), (G_HELL | G_NOCORPSE | G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 6), ATTK(AT_MAGC, AD_SPEL, 6, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_BRIBE, MZ_HUMAN), MR_FIRE | MR_POISON, 0, M1_FLY | M1_SEE_INVIS | M1_POIS | M1_HUMANOID, M2_NOPOLY | M2_DEMON | M2_STALK | M2_HOSTILE | M2_PNAME | M2_NASTY | M2_PRINCE | M2_MALE | M2_COLLECT, M3_WANTSAMUL | M3_INFRAVISIBLE | M3_INFRAVISION, 40, HI_LORD, "DISPATER");
    addMonster(ml,"", "", "Baalzebub", S_DEMON, LVL(89, 9, -5, 85, 20), (G_HELL | G_NOCORPSE | G_NOGEN | G_UNIQ), ATTK(AT_BITE, AD_DRST, 2, 6), ATTK(AT_GAZE, AD_STUN, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_BRIBE, MZ_LARGE), MR_FIRE | MR_POISON, 0, M1_FLY | M1_SEE_INVIS | M1_POIS, M2_NOPOLY | M2_DEMON | M2_STALK | M2_HOSTILE | M2_PNAME | M2_NASTY | M2_PRINCE | M2_MALE, M3_WANTSAMUL | M3_WAITFORU | M3_INFRAVISIBLE | M3_INFRAVISION, 45, HI_LORD, "BAALZEBUB");
}
void ResourceData::buildMonsterList5(std::vector<cmonster>& ml)
{
    addMonster(ml,"", "", "Asmodeus", S_DEMON, LVL(105, 12, -7, 90, 20), (G_HELL | G_NOCORPSE | G_NOGEN | G_UNIQ), ATTK(AT_CLAW, AD_PHYS, 4, 4), ATTK(AT_MAGC, AD_COLD, 6, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_BRIBE, MZ_HUGE), MR_FIRE | MR_COLD | MR_POISON, 0, M1_FLY | M1_SEE_INVIS | M1_HUMANOID | M1_POIS, M2_NOPOLY | M2_DEMON | M2_STALK | M2_HOSTILE | M2_PNAME | M2_STRONG | M2_NASTY | M2_PRINCE | M2_MALE, M3_WANTSAMUL | M3_WAITFORU | M3_INFRAVISIBLE | M3_INFRAVISION, 53, HI_LORD, "ASMODEUS");
    addMonster(ml,"", "", "Demogorgon", S_DEMON, LVL(106, 15, -8, 95, -20), (G_HELL | G_NOCORPSE | G_NOGEN | G_UNIQ), ATTK(AT_MAGC, AD_SPEL, 8, 6), ATTK(AT_STNG, AD_DRLI, 1, 4), ATTK(AT_CLAW, AD_DISE, 1, 6), ATTK(AT_CLAW, AD_DISE, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 500, MS_GROWL, MZ_HUGE), MR_FIRE | MR_POISON, 0, M1_FLY | M1_SEE_INVIS | M1_NOHANDS | M1_POIS, M2_NOPOLY | M2_DEMON | M2_STALK | M2_HOSTILE | M2_PNAME | M2_NASTY | M2_PRINCE | M2_MALE, M3_WANTSAMUL | M3_INFRAVISIBLE | M3_INFRAVISION, 57, HI_LORD, "DEMOGORGON");
    addMonster(ml,"", "", "Death", S_DEMON, LVL(30, 12, -5, 100, 0), (G_UNIQ | G_NOGEN), ATTK(AT_TUCH, AD_DETH, 8, 8), ATTK(AT_TUCH, AD_DETH, 8, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 1, MS_RIDER, MZ_HUMAN), MR_FIRE | MR_COLD | MR_ELEC | MR_SLEEP | MR_POISON | MR_STONE, 0, M1_FLY | M1_HUMANOID | M1_REGEN | M1_SEE_INVIS | M1_TPORT_CNTRL, M2_NOPOLY | M2_STALK | M2_HOSTILE | M2_PNAME | M2_STRONG | M2_NASTY, M3_INFRAVISIBLE | M3_INFRAVISION | M3_DISPLACES, 34, HI_OVERLORD, "DEATH");
    addMonster(ml,"", "", "Pestilence", S_DEMON, LVL(30, 12, -5, 100, 0), (G_UNIQ | G_NOGEN), ATTK(AT_TUCH, AD_PEST, 8, 8), ATTK(AT_TUCH, AD_PEST, 8, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 1, MS_RIDER, MZ_HUMAN), MR_FIRE | MR_COLD | MR_ELEC | MR_SLEEP | MR_POISON | MR_STONE, 0, M1_FLY | M1_HUMANOID | M1_REGEN | M1_SEE_INVIS | M1_TPORT_CNTRL, M2_NOPOLY | M2_STALK | M2_HOSTILE | M2_PNAME | M2_STRONG | M2_NASTY, M3_INFRAVISIBLE | M3_INFRAVISION | M3_DISPLACES, 34, HI_OVERLORD, "PESTILENCE");
    addMonster(ml,"", "", "Famine", S_DEMON, LVL(30, 12, -5, 100, 0), (G_UNIQ | G_NOGEN), ATTK(AT_TUCH, AD_FAMN, 8, 8), ATTK(AT_TUCH, AD_FAMN, 8, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 1, MS_RIDER, MZ_HUMAN), MR_FIRE | MR_COLD | MR_ELEC | MR_SLEEP | MR_POISON | MR_STONE, 0, M1_FLY | M1_HUMANOID | M1_REGEN | M1_SEE_INVIS | M1_TPORT_CNTRL, M2_NOPOLY | M2_STALK | M2_HOSTILE | M2_PNAME | M2_STRONG | M2_NASTY, M3_INFRAVISIBLE | M3_INFRAVISION | M3_DISPLACES, 34, HI_OVERLORD, "FAMINE");
    addMonster(ml,"", "", "mail daemon", S_DEMON, LVL(56, 24, 10, 127, 0), (G_NOGEN | G_NOCORPSE), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(600, 300, MS_SILENT, MZ_HUMAN), MR_FIRE | MR_COLD | MR_ELEC | MR_SLEEP | MR_POISON | MR_STONE, 0, M1_FLY | M1_SWIM | M1_BREATHLESS | M1_SEE_INVIS | M1_HUMANOID | M1_POIS, M2_NOPOLY | M2_STALK | M2_PEACEFUL, M3_INFRAVISIBLE | M3_INFRAVISION, 26, CLR_BRIGHT_BLUE, "MAIL_DAEMON");
    addMonster(ml,"", "", "djinni", S_DEMON, LVL(7, 12, 4, 30, 0), (G_NOGEN | G_NOCORPSE), ATTK(AT_WEAP, AD_PHYS, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 400, MS_DJINNI, MZ_HUMAN), MR_POISON | MR_STONE, 0, M1_HUMANOID | M1_FLY | M1_POIS, M2_NOPOLY | M2_STALK | M2_COLLECT, M3_INFRAVISIBLE, 8, CLR_YELLOW, "DJINNI");
    addMonster(ml,"", "", "jellyfish", S_EEL, LVL(3, 3, 6, 0, 0), (G_GENO | G_NOGEN), ATTK(AT_STNG, AD_DRST, 3, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(80, 20, MS_SILENT, MZ_SMALL), MR_POISON, MR_POISON, M1_SWIM | M1_AMPHIBIOUS | M1_NOLIMBS | M1_NOHEAD | M1_NOTAKE | M1_POIS, M2_HOSTILE, 0, 5, CLR_BLUE, "JELLYFISH");
    addMonster(ml,"", "", "piranha", S_EEL, LVL(5, 18, 4, 0, 0), (G_GENO | G_NOGEN | G_SGROUP), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_BITE, AD_PHYS, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(60, 30, MS_SILENT, MZ_SMALL), 0, 0, M1_SWIM | M1_AMPHIBIOUS | M1_ANIMAL | M1_NOLIMBS | M1_CARNIVORE | M1_OVIPAROUS | M1_NOTAKE, M2_HOSTILE, 0, 7, CLR_RED, "PIRANHA");
    addMonster(ml,"", "", "shark", S_EEL, LVL(7, 12, 2, 0, 0), (G_GENO | G_NOGEN), ATTK(AT_BITE, AD_PHYS, 5, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(500, 350, MS_SILENT, MZ_LARGE), 0, 0, M1_SWIM | M1_AMPHIBIOUS | M1_ANIMAL | M1_NOLIMBS | M1_CARNIVORE | M1_OVIPAROUS | M1_THICK_HIDE | M1_NOTAKE, M2_HOSTILE, 0, 9, CLR_GRAY, "SHARK");
    addMonster(ml,"", "", "giant eel", S_EEL, LVL(5, 9, -1, 0, 0), (G_GENO | G_NOGEN), ATTK(AT_BITE, AD_PHYS, 3, 6), ATTK(AT_TUCH, AD_WRAP, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(200, 250, MS_SILENT, MZ_HUGE), 0, 0, M1_SWIM | M1_AMPHIBIOUS | M1_ANIMAL | M1_SLITHY | M1_NOLIMBS | M1_CARNIVORE | M1_OVIPAROUS | M1_NOTAKE, M2_HOSTILE, M3_INFRAVISIBLE, 7, CLR_CYAN, "GIANT_EEL");
    addMonster(ml,"", "", "electric eel", S_EEL, LVL(7, 10, -3, 0, 0), (G_GENO | G_NOGEN), ATTK(AT_BITE, AD_ELEC, 4, 6), ATTK(AT_TUCH, AD_WRAP, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(200, 250, MS_SILENT, MZ_HUGE), MR_ELEC, MR_ELEC, M1_SWIM | M1_AMPHIBIOUS | M1_ANIMAL | M1_SLITHY | M1_NOLIMBS | M1_CARNIVORE | M1_OVIPAROUS | M1_NOTAKE, M2_HOSTILE, M3_INFRAVISIBLE, 10, CLR_BRIGHT_BLUE, "ELECTRIC_EEL");
    addMonster(ml,"", "", "kraken", S_EEL, LVL(20, 3, 6, 0, -3), (G_GENO | G_NOGEN), ATTK(AT_CLAW, AD_PHYS, 2, 4), ATTK(AT_CLAW, AD_PHYS, 2, 4), ATTK(AT_HUGS, AD_WRAP, 2, 6), ATTK(AT_BITE, AD_PHYS, 5, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1800, 1000, MS_SILENT, MZ_HUGE), 0, 0, M1_SWIM | M1_AMPHIBIOUS | M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_NOPOLY | M2_HOSTILE | M2_STRONG, M3_INFRAVISIBLE, 22, CLR_RED, "KRAKEN");
    addMonster(ml,"", "", "newt", S_LIZARD, LVL(0, 6, 8, 0, 0), (G_GENO | 5), ATTK(AT_BITE, AD_PHYS, 1, 2), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(10, 20, MS_SILENT, MZ_TINY), 0, 0, M1_SWIM | M1_AMPHIBIOUS | M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, 0, 1, CLR_YELLOW, "NEWT");
    addMonster(ml,"", "", "gecko", S_LIZARD, LVL(1, 6, 8, 0, 0), (G_GENO | 5), ATTK(AT_BITE, AD_PHYS, 1, 3), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(10, 20, MS_SQEEK, MZ_TINY), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, 0, 2, CLR_GREEN, "GECKO");
    addMonster(ml,"", "", "iguana", S_LIZARD, LVL(2, 6, 7, 0, 0), (G_GENO | 5), ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(30, 30, MS_SILENT, MZ_TINY), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, 0, 3, CLR_BROWN, "IGUANA");
    addMonster(ml,"", "", "baby crocodile", S_LIZARD, LVL(3, 6, 7, 0, 0), G_GENO, ATTK(AT_BITE, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(200, 200, MS_CHIRP, MZ_MEDIUM), 0, 0, M1_SWIM | M1_AMPHIBIOUS | M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, 0, 4, CLR_BROWN, "BABY_CROCODILE");
    addMonster(ml,"", "", "lizard", S_LIZARD, LVL(5, 6, 6, 10, 0), (G_GENO | 5), ATTK(AT_BITE, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(10, 40, MS_SILENT, MZ_TINY), MR_STONE, MR_STONE, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_HOSTILE, 0, 6, CLR_GREEN, "LIZARD");
    addMonster(ml,"", "", "chameleon", S_LIZARD, LVL(6, 5, 6, 10, 0), (G_GENO | 2), ATTK(AT_BITE, AD_PHYS, 4, 2), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(100, 100, MS_SILENT, MZ_TINY), 0, 0, M1_ANIMAL | M1_NOHANDS | M1_CARNIVORE, M2_NOPOLY | M2_HOSTILE | M2_SHAPESHIFTER, 0, 7, CLR_BROWN, "CHAMELEON");
    addMonster(ml,"", "", "crocodile", S_LIZARD, LVL(6, 9, 5, 0, 0), (G_GENO | 1), ATTK(AT_BITE, AD_PHYS, 4, 2), ATTK(AT_CLAW, AD_PHYS, 1, 12), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_BELLOW, MZ_LARGE), 0, 0, M1_SWIM | M1_AMPHIBIOUS | M1_ANIMAL | M1_THICK_HIDE | M1_NOHANDS | M1_OVIPAROUS | M1_CARNIVORE, M2_STRONG | M2_HOSTILE, 0, 7, CLR_BROWN, "CROCODILE");
    addMonster(ml,"", "", "salamander", S_LIZARD, LVL(8, 12, -1, 0, -9), (G_HELL | 1), ATTK(AT_WEAP, AD_PHYS, 2, 8), ATTK(AT_TUCH, AD_FIRE, 1, 6), ATTK(AT_HUGS, AD_PHYS, 2, 6), ATTK(AT_HUGS, AD_FIRE, 3, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1500, 400, MS_MUMBLE, MZ_HUMAN), MR_SLEEP | MR_FIRE, MR_FIRE, M1_HUMANOID | M1_SLITHY | M1_THICK_HIDE | M1_POIS, M2_STALK | M2_HOSTILE | M2_COLLECT | M2_MAGIC, M3_INFRAVISIBLE, 12, CLR_ORANGE, "SALAMANDER");
    addMonster(ml,"", "", "long worm tail", S_WORM_TAIL, LVL(0, 0, 0, 0, 0), (G_NOGEN | G_NOCORPSE | G_UNIQ), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(0, 0, MS_NONE, 0), 0, 0, 0, M2_NOPOLY, 0, 1, CLR_BROWN, "LONG_WORM_TAIL");
    addMonster(ml,"", "", "archeologist", S_HUMAN, LVL(10, 12, 10, 1, 3), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_TUNNEL | M1_NEEDPICK | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 12, HI_DOMESTIC, "ARCHEOLOGIST");
    addMonster(ml,"", "", "barbarian", S_HUMAN, LVL(10, 12, 10, 1, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 12, HI_DOMESTIC, "BARBARIAN");
    addMonster(ml, "caveman", "cavewoman", "cave dweller", S_HUMAN, LVL(10, 12, 10, 0, 1), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 12, HI_DOMESTIC, "CAVE_DWELLER");
    addMonster(ml,"", "", "healer", S_HUMAN, LVL(10, 12, 10, 1, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 12, HI_DOMESTIC, "HEALER");
    addMonster(ml,"", "", "knight", S_HUMAN, LVL(10, 12, 10, 1, 3), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 12, HI_DOMESTIC, "KNIGHT");
    addMonster(ml,"", "", "monk", S_HUMAN, LVL(10, 12, 10, 2, 0), (G_NOGEN), ATTK(AT_CLAW, AD_PHYS, 1, 8), ATTK(AT_KICK, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_HERBIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 11, HI_DOMESTIC, "MONK");
    addMonster(ml, "priest", "priestess", "cleric", S_HUMAN, LVL(10, 12, 10, 2, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 12, HI_DOMESTIC, "CLERIC");
    addMonster(ml,"", "", "ranger", S_HUMAN, LVL(10, 12, 10, 2, -3), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 12, HI_DOMESTIC, "RANGER");
    addMonster(ml,"", "", "rogue", S_HUMAN, LVL(10, 12, 10, 1, -3), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_GREEDY | M2_JEWELS | M2_COLLECT, M3_INFRAVISIBLE, 12, HI_DOMESTIC, "ROGUE");
    addMonster(ml,"", "", "samurai", S_HUMAN, LVL(10, 12, 10, 1, 3), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 12, HI_DOMESTIC, "SAMURAI");
    addMonster(ml,"", "", "tourist", S_HUMAN, LVL(10, 12, 10, 1, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 12, HI_DOMESTIC, "TOURIST");
    addMonster(ml,"", "", "valkyrie", S_HUMAN, LVL(10, 12, 10, 1, 1), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), MR_COLD, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_FEMALE | M2_COLLECT, M3_INFRAVISIBLE, 12, HI_DOMESTIC, "VALKYRIE");
    addMonster(ml,"", "", "wizard", S_HUMAN, LVL(10, 12, 10, 3, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_COLLECT | M2_MAGIC, M3_INFRAVISIBLE, 12, HI_DOMESTIC, "WIZARD");
    addMonster(ml,"", "", "Lord Carnarvon", S_HUMAN, LVL(20, 15, 0, 90, 20), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_MAGC, AD_SPEL, 4, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_LEADER, MZ_HUMAN), 0, 0, M1_TUNNEL | M1_NEEDPICK | M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PNAME | M2_PEACEFUL | M2_STRONG | M2_MALE | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISIBLE, 24, HI_LORD, "LORD_CARNARVON");
    addMonster(ml,"", "", "Pelias", S_HUMAN, LVL(20, 15, 0, 90, 0), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_LEADER, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PNAME | M2_PEACEFUL | M2_STRONG | M2_MALE | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISIBLE, 24, HI_LORD, "PELIAS");
    addMonster(ml,"", "", "Shaman Karnov", S_HUMAN, LVL(20, 15, 0, 90, 20), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_MAGC, AD_CLRC, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_LEADER, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PNAME | M2_PEACEFUL | M2_STRONG | M2_MALE | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISIBLE, 24, HI_LORD, "SHAMAN_KARNOV");
    addMonster(ml,"", "", "Earendil", S_HUMAN, LVL(20, 12, 0, 50, -20), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_ELF, 350, MS_LEADER, MZ_HUMAN), MR_SLEEP, MR_SLEEP, M1_HUMANOID | M1_SEE_INVIS | M1_OMNIVORE, M2_NOPOLY | M2_ELF | M2_HUMAN | M2_PNAME | M2_PEACEFUL | M2_STRONG | M2_MALE | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISION | M3_INFRAVISIBLE, 22, HI_LORD, "EARENDIL");
    addMonster(ml,"", "", "Elwing", S_HUMAN, LVL(20, 12, 0, 50, -20), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_ELF, 350, MS_LEADER, MZ_HUMAN), MR_SLEEP, MR_SLEEP, M1_HUMANOID | M1_SEE_INVIS | M1_OMNIVORE, M2_NOPOLY | M2_ELF | M2_HUMAN | M2_PNAME | M2_PEACEFUL | M2_STRONG | M2_FEMALE | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISION | M3_INFRAVISIBLE, 22, HI_LORD, "ELWING");
    addMonster(ml,"", "", "Hippocrates", S_HUMAN, LVL(20, 15, 0, 90, 0), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_MAGC, AD_CLRC, 3, 8), ATTK(AT_MAGC, AD_CLRC, 3, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_LEADER, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PNAME | M2_PEACEFUL | M2_STRONG | M2_MALE | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISIBLE, 26, HI_LORD, "HIPPOCRATES");
    addMonster(ml,"", "", "King Arthur", S_HUMAN, LVL(20, 15, 0, 90, 20), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_LEADER, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PNAME | M2_PEACEFUL | M2_STRONG | M2_MALE | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISIBLE, 24, HI_LORD, "KING_ARTHUR");
    addMonster(ml,"", "", "Grand Master", S_HUMAN, LVL(25, 15, 0, 90, 0), (G_NOGEN | G_UNIQ), ATTK(AT_CLAW, AD_PHYS, 4, 10), ATTK(AT_KICK, AD_PHYS, 2, 8), ATTK(AT_MAGC, AD_CLRC, 2, 8), ATTK(AT_MAGC, AD_CLRC, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_LEADER, MZ_HUMAN), MR_FIRE | MR_ELEC | MR_SLEEP | MR_POISON, 0, M1_HUMANOID | M1_SEE_INVIS | M1_HERBIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_MALE | M2_NASTY | M2_MAGIC, M3_CLOSE | M3_INFRAVISIBLE, 30, CLR_BLACK, "GRAND_MASTER");
    addMonster(ml,"", "", "Arch Priest", S_HUMAN, LVL(25, 15, 7, 90, 0), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_KICK, AD_PHYS, 2, 8), ATTK(AT_MAGC, AD_CLRC, 2, 8), ATTK(AT_MAGC, AD_CLRC, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_LEADER, MZ_HUMAN), MR_FIRE | MR_ELEC | MR_SLEEP | MR_POISON, 0, M1_HUMANOID | M1_SEE_INVIS | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_MALE | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISIBLE, 30, CLR_WHITE, "ARCH_PRIEST");
    addMonster(ml,"", "", "Orion", S_HUMAN, LVL(20, 15, 0, 90, 0), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_MAGC, AD_SPEL, 4, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2200, 700, MS_LEADER, MZ_HUGE), 0, 0, M1_HUMANOID | M1_OMNIVORE | M1_SEE_INVIS | M1_SWIM | M1_AMPHIBIOUS, M2_NOPOLY | M2_HUMAN | M2_PNAME | M2_PEACEFUL | M2_STRONG | M2_MALE | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISION | M3_INFRAVISIBLE, 24, HI_LORD, "ORION");
    addMonster(ml,"", "", "Master of Thieves", S_HUMAN, LVL(20, 15, 0, 90, -20), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_CLAW, AD_SAMU, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_LEADER, MZ_HUMAN), MR_STONE, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_MALE | M2_GREEDY | M2_JEWELS | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISIBLE, 24, HI_LORD, "MASTER_OF_THIEVES");
    addMonster(ml,"", "", "Lord Sato", S_HUMAN, LVL(20, 15, 0, 90, 20), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_LEADER, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PNAME | M2_PEACEFUL | M2_STRONG | M2_MALE | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISIBLE, 24, HI_LORD, "LORD_SATO");
    addMonster(ml,"", "", "Twoflower", S_HUMAN, LVL(20, 15, 10, 90, 0), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_LEADER, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PNAME | M2_PEACEFUL | M2_STRONG | M2_MALE | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISIBLE, 22, HI_DOMESTIC, "TWOFLOWER");
    addMonster(ml,"", "", "Norn", S_HUMAN, LVL(20, 15, 0, 90, 0), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1800, 550, MS_LEADER, MZ_HUGE), MR_COLD, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_FEMALE | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISIBLE, 24, HI_LORD, "NORN");
    addMonster(ml,"", "", "Neferet the Green", S_HUMAN, LVL(20, 15, 0, 90, 0), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 10), ATTK(AT_MAGC, AD_SPEL, 2, 8), ATTK(AT_MAGC, AD_SPEL, 2, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_LEADER, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_FEMALE | M2_PNAME | M2_PEACEFUL | M2_STRONG | M2_COLLECT | M2_MAGIC, M3_CLOSE | M3_INFRAVISIBLE, 25, CLR_GREEN, "NEFERET_THE_GREEN");
    addMonster(ml,"", "", "Minion of Huhetotl", S_DEMON, LVL(16, 12, -2, 75, -14), (G_NOCORPSE | G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 8, 4), ATTK(AT_WEAP, AD_PHYS, 4, 6), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_CLAW, AD_SAMU, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_NEMESIS, MZ_LARGE), MR_FIRE | MR_POISON | MR_STONE, 0, M1_FLY | M1_SEE_INVIS | M1_POIS, M2_NOPOLY | M2_DEMON | M2_STALK | M2_HOSTILE | M2_STRONG | M2_NASTY | M2_COLLECT, M3_WANTSARTI | M3_WAITFORU | M3_INFRAVISION | M3_INFRAVISIBLE, 23, CLR_RED, "MINION_OF_HUHETOTL");
    addMonster(ml,"", "", "Thoth Amon", S_HUMAN, LVL(16, 12, 0, 10, -14), (G_NOGEN | G_UNIQ | G_NOCORPSE), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_CLAW, AD_SAMU, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_NEMESIS, MZ_HUMAN), MR_POISON | MR_STONE, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PNAME | M2_STRONG | M2_MALE | M2_STALK | M2_HOSTILE | M2_NASTY | M2_COLLECT | M2_MAGIC, M3_WANTSARTI | M3_WAITFORU | M3_INFRAVISIBLE, 22, HI_LORD, "THOTH_AMON");
    addMonster(ml,"", "", "Chromatic Dragon", S_DRAGON, LVL(16, 12, 0, 30, -14), (G_NOGEN | G_UNIQ), ATTK(AT_BREA, AD_RBRE, 6, 6), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_CLAW, AD_SAMU, 2, 8), ATTK(AT_BITE, AD_PHYS, 4, 8), ATTK(AT_BITE, AD_PHYS, 4, 8), ATTK(AT_STNG, AD_PHYS, 1, 6), SIZ(WT_DRAGON, 1700, MS_NEMESIS, MZ_GIGANTIC), MR_FIRE | MR_COLD | MR_SLEEP | MR_DISINT | MR_ELEC | MR_POISON | MR_ACID | MR_STONE, MR_FIRE | MR_COLD | MR_SLEEP | MR_DISINT | MR_ELEC | MR_POISON | MR_ACID | MR_STONE, M1_THICK_HIDE | M1_NOHANDS | M1_CARNIVORE | M1_SEE_INVIS | M1_POIS, M2_NOPOLY | M2_HOSTILE | M2_FEMALE | M2_STALK | M2_STRONG | M2_NASTY | M2_GREEDY | M2_JEWELS | M2_MAGIC, M3_WANTSARTI | M3_WAITFORU | M3_INFRAVISION | M3_INFRAVISIBLE, 23, HI_LORD, "CHROMATIC_DRAGON");
}
void ResourceData::buildMonsterList6(std::vector<cmonster>& ml)
{
    addMonster(ml,"", "", "Goblin King", S_ORC, LVL(15, 12, 10, 0, -15), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_CLAW, AD_SAMU, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(750, 350, MS_NEMESIS, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_ORC | M2_HOSTILE | M2_STRONG | M2_STALK | M2_NASTY | M2_MALE | M2_GREEDY | M2_JEWELS | M2_COLLECT | M2_MAGIC, M3_WANTSARTI | M3_WAITFORU | M3_INFRAVISION | M3_INFRAVISIBLE, 18, HI_LORD, "GOBLIN_KING");
    addMonster(ml,"", "", "Cyclops", S_GIANT, LVL(18, 12, 0, 0, -15), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 4, 8), ATTK(AT_WEAP, AD_PHYS, 4, 8), ATTK(AT_CLAW, AD_SAMU, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(1900, 700, MS_NEMESIS, MZ_HUGE), MR_STONE, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_GIANT | M2_STRONG | M2_ROCKTHROW | M2_STALK | M2_HOSTILE | M2_NASTY | M2_MALE | M2_JEWELS | M2_COLLECT, M3_WANTSARTI | M3_WAITFORU | M3_INFRAVISION | M3_INFRAVISIBLE, 23, CLR_GRAY, "CYCLOPS");
    addMonster(ml,"", "", "Ixoth", S_DRAGON, LVL(15, 12, -1, 20, -14), (G_NOGEN | G_UNIQ), ATTK(AT_BREA, AD_FIRE, 8, 6), ATTK(AT_BITE, AD_PHYS, 4, 8), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_CLAW, AD_PHYS, 2, 4), ATTK(AT_CLAW, AD_SAMU, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_DRAGON, 1600, MS_NEMESIS, MZ_GIGANTIC), MR_FIRE | MR_STONE, MR_FIRE, M1_FLY | M1_THICK_HIDE | M1_NOHANDS | M1_CARNIVORE | M1_SEE_INVIS, M2_NOPOLY | M2_MALE | M2_PNAME | M2_HOSTILE | M2_STRONG | M2_NASTY | M2_STALK | M2_GREEDY | M2_JEWELS | M2_MAGIC, M3_WANTSARTI | M3_WAITFORU | M3_INFRAVISIBLE, 22, CLR_RED, "IXOTH");
    addMonster(ml,"", "", "Master Kaen", S_HUMAN, LVL(25, 12, -10, 10, -20), (G_NOGEN | G_UNIQ), ATTK(AT_CLAW, AD_PHYS, 16, 2), ATTK(AT_CLAW, AD_PHYS, 16, 2), ATTK(AT_MAGC, AD_CLRC, 0, 0), ATTK(AT_CLAW, AD_SAMU, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_NEMESIS, MZ_HUMAN), MR_POISON | MR_STONE, MR_POISON, M1_HUMANOID | M1_HERBIVORE | M1_SEE_INVIS, M2_NOPOLY | M2_HUMAN | M2_MALE | M2_PNAME | M2_HOSTILE | M2_STRONG | M2_NASTY | M2_STALK | M2_COLLECT | M2_MAGIC, M3_WANTSARTI | M3_WAITFORU | M3_INFRAVISIBLE, 31, HI_LORD, "MASTER_KAEN");
    addMonster(ml,"", "", "Nalzok", S_DEMON, LVL(16, 12, -2, 85, -127), (G_NOGEN | G_UNIQ | G_NOCORPSE), ATTK(AT_WEAP, AD_PHYS, 8, 4), ATTK(AT_WEAP, AD_PHYS, 4, 6), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_CLAW, AD_SAMU, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_NEMESIS, MZ_LARGE), MR_FIRE | MR_POISON | MR_STONE, 0, M1_FLY | M1_SEE_INVIS | M1_POIS, M2_NOPOLY | M2_DEMON | M2_MALE | M2_PNAME | M2_HOSTILE | M2_STRONG | M2_STALK | M2_NASTY | M2_COLLECT, M3_WANTSARTI | M3_WAITFORU | M3_INFRAVISION | M3_INFRAVISIBLE, 23, CLR_RED, "NALZOK");
    addMonster(ml,"", "", "Scorpius", S_SPIDER, LVL(15, 12, 10, 0, -15), (G_NOGEN | G_UNIQ), ATTK(AT_CLAW, AD_PHYS, 2, 6), ATTK(AT_CLAW, AD_SAMU, 2, 6), ATTK(AT_STNG, AD_DISE, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(750, 350, MS_NEMESIS, MZ_HUMAN), MR_POISON | MR_STONE, MR_POISON, M1_ANIMAL | M1_NOHANDS | M1_OVIPAROUS | M1_POIS | M1_CARNIVORE, M2_NOPOLY | M2_MALE | M2_PNAME | M2_HOSTILE | M2_STRONG | M2_STALK | M2_NASTY | M2_COLLECT | M2_MAGIC, M3_WANTSARTI | M3_WAITFORU, 17, HI_LORD, "SCORPIUS");
    addMonster(ml,"", "", "Master Assassin", S_HUMAN, LVL(15, 12, 0, 30, 18), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_DRST, 2, 6), ATTK(AT_WEAP, AD_PHYS, 2, 8), ATTK(AT_CLAW, AD_SAMU, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_NEMESIS, MZ_HUMAN), MR_STONE, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_MALE | M2_HOSTILE | M2_STALK | M2_NASTY | M2_COLLECT | M2_MAGIC, M3_WANTSARTI | M3_WAITFORU | M3_INFRAVISIBLE, 20, HI_LORD, "MASTER_ASSASSIN");
    addMonster(ml,"", "", "Ashikaga Takauji", S_HUMAN, LVL(15, 12, 0, 40, -13), (G_NOGEN | G_UNIQ | G_NOCORPSE), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_WEAP, AD_PHYS, 2, 6), ATTK(AT_CLAW, AD_SAMU, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_NEMESIS, MZ_HUMAN), MR_STONE, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PNAME | M2_HOSTILE | M2_STRONG | M2_STALK | M2_NASTY | M2_MALE | M2_COLLECT | M2_MAGIC, M3_WANTSARTI | M3_WAITFORU | M3_INFRAVISIBLE, 19, HI_LORD, "ASHIKAGA_TAKAUJI");
    addMonster(ml,"", "", "Lord Surtur", S_GIANT, LVL(15, 12, 2, 50, 12), (G_NOGEN | G_UNIQ), ATTK(AT_WEAP, AD_PHYS, 2, 10), ATTK(AT_WEAP, AD_PHYS, 2, 10), ATTK(AT_CLAW, AD_SAMU, 2, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(2250, 850, MS_NEMESIS, MZ_HUGE), MR_FIRE | MR_STONE, MR_FIRE, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_GIANT | M2_MALE | M2_PNAME | M2_HOSTILE | M2_STALK | M2_STRONG | M2_NASTY | M2_ROCKTHROW | M2_JEWELS | M2_COLLECT, M3_WANTSARTI | M3_WAITFORU | M3_INFRAVISION | M3_INFRAVISIBLE, 19, HI_LORD, "LORD_SURTUR");
    addMonster(ml,"", "", "Dark One", S_HUMAN, LVL(15, 12, 0, 80, -10), (G_NOGEN | G_UNIQ | G_NOCORPSE), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_CLAW, AD_SAMU, 1, 4), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_NEMESIS, MZ_HUMAN), MR_STONE, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_STRONG | M2_HOSTILE | M2_STALK | M2_NASTY | M2_COLLECT | M2_MAGIC, M3_WANTSARTI | M3_WAITFORU | M3_INFRAVISIBLE, 20, CLR_BLACK, "DARK_ONE");
    addMonster(ml,"", "", "student", S_HUMAN, LVL(5, 12, 10, 10, 3), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARDIAN, MZ_HUMAN), 0, 0, M1_TUNNEL | M1_NEEDPICK | M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 7, HI_DOMESTIC, "STUDENT");
    addMonster(ml,"", "", "chieftain", S_HUMAN, LVL(5, 12, 10, 10, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARDIAN, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 7, HI_DOMESTIC, "CHIEFTAIN");
    addMonster(ml,"", "", "neanderthal", S_HUMAN, LVL(5, 12, 10, 10, 1), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARDIAN, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 7, HI_DOMESTIC, "NEANDERTHAL");
    //addMonster(ml,"","","High-elf", S_HUMAN, LVL(5, 12, 10, 10, -7), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 2, 4), ATTK(AT_MAGC, AD_CLRC, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_ELF, 350, MS_GUARDIAN, MZ_HUMAN), MR_SLEEP, MR_SLEEP, M1_HUMANOID | M1_SEE_INVIS | M1_OMNIVORE, "M2_NOPOLY | M2_ELF | M2_PEACEFUL | M2_COLLEC");
    addMonster(ml,"", "", "attendant", S_HUMAN, LVL(5, 12, 10, 10, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARDIAN, MZ_HUMAN), MR_POISON, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 7, HI_DOMESTIC, "ATTENDANT");
    addMonster(ml,"", "", "page", S_HUMAN, LVL(5, 12, 10, 10, 3), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARDIAN, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 7, HI_DOMESTIC, "PAGE");
    addMonster(ml,"", "", "abbot", S_HUMAN, LVL(5, 12, 10, 20, 0), (G_NOGEN), ATTK(AT_CLAW, AD_PHYS, 8, 2), ATTK(AT_KICK, AD_STUN, 3, 2), ATTK(AT_MAGC, AD_CLRC, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARDIAN, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_HERBIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 8, HI_DOMESTIC, "ABBOT");
    addMonster(ml,"", "", "acolyte", S_HUMAN, LVL(5, 12, 10, 20, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_MAGC, AD_CLRC, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARDIAN, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 8, HI_DOMESTIC, "ACOLYTE");
    addMonster(ml,"", "", "hunter", S_HUMAN, LVL(5, 12, 10, 10, -7), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 4), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARDIAN, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_SEE_INVIS | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT, M3_INFRAVISION | M3_INFRAVISIBLE, 7, HI_DOMESTIC, "HUNTER");
    addMonster(ml,"", "", "thug", S_HUMAN, LVL(5, 12, 10, 10, -3), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARDIAN, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_GREEDY | M2_COLLECT, M3_INFRAVISIBLE, 7, HI_DOMESTIC, "THUG");
    addMonster(ml,"", "", "ninja", S_HUMAN, LVL(5, 12, 10, 10, 3), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_HUMANOID, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_HOSTILE | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 7, HI_DOMESTIC, "NINJA");
    addMonster(ml,"", "", "roshi", S_HUMAN, LVL(5, 12, 10, 10, 3), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARDIAN, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT, M3_INFRAVISIBLE, 7, HI_DOMESTIC, "ROSHI");
    addMonster(ml,"", "", "guide", S_HUMAN, LVL(5, 12, 10, 20, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARDIAN, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT | M2_MAGIC, M3_INFRAVISIBLE, 8, HI_DOMESTIC, "GUIDE");
    addMonster(ml,"", "", "warrior", S_HUMAN, LVL(5, 12, 10, 10, 1), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_WEAP, AD_PHYS, 1, 8), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARDIAN, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT | M2_FEMALE, M3_INFRAVISIBLE, 7, HI_DOMESTIC, "WARRIOR");
    addMonster(ml,"", "", "apprentice", S_HUMAN, LVL(5, 12, 10, 30, 0), (G_NOGEN), ATTK(AT_WEAP, AD_PHYS, 1, 6), ATTK(AT_MAGC, AD_SPEL, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), ATTK(AT_EMPTY, AD_EMPTY, 0, 0), SIZ(WT_HUMAN, 400, MS_GUARDIAN, MZ_HUMAN), 0, 0, M1_HUMANOID | M1_OMNIVORE, M2_NOPOLY | M2_HUMAN | M2_PEACEFUL | M2_STRONG | M2_COLLECT | M2_MAGIC, M3_INFRAVISIBLE, 8, HI_DOMESTIC, "APPRENTIC");
}





////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////




// weapon strike mode overloads the oc_dir field 
//#define PIERCE PIERCE
//#define S SLASH
//#define B WHACK



//void ResourceData::buildObjectList1()
//{
//
//    //OBJCLASS(1, ']', ILLOBJ, S_strange_obj, "illegal objects", "strange object")
//    //OBJCLASS(2, ')', WEAPON, S_weapon, "weapons", "weapon")
//    //OBJCLASS(3, '[', ARMOR, S_armor, "armor", "suit or piece of armor")
//    //OBJCLASS(4, '=', RING, S_ring, "rings", "ring")
//    //OBJCLASS(5, '"', AMULET, S_amulet, "amulets", "amulet")
//    //OBJCLASS(6, '(', TOOL, S_tool, "tools", "useful item (pick-axe, key, lamp...)")
//    //OBJCLASS(7, '%', FOOD, S_food, "food", "piece of food")
//    //OBJCLASS(8, '!', POTION, S_potion, "potions", "potion")
//    //OBJCLASS(9, '?', SCROLL, S_scroll, "scrolls", "scroll")
//    //OBJCLASS(10, '+', SPBOOK, S_book, "spellbooks", "spellbook")
//    //OBJCLASS(11, '/', WAND, S_wand, "wands", "wand")
//    //OBJCLASS2(12, '$', COIN, GOLD_SYM, S_coin, "coins", "pile of coins")
//    //OBJCLASS(13, '*', GEM, S_gem, "rocks", "gem or rock")
//    //OBJCLASS(14, '`', ROCK, S_rock, "large stones", "boulder or statue")
//    //OBJCLASS(15, '0', BALL, S_ball, "iron balls", "iron ball")
//    //OBJCLASS(16, '_', CHAIN, S_chain, "chains", "iron chain")
//    //OBJCLASS(17, '.', VENOM, S_venom, "venoms", "splash of venom")
//
//
//    ///////////////////////////////////////////////////////////////////////////////
//    ///////////////////////////////////////////////////////////////////////////////
//    ///////////////////////////////////////////////////////////////////////////////
//
//    //////
//   //slots [1] through [MAXOCLASSES-1] are indexed by class; some are
//   //used for display purposes, most aren't used; none are actual objects;
//   //note that 'real' strange object is in slot [0] but ILLOBJ_CLASS is 1
//   //so we add a dummy for it in slot [1] to simplify accessing the rest;
//   //there isn't any entry for RANDOM_CLASS (0) 
//    //////
//    //GENERIC("strange", ILLOBJ_CLASS, "GENERIC_ILLOBJ");  //[1] 
//    //GENERIC("weapon", WEAPON_CLASS, "GENERIC_WEAPON");  //[2] 
//    //GENERIC("armor", ARMOR_CLASS, "GENERIC_ARMOR");   //[3] 
//    //GENERIC("ring", RING_CLASS, "GENERIC_RING");   //[4] 
//    //GENERIC("amulet", AMULET_CLASS, "GENERIC_AMULET");  //[5] 
//    //GENERIC("tool", TOOL_CLASS, "GENERIC_TOOL");   //[6] 
//    //GENERIC("food", FOOD_CLASS, "GENERIC_FOOD");   //[7] 
//    //GENERIC("potion", POTION_CLASS, "GENERIC_POTION");  //[8] 
//    //GENERIC("scroll", SCROLL_CLASS, "GENERIC_SCROLL"); //[9] 
//    //GENERIC("spellbook", SPBOOK_CLASS, "GENERIC_SPBOOK");  //[10] 
//    //GENERIC("wand", WAND_CLASS, "GENERIC_WAND");   //[11] 
//    //GENERIC("coin", COIN_CLASS, "GENERIC_COIN");   //[12] 
//    //GENERIC("gem", GEM_CLASS, "GENERIC_GEM");    //[13] 
//    //GENERIC("large rock", ROCK_CLASS, "GENERIC_ROCK");   //[14] bldr+statue 
//    //GENERIC("iron ball", BALL_CLASS, "GENERIC_BALL");  //[15] 
//    //GENERIC("iron chain", CHAIN_CLASS, "GENERIC_CHAIN");  //[16] 
//    //GENERIC("venom", VENOM_CLASS, "GENERIC_VENOM");  //[17] 
//
//
//
//
//
//
//    //////////miscellaneous ... 
//    //////////Note: boulders and rocks are not normally created at random; the
//    ////////* probabilities only come into effect when you try to polymorph them.
//    ////////* Boulders weigh more than MAX_CARR_CAP; statues use corpsenm to take
//    ////////* on a specific type and may act as containers (both affect weight).
//    ////////
//    ////////OBJECT(OBJ("boulder", NoDes");
//    ////////BITS(1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, P_NONE, MINERAL"); 0,
//    ////////ROCK_CLASS, 100, 0, 6000, 0, 20, 20, 0, 0, 2000, HI_MINERAL, "BOULDER");
//    ////////OBJECT(OBJ("statue", NoDes");
//    ////////BITS(1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, P_NONE, MINERAL"); 0,
//    ////////ROCK_CLASS, 900, 0, 2500, 0, 20, 20, 0, 0, 2500, CLR_WHITE, "STATUE");
//    ////////
//    ////////OBJECT(OBJ("heavy iron ball", NoDes");
//    ////////BITS(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, WHACK, P_NONE, IRON"); 0,
//    ////////BALL_CLASS, 1000, 0, 480, 10, 25, 25, 0, 0, 200, HI_METAL,
//    ////////"HEAVY_IRON_BALL");
//    //////////+d4 when "very heavy" 
//    ////////OBJECT(OBJ("iron chain", NoDes");
//    ////////BITS(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, WHACK, P_NONE, IRON"); 0,
//    ////////CHAIN_CLASS, 1000, 0, 120, 0, 4, 4, 0, 0, 200, HI_METAL, "IRON_CHAIN");
//    //////////+1 both l & s 
//    ////////
//    //////////Venom is normally a transitory missile (spit by various creatures)
//    ////////* but can be wished for in wizard mode so could occur in bones data.
//    ////////
//    ////////OBJECT(OBJ("splash of blinding venom", "splash of venom"");
//    ////////BITS(0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, P_NONE, "LIQUID"); 0,
//    ////////VENOM_CLASS, 500, 0, 1, 0, 0, 0, 0, 0, 0, HI_ORGANIC, "BLINDING_VENOM");
//    ////////OBJECT(OBJ("splash of acid venom", "splash of venom"");
//    ////////BITS(0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, P_NONE, "LIQUID"); 0,
//    ////////VENOM_CLASS, 500, 0, 1, 0, 6, 6, 0, 0, 0, HI_ORGANIC, "ACID_VENOM");
//    //////////+d6 small or large 
//
//}

void ResourceData::loadProjectile(std::vector<ObjectProjectile>& projectileList)
{
    //missiles; materiel reflects the arrowhead, not the shaft 
    addProjectile(projectileList, "arrow", NoDes, 1, 55, 1, 2, 6, 6, 0, IRON, -P_BOW, HI_METAL, "ARROW");
    addProjectile(projectileList, "elven arrow", "runed arrow", 0, 20, 1, 2, 7, 6, 0, WOOD, -P_BOW, HI_WOOD, "ELVEN_ARROW");
    addProjectile(projectileList, "orcish arrow", "crude arrow", 0, 20, 1, 2, 5, 6, 0, IRON, -P_BOW, CLR_BLACK, "ORCISH_ARROW");
    addProjectile(projectileList, "silver arrow", NoDes, 1, 12, 1, 5, 6, 6, 0, SILVER, -P_BOW, HI_SILVER, "SILVER_ARROW");
    addProjectile(projectileList, "ya", "bamboo arrow", 0, 15, 1, 4, 7, 7, 1, METAL, -P_BOW, HI_METAL, "YA");
    addProjectile(projectileList, "crossbow bolt", NoDes, 1, 55, 1, 2, 4, 6, 0, IRON, -P_CROSSBOW, HI_METAL, "CROSSBOW_BOLT");
}

void ResourceData::loadWeapon(std::vector<ObjectWeapon>& weaponList)
{
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////

    //missiles that don't use a launcher 
    addWeapon(weaponList, "dart", NoDes, 1, 1, 0, 60, 1, 2, 3, 2, 0, PIERCE, -P_DART, IRON, HI_METAL, "DART");
    addWeapon(weaponList, "shuriken", "throwing star", 0, 1, 0, 35, 1, 5, 8, 6, 2, PIERCE, -P_SHURIKEN, IRON, HI_METAL, "SHURIKEN");
    addWeapon(weaponList, "boomerang", NoDes, 1, 1, 0, 15, 5, 20, 9, 9, 0, 0, -P_BOOMERANG, WOOD, HI_WOOD, "BOOMERANG");
    //spears [note: javelin used to have a separate skill from spears,
    //because the latter are primarily stabbing weapons rather than
    //throwing ones; but for playability, they've been merged together
    //under spear skill and spears can now be thrown like javelins]
    addWeapon(weaponList, "spear", NoDes, 1, 1, 0, 50, 30, 3, 6, 8, 0, PIERCE, P_SPEAR, IRON, HI_METAL, "SPEAR");
    addWeapon(weaponList, "elven spear", "runed spear", 0, 1, 0, 10, 30, 3, 7, 8, 0, PIERCE, P_SPEAR, WOOD, HI_WOOD, "ELVEN_SPEAR");
    addWeapon(weaponList, "orcish spear", "crude spear", 0, 1, 0, 13, 30, 3, 5, 8, 0, PIERCE, P_SPEAR, IRON, CLR_BLACK, "ORCISH_SPEAR");
    addWeapon(weaponList, "dwarvish spear", "stout spear", 0, 1, 0, 12, 35, 3, 8, 8, 0, PIERCE, P_SPEAR, IRON, HI_METAL, "DWARVISH_SPEAR");
    addWeapon(weaponList, "silver spear", NoDes, 1, 1, 0, 2, 36, 40, 6, 8, 0, PIERCE, P_SPEAR, SILVER, HI_SILVER, "SILVER_SPEAR");
    addWeapon(weaponList, "javelin", "throwing spear", 0, 1, 0, 10, 20, 3, 6, 6, 0, PIERCE, P_SPEAR, IRON, HI_METAL, "JAVELIN");
    //spearish; doesn't stack, not intended to be thrown 
    addWeapon(weaponList, "trident", NoDes, 1, 0, 0, 8, 25, 5, 6, 4, 0, PIERCE, P_TRIDENT, IRON, HI_METAL, "TRIDENT");
    //+1 small, +2d4 large 
    //blades; all stack 
    addWeapon(weaponList, "dagger", NoDes, 1, 1, 0, 30, 10, 4, 4, 3, 2, PIERCE, P_DAGGER, IRON, HI_METAL, "DAGGER");
    addWeapon(weaponList, "elven dagger", "runed dagger", 0, 1, 0, 10, 10, 4, 5, 3, 2, PIERCE, P_DAGGER, WOOD, HI_WOOD, "ELVEN_DAGGER");
    addWeapon(weaponList, "orcish dagger", "crude dagger", 0, 1, 0, 12, 10, 4, 3, 3, 2, PIERCE, P_DAGGER, IRON, CLR_BLACK, "ORCISH_DAGGER");
    addWeapon(weaponList, "silver dagger", NoDes, 1, 1, 0, 3, 12, 40, 4, 3, 2, PIERCE, P_DAGGER, SILVER, HI_SILVER, "SILVER_DAGGER");
    addWeapon(weaponList, "athame", NoDes, 1, 1, 0, 0, 10, 4, 4, 3, 2, SLASH, P_DAGGER, IRON, HI_METAL, "ATHAME");
    addWeapon(weaponList, "scalpel", NoDes, 1, 1, 0, 0, 5, 6, 3, 3, 2, SLASH, P_KNIFE, METAL, HI_METAL, "SCALPEL");
    addWeapon(weaponList, "knife", NoDes, 1, 1, 0, 20, 5, 4, 3, 2, 0, PIERCE | SLASH, P_KNIFE, IRON, HI_METAL, "KNIFE");
    addWeapon(weaponList, "stiletto", NoDes, 1, 1, 0, 5, 5, 4, 3, 2, 0, PIERCE | SLASH, P_KNIFE, IRON, HI_METAL, "STILETTO");
    //3.6: worm teeth and crysknives now stack;
    //when a stack of teeth is enchanted at once, they fuse into one crysknife;
    //when a stack of crysknives drops, the whole stack reverts to teeth 
    //3.7: change crysknife from MINERAL to BONE and worm tooth from 0 to BONE 
    addWeapon(weaponList, "worm tooth", NoDes, 1, 1, 0, 0, 20, 2, 2, 2, 0, 0, P_KNIFE, BONE, CLR_WHITE, "WORM_TOOTH");
    addWeapon(weaponList, "crysknife", NoDes, 1, 1, 0, 0, 20, 100, 10, 10, 3, PIERCE, P_KNIFE, BONE, CLR_WHITE, "CRYSKNIFE");
    //axes 
    addWeapon(weaponList, "axe", NoDes, 1, 0, 0, 40, 60, 8, 6, 4, 0, SLASH, P_AXE, IRON, HI_METAL, "AXE");
    addWeapon(weaponList, "battle-axe", "double-headed axe", 0, 0, 1, 10, 120, 40, 8, 6, 0, SLASH, P_AXE, IRON, HI_METAL, "BATTLE_AXE"); //"double-bitted"? 
    //swords 
    addWeapon(weaponList, "short sword", NoDes, 1, 0, 0, 8, 30, 10, 6, 8, 0, PIERCE, P_SHORT_SWORD, IRON, HI_METAL, "SHORT_SWORD");
    addWeapon(weaponList, "elven short sword", "runed short sword", 0, 0, 0, 2, 30, 10, 8, 8, 0, PIERCE, P_SHORT_SWORD, WOOD, HI_WOOD, "ELVEN_SHORT_SWORD");
    addWeapon(weaponList, "orcish short sword", "crude short sword", 0, 0, 0, 3, 30, 10, 5, 8, 0, PIERCE, P_SHORT_SWORD, IRON, CLR_BLACK, "ORCISH_SHORT_SWORD");
    addWeapon(weaponList, "dwarvish short sword", "broad short sword", 0, 0, 0, 2, 30, 10, 7, 8, 0, PIERCE, P_SHORT_SWORD, IRON, HI_METAL, "DWARVISH_SHORT_SWORD");
    addWeapon(weaponList, "scimitar", "curved sword", 0, 0, 0, 15, 40, 15, 8, 8, 0, SLASH, P_SABER, IRON, HI_METAL, "SCIMITAR");
    addWeapon(weaponList, "silver saber", NoDes, 1, 0, 0, 6, 40, 75, 8, 8, 0, SLASH, P_SABER, SILVER, HI_SILVER, "SILVER_SABER");
    addWeapon(weaponList, "broadsword", NoDes, 1, 0, 0, 8, 70, 10, 4, 6, 0, SLASH, P_BROAD_SWORD, IRON, HI_METAL, "BROADSWORD");
    //+d4 small, +1 large 
    addWeapon(weaponList, "elven broadsword", "runed broadsword", 0, 0, 0, 4, 70, 10, 6, 6, 0, SLASH, P_BROAD_SWORD, WOOD, HI_WOOD, "ELVEN_BROADSWORD");
    //+d4 small, +1 large 
    addWeapon(weaponList, "long sword", NoDes, 1, 0, 0, 50, 40, 15, 8, 12, 0, SLASH, P_LONG_SWORD, IRON, HI_METAL, "LONG_SWORD");
    addWeapon(weaponList, "two-handed sword", NoDes, 1, 0, 1, 22, 150, 50, 12, 6, 0, SLASH, P_TWO_HANDED_SWORD, IRON, HI_METAL, "TWO_HANDED_SWORD");
    //+2d6 large 
    addWeapon(weaponList, "katana", "samurai sword", 0, 0, 0, 4, 40, 80, 10, 12, 1, SLASH, P_LONG_SWORD, IRON, HI_METAL, "KATANA");
    //special swords set up for artifacts 
    addWeapon(weaponList, "tsurugi", "long samurai sword", 0, 0, 1, 0, 60, 500, 16, 8, 2, SLASH, P_TWO_HANDED_SWORD, METAL, HI_METAL, "TSURUGI");
    //+2d6 large 
    addWeapon(weaponList, "runesword", "runed broadsword", 0, 0, 0, 0, 40, 300, 4, 6, 0, SLASH, P_BROAD_SWORD, IRON, CLR_BLACK, "RUNESWORD");
    //+d4 small, +1 large; Stormbringer: +5d2 +d8 from level drain 
    //polearms 
    //spear-type 
    addWeapon(weaponList, "partisan", "vulgar polearm", 0, 0, 1, 5, 80, 10, 6, 6, 0, PIERCE, P_POLEARMS, IRON, HI_METAL, "PARTISAN");
    //+1 large 
    addWeapon(weaponList, "ranseur", "hilted polearm", 0, 0, 1, 5, 50, 6, 4, 4, 0, PIERCE, P_POLEARMS, IRON, HI_METAL, "RANSEUR");
    //+d4 both 
    addWeapon(weaponList, "spetum", "forked polearm", 0, 0, 1, 5, 50, 5, 6, 6, 0, PIERCE, P_POLEARMS, IRON, HI_METAL, "SPETUM");
    //+1 small, +d6 large 
    addWeapon(weaponList, "glaive", "single-edged polearm", 0, 0, 1, 8, 75, 6, 6, 10, 0, SLASH, P_POLEARMS, IRON, HI_METAL, "GLAIVE");
    //axe-type 
    addWeapon(weaponList, "halberd", "angled poleaxe", 0, 0, 1, 8, 150, 10, 10, 6, 0, PIERCE | SLASH, P_POLEARMS, IRON, HI_METAL, "HALBERD");
    //+1d6 large 
    addWeapon(weaponList, "bardiche", "long poleaxe", 0, 0, 1, 4, 120, 7, 4, 4, 0, SLASH, P_POLEARMS, IRON, HI_METAL, "BARDICHE");
    //+1d4 small, +2d4 large 
    addWeapon(weaponList, "voulge", "pole cleaver", 0, 0, 1, 4, 125, 5, 4, 4, 0, SLASH, P_POLEARMS, IRON, HI_METAL, "VOULGE");
    //+d4 both 
    //curved/hooked 
    addWeapon(weaponList, "fauchard", "pole sickle", 0, 0, 1, 6, 60, 5, 6, 8, 0, PIERCE | SLASH, P_POLEARMS, IRON, HI_METAL, "FAUCHARD");
    addWeapon(weaponList, "guisarme", "pruning hook", 0, 0, 1, 6, 80, 5, 4, 8, 0, SLASH, P_POLEARMS, IRON, HI_METAL, "GUISARME");
    //+1d4 small 
    addWeapon(weaponList, "bill-guisarme", "hooked polearm", 0, 0, 1, 4, 120, 7, 4, 10, 0, PIERCE | SLASH, P_POLEARMS, IRON, HI_METAL, "BILL_GUISARME");
    //+1d4 small 
    //other 
    addWeapon(weaponList, "lucern hammer", "pronged polearm", 0, 0, 1, 5, 150, 7, 4, 6, 0, WHACK | PIERCE, P_POLEARMS, IRON, HI_METAL, "LUCERN_HAMMER");
    //+1d4 small 
    addWeapon(weaponList, "bec de corbin", "beaked polearm", 0, 0, 1, 4, 100, 8, 8, 6, 0, WHACK | PIERCE, P_POLEARMS, IRON, HI_METAL, "BEC_DE_CORBIN");
    //formerly grouped with the polearms but don't use polearms skill;
    //lance isn't even two-handed 
    addWeapon(weaponList, "dwarvish mattock", "broad pick", 0, 0, 1, 13, 120, 50, 12, 8, -1, WHACK, P_PICK_AXE, IRON, HI_METAL, "DWARVISH_MATTOCK");
    addWeapon(weaponList, "lance", NoDes, 1, 0, 0, 4, 180, 10, 6, 8, 0, PIERCE, P_LANCE, IRON, HI_METAL, "LANCE");
    //+2d10 when jousting with lance as primary weapon,
    //+2d2 when jousting with it as secondary when dual wielding 
    //bludgeons 
    addWeapon(weaponList, "mace", NoDes, 1, 0, 0, 40, 30, 5, 6, 6, 0, WHACK, P_MACE, IRON, HI_METAL, "MACE");
    //+1 small 
    addWeapon(weaponList, "morning star", NoDes, 1, 0, 0, 12, 120, 10, 4, 6, 0, WHACK, P_MORNING_STAR, IRON, HI_METAL, "MORNING_STAR");
    //+d4 small, +1 large 
    addWeapon(weaponList, "war hammer", NoDes, 1, 0, 0, 15, 50, 5, 4, 4, 0, WHACK, P_HAMMER, IRON, HI_METAL, "WAR_HAMMER");
    //+1 small 
    addWeapon(weaponList, "club", NoDes, 1, 0, 0, 12, 30, 3, 6, 3, 0, WHACK, P_CLUB, WOOD, HI_WOOD, "CLUB");
    addWeapon(weaponList, "rubber hose", NoDes, 1, 0, 0, 0, 20, 3, 4, 3, 0, WHACK, P_WHIP, PLASTIC, CLR_BROWN, "RUBBER_HOSE");
    addWeapon(weaponList, "quarterstaff", "staff", 0, 0, 1, 11, 40, 5, 6, 6, 0, WHACK, P_QUARTERSTAFF, WOOD, HI_WOOD, "QUARTERSTAFF");
    //two-piece 
    addWeapon(weaponList, "aklys", "thonged club", 0, 0, 0, 8, 15, 4, 6, 3, 0, WHACK, P_CLUB, IRON, HI_METAL, "AKLYS");
    addWeapon(weaponList, "flail", NoDes, 1, 0, 0, 40, 15, 4, 6, 4, 0, WHACK, P_FLAIL, IRON, HI_METAL, "FLAIL");
    //+1 small, +1d4 large 
    //misc 
    addWeapon(weaponList, "bullwhip", NoDes, 1, 0, 0, 2, 20, 4, 2, 1, 0, 0, P_WHIP, LEATHER, CLR_BROWN, "BULLWHIP");


}

void ResourceData::loadBow(std::vector<ObjectBow>& bowList)
{
    //bows 
    addBow(bowList, "bow", NoDes, 1, 24, 30, 60, 0, WOOD, P_BOW, HI_WOOD, "BOW");
    addBow(bowList, "elven bow", "runed bow", 0, 12, 30, 60, 0, WOOD, P_BOW, HI_WOOD, "ELVEN_BOW");
    addBow(bowList, "orcish bow", "crude bow", 0, 12, 30, 60, 0, WOOD, P_BOW, CLR_BLACK, "ORCISH_BOW");
    addBow(bowList, "yumi", "long bow", 0, 0, 30, 60, 0, WOOD, P_BOW, HI_WOOD, "YUMI");
    addBow(bowList, "sling", NoDes, 1, 40, 3, 20, 0, LEATHER, P_SLING, HI_LEATHER, "SLING");
    addBow(bowList, "crossbow", NoDes, 1, 45, 50, 40, 0, WOOD, P_CROSSBOW, HI_WOOD, "CROSSBOW");
}

void ResourceData::loadHelm(std::vector<ObjectHelm>& helmList)
{
    //helmets 
    addHelm(helmList, "elven leather helm", "leather hat", 0, 0, 0, 6, 1, 3, 8, 9, 0, LEATHER, HI_LEATHER, "ELVEN_LEATHER_HELM");
    addHelm(helmList, "orcish helm", "iron skull cap", 0, 0, 0, 6, 1, 30, 10, 9, 0, IRON, CLR_BLACK, "ORCISH_HELM");
    addHelm(helmList, "dwarvish iron helm", "hard hat", 0, 0, 0, 6, 1, 40, 20, 8, 0, IRON, HI_METAL, "DWARVISH_IRON_HELM");
    addHelm(helmList, "fedora", NoDes, 1, 0, 0, 0, 0, 3, 1, 10, 0, CLOTH, CLR_BROWN, "FEDORA");
    addHelm(helmList, "cornuthaum", "conical hat", 0, 1, CLAIRVOYANT, 3, 1, 4, 80, 10, 1, CLOTH, CLR_BLUE, "CORNUTHAUM");
    //name coined by devteam; confers clairvoyance for wizards,
    //blocks clairvoyance if worn by role other than wizard 
    addHelm(helmList, "dunce cap", "conical hat", 0, 1, 0, 3, 1, 4, 1, 10, 0, CLOTH, CLR_BLUE, "DUNCE_CAP");
    //sets Int and Wis to fixed value of 6, so actually provides
    //protection against death caused by Int being drained below 3 
    addHelm(helmList, "dented pot", NoDes, 1, 0, 0, 2, 0, 10, 8, 9, 0, IRON, CLR_BLACK, "DENTED_POT");
    addHelm(helmList, "helm of brilliance", "crystal helmet", 0, 1, 0, 3, 1, 40, 50, 9, 0, GLASS, CLR_WHITE, "HELM_OF_BRILLIANCE");
    //used to be iron and shuffled as "etched helmet" but required
    //special case for the effect of iron armor on spell casting 
    //with shuffled appearances... 
    addHelm(helmList, "helmet", "plumed helmet", 0, 0, 0, 10, 1, 30, 10, 9, 0, IRON, HI_METAL, "HELMET");
    addHelm(helmList, "helm of caution", "etched helmet", 0, 1, WARNING, 3, 1, 50, 50, 9, 0, IRON, CLR_GREEN, "HELM_OF_CAUTION");
    addHelm(helmList, "helm of opposite alignment", "crested helmet", 0, 1, 0, 6, 1, 50, 50, 9, 0, IRON, HI_METAL, "HELM_OF_OPPOSITE_ALIGNMENT");
    addHelm(helmList, "helm of telepathy", "visored helmet", 0, 1, TELEPAT, 2, 1, 50, 50, 9, 0, IRON, HI_METAL, "HELM_OF_TELEPATHY");

}

void ResourceData::loadDragonArmor(std::vector<ObjectDragonArmor>& dragonArmorList)
{

    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////


    //3.4.1: dragon scale mail reclassified as "magic" since magic is needed to create them 
    addDragonArmor(dragonArmorList, "gray dragon scale mail", 1, ANTIMAGIC, 1200, 1, CLR_GRAY, "GRAY_DRAGON_SCALE_MAIL");
    //gold DSM is a light source; there's no property for that 
    addDragonArmor(dragonArmorList, "gold dragon scale mail", 1, 0, 900, 1, HI_GOLD, "GOLD_DRAGON_SCALE_MAIL");
    addDragonArmor(dragonArmorList, "silver dragon scale mail", 1, REFLECTING, 1200, 1, DRAGON_SILVER, "SILVER_DRAGON_SCALE_MAIL");
    //#if 0 //DEFERRED 
    addDragonArmor(dragonArmorList, "shimmering dragon scale mail", 1, DISPLACED, 1200, 1, CLR_CYAN, "SHIMMERING_DRAGON_SCALE_MAIL");
    //#endif
    addDragonArmor(dragonArmorList, "red dragon scale mail", 1, FIRE_RES, 900, 1, CLR_RED, "RED_DRAGON_SCALE_MAIL");
    addDragonArmor(dragonArmorList, "white dragon scale mail", 1, COLD_RES, 900, 1, CLR_WHITE, "WHITE_DRAGON_SCALE_MAIL");
    addDragonArmor(dragonArmorList, "orange dragon scale mail", 1, SLEEP_RES, 900, 1, CLR_ORANGE, "ORANGE_DRAGON_SCALE_MAIL");
    addDragonArmor(dragonArmorList, "black dragon scale mail", 1, DISINT_RES, 1200, 1, CLR_BLACK, "BLACK_DRAGON_SCALE_MAIL");
    addDragonArmor(dragonArmorList, "blue dragon scale mail", 1, SHOCK_RES, 900, 1, CLR_BLUE, "BLUE_DRAGON_SCALE_MAIL");
    addDragonArmor(dragonArmorList, "green dragon scale mail", 1, POISON_RES, 900, 1, CLR_GREEN, "GREEN_DRAGON_SCALE_MAIL");
    addDragonArmor(dragonArmorList, "yellow dragon scale mail", 1, ACID_RES, 900, 1, CLR_YELLOW, "YELLOW_DRAGON_SCALE_MAIL");
    //For now, only dragons leave these. 
    //3.4.1: dragon scales left classified as "non-magic"; they confer magical
    //properties but are produced "naturally"; affects use as polypile fodder 
    addDragonArmor(dragonArmorList, "gray dragon scales", 0, ANTIMAGIC, 700, 7, CLR_GRAY, "GRAY_DRAGON_SCALES");
    addDragonArmor(dragonArmorList, "gold dragon scales", 0, 0, 500, 7, HI_GOLD, "GOLD_DRAGON_SCALES");
    addDragonArmor(dragonArmorList, "silver dragon scales", 0, REFLECTING, 700, 7, DRAGON_SILVER, "SILVER_DRAGON_SCALES");
    //#if 0 //DEFERRED 
    addDragonArmor(dragonArmorList, "shimmering dragon scales", 0, DISPLACED, 700, 7, CLR_CYAN, "SHIMMERING_DRAGON_SCALES");
    //#endif
    addDragonArmor(dragonArmorList, "red dragon scales", 0, FIRE_RES, 500, 7, CLR_RED, "RED_DRAGON_SCALES");
    addDragonArmor(dragonArmorList, "white dragon scales", 0, COLD_RES, 500, 7, CLR_WHITE, "WHITE_DRAGON_SCALES");
    addDragonArmor(dragonArmorList, "orange dragon scales", 0, SLEEP_RES, 500, 7, CLR_ORANGE, "ORANGE_DRAGON_SCALES");
    addDragonArmor(dragonArmorList, "black dragon scales", 0, DISINT_RES, 700, 7, CLR_BLACK, "BLACK_DRAGON_SCALES");
    addDragonArmor(dragonArmorList, "blue dragon scales", 0, SHOCK_RES, 500, 7, CLR_BLUE, "BLUE_DRAGON_SCALES");
    addDragonArmor(dragonArmorList, "green dragon scales", 0, POISON_RES, 500, 7, CLR_GREEN, "GREEN_DRAGON_SCALES");
    addDragonArmor(dragonArmorList, "yellow dragon scales", 0, ACID_RES, 500, 7, CLR_YELLOW, "YELLOW_DRAGON_SCALES");
#undef DRGN_ARMR


    ///////////////////////////////////////////////////////////////////////////////
}

void ResourceData::loadArmor(std::vector<ObjectArmor>& armorList)
{
    //other suits 
    addArmor(armorList, "plate mail", NoDes, 1, 0, 1, 0, 44, 5, 450, 600, 3, 2, ARM_SUIT, IRON, HI_METAL, "PLATE_MAIL");
    addArmor(armorList, "crystal plate mail", NoDes, 1, 0, 1, 0, 10, 5, 450, 820, 3, 2, ARM_SUIT, GLASS, CLR_WHITE, "CRYSTAL_PLATE_MAIL");
    addArmor(armorList, "bronze plate mail", NoDes, 1, 0, 1, 0, 25, 5, 450, 400, 4, 1, ARM_SUIT, COPPER, HI_COPPER, "BRONZE_PLATE_MAIL");
    addArmor(armorList, "splint mail", NoDes, 1, 0, 1, 0, 62, 5, 400, 80, 4, 1, ARM_SUIT, IRON, HI_METAL, "SPLINT_MAIL");
    addArmor(armorList, "banded mail", NoDes, 1, 0, 1, 0, 72, 5, 350, 90, 4, 1, ARM_SUIT, IRON, HI_METAL, "BANDED_MAIL");
    addArmor(armorList, "dwarvish mithril-coat", NoDes, 1, 0, 0, 0, 10, 1, 150, 240, 4, 2, ARM_SUIT, MITHRIL, HI_SILVER, "DWARVISH_MITHRIL_COAT");
    addArmor(armorList, "elven mithril-coat", NoDes, 1, 0, 0, 0, 15, 1, 150, 240, 5, 2, ARM_SUIT, MITHRIL, HI_SILVER, "ELVEN_MITHRIL_COAT");
    addArmor(armorList, "chain mail", NoDes, 1, 0, 0, 0, 72, 5, 300, 75, 5, 1, ARM_SUIT, IRON, HI_METAL, "CHAIN_MAIL");
    addArmor(armorList, "orcish chain mail", "crude chain mail", 0, 0, 0, 0, 20, 5, 300, 75, 6, 1, ARM_SUIT, IRON, CLR_BLACK, "ORCISH_CHAIN_MAIL");
    addArmor(armorList, "scale mail", NoDes, 1, 0, 0, 0, 72, 5, 250, 45, 6, 1, ARM_SUIT, IRON, HI_METAL, "SCALE_MAIL");
    addArmor(armorList, "studded leather armor", NoDes, 1, 0, 0, 0, 72, 3, 200, 15, 7, 1, ARM_SUIT, LEATHER, HI_LEATHER, "STUDDED_LEATHER_ARMOR");
    addArmor(armorList, "ring mail", NoDes, 1, 0, 0, 0, 72, 5, 250, 100, 7, 1, ARM_SUIT, IRON, HI_METAL, "RING_MAIL");
    addArmor(armorList, "orcish ring mail", "crude ring mail", 0, 0, 0, 0, 20, 5, 250, 80, 8, 1, ARM_SUIT, IRON, CLR_BLACK, "ORCISH_RING_MAIL");
    addArmor(armorList, "leather armor", NoDes, 1, 0, 0, 0, 82, 3, 150, 5, 8, 1, ARM_SUIT, LEATHER, HI_LEATHER, "LEATHER_ARMOR");
    addArmor(armorList, "leather jacket", NoDes, 1, 0, 0, 0, 12, 0, 30, 10, 9, 0, ARM_SUIT, LEATHER, CLR_BLACK, "LEATHER_JACKET");
    //shirts 
    addArmor(armorList, "Hawaiian shirt", NoDes, 1, 0, 0, 0, 8, 0, 5, 3, 10, 0, ARM_SHIRT, CLOTH, CLR_MAGENTA, "HAWAIIAN_SHIRT");
    addArmor(armorList, "T-shirt", NoDes, 1, 0, 0, 0, 2, 0, 5, 2, 10, 0, ARM_SHIRT, CLOTH, CLR_WHITE, "T_SHIRT");

}

void ResourceData::loadCloak(std::vector<ObjectCloak>& cloakList)
{

    //cloaks 
    addCloak(cloakList, "mummy wrapping", NoDes, 1, 0, 0, 0, 0, 3, 2, 10, 1, CLOTH, CLR_GRAY, "MUMMY_WRAPPING");
    //worn mummy wrapping blocks invisibility 
    addCloak(cloakList, "elven cloak", "faded pall", 0, 1, STEALTH, 8, 0, 10, 60, 9, 1, CLOTH, CLR_BLACK, "ELVEN_CLOAK");
    addCloak(cloakList, "orcish cloak", "coarse mantelet", 0, 0, 0, 8, 0, 10, 40, 10, 1, CLOTH, CLR_BLACK, "ORCISH_CLOAK");
    addCloak(cloakList, "dwarvish cloak", "hooded cloak", 0, 0, 0, 8, 0, 10, 50, 10, 1, CLOTH, HI_CLOTH, "DWARVISH_CLOAK");
    addCloak(cloakList, "oilskin cloak", "slippery cloak", 0, 0, 0, 8, 0, 10, 50, 9, 2, CLOTH, HI_CLOTH, "OILSKIN_CLOAK");
    addCloak(cloakList, "robe", NoDes, 1, 1, 0, 3, 0, 15, 50, 8, 2, CLOTH, CLR_RED, "ROBE");
    //robe was adopted from slash'em, where it's worn as a suit
    //rather than as a cloak and there are several variations 
    addCloak(cloakList, "alchemy smock", "apron", 0, 1, POISON_RES, 9, 0, 10, 50, 9, 1, CLOTH, CLR_WHITE, "ALCHEMY_SMOCK");
    addCloak(cloakList, "leather cloak", NoDes, 1, 0, 0, 8, 0, 15, 40, 9, 1, LEATHER, CLR_BROWN, "LEATHER_CLOAK");
    //with shuffled appearances... 
    addCloak(cloakList, "cloak of protection", "tattered cape", 0, 1, PROTECTION, 9, 0, 10, 50, 7, 3, CLOTH, HI_CLOTH, "CLOAK_OF_PROTECTION");
    //cloak of protection is now the only item conferring MC 3 
    addCloak(cloakList, "cloak of invisibility", "opera cloak", 0, 1, INVIS, 10, 0, 10, 60, 9, 1, CLOTH, CLR_BRIGHT_MAGENTA, "CLOAK_OF_INVISIBILITY");
    addCloak(cloakList, "cloak of magic resistance", "ornamental cope", 0, 1, ANTIMAGIC, 2, 0, 10, 60, 9, 1, CLOTH, CLR_WHITE, "CLOAK_OF_MAGIC_RESISTANCE");
    //'cope' is not a spelling mistake... leave it be 
    addCloak(cloakList, "cloak of displacement", "piece of cloth", 0, 1, DISPLACED, 10, 0, 10, 50, 9, 1, CLOTH, HI_CLOTH, "CLOAK_OF_DISPLACEMENT");


}

void ResourceData::loadShield(std::vector<ObjectShield>& shieldList)
{
    //shields 
    addShield(shieldList, "small shield", NoDes, 1, 0, 0, 0, 6, 0, 30, 3, 9, 0, WOOD, HI_WOOD, "SMALL_SHIELD");
    addShield(shieldList, "elven shield", "blue and green shield", 0, 0, 0, 0, 2, 0, 40, 7, 8, 0, WOOD, CLR_GREEN, "ELVEN_SHIELD");
    addShield(shieldList, "Uruk-hai shield", "white-handed shield", 0, 0, 0, 0, 2, 0, 50, 7, 9, 0, IRON, HI_METAL, "URUK_HAI_SHIELD");
    addShield(shieldList, "orcish shield", "red-eyed shield", 0, 0, 0, 0, 2, 0, 50, 7, 9, 0, IRON, CLR_RED, "ORCISH_SHIELD");
    addShield(shieldList, "large shield", NoDes, 1, 0, 1, 0, 7, 0, 100, 10, 8, 0, IRON, HI_METAL, "LARGE_SHIELD");
    addShield(shieldList, "dwarvish roundshield", "large round shield", 0, 0, 0, 0, 4, 0, 100, 10, 8, 0, IRON, HI_METAL, "DWARVISH_ROUNDSHIELD");
    addShield(shieldList, "shield of reflection", "polished silver shield", 0, 1, 0, REFLECTING, 3, 0, 50, 50, 8, 0, SILVER, HI_SILVER, "SHIELD_OF_REFLECTION");

}

void ResourceData::loadGloves(std::vector<ObjectGloves>& glovesList)
{
    //gloves 
    //These have their color but not material shuffled, so the IRON must
    //* stay CLR_BROWN (== HI_LEATHER) even though it's normally either
    //* HI_METAL or CLR_BLACK.  All have shuffled descriptions.

    addGloves(glovesList, "leather gloves", "old gloves", 0, 0, 0, 16, 1, 10, 8, 9, 0, LEATHER, HI_LEATHER, "LEATHER_GLOVES");
    addGloves(glovesList, "gauntlets of fumbling", "padded gloves", 0, 1, FUMBLING, 8, 1, 10, 50, 9, 0, LEATHER, HI_LEATHER, "GAUNTLETS_OF_FUMBLING");
    addGloves(glovesList, "gauntlets of power", "riding gloves", 0, 1, 0, 8, 1, 30, 50, 9, 0, IRON, CLR_BROWN, "GAUNTLETS_OF_POWER");
    addGloves(glovesList, "gauntlets of dexterity", "fencing gloves", 0, 1, 0, 8, 1, 10, 50, 9, 0, LEATHER, HI_LEATHER, "GAUNTLETS_OF_DEXTERITY");



}

void ResourceData::loadBoots(std::vector<ObjectBoots>& bootsList)
{
    //boots 
    addBoots(bootsList, "low boots", "walking shoes", 0, 0, 0, 25, 2, 10, 8, 9, 0, LEATHER, HI_LEATHER, "LOW_BOOTS");
    addBoots(bootsList, "iron shoes", "hard shoes", 0, 0, 0, 7, 2, 50, 16, 8, 0, IRON, HI_METAL, "IRON_SHOES");
    addBoots(bootsList, "high boots", "jackboots", 0, 0, 0, 15, 2, 20, 12, 8, 0, LEATHER, HI_LEATHER, "HIGH_BOOTS");
    //with shuffled appearances... 
    addBoots(bootsList, "speed boots", "combat boots", 0, 1, FAST, 12, 2, 20, 50, 9, 0, LEATHER, HI_LEATHER, "SPEED_BOOTS");
    addBoots(bootsList, "water walking boots", "jungle boots", 0, 1, WWALKING, 12, 2, 15, 50, 9, 0, LEATHER, HI_LEATHER, "WATER_WALKING_BOOTS");
    addBoots(bootsList, "jumping boots", "hiking boots", 0, 1, JUMPING, 12, 2, 20, 50, 9, 0, LEATHER, HI_LEATHER, "JUMPING_BOOTS");
    addBoots(bootsList, "elven boots", "mud boots", 0, 1, STEALTH, 12, 2, 15, 8, 9, 0, LEATHER, HI_LEATHER, "ELVEN_BOOTS");
    addBoots(bootsList, "kicking boots", "buckled boots", 0, 1, 0, 12, 2, 50, 8, 9, 0, IRON, CLR_BROWN, "KICKING_BOOTS");
    //CLR_BROWN for same reason as gauntlets of power 
    addBoots(bootsList, "fumble boots", "riding boots", 0, 1, FUMBLING, 12, 2, 20, 30, 9, 0, LEATHER, HI_LEATHER, "FUMBLE_BOOTS");
    addBoots(bootsList, "levitation boots", "snow boots", 0, 1, LEVITATION, 12, 2, 15, 30, 9, 0, LEATHER, HI_LEATHER, "LEVITATION_BOOTS");

}

void ResourceData::loadRing(std::vector<ObjectRing>& ringList)
{
    //rings ... 


    addRing(ringList, "adornment", "wooden", ADORNED, 100, 1, 1, 2, WOOD, HI_WOOD, "RIN_ADORNMENT");
    addRing(ringList, "gain strength", "granite", 0, 150, 1, 1, 7, MINERAL, HI_MINERAL, "RIN_GAIN_STRENGTH");
    addRing(ringList, "gain constitution", "opal", 0, 150, 1, 1, 7, MINERAL, HI_MINERAL, "RIN_GAIN_CONSTITUTION");
    addRing(ringList, "increase accuracy", "clay", 0, 150, 1, 1, 4, MINERAL, CLR_RED, "RIN_INCREASE_ACCURACY");
    addRing(ringList, "increase damage", "coral", 0, 150, 1, 1, 4, MINERAL, CLR_ORANGE, "RIN_INCREASE_DAMAGE");
    addRing(ringList, "protection", "black onyx", PROTECTION, 100, 1, 1, 7, MINERAL, CLR_BLACK, "RIN_PROTECTION");
    //'PROTECTION' intrinsic enhances MC from worn armor by +1,
    //regardless of ring's enchantment; wearing a second ring of
    //protection (or even one ring of protection combined with
    //cloak of protection) doesn't give a second MC boost 
    addRing(ringList, "regeneration", "moonstone", REGENERATION, 200, 1, 0, 6, MINERAL, HI_MINERAL, "RIN_REGENERATION");
    addRing(ringList, "searching", "tiger eye", SEARCHING, 200, 1, 0, 6, GEMSTONE, CLR_BROWN, "RIN_SEARCHING");
    addRing(ringList, "stealth", "jade", STEALTH, 100, 1, 0, 6, GEMSTONE, CLR_GREEN, "RIN_STEALTH");
    addRing(ringList, "sustain ability", "bronze", FIXED_ABIL, 100, 1, 0, 4, COPPER, HI_COPPER, "RIN_SUSTAIN_ABILITY");
    addRing(ringList, "levitation", "agate", LEVITATION, 200, 1, 0, 7, GEMSTONE, CLR_RED, "RIN_LEVITATION");
    addRing(ringList, "hunger", "topaz", HUNGER, 100, 1, 0, 8, GEMSTONE, CLR_CYAN, "RIN_HUNGER");
    addRing(ringList, "aggravate monster", "sapphire", AGGRAVATE_MONSTER, 150, 1, 0, 9, GEMSTONE, CLR_BLUE, "RIN_AGGRAVATE_MONSTER");
    addRing(ringList, "conflict", "ruby", CONFLICT, 300, 1, 0, 9, GEMSTONE, CLR_RED, "RIN_CONFLICT");
    addRing(ringList, "warning", "diamond", WARNING, 100, 1, 0, 10, GEMSTONE, CLR_WHITE, "RIN_WARNING");
    addRing(ringList, "poison resistance", "pearl", POISON_RES, 150, 1, 0, 4, BONE, CLR_WHITE, "RIN_POISON_RESISTANCE");
    addRing(ringList, "fire resistance", "iron", FIRE_RES, 200, 1, 0, 5, IRON, HI_METAL, "RIN_FIRE_RESISTANCE");
    addRing(ringList, "cold resistance", "brass", COLD_RES, 150, 1, 0, 4, COPPER, HI_COPPER, "RIN_COLD_RESISTANCE");
    addRing(ringList, "shock resistance", "copper", SHOCK_RES, 150, 1, 0, 3, COPPER, HI_COPPER, "RIN_SHOCK_RESISTANCE");
    addRing(ringList, "free action", "twisted", FREE_ACTION, 200, 1, 0, 6, IRON, HI_METAL, "RIN_FREE_ACTION");
    addRing(ringList, "slow digestion", "steel", SLOW_DIGESTION, 200, 1, 0, 8, IRON, HI_METAL, "RIN_SLOW_DIGESTION");
    addRing(ringList, "teleportation", "silver", TELEPORT, 200, 1, 0, 3, SILVER, HI_SILVER, "RIN_TELEPORTATION");
    addRing(ringList, "teleport control", "gold", TELEPORT_CONTROL, 300, 1, 0, 3, GOLD, HI_GOLD, "RIN_TELEPORT_CONTROL");
    addRing(ringList, "polymorph", "ivory", POLYMORPH, 300, 1, 0, 4, BONE, CLR_WHITE, "RIN_POLYMORPH");
    addRing(ringList, "polymorph control", "emerald", POLYMORPH_CONTROL, 300, 1, 0, 8, GEMSTONE, CLR_BRIGHT_GREEN, "RIN_POLYMORPH_CONTROL");
    addRing(ringList, "invisibility", "wire", INVIS, 150, 1, 0, 5, IRON, HI_METAL, "RIN_INVISIBILITY");
    addRing(ringList, "see invisible", "engagement", SEE_INVIS, 150, 1, 0, 5, IRON, HI_METAL, "RIN_SEE_INVISIBLE");
    addRing(ringList, "protection from shape changers", "shiny", PROT_FROM_SHAPE_CHANGERS, 100, 1, 0, 5, IRON, CLR_BRIGHT_CYAN, "RIN_PROTECTION_FROM_SHAPE_CHAN");


}

void ResourceData::loadAmulet(std::vector<ObjectAmulet>& amuletList)
{
    //amulets ... - THE Amulet comes last because it is special 
    addAmulet(amuletList, "amulet of ESP", "circular", TELEPAT, 120, "AMULET_OF_ESP");
    /////////////////MARKER(FIRST_AMULET, AMULET_OF_ESP)
    addAmulet(amuletList, "amulet of life saving", "spherical", LIFESAVED, 75, "AMULET_OF_LIFE_SAVING");
    addAmulet(amuletList, "amulet of strangulation", "oval", STRANGLED, 115, "AMULET_OF_STRANGULATION");
    addAmulet(amuletList, "amulet of restful sleep", "triangular", SLEEPY, 115, "AMULET_OF_RESTFUL_SLEEP");
    addAmulet(amuletList, "amulet versus poison", "pyramidal", POISON_RES, 115, "AMULET_VERSUS_POISON");
    addAmulet(amuletList, "amulet of change", "square", 0, 115, "AMULET_OF_CHANGE");
    addAmulet(amuletList, "amulet of unchanging", "concave", UNCHANGING, 60, "AMULET_OF_UNCHANGING");
    addAmulet(amuletList, "amulet of reflection", "hexagonal", REFLECTING, 75, "AMULET_OF_REFLECTION");
    addAmulet(amuletList, "amulet of magical breathing", "octagonal", MAGICAL_BREATHING, 75, "AMULET_OF_MAGICAL_BREATHING");
    //+2 AC and +2 MC; +2 takes naked hero past 'warded' to 'guarded' 
    addAmulet(amuletList, "amulet of guarding", "perforated", PROTECTION, 75, "AMULET_OF_GUARDING");
    //cubical: some descriptions are already three dimensional and
    //parallelogrammatical (real word!) would be way over the top 
    addAmulet(amuletList, "amulet of flying", "cubical", FLYING, 60, "AMULET_OF_FLYING");
    //fixed descriptions; description duplication is deliberate;
   //* fake one must come before real one because selection for
   //* description shuffling stops when a non-magic amulet is encountered

////////////OBJECT(OBJ("cheap plastic imitation of the Amulet of Yendor",
////////////"Amulet of Yendor"");
////////////BITS(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, PLASTIC");
////////////0, AMULET_CLASS, 0, 0, 20, 0, 0, 0, 0, 0, 1, HI_METAL,
////////////FAKE_AMULET_OF_YENDOR");
////////////OBJECT(OBJ("Amulet of Yendor", //note: description == name 
////////////"Amulet of Yendor"");
////////////BITS(0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, MITHRIL");
////////////0, AMULET_CLASS, 0, 0, 20, 30000, 0, 0, 0, 0, 20, HI_METAL,
////////////AMULET_OF_YENDOR");
////////////MARKER(LAST_AMULET, AMULET_OF_YENDOR)
////////////
////////////
//////////////tools ... 
//////////////tools with weapon characteristics come last 
////////////#define addTool(toolList, name,desc,kn,mrg,mgc,chg,prob,wt,cost,mat,color,sn) \
////////////OBJECT(OBJ(name, desc");                                             \
////////////BITS(kn, mrg, chg, 0, mgc, chg, 0, 0, 0, 0, 0, P_NONE, mat"); \
////////////0, TOOL_CLASS, prob, 0, wt, cost, 0, 0, 0, 0, wt, color, sn)
////////////#define CONTAINER(name,desc,kn,mgc,chg,prob,wt,cost,mat,color,sn) \
////////////OBJECT(OBJ(name, desc");                                             \
////////////BITS(kn, 0, chg, 1, mgc, chg, 0, 0, 0, 0, 0, P_NONE, mat");   \
////////////0, TOOL_CLASS, prob, 0, wt, cost, 0, 0, 0, 0, wt, color, sn)
////////////#define EYEWEAR(name,desc,kn,prop,prob,wt,cost,mat,color,sn) \
////////////OBJECT(OBJ(name, desc");                                             \
////////////BITS(kn, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, P_NONE, mat");         \
////////////prop, TOOL_CLASS, prob, 0, wt, cost, 0, 0, 0, 0, wt, color, sn)
////////////#define WEPaddTool(toolList, name,desc,kn,mgc,bi,prob,wt,cost,sdam,ldam,hitbon,sub, \
////////////mat,clr,sn)                                             \
////////////OBJECT(OBJ(name, desc");                                             \
////////////BITS(kn, 0, 1, 0, mgc, 1, 0, 0, bi, 0, hitbon, sub, mat");    \
////////////0, TOOL_CLASS, prob, 0, wt, cost, sdam, ldam, hitbon, 0, wt, \
////////////clr, sn)
}

void ResourceData::loadContainer(std::vector<ObjectContainer>& containerList)
{

    //containers 
    addContainer(containerList, "large box", NoDes, 1, 0, 0, 40, 350, 8, WOOD, HI_WOOD, "LARGE_BOX");
    addContainer(containerList, "chest", NoDes, 1, 0, 0, 35, 600, 16, WOOD, HI_WOOD, "CHEST");
    addContainer(containerList, "ice box", NoDes, 1, 0, 0, 5, 900, 42, PLASTIC, CLR_WHITE, "ICE_BOX");
    addContainer(containerList, "sack", "bag", 0, 0, 0, 35, 15, 2, CLOTH, HI_CLOTH, "SACK");
    addContainer(containerList, "oilskin sack", "bag", 0, 0, 0, 5, 15, 100, CLOTH, HI_CLOTH, "OILSKIN_SACK");
    addContainer(containerList, "bag of holding", "bag", 0, 1, 0, 20, 15, 100, CLOTH, HI_CLOTH, "BAG_OF_HOLDING");
    addContainer(containerList, "bag of tricks", "bag", 0, 1, 1, 20, 15, 100, CLOTH, HI_CLOTH, "BAG_OF_TRICKS");
}

void ResourceData::loadTool(std::vector<ObjectTool>& toolList)
{
    //still other tools 
    addTool(toolList, "saddle", NoDes, 1, 0, 0, 0, 5, 200, 150, LEATHER, HI_LEATHER, "SADDLE");
    addTool(toolList, "leash", NoDes, 1, 0, 0, 0, 65, 12, 20, LEATHER, HI_LEATHER, "LEASH");
    addTool(toolList, "stethoscope", NoDes, 1, 0, 0, 0, 25, 4, 75, IRON, HI_METAL, "STETHOSCOPE");
    addTool(toolList, "tinning kit", NoDes, 1, 0, 0, 1, 15, 100, 30, IRON, HI_METAL, "TINNING_KIT");
    addTool(toolList, "tin opener", NoDes, 1, 0, 0, 0, 35, 4, 30, IRON, HI_METAL, "TIN_OPENER");
    addTool(toolList, "can of grease", NoDes, 1, 0, 0, 1, 15, 15, 20, IRON, HI_METAL, "CAN_OF_GREASE");
    addTool(toolList, "figurine", NoDes, 1, 0, 1, 0, 25, 50, 80, MINERAL, HI_MINERAL, "FIGURINE");
    //monster type specified by obj->corpsenm 
    addTool(toolList, "magic marker", NoDes, 1, 0, 1, 1, 15, 2, 50, PLASTIC, CLR_RED, "MAGIC_MARKER");
    //traps 
    addTool(toolList, "land mine", NoDes, 1, 0, 0, 0, 0, 200, 180, IRON, CLR_RED, "LAND_MINE");
    addTool(toolList, "beartrap", NoDes, 1, 0, 0, 0, 0, 200, 60, IRON, HI_METAL, "BEARTRAP");
    //instruments;
     //"If tin whistles are made out of tin, what do they make foghorns out of?" 
    addTool(toolList, "tin whistle", "whistle", 0, 0, 0, 0, 100, 3, 10, METAL, HI_METAL, "TIN_WHISTLE");
    addTool(toolList, "magic whistle", "whistle", 0, 0, 1, 0, 30, 3, 10, METAL, HI_METAL, "MAGIC_WHISTLE");
    addTool(toolList, "wooden flute", "flute", 0, 0, 0, 0, 4, 5, 12, WOOD, HI_WOOD, "WOODEN_FLUTE");
    addTool(toolList, "magic flute", "flute", 0, 0, 1, 1, 2, 5, 36, WOOD, HI_WOOD, "MAGIC_FLUTE");
    addTool(toolList, "tooled horn", "horn", 0, 0, 0, 0, 5, 18, 15, BONE, CLR_WHITE, "TOOLED_HORN");
    addTool(toolList, "frost horn", "horn", 0, 0, 1, 1, 2, 18, 50, BONE, CLR_WHITE, "FROST_HORN");
    addTool(toolList, "fire horn", "horn", 0, 0, 1, 1, 2, 18, 50, BONE, CLR_WHITE, "FIRE_HORN");
    addTool(toolList, "horn of plenty", "horn", 0, 0, 1, 1, 2, 18, 50, BONE, CLR_WHITE, "HORN_OF_PLENTY");
    //horn, but not an instrument 
    addTool(toolList, "wooden harp", "harp", 0, 0, 0, 0, 4, 30, 50, WOOD, HI_WOOD, "WOODEN_HARP");
    addTool(toolList, "magic harp", "harp", 0, 0, 1, 1, 2, 30, 50, WOOD, HI_WOOD, "MAGIC_HARP");
    addTool(toolList, "bell", NoDes, 1, 0, 0, 0, 2, 30, 50, COPPER, HI_COPPER, "BELL");
    addTool(toolList, "bugle", NoDes, 1, 0, 0, 0, 4, 10, 15, COPPER, HI_COPPER, "BUGLE");
    addTool(toolList, "leather drum", "drum", 0, 0, 0, 0, 4, 25, 25, LEATHER, HI_LEATHER, "LEATHER_DRUM");
    addTool(toolList, "drum of earthquake", "drum", 0, 0, 1, 1, 2, 25, 25, LEATHER, HI_LEATHER, "DRUM_OF_EARTHQUAKE");


    //lock opening tools 
    addTool(toolList, "skeleton key", "key", 0, 0, 0, 0, 80, 3, 10, IRON, HI_METAL, "SKELETON_KEY");
    addTool(toolList, "lock pick", NoDes, 1, 0, 0, 0, 60, 4, 20, IRON, HI_METAL, "LOCK_PICK");
    addTool(toolList, "credit card", NoDes, 1, 0, 0, 0, 15, 1, 10, PLASTIC, CLR_WHITE, "CREDIT_CARD");
    //light sources 
    addTool(toolList, "tallow candle", "candle", 0, 1, 0, 0, 20, 2, 10, WAX, CLR_WHITE, "TALLOW_CANDLE");
    addTool(toolList, "wax candle", "candle", 0, 1, 0, 0, 5, 2, 20, WAX, CLR_WHITE, "WAX_CANDLE");
    addTool(toolList, "brass lantern", NoDes, 1, 0, 0, 0, 30, 30, 12, COPPER, CLR_YELLOW, "BRASS_LANTERN");
    addTool(toolList, "oil lamp", "lamp", 0, 0, 0, 0, 45, 20, 10, COPPER, CLR_YELLOW, "OIL_LAMP");
    addTool(toolList, "magic lamp", "lamp", 0, 0, 1, 0, 15, 20, 50, COPPER, CLR_YELLOW, "MAGIC_LAMP");
    //other tools 
    addTool(toolList, "expensive camera", NoDes, 1, 0, 0, 1, 15, 12, 200, PLASTIC, CLR_BLACK, "EXPENSIVE_CAMERA");
    addTool(toolList, "mirror", "looking glass", 0, 0, 0, 0, 45, 13, 10, GLASS, HI_SILVER, "MIRROR");
    addTool(toolList, "crystal ball", "glass orb", 0, 0, 1, 1, 15, 150, 60, GLASS, HI_GLASS, "CRYSTAL_BALL");
}

void ResourceData::loadEyeware(std::vector<ObjectEyeware>& eyewareList)
{

    //eyewear - tools which can be worn on the face; (!mrg, !chg, !mgc)
     //worn lenses don't confer the Blinded property, blindfolds and towels do;
    //wet towel can be used as a weapon but is not a weptool and uses obj->spe
    //differently from weapons and weptools 
    addEyeware(eyewareList, "lenses", NoDes, 1, 0, 5, 3, 80, GLASS, HI_GLASS, "LENSES");
    addEyeware(eyewareList, "blindfold", NoDes, 1, BLINDED, 50, 2, 20, CLOTH, CLR_BLACK, "BLINDFOLD");
    addEyeware(eyewareList, "towel", NoDes, 1, BLINDED, 50, 2, 50, CLOTH, CLR_MAGENTA, "TOWEL");
}

void ResourceData::loadWepTool(std::vector<ObjectWepTool>& weptoolList)
{
    //tools useful as weapons 
    addWepTool(weptoolList, "pick-axe", NoDes, 1, 0, 0, 20, 100, 50, 6, 3, WHACK, P_PICK_AXE, IRON, HI_METAL, "PICK_AXE");
    addWepTool(weptoolList, "grappling hook", NoDes, 1, 0, 0, 5, 30, 50, 2, 6, WHACK, P_FLAIL, IRON, HI_METAL, "GRAPPLING_HOOK");
    addWepTool(weptoolList, "unicorn horn", NoDes, 1, 1, 1, 0, 20, 100, 12, 12, PIERCE, P_UNICORN_HORN, BONE, CLR_WHITE, "UNICORN_HORN");
    //3.4.1: unicorn horn left classified as "magic" 
    //two unique tools;
     //* not artifacts, despite the comment which used to be here

            //////////////////////////////////OBJECT(OBJ("Candelabrum of Invocation", "candelabrum"");
            //////////////////////////////////BITS(0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, P_NONE, GOLD");
            //////////////////////////////////0, TOOL_CLASS, 0, 0, 10, 5000, 0, 0, 0, 0, 200, HI_GOLD,
            //////////////////////////////////CANDELABRUM_OF_INVOCATION");
            //////////////////////////////////OBJECT(OBJ("Bell of Opening", "silver bell"");
            //////////////////////////////////BITS(0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, P_NONE, SILVER");
            //////////////////////////////////0, TOOL_CLASS, 0, 0, 10, 5000, 0, 0, 0, 0, 50, HI_SILVER,
            //////////////////////////////////BELL_OF_OPENING");
}

void ResourceData::loadFood(std::vector<ObjectFood>& foodList)
{
    //Comestibles ... 

////////////////////OBJECT(OBJ(name, NoDes");                                       \
        ////////////////////BITS(1, 1, unk, 0, 0, 0, 0, 0, 0, 0, 0, P_NONE, tin"); 0, \
        ////////////////////FOOD_CLASS, prob, delay, wt, nutrition / 20 + 5, 0, 0, 0, 0, \
        ////////////////////nutrition, color, sn)
    //All types of food (except tins & corpses) must have a delay of at least 1.
     //* Delay on corpses is computed and is weight dependant.
     //* Domestic pets prefer tripe rations above all others.
     //* Fortune cookies can be read, using them up without ingesting them.
     //* Carrots improve your vision.
     //* +0 tins contain monster meat.
     //* +1 tins (of spinach) make you stronger (like Popeye).
     //* Meatballs/sticks/rings are only created from objects via stone to flesh.

     //meat 
    addFood(foodList, "tripe ration", 140, 2, 10, 0, FLESH, 200, CLR_BROWN, "TRIPE_RATION");
    addFood(foodList, "corpse", 0, 1, 0, 0, FLESH, 0, CLR_BROWN, "CORPSE");
    addFood(foodList, "egg", 85, 1, 1, 1, FLESH, 80, CLR_WHITE, "EGG");
    addFood(foodList, "meatball", 0, 1, 1, 0, FLESH, 5, CLR_BROWN, "MEATBALL");
    addFood(foodList, "meat stick", 0, 1, 1, 0, FLESH, 5, CLR_BROWN, "MEAT_STICK");
    //formerly "huge chunk of meat" 
    addFood(foodList, "enormous meatball", 0, 20, 400, 0, FLESH, 2000, CLR_BROWN, "ENORMOUS_MEATBALL");
    //special case because it's not mergable 
    ////////////////OBJECT(OBJ("meat ring", NoDes");
    ////////////////BITS(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FLESH");
    ////////////////0, FOOD_CLASS, 0, 1, 5, 1, 0, 0, 0, 0, 5, CLR_BROWN, "MEAT_RING");
    //pudding 'corpses' will turn into these and combine;
    //must be in same order as the pudding monsters 
    addFood(foodList, "glob of gray ooze", 0, 2, 20, 0, FLESH, 20, CLR_GRAY, "GLOB_OF_GRAY_OOZE");
    addFood(foodList, "glob of brown pudding", 0, 2, 20, 0, FLESH, 20, CLR_BROWN, "GLOB_OF_BROWN_PUDDING");
    addFood(foodList, "glob of green slime", 0, 2, 20, 0, FLESH, 20, CLR_GREEN, "GLOB_OF_GREEN_SLIME");
    addFood(foodList, "glob of black pudding", 0, 2, 20, 0, FLESH, 20, CLR_BLACK, "GLOB_OF_BLACK_PUDDING");

    //fruits & veggies 
    addFood(foodList, "kelp frond", 0, 1, 1, 0, VEGGY, 30, CLR_GREEN, "KELP_FROND");
    addFood(foodList, "eucalyptus leaf", 3, 1, 1, 0, VEGGY, 1, CLR_GREEN, "EUCALYPTUS_LEAF");
    addFood(foodList, "apple", 15, 1, 2, 0, VEGGY, 50, CLR_RED, "APPLE");
    addFood(foodList, "orange", 10, 1, 2, 0, VEGGY, 80, CLR_ORANGE, "ORANGE");
    addFood(foodList, "pear", 10, 1, 2, 0, VEGGY, 50, CLR_BRIGHT_GREEN, "PEAR");
    addFood(foodList, "melon", 10, 1, 5, 0, VEGGY, 100, CLR_BRIGHT_GREEN, "MELON");
    addFood(foodList, "banana", 10, 1, 2, 0, VEGGY, 80, CLR_YELLOW, "BANANA");
    addFood(foodList, "carrot", 15, 1, 2, 0, VEGGY, 50, CLR_ORANGE, "CARROT");
    addFood(foodList, "sprig of wolfsbane", 7, 1, 1, 0, VEGGY, 40, CLR_GREEN, "SPRIG_OF_WOLFSBANE");
    addFood(foodList, "clove of garlic", 7, 1, 1, 0, VEGGY, 40, CLR_WHITE, "CLOVE_OF_GARLIC");
    //name of slime mold is changed based on player's OPTION=fruit:something
    //and bones data might have differently named ones from prior games 
    addFood(foodList, "slime mold", 75, 1, 5, 0, VEGGY, 250, HI_ORGANIC, "SLIME_MOLD");

    //people food 
    addFood(foodList, "lump of royal jelly", 0, 1, 2, 0, VEGGY, 200, CLR_YELLOW, "LUMP_OF_ROYAL_JELLY");
    addFood(foodList, "cream pie", 25, 1, 10, 0, VEGGY, 100, CLR_WHITE, "CREAM_PIE");
    addFood(foodList, "candy bar", 13, 1, 2, 0, VEGGY, 100, CLR_BRIGHT_BLUE, "CANDY_BAR");
    addFood(foodList, "fortune cookie", 55, 1, 1, 0, VEGGY, 40, CLR_YELLOW, "FORTUNE_COOKIE");
    addFood(foodList, "pancake", 25, 2, 2, 0, VEGGY, 200, CLR_YELLOW, "PANCAKE");
    addFood(foodList, "lembas wafer", 20, 2, 5, 0, VEGGY, 800, CLR_WHITE, "LEMBAS_WAFER");
    addFood(foodList, "cram ration", 20, 3, 15, 0, VEGGY, 600, HI_ORGANIC, "CRAM_RATION");
    addFood(foodList, "food ration", 380, 5, 20, 0, VEGGY, 800, HI_ORGANIC, "FOOD_RATION");
    addFood(foodList, "K-ration", 0, 1, 10, 0, VEGGY, 400, HI_ORGANIC, "K_RATION");
    addFood(foodList, "C-ration", 0, 1, 10, 0, VEGGY, 300, HI_ORGANIC, "C_RATION");
    //tins have type specified by obj->spe (+1 for spinach, other implies
       //flesh; negative specifies preparation method {homemade,boiled,&c})
       //and by obj->corpsenm (type of monster flesh) 
    addFood(foodList, "tin", 75, 0, 10, 1, METAL, 0, HI_METAL, "TIN");
}

void ResourceData::loadPotion(std::vector<ObjectPotion>& potionList)
{
    //potions ... 
//////////#defineaddPotion(name,desc,mgc,power,prob,cost,color,sn) \
//////////OBJECT(OBJ(name, desc");                                             \
//////////BITS(0, 1, 0, 0, mgc, 0, 0, 0, 0, 0, 0, P_NONE, GLASS");      \
//////////power, POTION_CLASS, prob, 0, 20, cost, 0, 0, 0, 0, 10, color, sn)
    addPotion(potionList, "gain ability", "ruby", 1, 0, 40, 300, CLR_RED, "POT_GAIN_ABILITY");
    addPotion(potionList, "restore ability", "pink", 1, 0, 40, 100, CLR_BRIGHT_MAGENTA, "POT_RESTORE_ABILITY");
    addPotion(potionList, "confusion", "orange", 1, CONFUSION, 40, 100, CLR_ORANGE, "POT_CONFUSION");
    addPotion(potionList, "blindness", "yellow", 1, BLINDED, 30, 150, CLR_YELLOW, "POT_BLINDNESS");
    addPotion(potionList, "paralysis", "emerald", 1, 0, 40, 300, CLR_BRIGHT_GREEN, "POT_PARALYSIS");
    addPotion(potionList, "speed", "dark green", 1, FAST, 40, 200, CLR_GREEN, "POT_SPEED");
    addPotion(potionList, "levitation", "cyan", 1, LEVITATION, 40, 200, CLR_CYAN, "POT_LEVITATION");
    addPotion(potionList, "hallucination", "sky blue", 1, HALLUC, 30, 100, CLR_CYAN, "POT_HALLUCINATION");
    addPotion(potionList, "invisibility", "brilliant blue", 1, INVIS, 40, 150, CLR_BRIGHT_BLUE, "POT_INVISIBILITY");
    addPotion(potionList, "see invisible", "magenta", 1, SEE_INVIS, 40, 50, CLR_MAGENTA, "POT_SEE_INVISIBLE");
    addPotion(potionList, "healing", "purple-red", 1, 0, 115, 20, CLR_MAGENTA, "POT_HEALING");
    addPotion(potionList, "extra healing", "puce", 1, 0, 45, 100, CLR_RED, "POT_EXTRA_HEALING");
    addPotion(potionList, "gain level", "milky", 1, 0, 20, 300, CLR_WHITE, "POT_GAIN_LEVEL");
    addPotion(potionList, "enlightenment", "swirly", 1, 0, 20, 200, CLR_BROWN, "POT_ENLIGHTENMENT");
    addPotion(potionList, "monster detection", "bubbly", 1, 0, 40, 150, CLR_WHITE, "POT_MONSTER_DETECTION");
    addPotion(potionList, "object detection", "smoky", 1, 0, 40, 150, CLR_GRAY, "POT_OBJECT_DETECTION");
    addPotion(potionList, "gain energy", "cloudy", 1, 0, 40, 150, CLR_WHITE, "POT_GAIN_ENERGY");
    addPotion(potionList, "sleeping", "effervescent", 1, 0, 40, 100, CLR_GRAY, "POT_SLEEPING");
    addPotion(potionList, "full healing", "black", 1, 0, 10, 200, CLR_BLACK, "POT_FULL_HEALING");
    addPotion(potionList, "polymorph", "golden", 1, 0, 10, 200, CLR_YELLOW, "POT_POLYMORPH");
    addPotion(potionList, "booze", "brown", 0, 0, 40, 50, CLR_BROWN, "POT_BOOZE");
    addPotion(potionList, "sickness", "fizzy", 0, 0, 40, 50, CLR_CYAN, "POT_SICKNESS");
    addPotion(potionList, "fruit juice", "dark", 0, 0, 40, 50, CLR_BLACK, "POT_FRUIT_JUICE");
    addPotion(potionList, "acid", "white", 0, 0, 10, 250, CLR_WHITE, "POT_ACID");
    addPotion(potionList, "oil", "murky", 0, 0, 30, 250, CLR_BROWN, "POT_OIL");
    //fixed description
    addPotion(potionList, "water", "clear", 0, 0, 80, 100, CLR_CYAN, "POT_WATER");
}

void ResourceData::loadScroll(std::vector<ObjectScroll>& scrollList)
{
    //scrolls ... 
////////#define addScroll(scrollList, name,text,mgc,prob,cost,sn) \
////////OBJECT(OBJ(name, text");                                           \
////////BITS(0, 1, 0, 0, mgc, 0, 0, 0, 0, 0, 0, P_NONE, PAPER");    \
////////0, SCROLL_CLASS, prob, 0, 5, cost, 0, 0, 0, 0, 6, \
////////HI_PAPER, sn)
    addScroll(scrollList, "enchant armor", "ZELGO MER", 1, 63, 80, "SCR_ENCHANT_ARMOR");
    addScroll(scrollList, "destroy armor", "JUYED AWK YACC", 1, 45, 100, "SCR_DESTROY_ARMOR");
    addScroll(scrollList, "confuse monster", "NR 9", 1, 53, 100, "SCR_CONFUSE_MONSTER");
    addScroll(scrollList, "scare monster", "XIXAXA XOXAXA XUXAXA", 1, 35, 100, "SCR_SCARE_MONSTER");
    addScroll(scrollList, "remove curse", "PRATYAVAYAH", 1, 65, 80, "SCR_REMOVE_CURSE");
    addScroll(scrollList, "enchant weapon", "DAIYEN FOOELS", 1, 80, 60, "SCR_ENCHANT_WEAPON");
    addScroll(scrollList, "create monster", "LEP GEX VEN ZEA", 1, 45, 200, "SCR_CREATE_MONSTER");
    addScroll(scrollList, "taming", "PRIRUTSENIE", 1, 15, 200, "SCR_TAMING");
    addScroll(scrollList, "genocide", "ELBIB YLOH", 1, 15, 300, "SCR_GENOCIDE");
    addScroll(scrollList, "light", "VERR YED HORRE", 1, 90, 50, "SCR_LIGHT");
    addScroll(scrollList, "teleportation", "VENZAR BORGAVVE", 1, 55, 100, "SCR_TELEPORTATION");
    addScroll(scrollList, "gold detection", "THARR", 1, 33, 100, "SCR_GOLD_DETECTION");
    addScroll(scrollList, "food detection", "YUM YUM", 1, 25, 100, "SCR_FOOD_DETECTION");
    addScroll(scrollList, "identify", "KERNOD WEL", 1, 180, 20, "SCR_IDENTIFY");
    addScroll(scrollList, "magic mapping", "ELAM EBOW", 1, 45, 100, "SCR_MAGIC_MAPPING");
    addScroll(scrollList, "amnesia", "DUAM XNAHT", 1, 35, 200, "SCR_AMNESIA");
    addScroll(scrollList, "fire", "ANDOVA BEGARIN", 1, 30, 100, "SCR_FIRE");
    addScroll(scrollList, "earth", "KIRJE", 1, 18, 200, "SCR_EARTH");
    addScroll(scrollList, "punishment", "VE FORBRYDERNE", 1, 15, 300, "SCR_PUNISHMENT");
    addScroll(scrollList, "charging", "HACKEM MUCHE", 1, 15, 300, "SCR_CHARGING");
    addScroll(scrollList, "stinking cloud", "VELOX NEB", 1, 15, 300, "SCR_STINKING_CLOUD");
    //Extra descriptions, shuffled into use at start of new game.
     //* Code in win/share/tilemap.c depends on SCR_STINKING_CLOUD preceding
     //* these and on how many of them there are.  If a real scroll gets added
     //* after stinking cloud or the number of extra descriptions changes,
     //* tilemap.c must be modified to match.

    addScroll(scrollList, NoDes, "FOOBIE BLETCH", 1, 0, 100, "SC01");
    addScroll(scrollList, NoDes, "TEMOV", 1, 0, 100, "SC02");
    addScroll(scrollList, NoDes, "GARVEN DEH", 1, 0, 100, "SC03");
    addScroll(scrollList, NoDes, "READ ME", 1, 0, 100, "SC04");
    addScroll(scrollList, NoDes, "ETAOIN SHRDLU", 1, 0, 100, "SC05");
    addScroll(scrollList, NoDes, "LOREM IPSUM", 1, 0, 100, "SC06");
    addScroll(scrollList, NoDes, "FNORD", 1, 0, 100, "SC07"); //Illuminati 
    addScroll(scrollList, NoDes, "KO BATE", 1, 0, 100, "SC08"); //Kurd Lasswitz 
    addScroll(scrollList, NoDes, "ABRA KA DABRA", 1, 0, 100, "SC09"); //traditional incantation 
    addScroll(scrollList, NoDes, "ASHPD SODALG", 1, 0, 100, "SC10"); //Portal 
    addScroll(scrollList, NoDes, "ZLORFIK", 1, 0, 100, "SC11"); //Zak McKracken 
    addScroll(scrollList, NoDes, "GNIK SISI VLE", 1, 0, 100, "SC12"); //Zak McKracken 
    addScroll(scrollList, NoDes, "HAPAX LEGOMENON", 1, 0, 100, "SC13");
    addScroll(scrollList, NoDes, "EIRIS SAZUN IDISI", 1, 0, 100, "SC14"); //Merseburg Incantations 
    addScroll(scrollList, NoDes, "PHOL ENDE WODAN", 1, 0, 100, "SC15"); //Merseburg Incantations 
    addScroll(scrollList, NoDes, "GHOTI", 1, 0, 100, "SC16"); //pronounced as 'fish',
    //George Bernard Shaw 
    addScroll(scrollList, NoDes, "MAPIRO MAHAMA DIROMAT", 1, 0, 100, "SC17"); //Wizardry 
    addScroll(scrollList, NoDes, "VAS CORP BET MANI", 1, 0, 100, "SC18"); //Ultima 
    addScroll(scrollList, NoDes, "XOR OTA", 1, 0, 100, "SC19"); //Aarne Haapakoski 
    addScroll(scrollList, NoDes, "STRC PRST SKRZ KRK", 1, 0, 100, "SC20"); //Czech and Slovak
    //tongue-twister 
    //These must come last because they have special fixed descriptions.

#ifdef MAIL_STRUCTURES
    addScroll(scrollList, "mail", "stamped", 0, 0, 0, SCR_MAIL");
#endif
        addScroll(scrollList, "blank paper", "unlabeled", 0, 28, 60, "SCR_BLANK_PAPER");
#undef SCROLL
}

void ResourceData::loadSpell(std::vector<ObjectSpell>& spellList)
{
    //spellbooks ... 
        //Expanding beyond 52 spells would require changes in spellcasting
         //* or imposition of a limit on number of spells hero can know because
         //* they are currently assigned successive letters, a-zA-Z, when learned.
         //* [The existing spell sorting capability could conceivably be extended
         //* to enable moving spells from beyond Z to within it, bumping others
         //* out in the process, allowing more than 52 spells be known but keeping
         //* only 52 be castable at any given time.]

//////////////////////////#define addSpell(spellList, name,desc,sub,prob,delay,level,mgc,dir,color,sn)  \
//////////////////////////OBJECT(OBJ(name, desc");                                             \
//////////////////////////BITS(0, 0, 0, 0, mgc, 0, 0, 0, 0, 0, dir, sub, PAPER");       \
//////////////////////////0, SPBOOK_CLASS, prob, delay, 50, level * 100, \
//////////////////////////0, 0, 0, level, 20, color, sn)
             //Spellbook description normally refers to book covers (primarily color).
                //Parchment and vellum would never be used for such, but rather than
                //eliminate those, finagle their definitions to refer to the pages
                //rather than the cover.  They are made from animal skin (typically of
                //a goat or sheep) and books using them for pages generally need heavy
                //covers with straps or clamps to tightly close the book in order to
                //keep the pages flat.  (However, a wooden cover might itself be covered
                //by a sheet of parchment, making this become less of an exception.  Also,
                //changing the internal composition from paper to leather makes eating a
                //parchment or vellum spellbook break vegetarian conduct, as it should.) 
#define PAPER LEATHER //override enum for use in addSpell(spellList, ) expansion 
    addSpell(spellList, "dig", "parchment", P_MATTER_SPELL, 20, 6, 5, 1, RAY, HI_LEATHER, "SPE_DIG");
    /////////////////////////////////////MARKER(FIRST_SPELL, SPE_DIG)
          //magic missile ... finger of death must be in this order; see buzz() 
    addSpell(spellList, "magic missile", "vellum", P_ATTACK_SPELL, 45, 2, 2, 1, RAY, HI_LEATHER, "SPE_MAGIC_MISSILE");
#undef PAPER //revert to normal material 
    addSpell(spellList, "fireball", "ragged", P_ATTACK_SPELL, 20, 4, 4, 1, RAY, HI_PAPER, "SPE_FIREBALL");
    addSpell(spellList, "cone of cold", "dog eared", P_ATTACK_SPELL, 10, 7, 4, 1, RAY, HI_PAPER, "SPE_CONE_OF_COLD");
    addSpell(spellList, "sleep", "mottled", P_ENCHANTMENT_SPELL, 30, 1, 3, 1, RAY, HI_PAPER, "SPE_SLEEP");
    addSpell(spellList, "finger of death", "stained", P_ATTACK_SPELL, 5, 10, 7, 1, RAY, HI_PAPER, "SPE_FINGER_OF_DEATH");
    addSpell(spellList, "light", "cloth", P_DIVINATION_SPELL, 45, 1, 1, 1, NODIR, HI_CLOTH, "SPE_LIGHT");
    addSpell(spellList, "detect monsters", "leathery", P_DIVINATION_SPELL, 43, 1, 1, 1, NODIR, HI_LEATHER, "SPE_DETECT_MONSTERS");
    addSpell(spellList, "healing", "white", P_HEALING_SPELL, 40, 2, 1, 1, IMMEDIATE, CLR_WHITE, "SPE_HEALING");
    addSpell(spellList, "knock", "pink", P_MATTER_SPELL, 25, 1, 1, 1, IMMEDIATE, CLR_BRIGHT_MAGENTA, "SPE_KNOCK");
    addSpell(spellList, "force bolt", "red", P_ATTACK_SPELL, 30, 2, 1, 1, IMMEDIATE, CLR_RED, "SPE_FORCE_BOLT");
    addSpell(spellList, "confuse monster", "orange", P_ENCHANTMENT_SPELL, 49, 2, 1, 1, IMMEDIATE, CLR_ORANGE, "SPE_CONFUSE_MONSTER");
    addSpell(spellList, "cure blindness", "yellow", P_HEALING_SPELL, 25, 2, 2, 1, IMMEDIATE, CLR_YELLOW, "SPE_CURE_BLINDNESS");
    addSpell(spellList, "drain life", "velvet", P_ATTACK_SPELL, 10, 2, 2, 1, IMMEDIATE, CLR_MAGENTA, "SPE_DRAIN_LIFE");
    addSpell(spellList, "slow monster", "light green", P_ENCHANTMENT_SPELL, 30, 2, 2, 1, IMMEDIATE, CLR_BRIGHT_GREEN, "SPE_SLOW_MONSTER");
    addSpell(spellList, "wizard lock", "dark green", P_MATTER_SPELL, 25, 3, 2, 1, IMMEDIATE, CLR_GREEN, "SPE_WIZARD_LOCK");
    addSpell(spellList, "create monster", "turquoise", P_CLERIC_SPELL, 35, 3, 2, 1, NODIR, CLR_BRIGHT_CYAN, "SPE_CREATE_MONSTER");
    addSpell(spellList, "detect food", "cyan", P_DIVINATION_SPELL, 30, 3, 2, 1, NODIR, CLR_CYAN, "SPE_DETECT_FOOD");
    addSpell(spellList, "cause fear", "light blue", P_ENCHANTMENT_SPELL, 25, 3, 3, 1, NODIR, CLR_BRIGHT_BLUE, "SPE_CAUSE_FEAR");
    addSpell(spellList, "clairvoyance", "dark blue", P_DIVINATION_SPELL, 15, 3, 3, 1, NODIR, CLR_BLUE, "SPE_CLAIRVOYANCE");
    addSpell(spellList, "cure sickness", "indigo", P_HEALING_SPELL, 32, 3, 3, 1, NODIR, CLR_BLUE, "SPE_CURE_SICKNESS");
    addSpell(spellList, "charm monster", "magenta", P_ENCHANTMENT_SPELL, 20, 3, 5, 1, IMMEDIATE, CLR_MAGENTA, "SPE_CHARM_MONSTER");
    addSpell(spellList, "haste self", "purple", P_ESCAPE_SPELL, 33, 4, 3, 1, NODIR, CLR_MAGENTA, "SPE_HASTE_SELF");
    addSpell(spellList, "detect unseen", "violet", P_DIVINATION_SPELL, 20, 4, 3, 1, NODIR, CLR_MAGENTA, "SPE_DETECT_UNSEEN");
    addSpell(spellList, "levitation", "tan", P_ESCAPE_SPELL, 20, 4, 4, 1, NODIR, CLR_BROWN, "SPE_LEVITATION");
    addSpell(spellList, "extra healing", "plaid", P_HEALING_SPELL, 27, 5, 3, 1, IMMEDIATE, CLR_GREEN, "SPE_EXTRA_HEALING");
    addSpell(spellList, "restore ability", "light brown", P_HEALING_SPELL, 25, 5, 4, 1, NODIR, CLR_BROWN, "SPE_RESTORE_ABILITY");
    addSpell(spellList, "invisibility", "dark brown", P_ESCAPE_SPELL, 20, 5, 4, 1, NODIR, CLR_BROWN, "SPE_INVISIBILITY");
    addSpell(spellList, "detect treasure", "gray", P_DIVINATION_SPELL, 20, 5, 4, 1, NODIR, CLR_GRAY, "SPE_DETECT_TREASURE");
    addSpell(spellList, "remove curse", "wrinkled", P_CLERIC_SPELL, 25, 5, 3, 1, NODIR, HI_PAPER, "SPE_REMOVE_CURSE");
    addSpell(spellList, "magic mapping", "dusty", P_DIVINATION_SPELL, 18, 7, 5, 1, NODIR, HI_PAPER, "SPE_MAGIC_MAPPING");
    addSpell(spellList, "identify", "bronze", P_DIVINATION_SPELL, 20, 6, 3, 1, NODIR, HI_COPPER, "SPE_IDENTIFY");
    addSpell(spellList, "turn undead", "copper", P_CLERIC_SPELL, 16, 8, 6, 1, IMMEDIATE, HI_COPPER, "SPE_TURN_UNDEAD");
    addSpell(spellList, "polymorph", "silver", P_MATTER_SPELL, 10, 8, 6, 1, IMMEDIATE, HI_SILVER, "SPE_POLYMORPH");
    addSpell(spellList, "teleport away", "gold", P_ESCAPE_SPELL, 15, 6, 6, 1, IMMEDIATE, HI_GOLD, "SPE_TELEPORT_AWAY");
    addSpell(spellList, "create familiar", "glittering", P_CLERIC_SPELL, 10, 7, 6, 1, NODIR, CLR_WHITE, "SPE_CREATE_FAMILIAR");
    addSpell(spellList, "cancellation", "shining", P_MATTER_SPELL, 15, 8, 7, 1, IMMEDIATE, CLR_WHITE, "SPE_CANCELLATION");
    addSpell(spellList, "protection", "dull", P_CLERIC_SPELL, 18, 3, 1, 1, NODIR, HI_PAPER, "SPE_PROTECTION");
    addSpell(spellList, "jumping", "thin", P_ESCAPE_SPELL, 20, 3, 1, 1, IMMEDIATE, HI_PAPER, "SPE_JUMPING");
    addSpell(spellList, "stone to flesh", "thick", P_HEALING_SPELL, 15, 1, 3, 1, IMMEDIATE, HI_PAPER, "SPE_STONE_TO_FLESH");
    addSpell(spellList, "chain lightning", "checkered", P_ATTACK_SPELL, 25, 4, 2, 1, NODIR, CLR_GRAY, "SPE_CHAIN_LIGHTNING");

#if 0 //DEFERRED 
    //from slash'em, create a tame critter which explodes when attacking,
    damaging adjacent creatures--friend or foe-- and dying in the process
        addSpell(spellList, "flame sphere", "canvas",
            P_MATTER_SPELL, 20, 2, 1, 1, NODIR, CLR_BROWN,
            ""SPE_FLAME_SPHERE");
            addSpell(spellList, "freeze sphere", "hardcover",
                P_MATTER_SPELL, 20, 2, 1, 1, NODIR, CLR_BROWN,
                ""SPE_FREEZE_SPHERE");
#endif
                //books with fixed descriptions

                addSpell(spellList, "blank paper", "plain", P_NONE, 18, 0, 0, 0, 0, HI_PAPER,
                    "SPE_BLANK_PAPER");
    //LAST_SPELL is used to calculate MAXSPELL, allocation size of spl_book[];
       //by including blank paper, which has no actual spell, we ensure that
       //even if hero learns every spell, spl_book[] will have at least one
       //unused slot at end; an unused slot is needed for use as terminator 
    ////////////////////MARKER(LAST_SPELL, SPE_BLANK_PAPER)
    //////////////////////tribute book for 3.6 
    ////////////////////OBJECT(OBJ("novel", "paperback"");
    ////////////////////BITS(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, P_NONE, PAPER");
    ////////////////////0, SPBOOK_CLASS, 1, 0, 10, 20, 0, 0, 0, 1, 20, CLR_BRIGHT_BLUE,
    ////////////////////"SPE_NOVEL");
    //////////////////////a special, one of a kind, spellbook 
    ////////////////////OBJECT(OBJ("Book of the Dead", "papyrus"");
    ////////////////////BITS(0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, P_NONE, PAPER");
    ////////////////////0, SPBOOK_CLASS, 0, 0, 50, 10000, 0, 0, 0, 7, 20, HI_PAPER,
    ////////////////////"SPE_BOOK_OF_THE_DEAD");
}

void ResourceData::loadWand(std::vector<ObjectWand>& wandList)
{
    //wands ... 
//////////////#define addWand(wandList, name,typ,prob,cost,mgc,dir,metal,color,sn) \
//////////////OBJECT(OBJ(name, typ");                                              \
//////////////BITS(0, 0, 1, 0, mgc, 1, 0, 0, 0, 0, dir, P_NONE, metal");    \
//////////////0, WAND_CLASS, prob, 0, 7, cost, 0, 0, 0, 0, 30, color, sn)
    addWand(wandList, "light", "glass", 95, 100, 1, NODIR, GLASS, HI_GLASS, "WAN_LIGHT");
    addWand(wandList, "secret door detection", "balsa", 50, 150, 1, NODIR, WOOD, HI_WOOD, "WAN_SECRET_DOOR_DETECTION");
    addWand(wandList, "enlightenment", "crystal", 15, 150, 1, NODIR, GLASS, HI_GLASS, "WAN_ENLIGHTENMENT");
    addWand(wandList, "create monster", "maple", 45, 200, 1, NODIR, WOOD, HI_WOOD, "WAN_CREATE_MONSTER");
    addWand(wandList, "wishing", "pine", 5, 500, 1, NODIR, WOOD, HI_WOOD, "WAN_WISHING");
    addWand(wandList, "nothing", "oak", 25, 100, 0, IMMEDIATE, WOOD, HI_WOOD, "WAN_NOTHING");
    addWand(wandList, "striking", "ebony", 75, 150, 1, IMMEDIATE, WOOD, HI_WOOD, "WAN_STRIKING");
    addWand(wandList, "make invisible", "marble", 45, 150, 1, IMMEDIATE, MINERAL, HI_MINERAL, "WAN_MAKE_INVISIBLE");
    addWand(wandList, "slow monster", "tin", 50, 150, 1, IMMEDIATE, METAL, HI_METAL, "WAN_SLOW_MONSTER");
    addWand(wandList, "speed monster", "brass", 50, 150, 1, IMMEDIATE, COPPER, HI_COPPER, "WAN_SPEED_MONSTER");
    addWand(wandList, "undead turning", "copper", 50, 150, 1, IMMEDIATE, COPPER, HI_COPPER, "WAN_UNDEAD_TURNING");
    addWand(wandList, "polymorph", "silver", 45, 200, 1, IMMEDIATE, SILVER, HI_SILVER, "WAN_POLYMORPH");
    addWand(wandList, "cancellation", "platinum", 45, 200, 1, IMMEDIATE, PLATINUM, CLR_WHITE, "WAN_CANCELLATION");
    addWand(wandList, "teleportation", "iridium", 45, 200, 1, IMMEDIATE, METAL, CLR_BRIGHT_CYAN, "WAN_TELEPORTATION");
    addWand(wandList, "opening", "zinc", 25, 150, 1, IMMEDIATE, METAL, HI_METAL, "WAN_OPENING");
    addWand(wandList, "locking", "aluminum", 25, 150, 1, IMMEDIATE, METAL, HI_METAL, "WAN_LOCKING");
    addWand(wandList, "probing", "uranium", 30, 150, 1, IMMEDIATE, METAL, HI_METAL, "WAN_PROBING");
    addWand(wandList, "digging", "iron", 55, 150, 1, RAY, IRON, HI_METAL, "WAN_DIGGING");
    //magic missile ... lightning must be in this order; see buzz() 
    addWand(wandList, "magic missile", "steel", 50, 150, 1, RAY, IRON, HI_METAL, "WAN_MAGIC_MISSILE");
    addWand(wandList, "fire", "hexagonal", 40, 175, 1, RAY, IRON, HI_METAL, "WAN_FIRE");
    addWand(wandList, "cold", "short", 40, 175, 1, RAY, IRON, HI_METAL, "WAN_COLD");
    addWand(wandList, "sleep", "runed", 50, 175, 1, RAY, IRON, HI_METAL, "WAN_SLEEP");
    addWand(wandList, "death", "long", 5, 500, 1, RAY, IRON, HI_METAL, "WAN_DEATH");
    addWand(wandList, "lightning", "curved", 40, 175, 1, RAY, IRON, HI_METAL, "WAN_LIGHTNING");
    //extra descriptions, shuffled into use at start of new game 
    addWand(wandList, NoDes, "forked", 0, 150, 1, 0, WOOD, HI_WOOD, "WAN1");
    addWand(wandList, NoDes, "spiked", 0, 150, 1, 0, IRON, HI_METAL, "WAN2");
    addWand(wandList, NoDes, "jeweled", 0, 150, 1, 0, IRON, HI_MINERAL, "WAN3");
    ////#undef WAND
    ////
}

void ResourceData::loadGem(std::vector<ObjectGem>& gemList)
{
    ////////////////gems ... - includes stones and rocks but not boulders 
    //////////////#define addGem(gemList, name,desc,prob,wt,gval,nutr,mohs,glass,color,sn) \
    //////////////OBJECT(OBJ(name, desc");                                             \
    //////////////BITS(0, 1, 0, 0, 0, 0, 0, 0, 0, \
    //////////////HARDaddGem(gemList, mohs"); 0, -P_SLING, glass");                     \
    //////////////0, GEM_CLASS, prob, 0, 1, gval, 3, 3, 0, 0, nutr, color, sn)
    //////////////#define ROCK(name,desc,kn,prob,wt,gval,sdam,ldam,mgc,nutr,mohs,glass,color,sn) \
    //////////////OBJECT(OBJ(name, desc");                                             \
    //////////////BITS(kn, 1, 0, 0, mgc, 0, 0, 0, 0, \
    //////////////HARDaddGem(gemList, mohs"); 0, -P_SLING, glass");                     \
    //////////////0, GEM_CLASS, prob, 0, wt, gval, sdam, ldam, 0, 0, nutr, color, sn)
    addGem(gemList, "dilithium crystal", "white", 2, 1, 4500, 15, 5, GEMSTONE, CLR_WHITE, "DILITHIUM_CRYSTAL");
    //MARKER(FIRST_REAL_GEM, DILITHIUM_CRYSTAL)
    addGem(gemList, "diamond", "white", 3, 1, 4000, 15, 10, GEMSTONE, CLR_WHITE, "DIAMOND");
    addGem(gemList, "ruby", "red", 4, 1, 3500, 15, 9, GEMSTONE, CLR_RED, "RUBY");
    addGem(gemList, "jacinth", "orange", 3, 1, 3250, 15, 9, GEMSTONE, CLR_ORANGE, "JACINTH");
    addGem(gemList, "sapphire", "blue", 4, 1, 3000, 15, 9, GEMSTONE, CLR_BLUE, "SAPPHIRE");
    addGem(gemList, "black opal", "black", 3, 1, 2500, 15, 8, GEMSTONE, CLR_BLACK, "BLACK_OPAL");
    addGem(gemList, "emerald", "green", 5, 1, 2500, 15, 8, GEMSTONE, CLR_GREEN, "EMERALD");
    addGem(gemList, "turquoise", "green", 6, 1, 2000, 15, 6, GEMSTONE, CLR_GREEN, "TURQUOISE");
    addGem(gemList, "citrine", "yellow", 4, 1, 1500, 15, 6, GEMSTONE, CLR_YELLOW, "CITRINE");
    addGem(gemList, "aquamarine", "green", 6, 1, 1500, 15, 8, GEMSTONE, CLR_GREEN, "AQUAMARINE");
    addGem(gemList, "amber", "yellowish brown", 8, 1, 1000, 15, 2, GEMSTONE, CLR_BROWN, "AMBER");
    addGem(gemList, "topaz", "yellowish brown", 10, 1, 900, 15, 8, GEMSTONE, CLR_BROWN, "TOPAZ");
    addGem(gemList, "jet", "black", 6, 1, 850, 15, 7, GEMSTONE, CLR_BLACK, "JET");
    addGem(gemList, "opal", "white", 12, 1, 800, 15, 6, GEMSTONE, CLR_WHITE, "OPAL");
    addGem(gemList, "chrysoberyl", "yellow", 8, 1, 700, 15, 5, GEMSTONE, CLR_YELLOW, "CHRYSOBERYL");
    addGem(gemList, "garnet", "red", 12, 1, 700, 15, 7, GEMSTONE, CLR_RED, "GARNET");
    addGem(gemList, "amethyst", "violet", 14, 1, 600, 15, 7, GEMSTONE, CLR_MAGENTA, "AMETHYST");
    addGem(gemList, "jasper", "red", 15, 1, 500, 15, 7, GEMSTONE, CLR_RED, "JASPER");
    addGem(gemList, "fluorite", "violet", 15, 1, 400, 15, 4, GEMSTONE, CLR_MAGENTA, "FLUORITE");
    addGem(gemList, "obsidian", "black", 9, 1, 200, 15, 6, GEMSTONE, CLR_BLACK, "OBSIDIAN");
    addGem(gemList, "agate", "orange", 12, 1, 200, 15, 6, GEMSTONE, CLR_ORANGE, "AGATE");
    addGem(gemList, "jade", "green", 10, 1, 300, 15, 6, GEMSTONE, CLR_GREEN, "JADE");
    /////////////////////////////////MARKER(LAST_REAL_GEM, JADE)
    addGem(gemList, "worthless piece of white glass", "white", 77, 1, 0, 6, 5, GLASS, CLR_WHITE, "WORTHLESS_WHITE_GLASS");
    //////////////////////////////////MARKER(FIRST_GLASS_GEM, "WORTHLESS_WHITE_GLASS)
    addGem(gemList, "worthless piece of blue glass", "blue", 77, 1, 0, 6, 5, GLASS, CLR_BLUE, "WORTHLESS_BLUE_GLASS");
    addGem(gemList, "worthless piece of red glass", "red", 77, 1, 0, 6, 5, GLASS, CLR_RED, "WORTHLESS_RED_GLASS");
    addGem(gemList, "worthless piece of yellowish brown glass", "yellowish brown", 77, 1, 0, 6, 5, GLASS, CLR_BROWN, "WORTHLESS_YELLOWBROWN_GLASS");
    addGem(gemList, "worthless piece of orange glass", "orange", 76, 1, 0, 6, 5, GLASS, CLR_ORANGE, "WORTHLESS_ORANGE_GLASS");
    addGem(gemList, "worthless piece of yellow glass", "yellow", 77, 1, 0, 6, 5, GLASS, CLR_YELLOW, "WORTHLESS_YELLOW_GLASS");
    addGem(gemList, "worthless piece of black glass", "black", 76, 1, 0, 6, 5, GLASS, CLR_BLACK, "WORTHLESS_BLACK_GLASS");
    addGem(gemList, "worthless piece of green glass", "green", 77, 1, 0, 6, 5, GLASS, CLR_GREEN, "WORTHLESS_GREEN_GLASS");
    addGem(gemList, "worthless piece of violet glass", "violet", 77, 1, 0, 6, 5, GLASS, CLR_MAGENTA, "WORTHLESS_VIOLET_GLASS");
    /////////////////////////////////////MARKER(LAST_GLASS_GEM, WORTHLESS_VIOLET_GLASS)
}

void ResourceData::loadCoin(std::vector<ObjectCoin>& coinList)
{
    //////coins ... - so far, gold is all there is 
    ////#define COIN(name,prob,metal,worth,sn) \
    ////OBJECT(OBJ(name, NoDes");                                         \
    ////BITS(1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, P_NONE, metal");    \
    ////0, COIN_CLASS, prob, 0, 1, worth, 0, 0, 0, 0, 0, HI_GOLD, sn)
    addCoin(coinList, "gold piece", 1000, GOLD, 1, "GOLD_PIECE");
    //#undef COIN

}

void ResourceData::loadRock(std::vector<ObjectRock>& rockList)
{
    //Placement note: there is a wishable subrange for
    //"gray stones" in the o_ranges[] array in objnam.c
    //that is currently everything between luckstones and flint
    //(inclusive).

    addRock(rockList, "luckstone", "gray", 0, 10, 10, 60, 3, 3, 1, 10, 7, MINERAL, CLR_GRAY, "LUCKSTONE");
    addRock(rockList, "loadstone", "gray", 0, 10, 500, 1, 3, 3, 1, 10, 6, MINERAL, CLR_GRAY, "LOADSTONE");
    addRock(rockList, "touchstone", "gray", 0, 8, 10, 45, 3, 3, 1, 10, 6, MINERAL, CLR_GRAY, "TOUCHSTONE");
    addRock(rockList, "flint", "gray", 0, 10, 10, 1, 6, 6, 0, 10, 7, MINERAL, CLR_GRAY, "FLINT");
    addRock(rockList, "rock", NoDes, 1, 100, 10, 0, 3, 3, 0, 10, 7, MINERAL, CLR_GRAY, "ROCK");
}
