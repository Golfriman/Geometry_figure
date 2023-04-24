#pragma once

#include "Shape.h"
namespace sh {
	class Line : public Shape
	{
		int x1;
		int y1;
		int x2;
		int y2;
	public:
		Line(int x1, int y1, int x2, int y2);
		void draw(HDC& hdc) const override;
	};
}