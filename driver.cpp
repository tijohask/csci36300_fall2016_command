// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

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
void run_test( Queue<std::string>& );
bool check_equation( std::istringstream& );
bool infix_to_postfix( std::istringstream&, Stack<std::string>&, Queue<std::string>& );
void clear_stack( int, Stack<Command*>&, Queue<Command*>& );
void clear_stack( std::string, Stack<std::string>&, Queue<std::string>& );
bool postfix_to_command( Queue<std::string>, Queue<Command*> );
bool evaluate( Queue<Command*> );
void make_command( std::string token, Command &command, Queue<Command*> queue );
bool is_integer( std::string );

int main()
{

	printf( "Welcome to the Infix to Postfix converting program\n" );
		
	run_code();
	
}

/*
 * I wanted to put most of my code in this method, 
 * just in case I wanted to run some tests from main
 */
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
		printf("Please input an equation,\nType \"QUIT\" to leave:\n");
		getline(std::cin, input);

		if( input.compare("QUIT") == 0 )
		{
			break;
		}
		std::istringstream check (input);
		flag = check_equation( check );		
		if( flag )
		{
			std::istringstream infix (input);
			flag = infix_to_postfix(infix, stack, queue);
			while( !stack.is_empty() )
			{
				queue.enqueue( stack.pop() );
			}
		}
		 
		if( flag )
		{
			//flag = postfix_to_command(queue, commands);
			while(!queue.is_empty())
			{
				printf( "%s ", queue.dequeue().c_str() );
			}
			printf("\n");
		
		}

//		if(flag)
//		{
//			evaluate(commands);
//		}

	}
	printf("Goodbye.\n");
}

bool check_equation( std::istringstream & check )
{
	std::string token;
	bool num_next = true;
	int parens = 0;
	while( !check.eof() )
	{
		check >> token;
		
		if( is_integer(token) )
		{
			if ( num_next )
			{
				num_next = false;
			}
			else
			{
				return false;
			}
		}
		else if ( token.compare("+") == 0 ||
		token.compare("-") == 0 ||
		token.compare("*") == 0 ||
		token.compare("/") == 0 ||
		token.compare("%") == 0 )
		{
			if ( !num_next )
			{
				num_next = true;
			}
			else
			{
				printf( "Error: \"%s\" Operator without numbers.\n", 
					token.c_str() );
				return false;
			}
		}
		else if ( token.compare("(") == 0 )
		{
			parens += 1;
			if ( num_next ) 
			{
				num_next = true;
			}
			else
			{
				printf( "Error: Expected Operator.\n" );
				return false;
			}
		}
		else if ( token.compare(")") == 0 )
		{
			parens -= 1;
			if ( !num_next )
			{
				if ( parens < 0 )
				{
					printf( "Error: \")\" without \"(\"\n" );
					return false;
				}
			}
			else
			{
				printf( "Error: Invalid equation inside parenthesis.\n" );
				return false;
			}
		}
		else
		{
			printf( "Error: %s not recognized.\n", token.c_str() );
			return false;
		}
	}
	if( parens != 0 )
	{
		printf( "Error: Unequal \"(\" and \")\" operators.\n" );
		return false;
	}
}

// Ryan: Need to ensure that you provide the correct output and 
// handle invalid input.

/*
 * Takes in a stringstream object and updates the queue 
 * to have the equation in postfix form
 */
 /*
bool infix_to_command(std::istringstream & infix, Queue<Command*> & queue)
{
	std::string token;
	Stack<Command*> stack;
	while(!infix.eof())
	{
		infix >> token;
		
		if( is_integer(token) )
		{
			cmd = factory.create_num_command(std::stoi(token));
			queue.enqueue(cmd);
		}
		else if( token.compare("+") == 0 )
		{
			cmd = factory.create_add_command();
			clear_stack(cmd->precedence(), stack, queue);
			stack.push( cmd );
		}
		else if( token.compare("-") == 0 )
		{
			cmd = factory.create_sub_command();
			clear_stack(cmd->precedence(), stack, queue);
			stack.push( cmd );
		}
		else if( token.compare("*") == 0 )
		{
			cmd = factory.create_mul_command();
			clear_stack(cmd->precedence(), stack, queue);
			stack.push( cmd );
		}
		else if( token.compare("/") == 0 )
		{
			cmd = factory.create_div_command();
			clear_stack(cmd->precedence(), stack, queue);
			stack.push( cmd );
		}
		else if( token.compare("%") == 0 )
		{
			cmd = factory.create_mod_command();
			clear_stack(cmd->precedence(), stack, queue);
			stack.push( cmd );
		}
		else if( token.compare("(") == 0 )
		{
			infix_to_command( infix, queue );
		}
		else if( token.compare(")") == 0 )
		{
			return true;
		}
	}
//	printf("Valid equation processed. Well done.\n");
	return true;
}
*/
bool infix_to_postfix(std::istringstream & infix, Stack<std::string> & stack, Queue<std::string> & postfix)
{
	std::string token;
	
	while(!infix.eof())
	{
		infix >> token;
		
		if( is_integer(token) )
		{
			postfix.enqueue(token);
		}
		else if( token.compare("+") == 0 )
		{
			clear_stack( token, stack, postfix );
			stack.push( token );
		}
		else if( token.compare("-") == 0 )
		{
			clear_stack( token, stack, postfix );
			stack.push( token );
		}
		else if( token.compare("*") == 0 )
		{
			if( !stack.is_empty() && ( (stack.top().compare("*") == 0 || stack.top().compare("/") == 0 || stack.top().compare("%") == 0) ) )
			{
				postfix.enqueue( stack.pop() );
			}
			stack.push( token );
		}
		else if( token.compare("/") == 0 )
		{
			if( !stack.is_empty() && ( (stack.top().compare("*") == 0 || stack.top().compare("/") == 0 || stack.top().compare("%") == 0) ) )
			{
				postfix.enqueue( stack.pop() );
			}
			stack.push( token );
			
		}
		else if( token.compare("%") == 0 )
		{
			if( !stack.is_empty() && ( (stack.top().compare("*") == 0 || stack.top().compare("/") == 0 || stack.top().compare("%") == 0) ) )
			{
				postfix.enqueue( stack.pop() );
			}
			stack.push( token );
			
		}
		else if( token.compare("(") == 0 )
		{
			stack.push( token );
			// Use an if statement to make sure that if the process fails
			// while recursing, it fails all the way up.
			if( !infix_to_postfix( infix, stack, postfix ) )
			{
				return false;
			}
			
		}
		else if( token.compare(")") == 0 )
		{
			clear_stack( token, stack, postfix );			
			return true;
		}
		else
		{
			printf( "%s Is not a valid equation character.\n", token.c_str() );
			return false;
		}
	}
//	printf("Valid equation processed. Well done.\n");
	return true;
}

/*
 * Clear the stack, with rules based on the string passed in. If the string
 * is a + or - sign, pop until you see a plus or a minus sign. If the string
 * is a closed parenthesis, pop until you see an open parenthesis. Else, pop 
 * until the stack is empty.
 */
void clear_stack(int prec, Stack<Command*> & stack, Queue<Command*> & take)
{
	while( !stack.is_empty() && stack.top()->precedence() <= prec )
	{
		take.enqueue( stack.pop() );
	}
}

void clear_stack(std::string until, Stack<std::string> & stack, Queue<std::string> & take)
{
	while( !stack.is_empty() )
	{
		if( ( until.compare("+") == 0 || until.compare("-") == 0 ) )
		{
			if( stack.top().compare("+") == 0 || stack.top().compare("-") == 0 )
			{
//				std::cout << stack.top() << " ";
				take.enqueue( stack.pop() );
//				printf("Added plus or minus to the queue.");
				break;
			}
			else if( stack.top().compare("(") == 0 )
			{
				break;
			}
			else
			{
//				std::cout << stack.top() << " ";
				take.enqueue( stack.pop() );
			}
		}
		else if( until.compare(")") == 0 )
		{
			if( stack.top().compare("(") == 0 )
			{
				stack.pop();
				break;
			}
			else
			{
//				std::cout << stack.top() << " ";
				take.enqueue( stack.pop() );
			}
		}
		else
		{
//			std::cout << stack.top() << " ";
			take.enqueue( stack.pop() );
		}
	}
}


/*
 * This will take the postfix queue created above and parse it into a command queue
 */

bool postfix_to_command(Queue<std::string> input, Queue<Command*> queue)
{
	std::string work;
	std::string token;
	Command *cmd = NULL;
	Stack_Factory factory;
	while(!input.is_empty())
	{
		token = input.dequeue();
			
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

/*
 * Checks whether the input string is a valid integer value. 
 * Allows for negative signs.
 */
bool is_integer(std::string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

/*
 * Runs through the Queue and executes the commands, then prints the resultant
 * number on the top of the stack. If the stack does not have exactly one 
 * element, return false.
 */
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
