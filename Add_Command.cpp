// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Binary_Command.h"
#include "Add_Command.h"

#define ADD_PREC 3
// Ryan: Why is this necessary?
// FIXED: It's not.
// #include <iostream>

// Ryan: Please include comments in each file.
// FIXED: Added comments

// Ryan: Why not pass the operands here rather than the stack?
// This will allow our design to be more flexible.
// FIXED: Passing operands instead of the stack.

// Add command. Adds the top two elements of the stack together
int Add_Command :: eval(int n1, int n2)
{
	//return addition of the numbers
	return (n1 + n2);
}

// Ryan: You should handle precedence here.
// FIXED: Added precedence function
int Add_Command :: precedence()
{
	return ADD_PREC;
}
