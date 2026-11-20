#pragma once

#include "MapDefs.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class LevelMgr
{
public:
	struct levelInfo
	{
		bool loaded;
		bool enabled;
		int levelnum;
	};
	std::vector<levelInfo> m_levels;

    LevelMgr();
    ~LevelMgr();

	void InitMapDefs(MapDefs defs);
	void GetLevelsToLoad(MapDefs defs, int playerCurLevel, int& minLevel, int& maxLevel);
	void SetLevelEnabled(int levelnum, bool enabled);
	void SetLevelLoaded(int levelnum, bool loaded);
	bool IsLevelEnabled(int levelnum);
	bool IsLevelLoaded(int levelnum);

	static int getCurLevelByPos(double z_pos);
};
