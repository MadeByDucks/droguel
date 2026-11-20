#include "RoomData.h"
#include "dnd_chance.h"

RoomData::RoomData()
{
    level = -1;
    sidelevel = -1;
    iteration = 0;
    //room;
    //block; 
}

RoomData::~RoomData()
{
}





int RoomData::getRoomBlockWidth()
{
    return (block.x2 - block.x1 + 1);
}

int RoomData::getRoomBlockLength()
{
    return (block.y2 - block.y1 + 1);
}

void RoomData::getRoomCenter(int& x, int& y)
{
    x = room.x1 + (getRoomBlockWidth() / 2);
    y = room.y1 + (getRoomBlockLength() / 2);
}





int RoomData::getRoomWidth()
{
    return (room.x2 - room.x1 + 1);
}

int RoomData::getRoomLength()
{
    return (room.y2 - room.y1 + 1);
}

void RoomData::getRandomTileInRoom(mapPosition& pos)
{
    //Doors/Walls are tiles so + or - one to get to valid tile
    pos.x = dnd_chance::randomBetween(room.x1 + 1, room.x2 - 1);
    pos.y = dnd_chance::randomBetween(room.y1 + 1, room.y2 - 1);
    pos.z = level;
    //pos.sidelevel = sidelevel;
}

