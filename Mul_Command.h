// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _MUL_COMMAND_H_
#define _MUL_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include <iostream>

class Mul_Command : public Command
{
public:
	virtual bool execute (Stack <int> & stack); 
};

#endif
