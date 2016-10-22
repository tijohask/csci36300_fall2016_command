// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _SUB_COMMAND_H_
#define _SUB_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include "Sub_Command.h"
// Ryan: Why is this necessary?
#include <iostream>

// Ryan: Please include comments in each file.
class Sub_Command : public Command
{
public:
// Ryan: Why not pass the operands here rather than the stack?
// This will allow our design to be more flexible.
	virtual bool execute (Stack <int> & stack); 
	
	// Ryan: You should handle precedence here.
};

#endif
