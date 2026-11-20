#include "CharBuildMonsters.h"
#include "dnd_chance.h"
#include "LevelData.h"
#include "dpUtilFile.h"

CharBuildMonsters::CharBuildMonsters()
{
}

CharBuildMonsters::~CharBuildMonsters()
{
}

void CharBuildMonsters::BuildLevelMonsters(TileMap& tilemap, int levelnum)
{
    int id;
    std::string name;    
    
    ActiveCharMonster monst;

    //Single Boss Monster
    tilemap.mResourceMgr.selectRandomMonster(id, name);
    monst.m_pos = tilemap.level[levelnum].getRandomOpenTileOnLevel();
    monst.name = name;
    monst.isBoss = true;
    tilemap.level[levelnum].monster_list.push_back(monst);
  
    //Monster in each room
    for (int j = 0; j < tilemap.level[levelnum].room_list.size(); j++)
    {
        tilemap.mResourceMgr.selectRandomMonster(id, name);
        tilemap.level[levelnum].room_list[j].getRandomTileInRoom(monst.m_pos);
        //monst.m_pos = tilemap.level[levelnum].getRandomOpenTileOnLevel();
        monst.name = name;
        monst.isBoss = true;
        tilemap.level[levelnum].monster_list.push_back(monst);
    }
}

void CharBuildMonsters::writeExportData(TileMap& tilemap, std::string fname)
{
    std::vector<std::string> monsterfile;
    std::string outstr;

    outstr = ",id,mt,tx,ty,tz,rx,ry,rz,sx,sy,sz";
    monsterfile.push_back(outstr);

    for (int lev = 0; lev < tilemap.getNumLevels(); lev++)
    {
        for (int i = 0; i < tilemap.level[lev].ue_monster_list.size(); i++)
        {
            LevelData::ue_monster m = tilemap.level[lev].ue_monster_list[i];

            outstr =
                std::to_string(m.line) + "," +
                std::to_string(m.id) + "," +
                std::to_string(m.mt) + "," +
                std::to_string(m.pos.tx) + "," +
                std::to_string(m.pos.ty) + "," +
                std::to_string(m.pos.tz) + "," +
                std::to_string(m.pos.rx) + "," +
                std::to_string(m.pos.ry) + "," +
                std::to_string(m.pos.rz) + "," +
                std::to_string(m.pos.sx) + "," +
                std::to_string(m.pos.sy) + "," +
                std::to_string(m.pos.sz) + "";
            monsterfile.push_back(outstr);
        }
    }
    monsterfile.push_back("");

    CUtilFile::writeStringArrayToFile(monsterfile, fname);
}

void CharBuildMonsters::AddMonster(TileMap& tilemap, int level, TileMap::MonsterType mt, int& line, int &id, int tx, int ty, int tz, int rx, int ry, int rz, int sx, int sy, int sz)
{
    LevelData::ue_monster monsterRec;
    monsterRec.line = line;
    monsterRec.id = id;
    monsterRec.level = level;
    monsterRec.mt = mt;
    monsterRec.pos.tx = tx;
    monsterRec.pos.ty = ty;
    monsterRec.pos.tz = tz;
    monsterRec.pos.rx = rx;
    monsterRec.pos.ry = ry;
    monsterRec.pos.rz = rz;
    monsterRec.pos.sx = sx;
    monsterRec.pos.sy = sy;
    monsterRec.pos.sz = sz;
    tilemap.level[level].ue_monster_list.push_back(monsterRec);

    line++;
    id++;
}

void CharBuildMonsters::ExportMonsterUE(TileMap& tilemap)
{
    int line = 0;
    int id = 0;
    int xm = tilemap.m_mapdef.xm;//300; //301; //100;
    int ym = tilemap.m_mapdef.ym;//300; //301; //100;
    int zm = tilemap.m_mapdef.zm;//800; //600 //500
//
//    for (int levelnum = 0; levelnum < tilemap.getNumLevels(); levelnum++)
//    {
//        for (int x = 0; x < tilemap.m_mapdef.m_num_x_tiles; x++)
//        {
//            for (int y = 0; y < tilemap.m_mapdef.m_num_y_tiles; y++)
//            {
//                int xx = ((x + tilemap.level[levelnum].m_offset_x) * xm);
//                int yy = ((y + tilemap.level[levelnum].m_offset_y) * ym);
//                int zz = (levelnum + tilemap.m_mapdef.m_zlevel_offset) * zm * -1;
//
//                TileData::TileType tt = tilemap.m_tilemap[x][y][levelnum].tiletype;
//
//
//                ///////////////////////////////////////////////////////////////
//                // doors
//                ///////////////////////////////////////////////////////////////
//                if (tt == TileData::TT_NorthDoor)
//                {
// //                   AddMonster(monsterfile, TileMap::M_General, line, id, xx + 170, yy - 140, zz + 100, 0, 0, 0, 1, 1, 1);
//                }
//                if (tt == TileData::TT_SouthDoor)
//                {
// //                   AddMonster(monsterfile, TileMap::M_General, line, id, xx + 180, yy - 140, zz + 100, 0, 0, 0, 1, 1, 1);
//                }
//                if (tt == TileData::TT_EastDoor)
//                {
// //                   AddMonster(monsterfile, TileMap::M_General, line, id, xx + 140, yy - 160, zz + 100, 0, 0, 0, 1, 1, 1);
//                }
//                if (tt == TileData::TT_WestDoor)
//                {
// //                   AddMonster(monsterfile, TileMap::M_General, line, id, xx + 140, yy - 160, zz + 100, 0, 0, 0, 1, 1, 1);
//                }
//            }
//        }
//    }

    for (int levelnum = 0; levelnum < tilemap.getNumLevels(); levelnum++)
    {
        for (int j = 0; j < tilemap.level[levelnum].monster_list.size(); j++)
        {
            //offset adjust
            int xx = ((tilemap.level[levelnum].monster_list[j].m_pos.x + tilemap.level[levelnum].m_offset_x) * xm);
            int yy = ((tilemap.level[levelnum].monster_list[j].m_pos.y + tilemap.level[levelnum].m_offset_y) * ym);
            //int zz = zm - 1500; // (levelnum * zm * -1) - 900;//ttdtodo adjust to just above level
            int zz = (levelnum + tilemap.m_mapdef.m_zlevel_offset) * zm * -1;
            zz += 100;

//            AddMonster(tilemap, levelnum, TileMap::M_General, line, id, xx + 140, yy - 160, zz + 100, 0, 0, 0, 1, 1, 1);
            AddMonster(tilemap, levelnum, TileMap::M_General, line, id, xx + 150, yy - 150, zz, 0, 0, 0, 1, 1, 1);
        }
    }
}

void CharBuildMonsters::DrawMonstersToMap(TileMap& tilemap, int levelnum)
{
    for (int list_idx = 0; list_idx < tilemap.level[levelnum].monster_list.size(); list_idx++)
    {
        int x = tilemap.level[levelnum].monster_list[list_idx].m_pos.x;
        int y = tilemap.level[levelnum].monster_list[list_idx].m_pos.y;
        tilemap.setTileChar(x, y, levelnum, "M");
    }
}
