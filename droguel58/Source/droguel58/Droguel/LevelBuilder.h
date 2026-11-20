#pragma once
#include <vector>
#include <string>
#include "RoomData.h"
#include "MapDefs.h"
#include "PathData.h"
#include "TileData.h"
#include "TileMap.h"
//#include "CharMonsterData.h"
#include "LevelData.h"

class LevelBuilder
{
public:

    LevelBuilder();
    ~LevelBuilder();

    void BuildConnectionList(MapDefs& mapdef, std::vector<RoomData>& room_list, std::vector<PathData>& path_list, int levelnum);
    void BuildDoors(std::vector<RoomData>& room_list, std::vector<PathData>& path_list);
    void BuildPathList(MapDefs& mapdef, std::vector<RoomData>& room_list, std::vector<PathData>& path_list);
    void BuildStairs(LevelData& level_info, std::vector<RoomData>& room_list, std::vector<TileData>& stair_list);
    void buildLevel(TileMap& tilemap, int levelnum);
};
