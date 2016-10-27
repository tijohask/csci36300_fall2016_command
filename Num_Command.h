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
class Num_Command : public Command
{
public:
	Num_Command (int n);
	virtual bool execute (Stack <int> & stack);
	virtual int precedence ();
private:
	int n_;
};

#endif
