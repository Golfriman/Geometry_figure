#include "Shape.h"

void sh::Shape::createPen()
{
	pen = CreatePen(iStyle, cWidth, color);
}

sh::Shape::Shape()
	:iStyle(PS_SOLID),
	 cWidth(2), 
	 color(Color::Black)
{
	createPen();
}

void sh::Shape::changeColorPen(Color color)
{
	this->color = color;
	createPen();
}

void sh::Shape::changeStylePen(int iStyle)
{
	this->iStyle = iStyle;
	createPen();
}

void sh::Shape::changeWidthPen(int cWdith)
{
	this->cWidth = cWidth;
	createPen();
}
