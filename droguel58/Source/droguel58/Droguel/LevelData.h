#pragma once
#include <vector>
#include <string>
#include "TileData.h"
#include "RoomData.h"
#include "PathData.h"
#include "ActiveCharMonster.h"
#include "ActiveItemData.h"
#include "TileData.h"
#include "MapDefs.h"

class LevelData
{
public:
    struct ue_pos
    {
        float tx;
        float ty;
        float tz;
        float rx;
        float ry;
        float rz;
        float sx;
        float sy;
        float sz;
    };

    struct ue_item
    {
        int line;
        int id;
        int level;
        int item_type;
        ue_pos pos;
    };

    struct ue_monster
    {
        int line;
        int id;
        int level;
        int mt; //monstertype
        ue_pos pos;
    };

    struct ue_panels
    {
        int line;
        int id;
        int level;
        int tt; //tiletype
        ue_pos pos;
    };

    int m_level_num;
    int m_map_num;
    int m_offset_x;
    int m_offset_y;
    TileData** m_tileLevelMap;

    std::vector<RoomData> room_list;
    std::vector<PathData> path_list;
    std::vector<TileData> stair_list;
    std::vector<ActiveCharMonster> monster_list;
    //std::vector<LevelConnector> level_connectors;
    std::vector<mapPosition> level_connectors;
    std::vector<ActiveItemData> item_list;

    std::vector<ue_panels> ue_panel_list;
    std::vector<ue_panels> ue_midlevel_list;
    std::vector<ue_monster> ue_monster_list;
    std::vector<ue_item> ue_item_list;

    LevelData();// MapDefs mapdef);
    ~LevelData();

    TileData** create_2d_array(int rows, int cols);
    void destroy_2d_array(TileData** array, int rows);

    bool checkForCollision(int x, int y);
    int getNumRooms();
    int getRandomRoomIndex();
    mapPosition getRandomOpenTileOnLevel();
};
