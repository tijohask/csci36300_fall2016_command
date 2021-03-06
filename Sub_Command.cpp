// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Sub_Command.h"

#define SUB_PREC 3
// Ryan: Why is this necessary?
// FIXED: It's not.
// #include <iostream>

// Ryan: Please include comments in each file.
// FIXED: Added comments

// Ryan: Why not pass the operands here rather than the stack?
// This will allow our design to be more flexible.
// FIXED: Passing operands
int Sub_Command :: eval(int n1, int n2)
{
	//return the subtraction of the top two elements on the stack
	return (n1 - n2);
}

// Ryan: You should handle precedence here.
// FIXED: Added precedence
int Sub_Command :: precedence()
{
	return SUB_PREC;
}

