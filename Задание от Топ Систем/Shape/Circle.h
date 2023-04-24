#pragma once
#include "Shape.h"
namespace sh {

	class Circle : public Shape
	{
		short int detalization;
		int r;
		int x0;
		int y0;
	public:
		Circle(int x0, int y0);
		Circle(int r);
		Circle(int r, int x0, int y0);
		void setDetalization(int short d);
		void draw(HDC& hdc)const override;
	};
}
