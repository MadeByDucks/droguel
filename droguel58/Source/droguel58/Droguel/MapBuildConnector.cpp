#include "MapBuildConnector.h"
#include "DrogDef.h"

//connect the map levels
//set offsets and/or build connector sub levels


MapBuildConnector::MapBuildConnector()
{
}

MapBuildConnector::~MapBuildConnector()
{
}



///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
// SWAP IF NEEDED
// OffsetSwapStairsCheck()
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
/////adjustment for stairs - no stairs, straight through
//if (levelnum != 0)
//{
//    mapPosition asis;
//    mapPosition swap;
//
//    asis.x = prev_down.x - cur_up.x + offset.x;      // +2;  //ttdtodo: move to match stairs
//    asis.y = prev_down.y - cur_up.y + offset.y;      // +2;  //+1 move to north
//
//    //m_num_x_tiles = 90;
//    //m_num_y_tiles = 25;
//    swap.x = prev_down.x - cur_down.x + offset.x;
//    swap.y = prev_down.y - cur_down.y + offset.y;
//    if (
//        ((abs(swap.x) < abs(asis.x)) && (abs(asis.x) > (180))) ||
//        ((abs(swap.y) < abs(asis.y)) && (abs(asis.y) > (50)))
//        )
//    {
//        int tempIdx = index_dn;
//        index_dn = index_up;
//        index_up = tempIdx;
//
//        TileData tempTile = cur_up;
//        cur_up = cur_down;
//        cur_down = cur_up;
//
//        asis.x = swap.x;
//        asis.y = swap.y;
//    }
//
//    offset.x = asis.x;
//    offset.y = asis.y;
//}


///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
// Find New Offset
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//  //offset adjuster small scale
//  //adjust layers with mid level hallways - ???adjust to zero level or absolute zero??? right now it is absolute zero
//int delta_x = 0;
//int delta_y = 0;
//int delta_x_dir = 0; //direction +/- 1
//int delta_y_dir = 0;
//int x_max_delta = 10;
//int y_max_delta = 10;
//if (levelnum != 0)
//{
//    if (offset.x > 0)
//    {
//        if (offset.x <= x_max_delta)
//            delta_x = offset.x;
//        else
//            delta_x = x_max_delta;
//        delta_x_dir = -1;
//    }
//    else if (offset.x < 0)
//    {
//        if (offset.x >= (x_max_delta * -1))
//            delta_x = offset.x * -1;
//        else
//            delta_x = x_max_delta;
//        delta_x_dir = 1;
//    }
//
//    if (offset.y > 0)
//    {
//        if (offset.y <= y_max_delta)
//            delta_y = offset.y;
//        else
//            delta_y = y_max_delta;
//        delta_y_dir = -1;
//    }
//    else if (offset.y < 0)
//    {
//        if (offset.y >= (y_max_delta * -1))
//            delta_y = offset.y * -1;
//        else
//            delta_y = y_max_delta;
//        delta_y_dir = 1;
//    }
//
//    offset.x = offset.x + (delta_x * delta_x_dir);
//    offset.y = offset.y + (delta_y * delta_y_dir);
//}



//connector staight through drop / map levels all over the place / manage offset
// UE adjust for stairs
// UE adjust stair direction
// UE first level adjustments
// swap stairs if better alignment?
// two level counters (main level counter) actual level counter with sub levels
// document level connector in code as level below (or up???)
// setting to allow for slow realighment (max n steps x and y directions)
//////////
// multi up/down stairs per level
// trap doors



void MapBuildConnector::OffsetMapLevelBuilder(TileMap& tilemap)
{
    int index_up = -1;
    int index_dn = -1;
    int level = -1;

    TileData cur_up;
    TileData cur_down;
    TileData prev_down;
    int prev_index_down = 0;


    mapPosition offset;
    offset.x = 0;
    offset.y = 0;
    //cur_up.m_pos.x = 0;
    //cur_up.m_pos.y = 0;
    //cur_down.m_pos.x = 0;
    //cur_down.m_pos.y = 0;
    cur_up.setTilePos(0, 0, level);
    cur_down.setTilePos(0, 0, level);


    //traverse all levels
    for (int levelnum = 0; levelnum < tilemap.level.size(); levelnum++)
    {
        //Create sublevel path
        std::vector<mapPosition> path;
        path.clear();
        //path.m_levelnum = levelnum;
        //path.connectPath.clear();


        //traverse list of stairs for current level. should only be one up and down for now
        index_up = -1;
        index_dn = -1;
        for (int list_idx = 0; list_idx < tilemap.level[levelnum].stair_list.size(); list_idx++)
        {
            TileData stair = tilemap.level[levelnum].stair_list[list_idx];
            if ((TileData::isStairUp(stair.getTileType())) && (index_up == -1))
            {
                cur_up = stair;
                index_up = list_idx;
            }
            if ((TileData::isStairDown(stair.getTileType())) && (index_dn == -1))
            {
                cur_down = stair;
                index_dn = list_idx;
            }
        }


        //level 0 adjustment
        if (levelnum == 0)
        {
            offset.x = (cur_up.m_pos.x * -1) + 14; //14 to get to front of UE Level Platform
            offset.y = (cur_up.m_pos.y * -1);
        }


        //adjustment for stairs - no stairs, straight through
        if (levelnum != 0)
        {
            mapPosition as_is;
            as_is.x = prev_down.m_pos.x - cur_up.m_pos.x + offset.x;      // +2;  //ttdtodo: move to match stairs
            as_is.y = prev_down.m_pos.y - cur_up.m_pos.y + offset.y;      // +2;  //+1 move to north

            ///////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////
            // SWAP IF NEEDED
            // OffsetSwapStairsCheck()
            ///////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////

            offset.x = as_is.x;
            offset.y = as_is.y;
        }




        ////adjust offset with path to base posisiton (0,0)
        int delta_x = 0;
        int delta_y = 0;
        if (levelnum != 0)
        {
            delta_x = offset.x * -1;//-10;
            delta_y = offset.y * -1;//-5;

            offset.x = offset.x + delta_x;
            offset.y = offset.y + delta_y;
        }

        //Build sublevel path
        //OffsetBuildSubPath();
        if (levelnum != 0)
        {
            mapPosition curpos;
            curpos.x = cur_up.m_pos.x;
            curpos.y = cur_up.m_pos.y;
            curpos.z = cur_up.m_pos.z;
            ///////////////////////////////////////////path.connectPath.push_back(curpos);


//ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE 

            /////
            if (delta_x > 0)
            {
                curpos.x -= 1; ///////////////////////////////////////////////
                for (int i = 1; i < delta_x; i++) /////////////////////////////////////////////////////
                {
                    curpos.x -= 1;
                    path.push_back(curpos);
                }
            }
            else
            {
                curpos.x += 1; ///////////////////////////////////////////////
                for (int i = 1; i < abs(delta_x); i++) //////////////////////////////////////////////////
                {
                    curpos.x += 1;
                    path.push_back(curpos);
                }
            }
            /////
            if (delta_y > 0)
            {
                for (int i = 0; i < delta_y; i++)
                {
                    curpos.y -= 1;
                    path.push_back(curpos);
                }
            }
            else
            {
                for (int i = 0; i < abs(delta_y); i++)
                {
                    curpos.y += 1;
                    path.push_back(curpos);
                }
            }

        }

        //ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE 
        //NEG INDEX CASE NEG INDEX CASE NEG INDEX CASE NEG INDEX CASE NEG INDEX CASE NEG INDEX CASE 



        //OffsetSubPathSetStairs()
        if (delta_x == 0)
        {
            tilemap.level[levelnum].stair_list[index_up].setTileType(TileData::TT_StairUpWest);
        }
        else if (delta_x > 0)
        {
            tilemap.level[levelnum].stair_list[index_up].setTileType(TileData::TT_StairUpWest);
        }
        else
        {
            tilemap.level[levelnum].stair_list[index_up].setTileType(TileData::TT_StairUpEast);
        }

        if ((delta_y == 0) && (levelnum > 0))
        {
            tilemap.level[levelnum - 1].stair_list[prev_index_down].setTileType(TileData::TT_StairDownSouth);
        }
        else if ((delta_y > 0) && (levelnum > 0))
        {
            tilemap.level[levelnum - 1].stair_list[prev_index_down].setTileType(TileData::TT_StairDownSouth);
        }
        else if (levelnum > 0)
        {
            tilemap.level[levelnum - 1].stair_list[prev_index_down].setTileType(TileData::TT_StairDownNorth);
        }



        //set offsets for the levels
        tilemap.level[levelnum].m_offset_x = offset.x;
        tilemap.level[levelnum].m_offset_y = offset.y;

        prev_down = cur_down;
        prev_index_down = index_dn;

        //ttdtodo build it not set it in case there are multiple paths to build
        tilemap.level[levelnum].level_connectors = path;
    }
}



void MapBuildConnector::GetStairsData(TileMap& tilemap, int levelnum, TileData &up, TileData &down, int& index_up, int& index_dn)
{
    index_up = -1;
    index_dn = -1;

    up.clearTile();
    down.clearTile();

    //traverse list of stairs for current level. should only be one up and down for now
    //map offsets are calculated by the first stairs up and down if there are multiple stairs
    index_up = -1;
    index_dn = -1;
    for (int list_idx = 0; list_idx < tilemap.level[levelnum].stair_list.size(); list_idx++)
    {
        TileData stair = tilemap.level[levelnum].stair_list[list_idx];
        if ((TileData::isStairUp(stair.getTileType())) && (index_up == -1))
        {
            up = stair;
            index_up = list_idx;
        }
        if ((TileData::isStairDown(stair.getTileType())) && (index_dn == -1))
        {
            down = stair;
            index_dn = list_idx;
        }
    }
}




//No connectors between levels, move offsets so downstairs matches position of upstairs on lower level
void MapBuildConnector::SetOffsetsOnly(TileMap& tilemap)
{
    int index_up = -1;
    int index_dn = -1;


    TileData cur_up;
    TileData cur_down;
    TileData prev_down;

    mapPosition offset;
    offset.x = 0;
    offset.y = 0;
    cur_up.clearTile();
    cur_down.clearTile();

    //traverse all levels
    for (int levelnum = 0; levelnum < tilemap.level.size(); levelnum++)
    {
        GetStairsData(tilemap, levelnum, cur_up, cur_down, index_up, index_dn);
        ////traverse list of stairs for current level. should only be one up and down for now
        ////map offsets are calculated by the first stairs up and down if there are multiple stairs
        //index_up = -1;
        //index_dn = -1;
        //for (int list_idx = 0; list_idx < tilemap.level[levelnum].stair_list.size(); list_idx++)
        //{
        //    TileData stair = tilemap.level[levelnum].stair_list[list_idx];
        //    if ((TileData::isStairUp(stair.getTileType())) && (index_up == -1))
        //    {
        //        cur_up = stair;
        //        index_up = list_idx;
        //    }
        //    if ((TileData::isStairDown(stair.getTileType())) && (index_dn == -1))
        //    {
        //        cur_down = stair;
        //        index_dn = list_idx;
        //    }
        //}

        //adjustment for stairs - no stairs, straight through
        if (levelnum != 0)
        {
            offset.x = prev_down.m_pos.x - cur_up.m_pos.x + offset.x;
            offset.y = prev_down.m_pos.y - cur_up.m_pos.y + offset.y;

            ///////////////////////////////////////////////////////////////////
            // SWAP STAIRS IF NEEDED
            ///////////////////////////////////////////////////////////////////
        }

        //set offsets for the levels
        tilemap.level[levelnum].m_offset_x = offset.x;
        tilemap.level[levelnum].m_offset_y = offset.y;

        prev_down = cur_down;
    }

}


void MapBuildConnector::MoveMap(TileMap& tilemap, int x, int y)
{
    for (int levelnum = 0; levelnum < tilemap.level.size(); levelnum++)
    {
        tilemap.level[levelnum].m_offset_x = tilemap.level[levelnum].m_offset_x * -1 + x;
        tilemap.level[levelnum].m_offset_y = tilemap.level[levelnum].m_offset_y * -1 + y;

        ///////////////////////////////////////////////////////////////////
        // Move Connectors
        ///////////////////////////////////////////////////////////////////
    }
}


void MapBuildConnector::AddConnectors(TileMap& tilemap) //stationary levels
{
    int index_up = -1;
    int index_dn = -1;

    TileData cur_up;
    TileData cur_down;
    TileData prev_down;

    mapPosition delta;
    delta.x = 0;
    delta.y = 0;
    cur_up.clearTile();
    cur_down.clearTile();

    //traverse all levels
    for (int levelnum = 0; levelnum < tilemap.level.size(); levelnum++)
    {
        //Create sublevel path
        std::vector<mapPosition> path;
        //path.m_levelnum = levelnum;
        path.clear();


        GetStairsData(tilemap, levelnum, cur_up, cur_down, index_up, index_dn);



        //Build sublevel path
//OffsetBuildSubPath();
        if (levelnum != 0)
        {
            mapPosition curpos;
            curpos.x = cur_up.m_pos.x;
            curpos.y = cur_up.m_pos.y;
            curpos.z = cur_up.m_pos.z;
            ///////////////////////////////////////////path.connectPath.push_back(curpos);


//ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE ZERO CASE 


        ////adjust offset with path to base posisiton (0,0)
            int delta_x = 0;
            int delta_y = 0;
            if (levelnum != 0)
            {
                delta_x = cur_up.m_pos.x - prev_down.m_pos.x;
                delta_y = cur_up.m_pos.y - prev_down.m_pos.y;
            }


            /////
            if (delta_x > 0)
            {
                for (int i = 0; i < delta_x; i++) 
                {
                    path.push_back(curpos);
                    curpos.x -= 1;
                }
            }
            else
            {
                for (int i = 0; i < abs(delta_x); i++) 
                {
                    path.push_back(curpos);
                    curpos.x += 1;
                }
            }
            //need to add extra for corner on turn so change from < to <=
            if (delta_y > 0)
            {
                for (int i = 0; i <= delta_y; i++)
                {
                    path.push_back(curpos);
                    curpos.y -= 1;
                }
            }
            else
            {
                for (int i = 0; i <= abs(delta_y); i++)
                {
                    path.push_back(curpos);
                    curpos.y += 1;
                }
            }

        }

        prev_down = cur_down;

        //ttdtodo build it not set it in case there are multiple paths to build
        tilemap.level[levelnum].level_connectors = path;
    }


}

void MapBuildConnector::RotateStairs(TileMap& tilemap, bool trimPath)
{
    int index_up = -1;
    int index_dn = -1;
    int prev_index_down = -1;

    TileData cur_up;
    TileData cur_down;
    //TileData prev_down;

    //mapPosition delta;
    int d1;
    int d2;

    //delta.x = 0;
    //delta.y = 0;
    //cur_up.clearTile();
    //cur_down.clearTile();



    //traverse all levels
    for (int levelnum = 0; levelnum < tilemap.level.size(); levelnum++)
    {
        GetStairsData(tilemap, levelnum, cur_up, cur_down, index_up, index_dn);
        std::vector<mapPosition> &path = tilemap.level[levelnum].level_connectors;

        //remove first and last elements. stairs account for the tile
        //no stairs with a drop to next level will need these there
        if (trimPath)
        {
            //remove two on the up to mid level
            if (path.size() > 1)
            {
                path.erase(path.begin(), path.begin() + 1); 
            }
            if (path.size() > 1)
            {
                path.erase(path.begin(), path.begin() + 1);
            }
            if (path.size() > 1)
            {
                path.pop_back();
            }
        }

        if (levelnum == 0)
        {
            //can not change stairs up because there is no level
        }

        if (path.size() >= 2)
        {
            d1 = path[0].x;
            d2 = path[1].x;
            int delta_x;
            delta_x = d1 - d2;

            if (delta_x == 0)
            {
                tilemap.level[levelnum].stair_list[index_up].setTileType(TileData::TT_StairUpWest);
            }
            else if (delta_x > 0)
            {
                tilemap.level[levelnum].stair_list[index_up].setTileType(TileData::TT_StairUpWest);
            }
            else
            {
                tilemap.level[levelnum].stair_list[index_up].setTileType(TileData::TT_StairUpEast);
            }
        }



        if ((path.size() >= 4) && (levelnum > 0))
        {
            d1 = path[path.size() - 2].y;
            d2 = path[path.size() - 1].y;
            int delta_y;
            delta_y = d1 - d2;

            if ((delta_y == 0) && (levelnum > 0))
            {
                tilemap.level[levelnum - 1].stair_list[prev_index_down].setTileType(TileData::TT_StairDownSouth);
            }
            else if ((delta_y > 0) && (levelnum > 0))
            {
                tilemap.level[levelnum - 1].stair_list[prev_index_down].setTileType(TileData::TT_StairDownSouth);
            }
            else if (levelnum > 0)
            {
                tilemap.level[levelnum - 1].stair_list[prev_index_down].setTileType(TileData::TT_StairDownNorth);
            }
        }

        prev_index_down = index_dn;
    }
}



//ttdtodo: order issue between the two UE and IMGUI

void MapBuildConnector::BuildConnectors(TileMap& tilemap, bool isUE) //sprawl map
{
    //OffsetMapLevelBuilder(tilemap);

    //ImGui: move map with offsets and generate connectors for visuals only


    //UE: connectors with stationary map
    if (isUE) //stack map //if (DrogDef::ENV_UE)
    {
        MoveMap(tilemap, 0, 0); //(14/0//for UE - do this before creating connectors
        //SetOffsetsOnly(tilemap);
        AddConnectors(tilemap);
        RotateStairs(tilemap, true); //rotate and shorten paths for stairs
    }
    else //sprawl map //if (DrogDef::ENV_IMGUI) 
    {
        SetOffsetsOnly(tilemap);//used for no pathways, match stairs on levels
        MoveMap(tilemap, 0, 0); //(14/0//for UE - do this before creating connectors
        AddConnectors(tilemap);
    }
}


//void MapBuildConnector::BuildConnectorsUE(TileMap& tilemap) //stacked map
//{
//    //OffsetMapLevelBuilder(tilemap);
//
//    //UE: connectors with stationary map
//    //if (DrogDef::ENV_UE)
//    {
//        MoveMap(tilemap, 0, 0); //(14/0//for UE - do this before creating connectors
////SetOffsetsOnly(tilemap);
//        AddConnectors(tilemap);
//        RotateStairs(tilemap, true); //rotate and shorten paths for stairs
//    }
//}
