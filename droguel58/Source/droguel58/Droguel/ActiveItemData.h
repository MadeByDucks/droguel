#pragma once

#include "MapDefs.h"
#include <string>

class ActiveItemData
{
public:

    ActiveItemData();
    ~ActiveItemData();

    mapPosition m_pos;
    std::string name;
};
