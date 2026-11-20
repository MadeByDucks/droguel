#pragma once

#include <string>
#include <vector>
//#include "sqlite3.h"
#include "ResourceDefs.h"

class ResourceMgr
{
public:
 
    ResourceMgr();
    ~ResourceMgr();


private:

    ///////////////////////////////////////////////////////////////////////////
    std::vector<cmonster>          monsterList;
    std::vector<itemDef>           itemList;
    ///////////////////////////////////////////////////////////////////////////
    std::vector<ObjectProjectile>  projectileList;
    std::vector<ObjectWeapon>      weaponList;
    std::vector<ObjectBow>         bowList;
    std::vector<ObjectHelm>        helmList;
    std::vector<ObjectDragonArmor> dragonArmorList;
    std::vector<ObjectArmor>       armorList;
    std::vector<ObjectCloak>       cloakList;
    std::vector<ObjectShield>      shieldList;
    std::vector<ObjectGloves>      glovesList;
    std::vector<ObjectBoots>       bootsList;
    std::vector<ObjectRing>        ringList;
    std::vector<ObjectAmulet>      amuletList;
    std::vector<ObjectContainer>   containerList;
    std::vector<ObjectTool>        toolList;
    std::vector<ObjectEyeware>     eyewareList;
    std::vector<ObjectWepTool>     weptoolList;
    std::vector<ObjectFood>        foodList;
    std::vector<ObjectPotion>      potionList;
    std::vector<ObjectScroll>      scrollList;
    std::vector<ObjectSpell>       spellList;
    std::vector<ObjectWand>        wandList;
    std::vector<ObjectGem>         gemList;
    std::vector<ObjectCoin>        coinList;
    std::vector<ObjectRock>        rockList;
    ////////////////////////////////////////////////////////////////////////////

public:
    void LoadResources();

public:
    void selectRandomMonster(int& id, std::string& item_str);
    void selectRandomItem(int& id, std::string& item_str);

    void importList();
    void exportList();

    //void getTableData(sqlite3* dbfile);
    //bool openSqlite3Database();
};
