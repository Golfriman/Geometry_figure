#pragma once
#include "Command.h"

class BoxCommand : public Command
{
public:
	BoxCommand() = default;
	Factory* execute()override;
};
