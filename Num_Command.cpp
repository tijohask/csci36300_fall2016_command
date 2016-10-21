// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack.h"
#include "Command.h"
#include "Num_Command.h"
#include <iostream>

Num_Command :: Num_Command(int n): n_(n)
{

}

bool Num_Command :: execute(Stack<int> & stack)
{
	stack.push(n_);
}
