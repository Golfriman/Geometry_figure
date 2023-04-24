#pragma once
#include "Factory.h"
#include <utility>

class CircleFactory : public Factory
{
	std::pair<int, int>* startPoint;
	int r;
public:
	CircleFactory() = default;
	bool buildShape(int x, int y)override;
	sh::Shape* endBuild()override;
	sh::Shape* tempBuild(int x, int y)override;
	~CircleFactory();
};
