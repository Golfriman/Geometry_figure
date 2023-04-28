#include "Mediator.h"

bool Mediator::checkStyle()
{
	return (iStyle != PS_SOLID || iStyle != PS_INSIDEFRAME);
}

void Mediator::changeStyle(int iStyle)
{
	this->iStyle = iStyle;
	if (checkStyle()) cWidth = 1;
}

void Mediator::changeWidth(int cWidth)
{
	if (checkStyle())
		return;
	this->cWidth = cWidth;

}

void Mediator::changeColor(sh::Shape::Color color)
{
	this->color = color;
}

HPEN Mediator::buildPen()
{
	return CreatePen(iStyle, cWidth, color);
}
