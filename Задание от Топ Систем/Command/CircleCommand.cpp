#include "CircleCommand.h"
#include "../Factory/CircleFactory.h"
Factory* CircleCommand::execute()
{
    return new CircleFactory();
}
