#pragma once
#include "Shape/Shape.h"
#include <list>

class Scene
{
public:
	Scene();
	void draw(HDC& hdc);
	void drawTempShape(HDC& hdc);
	void addShape(sh::Shape* shape);
	void addTempShape(sh::Shape* shape);
	void clear();
	~Scene();
private:
	std::list<sh::Shape*> shapes;
	sh::Shape* temp;
	void initScene();
	void createLineExample();
	void createBoxExample();
	void createCircleExample();
	void createPolygonExample();
};