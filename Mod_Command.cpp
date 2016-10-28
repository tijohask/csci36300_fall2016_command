// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Mod_Command.h"

#define MOD_PREC 2 

// Ryan: Why is this necessary?
// FIXED: It's not.
// #include <iostream>
// Ryan: Please include comments in each file.

// Ryan: Why not pass the operands here rather than the stack?
// This will allow our design to be more flexible.
// FIXED: Passing operands.
int Mod_Command :: eval(int n1, int n2)
{
	if( n2 == 0 )
	{
		throw 0;
	}
	return (n1 % n2);
}

// Ryan: You should handle precedence here.
// FIXED: Added precedence.
int Mod_Command :: precedence()
{
	return MOD_PREC;
}
