#pragma once
#include "Command.h"

class CircleCommand :public Command
{
public:
	Factory* execute()override;
};