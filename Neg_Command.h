// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _NEG_COMMAND_H_
#define _NEG_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include <iostream>

class Neg_Command : public Command
{
public:
	virtual bool execute (Stack <int> & stack); 
};

#endif
