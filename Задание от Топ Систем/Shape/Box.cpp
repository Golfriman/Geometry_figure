#include "Box.h"

void sh::Box::setLeftUpPoint(int x, int y)
{
	this->x = x;
	this->y = y;
	width = 0;
	height = 0;
}

void sh::Box::setWidth(int width)
{
	this->width = width;
}

void sh::Box::setHeight(int height)
{
	this->height = height;
}

void sh::Box::draw(HDC& hdc) const
{
	SelectObject(hdc, pen);
	MoveToEx(hdc, x, y, NULL);
	LineTo(hdc, x + width, y);
	LineTo(hdc, x + width, y + height);
	LineTo(hdc, x, y + height);
	LineTo(hdc, x, y);
}
