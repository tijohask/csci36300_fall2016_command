#ifndef _MUL_COMMAND_H_
#define _MUL_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include <iostream>

class Mul_Command : public Command
{
public:
	virtual bool execute (Stack <int> & stack); 
};

#endif
