#ifndef _NEG_COMMAND_H_
#define _NEG_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include <iostream>

class Neg_Command : public Command
{
public:
	virtual bool execute (Stack <int> & stack); 
};

#endif
