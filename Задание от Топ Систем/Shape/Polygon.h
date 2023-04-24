#pragma once
#include "Shape.h"
#include "Point.h"
#include <list>
namespace sh {
	class Polygon : public Shape
	{
	public:
		Polygon() = default;
		Polygon* clone();
		void draw(HDC& hdc) const override;
		void addPoint(Point p);
		~Polygon() = default;
		Polygon(const Polygon& copy);
	private:
		std::list<Point> points;
	};
}
