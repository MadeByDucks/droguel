#include "ResourceMgr.h"
#include <string>
//#include "sqlite3.h"
#include "dpUtilFile.h"
#include "ResourceDefs.h"
#include "ResourceData.h"
#include "dnd_chance.h"


//rarity and probability
//min num in game
//max num in game
//min level item may/will appears
//max level item may/will appears
//payload - how much can it carry
//items: artifacts and quest items
//monsters: race, sex, aligned, factions
//items+: oder, sounds, color, texture
//
//happy sad angry jealous love content ambivolent possessed confused
//joy trust fear surprise sadness discust anger anticipation (list of 6)
//happiness sadness fear/surprise anger disgust (4 basic)
//surly bad tempered


ResourceMgr::ResourceMgr()
{
}

ResourceMgr::~ResourceMgr()
{
}

void ResourceMgr::LoadResources()
{
    ResourceData rd;

    rd.loadCategories();

    rd.BuildMonsterList(monsterList);

    rd.loadProjectile(projectileList);
    rd.loadWeapon(weaponList);
    rd.loadBow(bowList);
    rd.loadHelm(helmList);
    rd.loadDragonArmor(dragonArmorList);
    rd.loadArmor(armorList);
    rd.loadCloak(cloakList);
    rd.loadShield(shieldList);
    rd.loadGloves(glovesList);
    rd.loadBoots(bootsList);
    rd.loadRing(ringList);
    rd.loadAmulet(amuletList);
    rd.loadContainer(containerList);
    rd.loadTool(toolList);
    rd.loadEyeware(eyewareList);
    rd.loadWepTool(weptoolList);
    rd.loadFood(foodList);
    rd.loadPotion(potionList);
    rd.loadScroll(scrollList);
    rd.loadSpell(spellList);
    rd.loadWand(wandList);
    rd.loadGem(gemList);
    rd.loadCoin(coinList);
    rd.loadRock(rockList);

    for (int i = 0; i < projectileList.size(); i++)
        itemList.push_back(itemDef({ projectileList[i].name, "projectile"}));
    for (int i=0; i<weaponList.size(); i++)
        itemList.push_back(itemDef({ weaponList[i].name, "weapon" }));
    for (int i=0; i<bowList.size(); i++)
        itemList.push_back(itemDef({ bowList[i].name, "bow" }));
    for (int i=0; i<helmList.size(); i++)
        itemList.push_back(itemDef({ helmList[i].name, "helm" }));
    for (int i=0; i<dragonArmorList.size(); i++)
        itemList.push_back(itemDef({ dragonArmorList[i].name, "dragonArmor" }));
    for (int i=0; i<armorList.size(); i++)
        itemList.push_back(itemDef({ armorList[i].name, "armor" }));
    for (int i=0; i<cloakList.size(); i++)
        itemList.push_back(itemDef({ cloakList[i].name, "cloak" }));
    for (int i=0; i<shieldList.size(); i++)
        itemList.push_back(itemDef({ shieldList[i].name, "shield" }));
    for (int i=0; i<glovesList.size(); i++)
        itemList.push_back(itemDef({ glovesList[i].name, "gloves" }));
    for (int i=0; i<bootsList.size(); i++)
        itemList.push_back(itemDef({ bootsList[i].name, "boots" }));
    for (int i=0; i<ringList.size(); i++)
        itemList.push_back(itemDef({ ringList[i].name, "ring" }));
    for (int i=0; i<amuletList.size(); i++)
        itemList.push_back(itemDef({ amuletList[i].name, "amulet" }));
    for (int i=0; i<containerList.size(); i++)
        itemList.push_back(itemDef({ containerList[i].name, "container" }));
    for (int i=0; i<toolList.size(); i++)
        itemList.push_back(itemDef({ toolList[i].name, "tool" }));
    for (int i=0; i<eyewareList.size(); i++)
        itemList.push_back(itemDef({ eyewareList[i].name, "eyeware" }));
    for (int i=0; i<weptoolList.size(); i++)
        itemList.push_back(itemDef({ weptoolList[i].name, "weaponTool" }));
    for (int i=0; i<foodList.size(); i++)
        itemList.push_back(itemDef({ foodList[i].name, "food" }));
    for (int i=0; i<potionList.size(); i++)
        itemList.push_back(itemDef({ potionList[i].name, "potion" }));
    for (int i=0; i<scrollList.size(); i++)
        itemList.push_back(itemDef({ scrollList[i].name, "scroll" }));
    for (int i=0; i<spellList.size(); i++)
        itemList.push_back(itemDef({ spellList[i].name, "spellbook" }));
    for (int i=0; i<wandList.size(); i++)
        itemList.push_back(itemDef({ wandList[i].name, "wand" }));
    for (int i=0; i<gemList.size(); i++)
        itemList.push_back(itemDef({ gemList[i].name, "gem" }));
    for (int i=0; i<coinList.size(); i++)
        itemList.push_back(itemDef({ coinList[i].name, "coin" }));
    for (int i=0; i<rockList.size(); i++)
        itemList.push_back(itemDef({ rockList[i].name, "rock" }));

    exportList();
}

void ResourceMgr::selectRandomMonster(int& id, std::string& item_str)
{
    id = dnd_chance::randomBetween(0, monsterList.size() - 1);

    std::string name;
    name = monsterList[id].namn;
    if (name == "")
    {
        name = monsterList[id].namm;
    }
    if (name == "")
    {
        name = monsterList[id].namf;
    }
    if (name == "")
    {
        name = "error monster name";
    }
    item_str = name;
}

void ResourceMgr::selectRandomItem(int& id, std::string& item_str)
{
    id = dnd_chance::randomBetween(0, itemList.size() - 1);
    std::string name = itemList[id].itemName + ":" + itemList[id].itemName;
    item_str = name;
}

void ResourceMgr::importList()
{

    ////#include "sqlite3.h"
    //open database
    //close database
//    openSqlite3Database();

}

void ResourceMgr::exportList()
{
    std::string fname = "D:\\projects\\devduck\\temp\\droguel\\monstdata.txt";
    std::vector<std::string> list;

    int baseLevelMin = 0;
    int baseLevelMax = 0;

    for (int i = 0; i < monsterList.size(); i++)
    {
        std::string linedata = "";

        linedata += "===========================================================================\n";
        linedata += "===========================================================================\n";
        linedata += "===========================================================================\n";

        linedata += "monster_namen: " + monsterList[i].namn + "\n";
        linedata += "monster_namem: " + monsterList[i].namm + "\n";
        linedata += "monster_namef: " + monsterList[i].namf + "\n";
        linedata += "     *symbol: " + std::to_string(monsterList[i].symbol) + "\n";
        linedata += "     level: \n";
        linedata += "          base_level:        " + std::to_string(monsterList[i].level.base_level) + "\n";
        linedata += "          move_rate_speed:   " + std::to_string(monsterList[i].level.move_rate_speed) + "\n";
        linedata += "          base_armor_class:  " + std::to_string(monsterList[i].level.base_ac_armor_class) + "\n";
        linedata += "          base_magic_resist: " + std::to_string(monsterList[i].level.base_mr_magic_resistance) + "\n";
        linedata += "          alignment:         " + std::to_string(monsterList[i].level.alignment) + "\n";

        linedata += "     size: \n";
        linedata += "          weight:            " + std::to_string(monsterList[i].m_siz.weight) + "\n";
        linedata += "          nut_val:           " + std::to_string(monsterList[i].m_siz.nut_val) + "\n";
        linedata += "          *sound:            " + std::to_string(monsterList[i].m_siz.sound) + "\n";
        linedata += "          size:              " + std::to_string(monsterList[i].m_siz.size) + "\n";

        linedata += "     magic_resist_1:         " + std::to_string(monsterList[i].mr1) + "\n";
        linedata += "     magic_resist_2:         " + std::to_string(monsterList[i].mr2) + "\n";
        linedata += "     flg1:                   " + std::to_string(monsterList[i].flg1) + "\n";
        linedata += "     flg2:                   " + std::to_string(monsterList[i].flg2) + "\n";
        linedata += "     flg3:                   " + std::to_string(monsterList[i].flg3) + "\n";
        linedata += "     dificulty:              " + std::to_string(monsterList[i].dificulty) + "\n";
        linedata += "     color:                  " + std::to_string(monsterList[i].color) + "\n";
        linedata += "     defmon:                 " + monsterList[i].defmon + "\n";

        linedata += "     attack_1: \n";
        linedata += "          attk_type:        " + std::to_string(monsterList[i].m_atk1.attk_type) + "\n";
        linedata += "          damage_type:      " + std::to_string(monsterList[i].m_atk1.damage_type) + "\n";
        linedata += "          numdice:          " + std::to_string(monsterList[i].m_atk1.numdice) + "\n";
        linedata += "          numsides:         " + std::to_string(monsterList[i].m_atk1.numsides) + "\n";

        linedata += "     attack_2: \n";
        linedata += "          attk_type:        " + std::to_string(monsterList[i].m_atk2.attk_type) + "\n";
        linedata += "          damage_type:      " + std::to_string(monsterList[i].m_atk2.damage_type) + "\n";
        linedata += "          numdice:          " + std::to_string(monsterList[i].m_atk2.numdice) + "\n";
        linedata += "          numsides:         " + std::to_string(monsterList[i].m_atk2.numsides) + "\n";

        linedata += "     attack_3: \n";
        linedata += "          attk_type:        " + std::to_string(monsterList[i].m_atk3.attk_type) + "\n";
        linedata += "          damage_type:      " + std::to_string(monsterList[i].m_atk3.damage_type) + "\n";
        linedata += "          numdice:          " + std::to_string(monsterList[i].m_atk3.numdice) + "\n";
        linedata += "          numsides:         " + std::to_string(monsterList[i].m_atk3.numsides) + "\n";

        linedata += "     attack_4: \n";
        linedata += "          attk_type:        " + std::to_string(monsterList[i].m_atk4.attk_type) + "\n";
        linedata += "          damage_type:      " + std::to_string(monsterList[i].m_atk4.damage_type) + "\n";
        linedata += "          numdice:          " + std::to_string(monsterList[i].m_atk4.numdice) + "\n";
        linedata += "          numsides:         " + std::to_string(monsterList[i].m_atk4.numsides) + "\n";

        linedata += "     attack_5: \n";
        linedata += "          attk_type:        " + std::to_string(monsterList[i].m_atk5.attk_type) + "\n";
        linedata += "          damage_type:      " + std::to_string(monsterList[i].m_atk5.damage_type) + "\n";
        linedata += "          numdice:          " + std::to_string(monsterList[i].m_atk5.numdice) + "\n";
        linedata += "          numsides:         " + std::to_string(monsterList[i].m_atk5.numsides) + "\n";

        linedata += "     attack_6: \n";
        linedata += "          attk_type:        " + std::to_string(monsterList[i].m_atk6.attk_type) + "\n";
        linedata += "          damage_type:      " + std::to_string(monsterList[i].m_atk6.damage_type) + "\n";
        linedata += "          numdice:          " + std::to_string(monsterList[i].m_atk6.numdice) + "\n";
        linedata += "          numsides:         " + std::to_string(monsterList[i].m_atk6.numsides) + "\n";

        if (monsterList[i].level.base_level < baseLevelMin)
            baseLevelMin = monsterList[i].level.base_level;
        if (monsterList[i].level.base_level > baseLevelMax)
            baseLevelMax = monsterList[i].level.base_level;

        list.push_back(linedata);
    }

    std::string stats;
    stats = "base level min/max: " + std::to_string(baseLevelMin) + "/" + std::to_string(baseLevelMax);
    list.insert(list.begin(), stats);

    CUtilFile::writeStringArrayToFile(list, fname);
}










//// seelct all data from table 
//void ResourceMgr::getTableData(sqlite3* dbfile)
//{
//    sqlite3_stmt* statement;
//
//    //char *query = "select * from dbt_Table";
//    std::string query = "select * from dbt_Table";
//
//    if (sqlite3_prepare(dbfile, query.c_str(), -1, &statement, 0) == SQLITE_OK)
//    {
//        int ctotal = sqlite3_column_count(statement);
//        int res = 0;
//
//        while (1)
//        {
//            res = sqlite3_step(statement);
//
//            if (res == SQLITE_ROW)
//            {
//                for (int i = 0; i < ctotal; i++)
//                {
//                    std::string s = (char*)sqlite3_column_text(statement, i);
//                    // print or format the output as you want 
////                    std::cout << s << " ";
//                }
//                //                std::cout << std::endl;
//            }
//
//            if (res == SQLITE_DONE || res == SQLITE_ERROR)
//            {
//                //                std::cout << "done " << std::endl;
//                break;
//            }
//        }
//    }
//}


//bool ResourceMgr::openSqlite3Database()
//{
//
//    //AccessCvsToSqliteSql();
//
//
// //   CUtilFile x;
//
//    //x.removeFile("C:\\projects\\here\\junk.txt");
//    //x.copyFile("C:\\projects\\here\\junk1.txt", "C:\\projects\\here\\junk2.txt");
//    //std::vector<std::string> features = { "X1", "X2", "X3", "X4" };
//    //x.writeStringArrayToFile(features, "C:\\projects\\here\\junk3.txt");
//
//    bool bSuccess = true;
//    //    CUtilString y;
//    //    std::string envVal = y.getEnvironmentVar( "DevDuck" );
//    //    std::string fname = envVal + "\\DatabaseFiles\\devduckdata.db";
//    std::string fname = "D:\\projects\\devduck\\drog\\db\\drogdb.db";
//
//    sqlite3* db;
//    char* zErrMsg = 0;
//    int rc;
//
//    //if (argc != 3)
//    //{
//    //    fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
//    //    return(1);
//    //}
//    rc = sqlite3_open(fname.c_str(), &db);
//    if (rc)
//    {
//
//        //        dpUtilLog::outputProgress( "Can't open database: " + std::string( sqlite3_errmsg( db ) ) + "\n" );
//                //fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//        sqlite3_close(db);
//        bSuccess = false;
//    }
//
//    if (rc == SQLITE_OK)
//    {
//        getTableData(db);
//        int x = 9;
//    }
//
//    //rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
//    //if (rc != SQLITE_OK)
//    //{
//    //    fprintf(stderr, "SQL error: %s\n", zErrMsg);
//    //    sqlite3_free(zErrMsg);
//    //}
//    sqlite3_close(db);
//
//    return bSuccess;
//}



