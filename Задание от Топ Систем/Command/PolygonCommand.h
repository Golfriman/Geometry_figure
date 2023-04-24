#pragma once
#include "Command.h"

class PolygonCommand : public Command
{
public:
	Factory* execute() override;
};