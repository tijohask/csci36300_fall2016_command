// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Neg_Command.h"
#include <iostream>

bool Neg_Command :: execute(Stack<int> & stack)
{
	int n1 = stack.pop();
	stack.push(n1*(-1));
}
