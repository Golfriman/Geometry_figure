#pragma once
#include "Command/Command.h"

class InputHandler
{
public:
    enum ID
    {
        IDM_BUTTON1 = 101,
        IDM_BUTTON2,
        IDM_BUTTON3,
        IDM_BUTTON4,
        IDM_BUTTON5,
        IDM_BUTTON6
    };
    Command* handleInput(int idCommand);
};
