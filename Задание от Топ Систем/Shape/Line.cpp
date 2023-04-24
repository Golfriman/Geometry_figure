#include "Line.h"

sh::Line::Line(int x1, int y1, int x2, int y2)
	:x1(x1), y1(y1), x2(x2), y2(y2)
{
}

void sh::Line::draw(HDC& hdc) const
{
	SelectObject(hdc, pen);
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}
