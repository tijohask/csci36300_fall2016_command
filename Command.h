// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Stack.h"
// Ryan: Why is this necessary?
#include <iostream>

// Ryan: Please include comments in each file.
class Command
{
public:
	virtual bool execute (Stack <int> & stack) = 0;
	
	// Ryan: You should handle precedence here.
};

//#include "Command.cpp"

#endif
