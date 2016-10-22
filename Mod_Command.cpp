// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Mod_Command.h"
// Ryan: Why is this necessary?
#include <iostream>
// Ryan: Please include comments in each file.

// Ryan: Why not pass the operands here rather than the stack?
// This will allow our design to be more flexible.
bool Mod_Command :: execute(Stack<int> & stack)
{
	int n1 = stack.pop(), n2 = stack.pop();
	stack.push(n1 % n2);
}

// Ryan: You should handle precedence here.