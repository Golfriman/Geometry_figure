#pragma once
#include "Command.h"

class LineCommand : public Command
{
public:
	Factory* execute()override;
};
