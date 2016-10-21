#include "Array.h"
#include "Base_Array.h"
#include "Stack.h"
#include "Queue.h"

#include "Abstract_Factory.h"
#include "Stack_Factory.h"
#include "Command.h"
#include "Num_Command.h"
#include "Add_Command.h"
#include "Sub_Command.h"
#include "Mul_Command.h"
#include "Div_Command.h"
#include "Mod_Command.h"
//#include "Neg_Command.h"

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cstdlib>
//#include <stack>

//void array_test();
//void stack_test();
//void base_array_test();
void run_code();
bool infix_to_postfix(std::istringstream*, Stack<std::string>, Queue<std::string>);
void clear_stack(std::string, Stack<std::string>, Queue<std::string>);
bool postfix_to_command(Queue<std::string>, Queue<Command*>);
bool evaluate(Queue<Command*>);
void make_command(std::string token, Command &command, Queue<Command*> queue);
bool is_integer(std::string);

int main()
{

	printf( "Welcome to the Infix to Postfix converting program\n" );

//	std::string token = 0;
//	int thing = "";	
	
	run_code();
	
//	while(true)
//	{
//		std::getline(std::cin, input);
//		if(input.compare("QUIT") == 0)
//		{
//			break;
//		}
//		postfix = infix_to_postfix(input);
//		std::cout << "You typed: " << input << "\n";
//	}

}

void run_code()
{
	std::string input;
	Queue<std::string> queue;
	Queue<Command*> commands;
	Stack<std::string> stack;
	bool flag = true;
	while(true)
	{	
		flag = true;
		printf("Please input an equation:\n");
		getline(std::cin, input);
//		printf("Thanks");
		if( input.compare("QUIT") == 0 )
		{
			break;
		}
//		printf("Well, guess you're not quitting");
		std::istringstream infix (input);
		flag = infix_to_postfix(&infix, stack, queue);
		if(flag)
		{
			flag = postfix_to_command(queue, commands);
		}
//		if(flag)
//		{
//			evaluate(commands);
//		}
	}
	printf("Goodbye\n");
}


bool infix_to_postfix(std::istringstream * infix, Stack<std::string> stack, Queue<std::string> postfix)
{
	std::string token;
	
	while(!infix->eof())
	{
//		printf("Here");
		*infix >> token;
//		printf("And Here");
		if( is_integer(token) )
		{
			printf("Number!\n");
//			postfix.enqueue(token);
		}
		else if( token.compare("+") == 0 )
		{
			printf("Plus!\n");	
		}
		else if( token.compare("-") == 0 )
		{
			printf("Minus!\n");
		}
		else if( token.compare("*") == 0 )
		{
			printf("Multiplication!\n");
//			stack.push( token );
		}
		else if( token.compare("/") == 0 )
		{
			printf("Division!\n");
//			stack.push( token );
			
		}
		else if( token.compare("%") == 0 )
		{
			printf("Modulus!\n");
//			stack.push( token );
			
		}
		else if( token.compare("(") == 0 )
		{
			printf("Parenthesis!\n");			
//			clear_stack(token, stack, postfix);
			// Use an if statement to make sure that if the process fails
			// while recursing, it fails all the way up.
			if( !infix_to_postfix( infix, stack, postfix ) )
			{
				return false;
			}
			
		}
		else if( token.compare(")") == 0 )
		{
			printf("Parenthesis!\n");			
			break;
		}
		else
		{
			std::cout << token << " Is not a valid equation character.\n";
			return false;
		}
//		else if( token.compare("-") == 0 )
//		{
//			
//		}
	}
//	printf("Valid equation processed. Well done.\n");
//	return true;
}

void clear_stack(std::string until, Stack<std::string> to_clear, Queue<std::string> take)
{
	while( !to_clear.is_empty() )
	{
		take.enqueue(to_clear.pop());
	}
}


bool postfix_to_command(Queue<std::string> input, Queue<Command*> queue)
{
	std::string work;
	std::string token;
	Command *cmd = NULL;
	Stack_Factory factory;
	while(!input.is_empty())
	{
		token = input.dequeue();
	
//		make_command(token, *cmd, queue);
		
		if(      token.compare("+") == 0 )
		{
			cmd = factory.create_add_command();
			queue.enqueue(cmd);
		}
		else if( token.compare("-") == 0 )
		{
			cmd = factory.create_sub_command();
			queue.enqueue(cmd);
		}
		else if( token.compare("*") == 0 )
		{
			cmd = factory.create_mul_command();
			queue.enqueue(cmd);
		}
		else if( token.compare("/") == 0 )
		{
			cmd = factory.create_div_command();
			queue.enqueue(cmd);
		}
		else if( token.compare("%") == 0 )
		{
			cmd = factory.create_mod_command();
			queue.enqueue(cmd);
		}
//		else if( token.compare("-") == 0 )
//		{
//			cmd = factory.create_neg_command();
//			queue.enqueue(cmd);
//		}
		else
		{
			cmd = factory.create_num_command(std::stoi(token));
			queue.enqueue(cmd);
		}
	}
}

void make_command(std::string token, Command &command, Queue<Command*> queue)
{

		
}

bool is_integer(std::string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}
// Tested. Allows the inclusion of negative integers without tripping
// on just the negative sign. very useful

bool evaluate(Queue<Command*> queue)
{
	Command * cmd;
	Stack<int> stack;
	while( !queue.is_empty() )
	{
		cmd = queue.dequeue();
		cmd->execute(stack);
	}
}
