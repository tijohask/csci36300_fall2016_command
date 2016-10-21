// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Stack.h"
#include <iostream>

class Command
{
public:
	virtual bool execute (Stack <int> & stack) = 0;
};

//#include "Command.cpp"

#endif
