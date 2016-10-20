#ifndef _DIV_COMMAND_H_
#define _DIV_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include <iostream>

class Div_Command : public Command
{
public:
	virtual bool execute (Stack <int> & stack); 
};

#endif
