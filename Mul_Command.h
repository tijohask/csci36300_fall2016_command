// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _MUL_COMMAND_H_
#define _MUL_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include "Binary_Command.h"
// Ryan: Why is this necessary?
// FIXED: It's not.
// #include <iostream>

// Ryan: Please include comments in each file.
// FIXED: Added comments

// Mul command. Multiply the top two elements of the stack
class Mul_Command : public Binary_Command
{
public:
	// Ryan: Why not pass the operands here rather than the stack?
	// This will allow our design to be more flexible.
	// FIXED: Passing operands
	virtual int eval (int n1, int n2);
	
	// Ryan: You should handle precedence here.
	// FIXED: Added precedence.
	virtual int precedence();
};

#endif
