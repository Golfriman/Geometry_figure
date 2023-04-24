#include "LineCommand.h"
#include "../Factory/LineFactory.h"

Factory* LineCommand::execute()
{
	return new LineFactory();
}
