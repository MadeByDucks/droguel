#pragma once

#include <string>
//#include "sqlite3.h"
#include "dpUtilFile.h"
#include "ResourceDefs.h"

class ResourceData
{
public:

    ResourceData();
    ~ResourceData();

    void insertCharCat(std::string ascii, std::string desc);
    void insertMonster(std::string ascii, std::string fname, std::string desc);
    void loadCategories();

    void BuildMonsterList(std::vector<cmonster>& ml);
    void buildMonsterList1(std::vector<cmonster> &ml);
    void buildMonsterList2(std::vector<cmonster> &ml);
    void buildMonsterList3(std::vector<cmonster> &ml);
    void buildMonsterList4(std::vector<cmonster> &ml);
    void buildMonsterList5(std::vector<cmonster> &ml);
    void buildMonsterList6(std::vector<cmonster> &ml);

    void addMonster(std::vector<cmonster>& ml, std::string namm, std::string namf, std::string namn, SYSMON symbol, LVL level, long geno,
        ATTK at1, ATTK at2, ATTK at3, ATTK at4, ATTK at5, ATTK at6, SIZ sizrec,
        int mr1, int mr2, long flg1, long flg2, long flg3, int dificulty, int color, std::string defmon);    void addProjectile  (std::vector<ObjectProjectile>  &projectileList, std::string name, std::string desc, int kn, int prob, int wt, int cost, int sdam, int ldam, int hitbon, int metal, int sub_x, int color, std::string sn);
    void addWeapon      (std::vector<ObjectWeapon>      &weaponList, std::string name, std::string desc, int kn, int mg, int bi, int prob, int wt, int cost, int sdam, int ldam, int hitbon, int typ, int sub_x, int metal, int color, std::string sn);
    void addBow         (std::vector<ObjectBow>         &bowList, std::string name, std::string desc, int kn, int prob, int wt, int cost, int hitbon, int metal, int sub_x, int color, std::string sn);
    void addHelm        (std::vector<ObjectHelm>        &helmList, std::string name, std::string desc, int kn, int mgc, int power, int prob, int delay, int wt, int cost, int ac, int can, int metal, int c, std::string sn);
    void addDragonArmor (std::vector<ObjectDragonArmor> &dragonArmorList, std::string name, int mgc, int power, int cost, int ac, int color, std::string snam);
    void addArmor       (std::vector<ObjectArmor>       &armorList, std::string name, std::string desc, int kn, int mgc, int blk, int power, int prob, int delay, int wt, int cost, int ac, int can, int sub, int metal, int c, std::string sn);
    void addCloak       (std::vector<ObjectCloak>       &cloakList, std::string name, std::string desc, int kn, int mgc, int power, int prob, int delay, int wt, int cost, int ac, int can, int metal, int c, std::string sn);
    void addShield      (std::vector<ObjectShield>      &shieldList, std::string name, std::string desc, int kn, int mgc, int blk, int power, int prob, int delay, int wt, int cost, int ac, int can, int metal, int c, std::string sn);
    void addGloves      (std::vector<ObjectGloves>      &glovesList, std::string name, std::string desc, int kn, int mgc, int power, int prob, int delay, int wt, int cost, int ac, int can, int metal, int c, std::string sn);
    void addBoots       (std::vector<ObjectBoots>       &bootsList, std::string name, std::string desc, int kn, int mgc, int power, int prob, int delay, int wt, int cost, int ac, int can, int metal, int c, std::string sn);
    void addRing        (std::vector<ObjectRing>        &ringList, std::string name, std::string stone, int power, int cost, int mgc, int spec, int mohs, int metal, int color, std::string sn);
    void addAmulet      (std::vector<ObjectAmulet>      &amuletList, std::string name, std::string desc, int power, int prob, std::string sn);
    void addContainer   (std::vector<ObjectContainer>   &containerList, std::string name, std::string desc, int kn, int mgc, int chg, int prob, int wt, int cost, int mat, int color, std::string sn);
    void addTool        (std::vector<ObjectTool>        &toolList, std::string name, std::string desc, int kn, int mrg, int mgc, int chg, int prob, int wt, int cost, int mat, int color, std::string sn);
    void addEyeware     (std::vector<ObjectEyeware>     &eyewareList, std::string name, std::string desc, int kn, int prop, int prob, int wt, int cost, int mat, int color, std::string sn);
    void addWepTool     (std::vector<ObjectWepTool>     &weptoolList, std::string name, std::string desc, int kn, int mgc, int bi, int prob, int wt, int cost, int sdam, int ldam, int hitbon, int sub, int mat, int clr, std::string sn);
    void addFood        (std::vector<ObjectFood>        &foodList, std::string name, int prob, int delay, int wt, int unk, int tin, int nutrition, int color, std::string sn);
    void addPotion      (std::vector<ObjectPotion>      &potionList, std::string name, std::string desc, int mgc, int power, int prob, int cost, int color, std::string sn);
    void addScroll      (std::vector<ObjectScroll>      &scrollList, std::string name, std::string text, int mgc, int prob, int cost, std::string sn);
    void addSpell       (std::vector<ObjectSpell>       &spellList, std::string name, std::string desc, int sub, int prob, int delay, int level, int mgc, int dir, int color, std::string sn);
    void addWand        (std::vector<ObjectWand>        &wandList, std::string name, std::string typ, int prob, int cost, int mgc, int dir, int metal, int color, std::string sn);
    void addGem         (std::vector<ObjectGem>         &gemList, std::string name, std::string desc, int prob, int wt, int gval, int nutr, int mohs, int glass, int color, std::string sn);
    void addCoin        (std::vector<ObjectCoin>        &coinList, std::string name, int prob, int metal, int worth, std::string sn);
    void addRock        (std::vector<ObjectRock>        &rockList, std::string name, std::string desc, int kn, int prob, int wt, int gval, int sdam, int ldam, int mgc, int nutr, int mohs, int glass, int color, std::string sn);

    void loadProjectile (std::vector<ObjectProjectile>  &projectileList);
    void loadWeapon     (std::vector<ObjectWeapon>      &weaponList);
    void loadBow        (std::vector<ObjectBow>         &bowList);
    void loadHelm       (std::vector<ObjectHelm>        &helmList);
    void loadDragonArmor(std::vector<ObjectDragonArmor> &dragonArmorList);
    void loadArmor      (std::vector<ObjectArmor>       &armorList);
    void loadCloak      (std::vector<ObjectCloak>       &cloakList);
    void loadShield     (std::vector<ObjectShield>      &shieldList);
    void loadGloves     (std::vector<ObjectGloves>      &glovesList);
    void loadBoots      (std::vector<ObjectBoots>       &bootsList);
    void loadRing       (std::vector<ObjectRing>        &ringList);
    void loadAmulet     (std::vector<ObjectAmulet>      &amuletList);
    void loadContainer  (std::vector<ObjectContainer>   &containerList);
    void loadTool       (std::vector<ObjectTool>        &toolList);
    void loadEyeware    (std::vector<ObjectEyeware>     &eyewareList);
    void loadWepTool    (std::vector<ObjectWepTool>     &weptoolList);
    void loadFood       (std::vector<ObjectFood>        &foodList);
    void loadPotion     (std::vector<ObjectPotion>      &potionList);
    void loadScroll     (std::vector<ObjectScroll>      &scrollList);
    void loadSpell      (std::vector<ObjectSpell>       &spellList);
    void loadWand       (std::vector<ObjectWand>        &wandList);
    void loadGem        (std::vector<ObjectGem>         &gemList);
    void loadCoin       (std::vector<ObjectCoin>        &coinList);
    void loadRock       (std::vector<ObjectRock>        &rockList);

    //void buildObjectList1();
};
