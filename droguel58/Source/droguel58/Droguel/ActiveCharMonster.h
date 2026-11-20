#pragma once

#include "MapDefs.h"
#include <string>

class ActiveCharMonster
{
public:

    ActiveCharMonster();
    ~ActiveCharMonster();

    mapPosition m_pos;
    std::string name;
    bool isBoss;
};
