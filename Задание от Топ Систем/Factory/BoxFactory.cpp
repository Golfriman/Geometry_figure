#include "BoxFactory.h"

bool BoxFactory::buildShape(int x, int y)
{
    if (currentStep == 0)
    {
        points[0] = std::make_pair(x, y);
        currentStep++;
        return false;
    }
    else if (currentStep == 1)
    {
        points[1] = std::make_pair(-points[0].first + x, -points[0].second + y);
        return true;
    }
}

sh::Shape* BoxFactory::endBuild()
{
    auto* shape = new sh::Box();
    shape->setLeftUpPoint(points[0].first, points[0].second);
    shape->setWidth(points[1].first);
    shape->setHeight(points[1].second);
    return shape;
}

sh::Shape* BoxFactory::tempBuild(int x, int y)
{
    sh::Box* shape = nullptr;
    if (currentStep == 1)
    {
        shape= new sh::Box();
        shape->setLeftUpPoint(points[0].first, points[0].second);
        shape->setWidth(-points[0].first + x);
        shape->setHeight(-points[0].second + y);
    }
    return shape;
}
