#ifndef _NUM_COMMAND_H_
#define _NUM_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include <iostream>

class Num_Command : public Command
{
public:
	Num_Command (int n);
	virtual bool execute (Stack <int> & stack); 
private:
	int n_;
};

#endif
