#pragma once
#include "Factory.h"

class ClearFactory : public Factory
{
public:
	bool buildShape(int x, int y)override;
	sh::Shape* tempBuild(int x, int y)override;
	sh::Shape* endBuild()override;
};
