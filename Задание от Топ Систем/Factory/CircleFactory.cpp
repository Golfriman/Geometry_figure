#include "CircleFactory.h"
#include "../Shape/Circle.h"
#include <cmath>

bool CircleFactory::buildShape(int x, int y)
{
    if (startPoint == nullptr)
    {
        startPoint = new std::pair<int, int>(std::make_pair(x, y));
    }
    else {
        r = static_cast<int>(std::sqrt(std::pow(x - startPoint->first, 2) + std::pow(y - startPoint->second, 2)));
        return true;
    }
    return false;
}

sh::Shape* CircleFactory::endBuild()
{
    return new sh::Circle(r, startPoint->first, startPoint->second);
}

sh::Shape* CircleFactory::tempBuild(int x, int y)
{
    if (startPoint != nullptr)
    {
        r = static_cast<int>(std::sqrt(std::pow(x - startPoint->first, 2) + std::pow(y - startPoint->second, 2)));
        return endBuild();
    }
    return nullptr;
}

CircleFactory::~CircleFactory()
{
    delete startPoint;
    startPoint = nullptr;
}
