#include "LevelMgr.h"
#include "MapDefs.h"

LevelMgr::LevelMgr()
{
}

LevelMgr::~LevelMgr()
{
}

void LevelMgr::InitMapDefs(MapDefs defs)
{
    for (int i = 0; i < defs.getMaxNumLevels(); i++)
    {
        levelInfo lev;
        lev.levelnum = i;
        lev.enabled = false;
        lev.loaded = false;

        m_levels.push_back(lev);
    }
}

void LevelMgr::GetLevelsToLoad(MapDefs defs, int playerCurLevel, int &minLevel, int &maxLevel)
{
    int maxWorldLevel = defs.getMaxNumLevels()-1; //0 based
    int LevPrev = 2;
    int LevNext = 5;

    //get new range
    minLevel = playerCurLevel - LevNext;
    maxLevel = playerCurLevel + LevNext;
    if (minLevel < 0)
        minLevel = 0;
    if (maxLevel > maxWorldLevel)
        maxLevel = maxWorldLevel;
}

bool LevelMgr::IsLevelLoaded(int levelnum)
{
    return (m_levels[levelnum].loaded == true);
}

bool LevelMgr::IsLevelEnabled(int levelnum)
{
    return (m_levels[levelnum].enabled == true);
}

void LevelMgr::SetLevelEnabled(int levelnum, bool enabled)
{
    m_levels[levelnum].enabled = enabled;
}

void LevelMgr::SetLevelLoaded(int levelnum, bool loaded)
{
    m_levels[levelnum].loaded = loaded;
}

int LevelMgr::getCurLevelByPos(double z_pos)
{
    int level = -1;
    double jump = 142.79; //distance
    //double lev0g = 1738.918; //256 - gateway
    double levDelta = 800;
    double lev0 = 1482.725 - jump;// +jump;//1482.725;

    if (z_pos > -800.0)
    {
        level = -1;
    }
    else
    {
        z_pos = z_pos * -1.0;//work with pos nums
        z_pos = z_pos - lev0;//zero out the pos
        level = (z_pos / levDelta);
    }

    return level;
}
