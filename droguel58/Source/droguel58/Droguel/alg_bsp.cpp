#include "alg_bsp.h"
#include "dnd_chance.h"

//Implementation of the BSP(binary space partitioning)


alg_bsp::alg_bsp()
{
}


alg_bsp::~alg_bsp()
{
}



////todo remove
//int alg_bsp::GetBlockWidth(RoomData room)
//{
//    return (room.block.x2 - room.block.x1 + 1);
//}
//
////todo remove
//int alg_bsp::GetBlockHeight(RoomData room)
//{
//    return (room.block.y2 - room.block.y1 + 1);
//}

int alg_bsp::GetBlockWidthX(RoomData::MapRect block)
{
    return (block.x2 - block.x1 + 1);
}

int alg_bsp::GetBlockHeightY(RoomData::MapRect block)
{
    return (block.y2 - block.y1 + 1);
}



//go by count or size
void alg_bsp::bspRecursive(MapDefs& mapdef, std::vector<RoomData>& room_list,  RoomData rect_in, int levelnum, int& iteration)
{
    enum SplitType { horizontal, vertical, no_split };
    SplitType split = horizontal;

    RoomData rect_top;
    RoomData rect_bottom;
    RoomData rect_left;
    RoomData rect_right;

    bool forceFlip = true;
    bool half_alg = false;

    int min_horz = 7; // 3;// 5; //ttdtodo: runtime error if < 4
    int min_vert = 15;// 8;//15;

    int split_horz = 0;
    int split_vert = 0;

    if (dnd_chance::pickRandom())
        split = horizontal;
    else
        split = vertical;

    ///////////////////////////////////////////////////////////////////////////
    //calculate a spit_horz and split_vert value
    ///////////////////////////////////////////////////////////////////////////

    if (half_alg)
    {
        //todo: is plus one okay
        int height = (rect_in.block.y2 - rect_in.block.y1 + 1);
        split_horz = height / 2; //remainder = height % 2;

        int width = (rect_in.block.x2 - rect_in.block.x1 + 1);
        split_vert = width / 2; //remainder = width % 2;
    }
    else
    {
        //todo: is plus one okay
        //        int padding = 3;
        split_horz = dnd_chance::randomSplit(rect_in.block.y1, rect_in.block.y2, min_horz);// padding);
        split_vert = dnd_chance::randomSplit(rect_in.block.x1, rect_in.block.x2, min_vert);// padding);
        //add padding steps that match minimum-ish??
    }

    ///////////////////////////////////////////////////////////////////////////
    //horizontal calculations
    ///////////////////////////////////////////////////////////////////////////

    rect_top.level = levelnum;
    rect_top.iteration = iteration;
    rect_top.block.x1 = rect_in.block.x1;
    rect_top.block.y1 = rect_in.block.y1;
    rect_top.block.x2 = rect_in.block.x2;
    rect_top.block.y2 = split_horz;

    rect_bottom.level = levelnum;
    rect_bottom.iteration = iteration;
    rect_bottom.block.x1 = rect_in.block.x1;
    rect_bottom.block.y1 = split_horz + 1;
    rect_bottom.block.x2 = rect_in.block.x2;
    rect_bottom.block.y2 = rect_in.block.y2;

    ///////////////////////////////////////////////////////////////////////////
    //vertical calculations
    ///////////////////////////////////////////////////////////////////////////

    rect_left.level = levelnum;
    rect_left.iteration = iteration;
    rect_left.block.x1 = rect_in.block.x1;
    rect_left.block.y1 = rect_in.block.y1;
    rect_left.block.x2 = split_vert;
    rect_left.block.y2 = rect_in.block.y2;

    rect_right.level = levelnum;
    rect_right.iteration = iteration;
    rect_right.block.x1 = split_vert + 1;
    rect_right.block.y1 = rect_in.block.y1;
    rect_right.block.x2 = rect_in.block.x2;
    rect_right.block.y2 = rect_in.block.y2;

    ///////////////////////////////////////////////////////////////////////////
    // 
    ///////////////////////////////////////////////////////////////////////////

    bool top_safe = rect_top.getRoomBlockLength()/*GetBlockHeight(rect_top)*/ >= min_horz;
    bool bottom_safe = rect_bottom.getRoomBlockLength()/*GetBlockHeight(rect_bottom)*/ >= min_horz;
    bool left_safe = rect_left.getRoomBlockWidth()/*GetBlockWidth(rect_left)*/ >= min_vert;
    bool right_safe = rect_right.getRoomBlockWidth()/*GetBlockWidth(rect_right)*/ >= min_vert;

    ///////////////////////////////////////////////////////////////////////////
    // checks
    ///////////////////////////////////////////////////////////////////////////

     //force flip
    if ((forceFlip) && (split == horizontal))
    {
        if ((!top_safe) || (!bottom_safe))
            split = vertical;
    }
    else if ((forceFlip) && (split == vertical))
    {
        if ((!left_safe) || (!right_safe))
            split = horizontal;
    }

    //abort split either side is too small
    //add always split - one too small, one okay, split anyway
    if (split == horizontal)
    {
        if ((!top_safe) || (!bottom_safe))
            split = no_split;
    }
    if (split == vertical)
    {
        if ((!left_safe) || (!right_safe))
            split = no_split;
    }

    ///////////////////////////////////////////////////////////////////////////
    // recursion or leaf
    ///////////////////////////////////////////////////////////////////////////

    if (split == no_split)
    {
        room_list.push_back(rect_in);
    }
    else
    {
        iteration++;
        int cur_iteration = iteration;
        if (split == horizontal)
        {
            bspRecursive(mapdef, room_list, rect_top, levelnum, cur_iteration);
            bspRecursive(mapdef, room_list, rect_bottom, levelnum, cur_iteration);
        }
        else //(split == vertical)
        {
            bspRecursive(mapdef, room_list, rect_left, levelnum, cur_iteration);
            bspRecursive(mapdef, room_list, rect_right, levelnum, cur_iteration);
        }
    }
}



void alg_bsp::buildRoomBlocks(MapDefs& mapdef, std::vector<RoomData>& room_list, int levelnum)
{
    RoomData rect;
    int iteration = 0;

    iteration = 0;
    rect.block.x1 = 0;
    rect.block.y1 = 0;
    rect.block.x2 = mapdef.getSizeX() - 1;
    rect.block.y2 = mapdef.getSizeY() - 1;

    bspRecursive(mapdef, room_list, rect, levelnum, iteration);
}



void alg_bsp::BuildRoomsFromBlocks(MapDefs& mapdef, std::vector<RoomData>& room_list)
{
    RoomData::MapRect block;
    RoomData::MapRect room;
    int room_width;
    int room_length;
    int xpos;
    int ypos;

    for (int i = 0; i < room_list.size(); i++)
    {
        block = room_list[i].block;
        room = room_list[i].room;

        //pad block and reduce block size befor placing room
        block.x1 += 1;
        block.y1 += 1;
        block.x2 -= 1;
        block.y2 -= 1;

        room.x1 = 0;
        room.y1 = 0;
        room.x2 = 0;
        room.y2 = 0;


        //CreateRoomFromBlock 4 15  4 8
        room_width = dnd_chance::randomBetween(mapdef.getRoomMinWidth(), mapdef.getRoomMaxWidth());
        room_length = dnd_chance::randomBetween(mapdef.getRoomMinHeight(), mapdef.getRoomMaxHeight());

        if (room_width > GetBlockWidthX(block))
            room_width = GetBlockWidthX(block);
        if (room_length > GetBlockHeightY(block))
            room_length = GetBlockHeightY(block);

        xpos = dnd_chance::randomBetween(block.x1, block.x2 - room_width + 1);
        ypos = dnd_chance::randomBetween(block.y1, block.y2 - room_length + 1);

        room.x1 = xpos;
        room.y1 = ypos;
        room.x2 = xpos + room_width - 1;
        room.y2 = ypos + room_length - 1;

        room_list[i].room = room;
    }
}





//draw blocks to map