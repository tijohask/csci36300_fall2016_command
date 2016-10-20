#include "Stack.h"
#include "Command.h"
#include "Mul_Command.h"
#include <iostream>

bool Mul_Command :: execute(Stack<int> & stack)
{
	int n1 = stack.pop(), n2 = stack.pop();
	stack.push(n1 * n2);
}
