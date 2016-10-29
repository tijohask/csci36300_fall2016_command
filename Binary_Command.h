// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _BINARY_COMMAND_H_
#define _BINARY_COMMAND_H_

#include "Stack.h"
#include "Command.h"
// Ryan: Why is this necessary?
// FIXED: It's not.
// #include <iostream>

class Binary_Command : public Command
{
public:
	// Take two elements from the top and apply eval on them
	virtual bool execute(Stack<int> & stack);

	virtual int eval (int n1, int n2) = 0;
	
	virtual int precedence() = 0;
};

#endif
