#include "ItemBuildObjects.h"
#include "dnd_chance.h"
#include "TileMap.h"
#include "dpUtilFile.h"
#include "ActiveItemData.h"

ItemBuildObjects::ItemBuildObjects()
{
}

ItemBuildObjects::~ItemBuildObjects()
{
}

void ItemBuildObjects::BuildLevelObjects(TileMap& tilemap, int levelnum)
{

    int id;
    std::string name;

    ActiveItemData item;

    //Single Boss Monster
    tilemap.mResourceMgr.selectRandomMonster(id, name);
    item.m_pos = tilemap.level[levelnum].getRandomOpenTileOnLevel();
    item.name = name;
    tilemap.level[levelnum].item_list.push_back(item);

    //Monster in each room
    for (int j = 0; j < tilemap.level[levelnum].room_list.size(); j++)
    {
        tilemap.mResourceMgr.selectRandomMonster(id, name);
        tilemap.level[levelnum].room_list[j].getRandomTileInRoom(item.m_pos);
        //item.m_pos = tilemap.level[levelnum].getRandomOpenTileOnLevel();
        item.name = name;
        tilemap.level[levelnum].item_list.push_back(item);
    }








    ////Single Boss Object
    //mapPosition boss_pos = tilemap.level[levelnum].getRandomOpenTileOnLevel();





    //ActiveItemData boss_object;
    //boss_object.m_pos = boss_pos;
    //tilemap.level[levelnum].item_list.push_back(boss_object);

    ////Object in each room
    //for (int j = 0; j < tilemap.level[levelnum].room_list.size(); j++)
    //{
    //    ActiveItemData room_object;
    //    tilemap.level[levelnum].room_list[j].getRandomTileInRoom(room_object.m_pos);
    //    tilemap.level[levelnum].item_list.push_back(room_object);
    //}
}

void ItemBuildObjects::AddObject(TileMap& tilemap, int level, TileMap::ObjectType ot, int& line, int& id, int tx, int ty, int tz, int rx, int ry, int rz, int sx, int sy, int sz)
{
    LevelData::ue_item itemRec;
    itemRec.line = line;
    itemRec.id = id;
    itemRec.level = level;
    itemRec.item_type = ot;
    itemRec.pos.tx = tx;
    itemRec.pos.ty = ty;
    itemRec.pos.tz = tz;
    itemRec.pos.rx = rx;
    itemRec.pos.ry = ry;
    itemRec.pos.rz = rz;
    itemRec.pos.sx = sx;
    itemRec.pos.sy = sy;
    itemRec.pos.sz = sz;
    tilemap.level[level].ue_item_list.push_back(itemRec);

    line++;
    id++;
}


void ItemBuildObjects::writeExportData(TileMap& tilemap, std::string fname)
{
    std::vector<std::string> itemfile;
    std::string outstr;

    outstr = ",id,mt,tx,ty,tz,rx,ry,rz,sx,sy,sz";
    itemfile.push_back(outstr);

    for (int lev = 0; lev < tilemap.getNumLevels(); lev++)
    {
        for (int i = 0; i < tilemap.level[lev].ue_item_list.size(); i++)
        {
            LevelData::ue_item m = tilemap.level[lev].ue_item_list[i];

            outstr =
                std::to_string(m.line) + "," +
                std::to_string(m.id) + "," +
                std::to_string(m.item_type) + "," +
                std::to_string(m.pos.tx) + "," +
                std::to_string(m.pos.ty) + "," +
                std::to_string(m.pos.tz) + "," +
                std::to_string(m.pos.rx) + "," +
                std::to_string(m.pos.ry) + "," +
                std::to_string(m.pos.rz) + "," +
                std::to_string(m.pos.sx) + "," +
                std::to_string(m.pos.sy) + "," +
                std::to_string(m.pos.sz) + "";
            itemfile.push_back(outstr);
        }
    }
    itemfile.push_back("");

    CUtilFile::writeStringArrayToFile(itemfile, fname);
}


void ItemBuildObjects::ExportObjectsUE(TileMap& tilemap)
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
    // //                   AddObject(objectfile, TileMap::O_General, line, id, xx + 170, yy - 140, zz + 100, 0, 0, 0, 1, 1, 1);
    //                }
    //                if (tt == TileData::TT_SouthDoor)
    //                {
    // //                   AddObject(objectfile, TileMap::O_General, line, id, xx + 180, yy - 140, zz + 100, 0, 0, 0, 1, 1, 1);
    //                }
    //                if (tt == TileData::TT_EastDoor)
    //                {
    // //                   AddObject(objectfile, TileMap::O_General, line, id, xx + 140, yy - 160, zz + 100, 0, 0, 0, 1, 1, 1);
    //                }
    //                if (tt == TileData::TT_WestDoor)
    //                {
    // //                   AddObject(objectfile, TileMap::O_General, line, id, xx + 140, yy - 160, zz + 100, 0, 0, 0, 1, 1, 1);
    //                }
    //            }
    //        }
    //    }

    for (int levelnum = 0; levelnum < tilemap.getNumLevels(); levelnum++)
    {
        for (int j = 0; j < tilemap.level[levelnum].item_list.size(); j++)
        {
            //offset adjust
            int xx = ((tilemap.level[levelnum].item_list[j].m_pos.x + tilemap.level[levelnum].m_offset_x) * xm);
            int yy = ((tilemap.level[levelnum].item_list[j].m_pos.y + tilemap.level[levelnum].m_offset_y) * ym);
            //int zz = zm - 1500; // (levelnum * zm * -1) - 900;//ttdtodo adjust to just above level
            int zz = (levelnum + tilemap.m_mapdef.m_zlevel_offset) * zm * -1;
            zz += 100;

            //            AddObject(tilemap, levelnum, TileMap::O_General, line, id, xx + 140, yy - 160, zz + 100, 0, 0, 0, 1, 1, 1);
            AddObject(tilemap, levelnum, TileMap::O_General, line, id, xx + 150, yy - 150, zz, 0, 0, 0, 1, 1, 1);
        }
    }
}

void ItemBuildObjects::DrawObjectsToMap(TileMap& tilemap, int levelnum)
{
    for (int list_idx = 0; list_idx < tilemap.level[levelnum].item_list.size(); list_idx++)
    {
        int x = tilemap.level[levelnum].item_list[list_idx].m_pos.x;
        int y = tilemap.level[levelnum].item_list[list_idx].m_pos.y;
        tilemap.setTileChar(x, y, levelnum, "X");
    }
}
