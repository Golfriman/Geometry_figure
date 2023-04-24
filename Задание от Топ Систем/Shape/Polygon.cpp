#include "Polygon.h"
#include <algorithm>

sh::Polygon* sh::Polygon::clone()
{
	return new Polygon(*this);
}

void sh::Polygon::draw(HDC& hdc) const
{
	SelectObject(hdc, pen);
	auto p1 = points.begin();
	MoveToEx(hdc, p1->x, p1->y, NULL);
	std::for_each(points.cbegin(), points.cend(), [&hdc](const Point& p)->void
	{
		LineTo(hdc, p.x, p.y);
	});
}

void sh::Polygon::addPoint(Point p)
{
	this->points.push_back(p);
}

sh::Polygon::Polygon(const Polygon& copy)
{
	this->points = copy.points;
}


