#pragma once
#include "Factory.h"
#include "../Shape/Box.h"
#include <array>

class BoxFactory : public Factory
{
	enum {
		step = 2
	};
	std::array<std::pair<int, int>, 2> points;
	int currentStep = 0;
public:
	bool buildShape(int x, int y)override;
	sh::Shape* endBuild()override;
	sh::Shape* tempBuild(int x, int y)override;
	~BoxFactory() = default;
};