// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Div_Command.h"

#define DIV_PREC 2

// Ryan: Why is this necessary?
// FIXED: It's not.
// #include <iostream>

// Ryan: Please include comments in each file.
int Div_Command :: eval(int n1, int n2)
{
	if( n2 == 0 )
	{
		throw 0;
	}
	return (n1 / n2);
}

// Ryan: You should handle precedence here.
// FIXED: Added precedence
int Div_Command :: precedence()
{
	return DIV_PREC;
}
