#include "LineFactory.h"

bool LineFactory::buildShape(int x, int y)
{
    if (currentStep < step)
    {
        points[currentStep] = std::make_pair(x, y);
        currentStep++;
        if (currentStep == step)
            return true;
        return false;
    }
    return true;

}

sh::Shape* LineFactory::endBuild()
{
    return new sh::Line(points[0].first, points[0].second, points[1].first, points[1].second);
}

sh::Shape* LineFactory::tempBuild(int x, int y)
{
    if (currentStep == 1)
        return new sh::Line(points[0].first, points[0].second, x, y);
    else return nullptr;
}
