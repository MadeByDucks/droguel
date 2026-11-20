#pragma once

class DrogDef
{
public:
    struct PlayerPos
    {
        float playerTilePosX;
        float playerTilePosY;
        float playerWorldPosX;
        float playerWorldPosY;

        float pointX;
        float pointY;
    };

public:
    DrogDef();
    ~DrogDef();

    static const bool ENV_IMGUI = true;
    static const bool ENV_UE = false;

    static const bool UE_ADD_MONSTER = true;
    static const bool UE_ADD_ITEMS = true;
};

