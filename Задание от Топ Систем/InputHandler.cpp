#include "InputHandler.h"
#include "Command/ClearCommand.h"
#include "Command/LineCommand.h"
#include "Command/BoxCommand.h"
#include "Command/PolygonCommand.h"
#include "Command/CircleCommand.h"
Command* InputHandler::handleInput(int idCommand)
{
	switch (idCommand)
	{
	case IDM_BUTTON1:
		return new CircleCommand;
	case IDM_BUTTON2:
		return new LineCommand;
	case IDM_BUTTON3:
		return new BoxCommand;
	case IDM_BUTTON4:
		return new PolygonCommand;
	case IDM_BUTTON5:
		return new ClearCommand;
	default:
		break;
	}
	return nullptr;
}
