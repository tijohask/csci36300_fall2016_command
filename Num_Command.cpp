// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Num_Command.h"
// Ryan: Why is this necessary?
// FIXED: It's not.
// #include <iostream>

// Ryan: Please include comments in each file.
// FIXED: Added comments
Num_Command :: Num_Command(int n): n_(n)
{
	//Constructs a new number command with the input integer
}

bool Num_Command :: execute(Stack<int> & stack)
{
	//push the number onto the stack
	stack.push(n_);
	return true;
}

int Num_Command :: precedence()
{
	//the compiler wouldn't stop crying so I had to make this method.
}
