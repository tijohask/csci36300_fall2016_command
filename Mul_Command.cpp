// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Mul_Command.h"

#define MUL_PREC 2

// Ryan: Why is this necessary?
// FIXED: It's not.
// #include <iostream>

// Ryan: Please include comments in each file.
// FIXED: Added comments

// Ryan: Why not pass the operands here rather than the stack?
// This will allow our design to be more flexible.
// FIXED: Passing operands here.

// MUL Command. Multiplies the top two elements of the stack.
int Mul_Command :: eval(int n1, int n2)
{
	//return multiplication
	return (n1 * n2);
}

// Ryan: You should handle precedence here.
// FIXED: Added precedence
int Mul_Command :: precedence()
{
	return MUL_PREC;
}

