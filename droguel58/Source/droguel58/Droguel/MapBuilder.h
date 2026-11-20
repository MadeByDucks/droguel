#pragma once

#include <string>
#include <vector>
#include "TileMap.h"
#include "TileData.h"
#include "LevelData.h"
#include "RoomData.h"

class MapBuilder
{
public:
    MapBuilder();
    ~MapBuilder();

    bool CheckRoomCollision(RoomData room, std::vector<RoomData> &room_list);
    void createRoomList(TileMap& tilemap, std::vector<RoomData>& room_list);
    //void OffsetMapLevelBuilder(TileMap& tilemap);
    void writeExportData(TileMap& tilemap, std::string fname);
    void BuildMap(TileMap& tilemap, bool isUE);
    //void BuildMapUE(TileMap& tilemap);
    void ExportMapData(TileMap& tilemap);
    //void BuildMapAndWrite();
};

