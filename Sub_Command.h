// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

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
