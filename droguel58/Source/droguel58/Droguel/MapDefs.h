#pragma once

#define MAPDEF_DEFAULT_TILES_X 90       //82 //240 //maxish 250 (80)
#define MAPDEF_DEFAULT_TILES_Y 25       //20 //60  //maxish 70  (20)
#define MAPDEF_DEFAULT_LEVELS_Z 100

class mapPosition
{
public:
    int x;
    int y;
    int z;

    float x_world; //with offsets
    float y_world; //with offsets
    float z_world;
    //int sidelevel;

    mapPosition()
    {
        x = -1;
        y = -1;
        z = -1;
        x_world= 0.0;
        y_world= 0.0;
        z_world= 0.0;
        //sidelevel = -1;
    };

    //~mapPosition();
};

class MapDefs
{
public:
    MapDefs();
    ~MapDefs();

    int m_num_x_tiles;
    int m_num_y_tiles;
    int m_num_z_max_levels;
    int m_zlevel_offset;

    int m_num_rooms_min;
    int m_num_rooms_max;

    int m_room_min_width;
    int m_room_max_width;
    int m_room_min_height;
    int m_room_max_height;

    int getSizeX();
    int getSizeY();
    int getSizeZmax(); //levels

    int getNumRoomsMin();
    int getNumRoomsMax();
    int getRoomMinWidth();
    int getRoomMaxWidth();
    int getRoomMinHeight();
    int getRoomMaxHeight();
    int getMaxNumLevels();

    void setMaxNumLevels(int numlevels);

    //tilesize
    int xm;
    int ym;
    int zm;
};
