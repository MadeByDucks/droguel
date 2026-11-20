#pragma once

#include "MapDefs.h"

class RoomData
{
public:

    RoomData();
    ~RoomData();

    struct MapRect
    {
        int x1;
        int y1;
        int x2;
        int y2;
    };


    int level;
    int sidelevel;
    int iteration; //temp tracker for building random levels
    MapRect room;
    MapRect block; //block encapsulating the room
    //bool isValid;
    //std::string room_name;
    //int room_num;
    //int room_type (kitchen, storage, crypt, throne, river, drawbridge)
    //door list


    int getRoomBlockWidth();
    int getRoomBlockLength();
    void getRoomCenter(int& x, int& y);

    int getRoomWidth();
    int getRoomLength();

    void getRandomTileInRoom(mapPosition &pos);
};
