#include "PolygonFactory.h"

bool PolygonFactory::buildShape(int x, int y)
{
    if (startPoint == nullptr)
    {
        startPoint = new std::pair<int, int>(std::make_pair(x, y));
        polygon = new sh::Polygon();
        polygon->addPoint({x,y});
    }
    else if
        ((((startPoint->first - error) <= x) && ((startPoint->first + error) >= x)) && (((startPoint->second - error) <= y) && ((startPoint->second + error) >= y)))
    {
        polygon->addPoint({ startPoint->first, startPoint->second });
        return true;
    }
    else {
        polygon->addPoint({ x, y});
    }
    return false;
}

sh::Shape* PolygonFactory::endBuild()
{
    return polygon->clone();
}

sh::Shape* PolygonFactory::tempBuild(int x, int y)
{
    if (polygon == nullptr)
        return nullptr;
    auto temp = polygon->clone();
    temp->addPoint({ x, y });
    return temp;
}
