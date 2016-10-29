// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Stack.h"
// Ryan: Why is this necessary?
// FIXED: It's not.
// #include <iostream>

// Ryan: Please include comments in each file.
// FIXED: Added comments

// The top object that all other command objects will be inheriting from.
class Command
{
public:
	virtual bool execute (Stack <int> & stack) = 0;

	// Ryan: You should handle precedence here.	
	// FIXED: Added precedence
	virtual int precedence() = 0;
};


#endif
