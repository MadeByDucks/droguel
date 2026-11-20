#include "TileMapBuilder.h"
#include "MapDefs.h"
#include "pathfinder.h"
#include "LevelBuilder.h"
#include "ItemBuildObjects.h"
#include "CharBuildMonsters.h"

TileMapBuilder::TileMapBuilder()
{
}

TileMapBuilder::~TileMapBuilder()
{
}


///////////////////////////////////////////////////////////////////////////////
// draw function //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void TileMapBuilder::ClearTileMap(TileMap& tilemap)
{
    tilemap.clearAllTiles();
}

void TileMapBuilder::DrawRoomsToMap(TileMap& tilemap, int levelnum)
{
    RoomData::MapRect room;

    std::cout << std::endl << std::endl << std::endl;

    //draw room on map
    std::cout << "DRAW ROOMS TO MAP - LEVEL: " << levelnum << std::endl;

    for (int i = 0; i < tilemap.level[levelnum].room_list.size(); i++)
    {
        //TileMap::MapRect room;
        room = tilemap.level[levelnum].room_list[i].room;
        for (int x = room.x1; x <= room.x2; x++)
        {
            for (int y = room.y1; y <= room.y2; y++)
            {
                //ttdtodo: corners, side posts
                //ttdtodo: resolve the wall floor tiles

                //corner check /////////////////////////////////////////////////
                if ((y == room.y1) && (x == room.x1))
                {
                    tilemap.setTileChar(x, y, levelnum, "-");
                    tilemap.setTileType(x, y, levelnum, TileData::TileType::TT_NW_Corner);
                }
                else if ((y == room.y1) && (x == room.x2))
                {
                    tilemap.setTileChar(x, y, levelnum, "-");
                    tilemap.setTileType(x, y, levelnum, TileData::TileType::TT_NE_Corner);
                }
                else if ((y == room.y2) && (x == room.x1))
                {
                    tilemap.setTileChar(x, y, levelnum, "-");
                    tilemap.setTileType(x, y, levelnum, TileData::TileType::TT_SW_Corner);
                }
                else if ((y == room.y2) && (x == room.x2))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TileType::TT_SE_Corner);
                    tilemap.setTileChar(x, y, levelnum, "-");
                }
                ////////////////////////////////////////////////////////////////
                else if (y == room.y1)
                {
                    tilemap.setTileChar(x, y, levelnum, "-");
                    tilemap.setTileType(x, y, levelnum, TileData::TileType::TT_NorthWall);
                }
                else if (y == room.y2)
                {
                    tilemap.setTileChar(x, y, levelnum, "-");
                    tilemap.setTileType(x, y, levelnum, TileData::TileType::TT_SouthWall);
                }
                else if (x == room.x1)
                {
                    tilemap.setTileChar(x, y, levelnum, "|");
                    tilemap.setTileType(x, y, levelnum, TileData::TileType::TT_WestWall);
                }
                else if (x == room.x2)
                {
                    tilemap.setTileChar(x, y, levelnum, "|");
                    tilemap.setTileType(x, y, levelnum, TileData::TileType::TT_EastWall);
                }
                ////////////////////////////////////////////////////////////////
                else
                {
                    tilemap.setTileChar(x, y, levelnum, ".");
                    tilemap.setTileType(x, y, levelnum, TileData::TileType::TT_Floor);
                }
            }
        }
    }
}

void TileMapBuilder::DrawBlocksToMap(TileMap& tilemap, int levelnum)
{
    char marker[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                      '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '~', ':', '?' };
    int marker_idx = 0; //78// char(97 + i);

    marker_idx = 0;
    for (int i = 0; i < tilemap.level[levelnum].room_list.size(); i++)
    {
        RoomData room = tilemap.level[levelnum].room_list[i];
        std::string roomchar = "";
        roomchar += marker[marker_idx];
        marker_idx++;
        if (marker_idx >= 78)
        {
            marker_idx = 0;
        }

        for (int x = 0; x < room.getRoomBlockWidth()/*GetRoomWidth(room)*/; x++)
        {
            for (int y = 0; y < room.getRoomBlockWidth()/*GetRoomHeight(room)*/; y++)
            {
                if ((x + room.block.x1 < tilemap.m_mapdef.getSizeX()) && (y + room.block.y1 < tilemap.m_mapdef.getSizeY()))
                {
                    ///////////////////////////////////////////////////////////////////////////////
                    //blocks
                    ///////////////////////////////////////////////////////////////////////////////
                    tilemap.setTileChar(x + room.block.x1, y + room.block.y1, levelnum, " ");
                }
            }
        }
    }
}

void TileMapBuilder::DrawWallsOnPaths(TileMap& tilemap, int levelnum)
{
    //changes the path tile to a tile that has walls in UE

    //ttdtodo: can end up with double walls, probably with double Tee Paths

    std::string c_cross = "#";
    std::string c_vert = "#";
    std::string c_horz = "#";
    std::string c_tn = "#";
    std::string c_te = "#";
    std::string c_ts = "#";
    std::string c_tw = "#";
    std::string c_nw = "#";
    std::string c_ne = "#";
    std::string c_se = "#";
    std::string c_sw = "#";

    for (int x = 0; x < tilemap.m_mapdef.m_num_x_tiles; x++)
    {
        for (int y = 0; y < tilemap.m_mapdef.m_num_y_tiles; y++)
        {
            TileData::TileType cur_tile = tilemap.getTileType(x, y, levelnum);
            TileData::TileType top_tile = TileData::TT_Empty;
            TileData::TileType bottom_tile = TileData::TT_Empty;
            TileData::TileType left_tile = TileData::TT_Empty;
            TileData::TileType right_tile = TileData::TT_Empty;

            if (y > 0)
                top_tile = tilemap.getTileType(x, y - 1, levelnum);

            if (y < tilemap.m_mapdef.m_num_y_tiles - 1)
                bottom_tile = tilemap.getTileType(x, y + 1, levelnum);

            if (x > 0)
                left_tile = tilemap.getTileType(x - 1, y, levelnum);

            if (x < tilemap.m_mapdef.m_num_x_tiles - 1)
                right_tile = tilemap.getTileType(x + 1, y, levelnum);


            if (TileData::isPathTile(cur_tile))
            {
                if (TileData::isNavTile(top_tile) && TileData::isNavTile(bottom_tile) && TileData::isNavTile(left_tile) && TileData::isNavTile(right_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_CrossPath);
                    tilemap.setTileChar(x, y, levelnum, c_cross);
                }


                //////////
                //Tees
                //////////
                else if (TileData::isNavTile(top_tile) && TileData::isNavTile(bottom_tile) && TileData::isNavTile(left_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_TWestPath);
                    tilemap.setTileChar(x, y, levelnum, c_tw);
                }
                else if (TileData::isNavTile(top_tile) && TileData::isNavTile(bottom_tile) && TileData::isNavTile(right_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_TEastPath);
                    tilemap.setTileChar(x, y, levelnum, c_te);
                }
                else if (TileData::isNavTile(left_tile) && TileData::isNavTile(right_tile) && TileData::isNavTile(top_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_TNorthPath);
                    tilemap.setTileChar(x, y, levelnum, c_tn);
                }
                else if (TileData::isNavTile(left_tile) && TileData::isNavTile(right_tile) && TileData::isNavTile(bottom_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_TSouthPath);
                    tilemap.setTileChar(x, y, levelnum, c_ts);
                }


                //////////
                //vertcal and horizontal
                //////////
                else if (TileData::isNavTile(top_tile) && TileData::isNavTile(bottom_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_NS_Path);
                    tilemap.setTileChar(x, y, levelnum, c_vert);
                }
                else if (TileData::isNavTile(left_tile) && TileData::isNavTile(right_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_EW_Path);
                    tilemap.setTileChar(x, y, levelnum, c_horz);
                }


                //////////
                //angles
                //////////
                else if (TileData::isNavTile(top_tile) && TileData::isNavTile(right_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_SW_Path);
                    tilemap.setTileChar(x, y, levelnum, c_sw);
                }
                else if (TileData::isNavTile(right_tile) && TileData::isNavTile(bottom_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_NW_Path);
                    tilemap.setTileChar(x, y, levelnum, c_nw);
                }
                else if (TileData::isNavTile(bottom_tile) && TileData::isNavTile(left_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_NE_Path);
                    tilemap.setTileChar(x, y, levelnum, c_ne);
                }
                else if (TileData::isNavTile(left_tile) && TileData::isNavTile(top_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_SE_Path);
                    tilemap.setTileChar(x, y, levelnum, c_se);
                }


                //////////
                //single ended
                //////////
                else if (TileData::isNavTile(top_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_PathEndSouth);// TT_NS_Path;
                    tilemap.setTileChar(x, y, levelnum, c_sw);
                }
                else if (TileData::isNavTile(bottom_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_PathEndNorth);// TT_NS_Path;
                    tilemap.setTileChar(x, y, levelnum, c_nw);
                }
                else if (TileData::isNavTile(left_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_PathEndEast);// TT_EW_Path;
                    tilemap.setTileChar(x, y, levelnum, c_ne);
                }
                else if (TileData::isNavTile(right_tile))
                {
                    tilemap.setTileType(x, y, levelnum, TileData::TT_PathEndWest);// TT_EW_Path;
                    tilemap.setTileChar(x, y, levelnum, c_se);
                }
            }
        }
    }
}

void TileMapBuilder::DrawPathsToMap(TileMap& tilemap, int levelnum)
{
    for (int path_idx = 0; path_idx < tilemap.level[levelnum].path_list.size(); path_idx++)
    {
        for (int idx = 0; idx < tilemap.level[levelnum].path_list[path_idx].path.size(); idx++)
        {
            TileData element = tilemap.level[levelnum].path_list[path_idx].path[idx];
            tilemap.setTileChar(element.m_pos.x, element.m_pos.y, levelnum, "#");
            tilemap.setTileType(element.m_pos.x, element.m_pos.y, levelnum, TileData::TileType::TT_PathSimple);
        }
    }
}

void TileMapBuilder::DrawDoorsToMap(TileMap& tilemap, int levelnum)
{
    for (int path_idx = 0; path_idx < tilemap.level[levelnum].path_list.size(); path_idx++)
    {
        PathData path = tilemap.level[levelnum].path_list[path_idx];
        if (path.connect.active_connector)
        {
            tilemap.setTileChar(path.door_a.m_pos.x, path.door_a.m_pos.y, levelnum, "+");
            tilemap.setTileType(path.door_a.m_pos.x, path.door_a.m_pos.y, levelnum, path.door_a.getTileType());

            //if (path.door_a.tiletype == TileMap::TT_NorthDoor)
            //{
            //    tilemap.m_tilemap[path.door_a.x][path.door_a.y][levelnum].tile = "^";
            //}
            //else if (path.door_a.tiletype == TileMap::TT_SouthDoor)
            //{
            //    tilemap.m_tilemap[path.door_a.x][path.door_a.y][levelnum].tile = "v";
            //}
            //else if (path.door_a.tiletype == TileMap::TT_EastDoor)
            //{
            //    tilemap.m_tilemap[path.door_a.x][path.door_a.y][levelnum].tile = ">";
            //}
            //else if (path.door_a.tiletype == TileMap::TT_WestDoor)
            //{
            //    tilemap.m_tilemap[path.door_a.x][path.door_a.y][levelnum].tile = "<";
            //}


            tilemap.setTileChar(path.door_b.m_pos.x, path.door_b.m_pos.y, levelnum, "+");
            tilemap.setTileType(path.door_b.m_pos.x, path.door_b.m_pos.y, levelnum, path.door_b.getTileType());


            //if (path.door_b.tiletype == TileMap::TT_NorthDoor)
            //{
            //    tilemap.m_tilemap[path.door_b.x][path.door_b.y][levelnum].tile = "^";
            //}
            //else if (path.door_b.tiletype == TileMap::TT_SouthDoor)
            //{
            //    tilemap.m_tilemap[path.door_b.x][path.door_b.y][levelnum].tile = "v";
            //}
            //else if (path.door_b.tiletype == TileMap::TT_EastDoor)
            //{
            //    tilemap.m_tilemap[path.door_b.x][path.door_b.y][levelnum].tile = ">";
            //}
            //else if (path.door_b.tiletype == TileMap::TT_WestDoor)
            //{
            //    tilemap.m_tilemap[path.door_b.x][path.door_b.y][levelnum].tile = "<";
            //}
        }
    }
}

void TileMapBuilder::DrawStairsToMap(TileMap& tilemap, int levelnum)
{
    for (int list_idx = 0; list_idx < tilemap.level[levelnum].stair_list.size(); list_idx++)
    {
        TileData stair = tilemap.level[levelnum].stair_list[list_idx];
        if (TileData::isStairDown(stair.getTileType()))
        {
            tilemap.setTileChar(stair.m_pos.x, stair.m_pos.y, levelnum, ">");
            tilemap.setTileType(stair.m_pos.x, stair.m_pos.y, levelnum, stair.getTileType());
        }
        else if (TileData::isStairUp(stair.getTileType()))
        {
            tilemap.setTileChar(stair.m_pos.x, stair.m_pos.y, levelnum, "<");
            tilemap.setTileType(stair.m_pos.x, stair.m_pos.y, levelnum, stair.getTileType());
        }
    }
}



void TileMapBuilder::AddTile(TileMap& tilemap, int levnum,
    TileData::TileType tile, int& line, int& id,
    int tx, int ty, int tz, int rx, int ry, int rz, int sx, int sy, int sz)
{
    LevelData::ue_panels panel;
    panel.line = line;
    panel.id = id;
    panel.level = levnum;
    panel.tt = tile;
    panel.pos.tx = tx;
    panel.pos.ty = ty;
    panel.pos.tz = tz;
    panel.pos.rx = rx;
    panel.pos.ry = ry;
    panel.pos.rz = rz;
    panel.pos.sx = sx;
    panel.pos.sy = sy;
    panel.pos.sz = sz;
    tilemap.level[levnum].ue_panel_list.push_back(panel);

    line++;
    id++;
}

/////////////////////////////////////
//                                 //
//               E                 //
//                                 //
//              (+)                //
//               X                 //
//   N (left)   (-)    (Right) S   //
//                                 //
//           (-) Y (+)             //
//                                 //
//               W                 //
//                                 //
//            z - down             //
//            z + up               //
//                                 //
/////////////////////////////////////


void TileMapBuilder::ExportTileMapUE(TileMap& tilemap)
{
    int line = 0;
    int id = 0;
    for (int levelnum = 0; levelnum < tilemap.getNumLevels(); levelnum++)
    {
        int xm = tilemap.m_mapdef.xm;//300; //301; //100;
        int ym = tilemap.m_mapdef.ym;//300; //301; //100;
        int zm = tilemap.m_mapdef.zm;//800; //600; //500;

        int halfwall_adjust = 0; //150;

        TileData::TileType ttf = TileData::TT_Floor;
        TileData::TileType ttp = TileData::TT_PathWall;
        TileData::TileType ttw = TileData::TT_Wall;
        TileData::TileType ttc = TileData::TT_Ceiling;
        TileData::TileType ttsd = TileData::TT_StairDown;
        TileData::TileType ttsu = TileData::TT_StairUp;
        TileData::TileType ttd = TileData::TT_Door;
        TileData::TileType ttg = TileData::TT_Gateway;

        for (int x = 0; x < tilemap.m_mapdef.m_num_x_tiles; x++)
        {
            for (int y = 0; y < tilemap.m_mapdef.m_num_y_tiles; y++)
            {
                int xx = ((x + tilemap.level[levelnum].m_offset_x) * xm);
                int yy = ((y + tilemap.level[levelnum].m_offset_y) * ym);
                int zz = (levelnum + tilemap.m_mapdef.m_zlevel_offset) * zm * -1;  //level_offset +2 for two below platform

                TileData::TileType tt = tilemap.getTileType(x, y, levelnum);

                ///////////////////////////////////////////////////////////////
                // walls
                ///////////////////////////////////////////////////////////////
                if (tt == TileData::TT_NorthWall)
                {
                    AddTile(tilemap, levelnum, ttw, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //north wall
                }
                if (tt == TileData::TT_SouthWall)
                {
                    AddTile(tilemap, levelnum, ttw, line, id, xx, yy - 300, zz, 0, 0, 0, 1, 1, 1); //south wall
                }
                if (tt == TileData::TT_EastWall)
                {
                    AddTile(tilemap, levelnum, ttw, line, id, xx, yy - 300, zz, 0, 0, 90, 1, 1, 1); //east wall
                }
                if (tt == TileData::TT_WestWall)
                {
                    AddTile(tilemap, levelnum, ttw, line, id, xx + 300, yy - 300, zz, 0, 0, 90, 1, 1, 1); //west wall
                }


                ///////////////////////////////////////////////////////////////
                // corners
                ///////////////////////////////////////////////////////////////
                if (tt == TileData::TT_NW_Corner)
                {
 //                   AddTile(tilemap, levelnum, ttw, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //north wall
                }
                if (tt == TileData::TT_NE_Corner)
                {
 //                   AddTile(tilemap, levelnum, ttw, line, id, xx, yy - 300, zz, 0, 0, 0, 1, 1, 1); //south wall
                }
                if (tt == TileData::TT_SW_Corner)
                {
 //                   AddTile(tilemap, levelnum, ttw, line, id, xx, yy - 300, zz, 0, 0, 90, 1, 1, 1); //east wall
                }
                if (tt == TileData::TT_SE_Corner)
                {
//                    AddTile(tilemap, levelnum, ttw, line, id, xx + 300, yy - 300, zz, 0, 0, 90, 1, 1, 1); //west wall
                }

                ///////////////////////////////////////////////////////////////
                // doors
                ///////////////////////////////////////////////////////////////
                if (tt == TileData::TT_NorthDoor)
                {
                    AddTile(tilemap, levelnum, ttd, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //north door
                    AddTile(tilemap, levelnum, ttp, line, id, xx + 300, yy - 300, zz, 0, 0, 90, 1, 1, 1); //east wall
                    AddTile(tilemap, levelnum, ttp, line, id, xx - 0, yy - 300, zz, 0, 0, 90, 1, 1, 1); //west wall
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                }
                if (tt == TileData::TT_SouthDoor)
                {
                    AddTile(tilemap, levelnum, ttd, line, id, xx, yy - 300, zz, 0, 0, 0, 1, 1, 1); //south door
                    AddTile(tilemap, levelnum, ttp, line, id, xx + 300, yy - 300, zz, 0, 0, 90, 1, 1, 1); //east wall
                    AddTile(tilemap, levelnum, ttp, line, id, xx - 0, yy - 300, zz, 0, 0, 90, 1, 1, 1); //west wall
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                }
                if (tt == TileData::TT_EastDoor)
                {
                    AddTile(tilemap, levelnum, ttd, line, id, xx, yy - 300, zz, 0, 0, 90, 1, 1, 1); //east door
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //north wall
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy - 300, zz, 0, 0, 0, 1, 1, 1); //south wall                    
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                 }
                if (tt == TileData::TT_WestDoor)
                {
                    AddTile(tilemap, levelnum, ttd, line, id, xx + 300, yy - 300, zz, 0, 0, 90, 1, 1, 1); //west door
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy + 0, zz, 0, 0, 0, 1, 1, 1); //north wall
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy - 300, zz, 0, 0, 0, 1, 1, 1); //south wall                    
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                }


                ///////////////////////////////////////////////////////////////
                // stairs
                ///////////////////////////////////////////////////////////////
                if (tt == TileData::TT_StairUp)
                {
                    ////////////AddTile(tilemap, levelnum, ttsu, line, id,       xx, yy,     zz + 25,          0, 0, 0,    1, 1, 1); //120//135
                    ////////////AddTile(tilemap, levelnum, ttsu, line, id,       xx, yy-150, zz + 150,         0, 0, 0,    1, 1, 1); //120//135
                    ////////////AddTile(tilemap, levelnum, ttsu, line, id,       xx, yy-300, zz + 275,         0, 0, 0,    1, 1, 1); //120//135
                    //////////////AddTile(mapfile, ttf, line, id, xx, yy, zz - 0, 0, 0, 0, 1, 1, 1); // add a floor tile
                }
                if (tt == TileData::TT_StairDown) //up righ now
                {
                    //////////AddTile(tilemap, levelnum, ttsd, line, id,      xx, yy-150, zz - 125,           0, 0, 0,     1, 1, 1); //45 //y is side
                    //////////AddTile(tilemap, levelnum, ttsd, line, id,      xx, yy,     zz - 250,           0, 0, 0,     1, 1, 1); //45 //y is side
                    //////////AddTile(tilemap, levelnum, ttsd, line, id,      xx, yy+150, zz - 375,           0, 0, 0,     1, 1, 1); //45 //y is side
                    ////////////gateway
                    //////////AddTile(tilemap, levelnum, ttg, line, id,      xx, yy+150, zz - 375,           0, 0, 0,     1, 1, 1);
                }









                if (tt == TileData::TT_StairUpNorth)
                {

                    //Up North
                    AddTile(tilemap, levelnum, ttsu, line, id, xx, yy, zz + 25, 0, 0, 0, 1, 1, 1); //120//135
                    AddTile(tilemap, levelnum, ttsu, line, id, xx, yy - 150, zz + 150, 0, 0, 0, 1, 1, 1); //120//135
                    AddTile(tilemap, levelnum, ttsu, line, id, xx, yy - 300, zz + 275, 0, 0, 0, 1, 1, 1); //120//135
                    //AddTile(mapfile, ttf, line, id, xx, yy, zz - 0, 0, 0, 0, 1, 1, 1); // add a floor tile
                }
                if (tt == TileData::TT_StairUpSouth)
                {
                    //Up South
                    AddTile(tilemap, levelnum, ttsu, line, id, xx + 300, yy - 300, zz + 25, 0, 0, 180, 1, 1, 1); //120//135
                    AddTile(tilemap, levelnum, ttsu, line, id, xx + 300, yy - 150, zz + 150, 0, 0, 180, 1, 1, 1); //120//135
                    AddTile(tilemap, levelnum, ttsu, line, id, xx + 300, yy + 0, zz + 275, 0, 0, 180, 1, 1, 1); //120//135
                    //AddTile(mapfile, ttf, line, id, xx, yy, zz - 0, 0, 0, 0, 1, 1, 1); // add a floor tile
                }
                if (tt == TileData::TT_StairUpEast)
                {
                    //Up East
                    AddTile(tilemap, levelnum, ttsu, line, id, xx, yy - 300, zz + 25, 0, 0, 90, 1, 1, 1); //120//135
                    AddTile(tilemap, levelnum, ttsu, line, id, xx + 150, yy - 300, zz + 150, 0, 0, 90, 1, 1, 1); //120//135
                    AddTile(tilemap, levelnum, ttsu, line, id, xx + 300, yy - 300, zz + 275, 0, 0, 90, 1, 1, 1); //120//135
                    //AddTile(mapfile, ttf, line, id, xx, yy, zz - 0, 0, 0, 0, 1, 1, 1); // add a floor tile
                }
                if (tt == TileData::TT_StairUpWest)
                {
                    //Up West
                    AddTile(tilemap, levelnum, ttsu, line, id, xx + 300, yy - 0, zz + 25, 0, 0, -90, 1, 1, 1); //120//135
                    AddTile(tilemap, levelnum, ttsu, line, id, xx + 150, yy - 0, zz + 150, 0, 0, -90, 1, 1, 1); //120//135
                    AddTile(tilemap, levelnum, ttsu, line, id, xx + 0, yy - 0, zz + 275, 0, 0, -90, 1, 1, 1); //120//135
                    //AddTile(mapfile, ttf, line, id, xx, yy, zz - 0, 0, 0, 0, 1, 1, 1); // add a floor tile
                }

                if (tt == TileData::TT_StairDownNorth)
                {
                    //Down North
                    AddTile(tilemap, levelnum, ttsd, line, id, xx + 300, yy - 150, zz - 125, 0, 0, 180, 1, 1, 1); //45 //y is side
                    AddTile(tilemap, levelnum, ttsd, line, id, xx + 300, yy - 300, zz - 250, 0, 0, 180, 1, 1, 1); //45 //y is side
                    AddTile(tilemap, levelnum, ttsd, line, id, xx + 300, yy - 450, zz - 375, 0, 0, 180, 1, 1, 1); //45 //y is side
                    //gateway
                    AddTile(tilemap, levelnum, ttg, line, id, xx + 300, yy - 600, zz - 375, 0, 0, 180, 1, 1, 1); //just past stairs +150 to meet stairs
                }
                if (tt == TileData::TT_StairDownSouth)
                {
                    //Down South
                    AddTile(tilemap, levelnum, ttsd, line, id, xx, yy - 150, zz - 125, 0, 0, 0, 1, 1, 1); //45 //y is side
                    AddTile(tilemap, levelnum, ttsd, line, id, xx, yy, zz - 250, 0, 0, 0, 1, 1, 1); //45 //y is side
                    AddTile(tilemap, levelnum, ttsd, line, id, xx, yy + 150, zz - 375, 0, 0, 0, 1, 1, 1); //45 //y is side
                    //gateway
                    AddTile(tilemap, levelnum, ttg, line, id, xx, yy + 150, zz - 375, 0, 0, 0, 1, 1, 1);
                }
                if (tt == TileData::TT_StairDownEast)
                {
                    //Down East
                    AddTile(tilemap, levelnum, ttsd, line, id, xx + 150, yy - 0, zz - 125, 0, 0, -90, 1, 1, 1); //45 //y is side
                    AddTile(tilemap, levelnum, ttsd, line, id, xx + 300, yy - 0, zz - 250, 0, 0, -90, 1, 1, 1); //45 //y is side
                    AddTile(tilemap, levelnum, ttsd, line, id, xx + 450, yy - 0, zz - 375, 0, 0, -90, 1, 1, 1); //45 //y is side
                    //gateway                                                  
                    AddTile(tilemap, levelnum, ttg, line, id, xx + 600, yy - 0, zz - 375, 0, 0, -90, 1, 1, 1); //just past stairs +150 to meet stairs
                }
                if (tt == TileData::TT_StairDownWest)
                {
                    //Down West
                    AddTile(tilemap, levelnum, ttsd, line, id, xx + 150, yy - 300, zz - 125, 0, 0, 90, 1, 1, 1); //45 //y is side
                    AddTile(tilemap, levelnum, ttsd, line, id, xx + 0, yy - 300, zz - 250, 0, 0, 90, 1, 1, 1); //45 //y is side
                    AddTile(tilemap, levelnum, ttsd, line, id, xx - 150, yy - 300, zz - 375, 0, 0, 90, 1, 1, 1); //45 //y is side
                    //gateway
                    AddTile(tilemap, levelnum, ttg, line, id, xx - 300, yy - 300, zz - 375, 0, 0, 90, 1, 1, 1); //just past stairs +150 to meet stairs
                }





                if (tt == TileData::TT_StairUp)
                {
                    AddTile(tilemap, levelnum, ttsu, line, id, xx, yy, zz + 25, 0, 0, 0, 1, 1, 1); //120//135
                 }
                if (tt == TileData::TT_StairDown)
                {
                    //Down West
                    AddTile(tilemap, levelnum, ttsd, line, id, xx + 150, yy - 300, zz - 125, 0, 0, 90, 1, 1, 1); //45 //y is side
                    //gateway
                    AddTile(tilemap, levelnum, ttg, line, id, xx - 300, yy - 300, zz - 375, 0, 0, 90, 1, 1, 1); //just past stairs +150 to meet stairs
                }






















                ///////////////////////////////////////////////////////////////
                // floor
                ///////////////////////////////////////////////////////////////
                if (tt == TileData::TT_Floor)
                {
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //floor
                }


                ///////////////////////////////////////////////////////////////
                // straight cooridors
                ///////////////////////////////////////////////////////////////

                if (tt == TileData::TT_NS_Path)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx + 300, yy - 300, zz - halfwall_adjust, 0, 0, 90, 1, 1, 1); //east wall
                    AddTile(tilemap, levelnum, ttp, line, id, xx - 0, yy - 300, zz - halfwall_adjust, 0, 0, 90, 1, 1, 1); //west wall
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //floor
                }
                if (tt == TileData::TT_EW_Path)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy, zz - halfwall_adjust, 0, 0, 0, 1, 1, 1); //north wall
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy - 300, zz - halfwall_adjust, 0, 0, 0, 1, 1, 1); //south wall
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //floor
                }


                ///////////////////////////////////////////////////////////////
                // path corners
                ///////////////////////////////////////////////////////////////

                if (tt == TileData::TT_NW_Path)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy - 300, zz - halfwall_adjust, 0, 0, 0, 1, 1, 1); //south walled
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy - 300, zz - halfwall_adjust, 0, 0, 90, 1, 1, 1); //west wall
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //floor
                }
                //
                if (tt == TileData::TT_SW_Path)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy, zz - halfwall_adjust, 0, 0, 0, 1, 1, 1); //south walled
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy - 300, zz - halfwall_adjust, 0, 0, 90, 1, 1, 1); //west wall
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //floor
                }
                if (tt == TileData::TT_NE_Path)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy - 300, zz - halfwall_adjust, 0, 0, 0, 1, 1, 1); //north wall
                    AddTile(tilemap, levelnum, ttp, line, id, xx + 300, yy - 300, zz - halfwall_adjust, 0, 0, 90, 1, 1, 1); //east wall
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //floor
                }
                if (tt == TileData::TT_SE_Path)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy, zz - halfwall_adjust, 0, 0, 0, 1, 1, 1);  //south wall
                    AddTile(tilemap, levelnum, ttp, line, id, xx + 300, yy - 300, zz - halfwall_adjust, 0, 0, 90, 1, 1, 1);  //east wall
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);  //floor
                }


                ///////////////////////////////////////////////////////////////
                // paths other
                ///////////////////////////////////////////////////////////////

                if (tt == TileData::TT_CrossPath)
                {
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                }
                if (tt == TileData::TT_PathSimple)
                {
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                }


                ///////////////////////////////////////////////////////////////
                // paths tees
                ///////////////////////////////////////////////////////////////

                if (tt == TileData::TT_TNorthPath)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy, zz - halfwall_adjust, 0, 0, 0, 1, 1, 1); //south wall
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //floor
                }
                if (tt == TileData::TT_TSouthPath)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy - 300, zz - halfwall_adjust, 0, 0, 0, 1, 1, 1); //north wall
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //floor
                }
                if (tt == TileData::TT_TEastPath)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy - 300, zz - halfwall_adjust, 0, 0, 90, 1, 1, 1); //west wall
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //floor
                }
                if (tt == TileData::TT_TWestPath)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx + 300, yy - 300, zz - halfwall_adjust, 0, 0, 90, 1, 1, 1); //east wall
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1); //floor
                }


                ///////////////////////////////////////////////////////////////
                // path ends - ttdtodo - needs adjusting
                ///////////////////////////////////////////////////////////////

                if (tt == TileData::TT_PathEndNorth)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx + 150, yy + 150, zz - 75, 0, 0, 90, 1, 1, 1); //east wall
                    AddTile(tilemap, levelnum, ttp, line, id, xx - 150, yy + 150, zz - 75, 0, 0, 90, 1, 1, 1); //west wall
                    //wall on end //wall on end
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                }
                if (tt == TileData::TT_PathEndSouth)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx + 150, yy + 150, zz - 75, 0, 0, 90, 1, 1, 1); //east wall
                    AddTile(tilemap, levelnum, ttp, line, id, xx - 150, yy + 150, zz - 75, 0, 0, 90, 1, 1, 1); //west wall
                    //wall on end //wall on end
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                }
                if (tt == TileData::TT_PathEndEast)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy + 300, zz - 75, 0, 0, 0, 1, 1, 1); //north wall
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy, zz - 150, 0, 0, 0, 1, 1, 1); //south wall     
                    //wall on end //wall on end
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                }
                if (tt == TileData::TT_PathEndWest)
                {
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy + 300, zz - 75, 0, 0, 0, 1, 1, 1); //north wall
                    AddTile(tilemap, levelnum, ttp, line, id, xx, yy, zz - 150, 0, 0, 0, 1, 1, 1); //south wall     
                    //wall on end //wall on end
                    AddTile(tilemap, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                }

                ///////////////////////////////////////////////////////////////
                // path diags
                ///////////////////////////////////////////////////////////////

                //if (tt == TileMap::TT_PathDiagNW)
                //{
                //    AddTile(mapfile, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                //}
                //if (tt == TileMap::TT_PathDiagNE)
                //{
                //    AddTile(mapfile, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                //}
                //if (tt == TileMap::TT_PathDiagSE)
                //{
                //    AddTile(mapfile, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                //}
                //if (tt == TileMap::TT_PathDiagSW)
                //{
                //    AddTile(mapfile, levelnum, ttf, line, id, xx, yy, zz, 0, 0, 0, 1, 1, 1);//floor
                //}


                ///////////////////////////////////////////////////////////////
                // errors and other
                ///////////////////////////////////////////////////////////////

                if (tt == TileData::TT_Error)
                {
                    //    AddTile(mapfile, levelnum, ttf, line, id, xx, yy, zz - 0, 0, 0, 0, 1, 1, 1);//floor
                }
                //if (tt == TileMap::TT_Empty)
                //{
                //   
                //    AddTile(mapfile, levelnum, ttf, line, id, xx, yy, zz - 0, 0, 0, 0, 1, 1, 1); //floor
                //}
            }
        }


        //Add sub/mid level tiles
        for (int i = 0; i < tilemap.level[levelnum].level_connectors.size(); i++)  //connector paths
        {
                mapPosition pos = tilemap.level[levelnum].level_connectors[i];
                int mid_xx = ((pos.x + tilemap.level[levelnum].m_offset_x) * xm);
                int mid_yy = ((pos.y + tilemap.level[levelnum].m_offset_y) * ym);
                int mid_zz = (levelnum + tilemap.m_mapdef.m_zlevel_offset) * zm * -1;  //level_offset +2 for two below platform
                mid_zz = mid_zz + 400;// 400;

                //AddTile(tilemap, levelnum, ttsd, line, id, mid_xx, mid_yy, mid_zz, 0, 0, 0, 1, 1, 1);//floor
                AddTile(tilemap, levelnum, ttf, line, id, mid_xx, mid_yy, mid_zz, 0, 0, 0, 1, 1, 1);//floor
        }
    }
}

void TileMapBuilder::CreateTileMap(TileMap& tilemap)
{
    CharBuildMonsters monster_util;
    ItemBuildObjects objectUtil;
    ClearTileMap(tilemap);
    for (int i = 0; i < tilemap.getNumLevels(); i++)
    {
        DrawBlocksToMap(tilemap, i);
        DrawRoomsToMap(tilemap, i);
        DrawDoorsToMap(tilemap, i);
        DrawPathsToMap(tilemap, i);
        DrawWallsOnPaths(tilemap, i);

        DrawStairsToMap(tilemap, i);
        monster_util.DrawMonstersToMap(tilemap, i);
        objectUtil.DrawObjectsToMap(tilemap, i);
    }
}
