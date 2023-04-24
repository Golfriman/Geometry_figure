#include "BoxCommand.h"
#include "../Factory/BoxFactory.h"
Factory* BoxCommand::execute()
{
    return new BoxFactory();
}
