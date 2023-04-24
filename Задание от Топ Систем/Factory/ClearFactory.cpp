#include "ClearFactory.h"

bool ClearFactory::buildShape(int x, int y)
{
    return true;
}

sh::Shape* ClearFactory::tempBuild(int x, int y)
{
    return nullptr;
}

sh::Shape* ClearFactory::endBuild()
{
    return nullptr;
}
