#pragma once
#include "Shape/Shape.h"

class Mediator
{
	int iStyle;
	int cWidth;
	sh::Shape::Color color;
	bool checkStyle();
public:
	Mediator() :iStyle(PS_SOLID), cWidth(2), color(sh::Shape::Black) {}
	void changeStyle(int iStyle);
	void changeWidth(int cWidth);
	void changeColor(sh::Shape::Color color);
	HPEN buildPen();
};
