#pragma once
#include "Command.h"

class ClearCommand :public Command
{
public:
	Factory* execute()override;
};
