#pragma once
#include "../Shape/Shape.h"

class Factory
{
public:
	virtual bool buildShape(int x, int y) = 0;
	virtual sh::Shape* endBuild() = 0;
	virtual sh::Shape* tempBuild(int x, int y) = 0;
	virtual ~Factory() = default;
};
