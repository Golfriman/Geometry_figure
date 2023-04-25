#pragma once
#include <windows.h>
namespace sh {
	class Shape
	{
	public:
		const float PI = 3.141'592'6f;
		enum Color
		{
			Black = 0x000000,
			Red = 0x0000ff,
			Green = 0x00ff00,
			Blue = 0xff0000,
			Magenta = 0xff00ff,
			Yellow = 0x00ffff,
			Cyan = 0xffff00
		};
		Shape();
		void changeColorPen(Color color);
		void changeStylePen(int iStyle);
		void changeWidthPen(int cWdith);
		void setHPEN(HPEN pen);
		virtual void draw(HDC& hdc) const = 0;
		virtual ~Shape() = default;
	private:
		int iStyle;
		int cWidth;
		Color color;
		void createPen();
	protected:
		HPEN pen;
	};
}