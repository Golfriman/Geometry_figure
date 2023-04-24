#include "ClearCommand.h"
#include "../Factory/ClearFactory.h"

Factory* ClearCommand::execute()
{
	return new ClearFactory();
}
