#ifndef _SUB_COMMAND_H_
#define _SUB_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include "Sub_Command.h"
#include <iostream>

class Sub_Command : public Command
{
public:
	virtual bool execute (Stack <int> & stack); 
};

#endif
