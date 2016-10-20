#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include <iostream>

class Add_Command : public Command
{
public:
	virtual bool execute (Stack <int> & stack); 
};

#endif
