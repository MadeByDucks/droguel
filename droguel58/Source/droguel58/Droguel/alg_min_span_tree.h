#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include "tilemap.h"


class alg_msp
{
public:

    alg_msp();
    ~alg_msp();

    typedef std::pair<int, int> PII;
    typedef std::vector<PII> VPII;

    int Prims_MST(int source_node, std::vector<VPII>& graph);

    void testone();
    void testtwo();

    int process_minspantree(TileMap& tilemap);

};
