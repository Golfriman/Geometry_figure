#include "PolygonCommand.h"
#include "../Factory/PolygonFactory.h"

Factory* PolygonCommand::execute()
{
    return new PolygonFactory();
}
