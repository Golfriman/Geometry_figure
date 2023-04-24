#include "Scene.h"
#include "Shape/Polygon.h"
#include "Shape/Circle.h"
#include "Shape/Line.h"
#include "Shape/Box.h"

Scene::Scene()
{
	initScene();
}

void Scene::draw(HDC& hdc)
{
	for (auto& i : shapes)
	{
		if(i!=nullptr)
			i->draw(hdc);
	}
}

void Scene::drawTempShape(HDC& hdc)
{
	if (temp != nullptr)
	{
		temp->draw(hdc);
		delete temp;
		temp = nullptr;
	}
}

void Scene::clear()
{
	for (auto& i : shapes)
		delete i;
	shapes.clear();
}

Scene::~Scene()
{
	this->clear();
}

void Scene::initScene()
{
	createLineExample();
	createBoxExample();
	createCircleExample();
	createPolygonExample();
}

void Scene::addShape(sh::Shape* shape)
{
	shapes.push_back(std::move(shape));
	shape = nullptr;
}

void Scene::addTempShape(sh::Shape* shape)
{
	this->temp = std::move(shape);
}

void Scene::createCircleExample()
{
	sh::Circle* circle = new sh::Circle(100, 300, 300);
	circle->changeColorPen(sh::Shape::Magenta);
	circle->setDetalization(360);
	addShape(circle);
	circle->setDetalization(30);
}

void Scene::createPolygonExample()
{
	sh::Polygon* polygon = new sh::Polygon();
	polygon->changeColorPen(sh::Shape::Cyan);
	polygon->addPoint(Point{ 300, 100 });
	polygon->addPoint(Point{ 400, 100 });
	polygon->addPoint(Point{ 250, 50 });
	polygon->addPoint(Point{ 300, 100 });
	addShape(polygon);
}

void Scene::createLineExample()
{
	sh::Line* line = new sh::Line(30, 30, 100, 100);
	addShape(line);
}

void Scene::createBoxExample()
{
	sh::Box* box = new sh::Box();
	box->changeColorPen(sh::Shape::Green);
	box->setLeftUpPoint(50, 200);
	box->setWidth(50);
	box->setHeight(50);
	addShape(box);
}
