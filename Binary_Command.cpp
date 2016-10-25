// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Binary_Command.h"

// Ryan: Please include comments in each file.
// Ryan: Why not pass the operands here rather than the stack?
// This will allow our design to be more flexible.
bool Binary_Command :: execute(Stack<int> & stack)
{
	int n2 = stack.pop(), n1 = stack.pop();
	int result = this->eval(n1, n2);
	stack.push(result);
}

// Ryan: You should handle precedence here.

