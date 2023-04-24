#pragma once
#include "Shape.h"
namespace sh {
	class Box : public Shape
	{
		int x;
		int y;
		int width;
		int height;
	public:
		Box() = default;
		void setLeftUpPoint(int x, int y);
		void setWidth(int width);
		void setHeight(int h);
		void draw(HDC& hdc)const override;
	};
}
