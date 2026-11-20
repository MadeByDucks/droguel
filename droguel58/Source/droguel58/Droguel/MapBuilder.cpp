#include "MapBuilder.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <random>
#include "dpUtilFile.h"
#include "dpUtilDate.h"
#include "dpUtilLog.h"
#include "dpUtilString.h"
#include "dnd_chance.h"
#include "MapDefs.h"
#include "pathfinder.h"
#include "LevelBuilder.h"
#include "TileMapBuilder.h"
#include "ItemBuildObjects.h"
#include "CharBuildMonsters.h"
#include "MapBuildConnector.h"




//rooms: add secret room with no access
//room types and crazy names


//ttdtodo
//path active / selected and connection make one var
//Only make active paths and doors


MapBuilder::MapBuilder()
{
}


MapBuilder::~MapBuilder()
{
}

bool MapBuilder::CheckRoomCollision(RoomData room, std::vector<RoomData>& room_list)
{
    //todo: add buffer vars
    bool collision = false;
    for (int i = 0; ((i < room_list.size()) && (!collision)); i++)
    {
        RoomData compare = room_list[i];
        collision = (
            ((room.block.x1 >= compare.block.x1) && (room.block.x1 <= compare.block.x2)) ||
            ((room.block.x2 >= compare.block.x1) && (room.block.x2 <= compare.block.x2)) ||
            ((room.block.y1 >= compare.block.y1) && (room.block.y1 <= compare.block.y2)) ||
            ((room.block.y2 >= compare.block.y1) && (room.block.y2 <= compare.block.y2))
            );
    }

    return collision;
}

void MapBuilder::createRoomList(TileMap& tilemap, std::vector<RoomData>& room_list)
{
    //int num_rooms = getRandomInt(tilemap.getNumRoomsMin(), tilemap.getNumRoomsMax()); //5-10 but 4-12

    //for (int i = 0; i < num_rooms; i++)
    //{
    //    room_rec room;

    //    //gerate random room with random placement - try x number of times in case of collisions
    //    bool roomPlaced = false;
    //    int count = 0;
    //    while ((!roomPlaced) && (count < 1000))
    //    {
    //        int height = getRandomInt(tilemap.getRoomMinHeight(), tilemap.getRoomMaxHeight());
    //        int width = getRandomInt(tilemap.getRoomMinWidth(), tilemap.getRoomMaxWidth());

    //        room.x1 = getRandomInt(0, tilemap.getSizeX() - width);
    //        room.y1 = getRandomInt(0, tilemap.getSizeY() - height);
    //        room.x2 = room.x1 + width;
    //        room.y2 = room.y1 + height;

    //        roomPlaced = (!CheckRoomCollision(room, room_list));
    //        //roomPlaced = true;
    //        count++;
    //    }

    //    if (roomPlaced)
    //    {
    //        room_list.push_back(room);
    //    }
    //}
}



void MapBuilder::writeExportData(TileMap& tilemap, std::string fname)
{
    std::vector<std::string> outfile;
    std::string outstr;

    //line no / id / transform / rotate / scale
    //outstr = "'', 'id', 'tx', 'ty', 'tz', 'rx', 'ry', 'rz', 'sx', 'sy', 'sz'"; 
    outstr = ",id,tt,tx,ty,tz,rx,ry,rz,sx,sy,sz";
    outfile.push_back(outstr);

    for (int lev = 0; lev < tilemap.getNumLevels(); lev++)
    {
        for (int i = 0; i < tilemap.level[lev].ue_panel_list.size(); i++)
        {
            LevelData::ue_panels p = tilemap.level[lev].ue_panel_list[i];
            p.line = i; //ttdtodo set earlier

            outstr =
                std::to_string(p.line) + "," +
                std::to_string(p.id) + "," +
                std::to_string(p.tt) + "," +
                std::to_string(p.pos.tx) + "," +
                std::to_string(p.pos.ty) + "," +
                std::to_string(p.pos.tz) + "," +
                std::to_string(p.pos.rx) + "," +
                std::to_string(p.pos.ry) + "," +
                std::to_string(p.pos.rz) + "," +
                std::to_string(p.pos.sx) + "," +
                std::to_string(p.pos.sy) + "," +
                std::to_string(p.pos.sz) + "";
            outfile.push_back(outstr);
        }
    }
    outfile.push_back("");

    CUtilFile::writeStringArrayToFile(outfile, fname);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void MapBuilder::BuildMap(TileMap& tilemap, bool isUE)
{
    MapBuildConnector buildConnector;

    srand(unsigned int(time(0)));  // Initialize random number generator.


    //build the phisical levels
    LevelBuilder levbuilder;
    for (int i = 0; i < tilemap.getNumLevels(); i++)
    {
        levbuilder.buildLevel(tilemap, i);
    }
    buildConnector.BuildConnectors(tilemap, isUE);


    //Add monsters / items / etc.
    ItemBuildObjects objectUtil;
    CharBuildMonsters monster_util;
    for (int levnum = 0; levnum < tilemap.getNumLevels(); levnum++)
    {
        monster_util.BuildLevelMonsters(tilemap, levnum);
        objectUtil.BuildLevelObjects(tilemap, levnum);
    }

    //Build the char matrix
    TileMapBuilder tmb;    
    tmb.CreateTileMap(tilemap);
    tmb.ExportTileMapUE(tilemap);
    monster_util.ExportMonsterUE(tilemap);
    objectUtil.ExportObjectsUE(tilemap);
}


void MapBuilder::ExportMapData(TileMap& tilemap)
{
    CharBuildMonsters monster_util;
    ItemBuildObjects objectUtil;

    //Write out files    
    tilemap.dumpTileMap("D:\\projects\\devduck\\temp\\droguel\\leveldata.txt");

    writeExportData(tilemap, "D:\\projects\\devduck\\temp\\droguel\\exportlevel3.csv");
    writeExportData(tilemap, "D:\\projects\\droguel_test_cpp\\droguel_test_cpp\\Content\\DroguelContent\\exportlevel3.csv");
    writeExportData(tilemap, "D:\\projects\\droguel\\droguel\\Content\\Droguel\\exportlevel.csv");

    monster_util.writeExportData(tilemap, "D:\\projects\\devduck\\temp\\droguel\\exportmonster.csv");
    monster_util.writeExportData(tilemap, "D:\\projects\\droguel_test_cpp\\droguel_test_cpp\\Content\\DroguelContent\\exportmonster.csv");
    monster_util.writeExportData(tilemap, "D:\\projects\\droguel\\droguel\\Content\\Droguel\\exportmonster.csv");

    objectUtil.writeExportData(tilemap, "D:\\projects\\devduck\\temp\\droguel\\exportobject.csv");
    objectUtil.writeExportData(tilemap, "D:\\projects\\droguel_test_cpp\\droguel_test_cpp\\Content\\DroguelContent\\exportobject.csv");
    objectUtil.writeExportData(tilemap, "D:\\projects\\droguel\\droguel\\Content\\Droguel\\exportobject.csv");
}

