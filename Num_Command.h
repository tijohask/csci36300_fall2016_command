// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _NUM_COMMAND_H_
#define _NUM_COMMAND_H_

#include "Stack.h"
#include "Command.h"
// Ryan: Why is this necessary?
// FIXED: It's not.
// #include <iostream>

// Ryan: Please include comments in each file.
// FIXED: Added comments

// Num command. Push a number onto the stack
class Num_Command : public Command
{
public:
	//construct with a number
	Num_Command (int n);
	//push the number on the stack
	virtual bool execute (Stack <int> & stack);
	virtual int precedence ();
private:
	int n_;
};

#endif
