#pragma once
#include "Factory.h"
#include "../Shape/Polygon.h"
#include <utility>

class PolygonFactory : public Factory
{
	sh::Polygon* polygon;
	std::pair<int, int>* startPoint;
	enum {
		error = 10
	};
public:
	bool buildShape(int x, int y)override;
	sh::Shape* endBuild()override;
	sh::Shape* tempBuild(int x, int y)override;
	~PolygonFactory()
	{
		if (startPoint != nullptr)
			delete startPoint;
		if (polygon != nullptr)
			delete polygon;
	}
};