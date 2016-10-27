// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Binary_Command.h"

// Binary Command
bool Binary_Command :: execute(Stack<int> & stack)
{
	int n2 = stack.pop(), n1 = stack.pop();
	int result = this->eval(n1, n2);
	stack.push(result);
}

