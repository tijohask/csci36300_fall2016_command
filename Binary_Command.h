// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _BINARY_COMMAND_H_
#define _BINARY_COMMAND_H_

#include "Stack.h"
#include "Command.h"
// Ryan: Why is this necessary?
// Fix: It's not.
// #include <iostream>

class Binary_Command : public Command
{
public:
	virtual bool execute(Stack<int> & stack);

	virtual int eval (int n1, int n2) = 0;
	
	// Ryan: You should handle precedence here.
	virtual int precedence() = 0;
};

//#include "Command.cpp"

#endif
