#pragma once
#include <vector>
#include "RoomData.h"
#include "MapDefs.h"

class alg_bsp
{
public:

    alg_bsp();
    ~alg_bsp();


    //int GetBlockWidth(RoomData room);
    //int GetBlockHeight(RoomData room);
    int GetBlockWidthX(RoomData::MapRect block);
    int GetBlockHeightY(RoomData::MapRect block);


    void bspRecursive(MapDefs &mapdef, std::vector<RoomData>& room_list, RoomData rect_in, int levelnum, int& iteration);

    void buildRoomBlocks(MapDefs &mapdef, std::vector<RoomData>& room_list, int levelnum);
    void BuildRoomsFromBlocks(MapDefs &mapdef, std::vector<RoomData>& room_list);
};
