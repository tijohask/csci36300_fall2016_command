// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Div_Command.h"
// Ryan: Why is this necessary?
#include <iostream>

// Ryan: Please include comments in each file.
bool Div_Command :: execute(Stack<int> & stack)
{
	// Ryan: You should check for exceptions here - 
	// division by 0.
	int n1 = stack.pop(), n2 = stack.pop();
	stack.push(n1 / n2);
}

// Ryan: You should handle precedence here.
