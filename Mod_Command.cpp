// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Mod_Command.h"

#define MOD_PREC 2 

// Ryan: Why is this necessary?
// Fix: It's not.
// #include <iostream>
// Ryan: Please include comments in each file.

// Ryan: Why not pass the operands here rather than the stack?
// This will allow our design to be more flexible.
int Mod_Command :: eval(int n1, int n2)
{
	return (n1 + n2);
}

// Ryan: You should handle precedence here.
int Mod_Command :: precedence()
{
	return MOD_PREC;
}
// Ryan: You should handle precedence here.
