#pragma once
#include "../Scene.h"
#include "../Factory/Factory.h"
class Command
{
public:
	virtual Factory* execute() = 0;
};