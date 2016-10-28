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
Num_Command :: Num_Command(int n): n_(n)
{

}

bool Num_Command :: execute(Stack<int> & stack)
{
	stack.push(n_);
	return true;
}

int Num_Command :: precedence()
{
	
}
