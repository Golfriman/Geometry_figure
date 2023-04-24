#include "Circle.h"
#include <cmath>

sh::Circle::Circle(int x0, int y0) :
	detalization(30), r(10), x0(x0), y0(y0)
{}

sh::Circle::Circle(int r):
	detalization(30), r(r), x0(100), y0(100)
{}

sh::Circle::Circle(int r, int x0, int y0) :
	detalization(30), r(r), x0(x0), y0(y0)
{}

void sh::Circle::setDetalization(int short d)
{
	this->detalization = d;
}

void sh::Circle::draw(HDC& hdc) const
{	
	SelectObject(hdc, pen);
	MoveToEx(hdc, x0 + static_cast<int>(r * cosf(0.f)), y0 + static_cast<int>(r * sinf(0.f)), NULL);
	for (int i = 1; i < this->detalization; i++)
	{
		int x = x0 + static_cast<int>(r * cosf(sh::Shape::PI * i * 2.f / detalization));
		int y = y0 + static_cast<int>(r * sinf(sh::Shape::PI * i * 2.f / detalization));
		LineTo(hdc, x, y);
	}
	LineTo(hdc, x0 + static_cast<int>(r * cosf(0.f)), y0 + static_cast<int>(r * sinf(0.f)));
}
