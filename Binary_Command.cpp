// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Binary_Command.h"

// Take two elements from the top and apply eval on them.
bool Binary_Command :: execute(Stack<int> & stack)
{
	//The second number is the first popped from the stack
	int n2 = stack.pop(), n1 = stack.pop();
	try
	{
		//evaluate the expression, and push it on the stack
		int result = this->eval(n1, n2);
		stack.push(result); 
	}
	catch( int e )
	{
		//return false if int was thrown
		return false;
	}
	//return true if successful
	return true;
}

