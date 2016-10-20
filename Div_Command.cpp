#include "Stack.h"
#include "Command.h"
#include "Div_Command.h"
#include <iostream>

bool Div_Command :: execute(Stack<int> & stack)
{
	int n1 = stack.pop(), n2 = stack.pop();
	stack.push(n1 / n2);
}
