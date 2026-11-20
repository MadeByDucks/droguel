#pragma once
#include "tilemap.h"
#include "MapDefs.h"
#include "RoomData.h"
#include "PathData.h"

class pathfinder
{
public:

    pathfinder();
    ~pathfinder();

    void test();
    void process(MapDefs& mapdef, std::vector<RoomData>& room_list, std::vector<PathData>& path_list);
};
