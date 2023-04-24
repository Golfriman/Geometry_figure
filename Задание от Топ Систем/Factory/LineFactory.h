#pragma once
#include "Factory.h"
#include "../Shape/Line.h"
#include <array>
#include <utility>


class LineFactory : public Factory
{
	const int step = 2;
	std::array<std::pair<int, int>, 2> points;
	int currentStep = 0;
public:
	bool buildShape(int x, int y)override;
	sh::Shape* endBuild()override;
	sh::Shape* tempBuild(int x, int y)override;
};
