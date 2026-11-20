#include "MapDefs.h"



MapDefs::MapDefs()
{
    //defaults
    m_num_x_tiles = MAPDEF_DEFAULT_TILES_X;
    m_num_y_tiles = MAPDEF_DEFAULT_TILES_Y;
    m_num_z_max_levels = MAPDEF_DEFAULT_LEVELS_Z;

    m_num_rooms_min = 4;
    m_num_rooms_max = 15;

    //size
    m_room_min_width = 5;
    m_room_max_width = 15;
    m_room_min_height = 5;
    m_room_max_height = 8;

    //panel size and level spacing

    xm = 300; //301; //100;
    ym = 300; //301; //100;
    zm = 800; //600; //500;

    m_zlevel_offset = 2;
}

MapDefs::~MapDefs()
{
}

int MapDefs::getSizeX()
{
    return(m_num_x_tiles);
}

int MapDefs::getSizeY()
{
    return(m_num_y_tiles);
}

int MapDefs::getSizeZmax()
{
    return(m_num_z_max_levels);
}

int MapDefs::getNumRoomsMin()
{
    return(m_num_rooms_min);
}

int MapDefs::getNumRoomsMax()
{
    return(m_num_rooms_max);
}

int MapDefs::getRoomMinWidth()
{
    return(m_room_min_width);
}

int MapDefs::getRoomMaxWidth()
{
    return(m_room_max_width);
}

int MapDefs::getRoomMinHeight()
{
    return(m_room_min_height);
}

int MapDefs::getRoomMaxHeight()
{
    return(m_room_max_height);
}

int MapDefs::getMaxNumLevels()
{
    return(m_num_z_max_levels);
}

void MapDefs::setMaxNumLevels(int numlevels)
{
    m_num_z_max_levels = numlevels;
}

