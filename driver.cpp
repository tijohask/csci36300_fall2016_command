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

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cstdlib>

void run_code();
bool check_equation( std::istringstream& );
bool infix_to_command( std::istringstream&, Queue<Command*>& );
void clear_stack( int, Stack<Command*>&, Queue<Command*>& );
int evaluate( Queue<Command*> );
bool is_integer( std::string );

int main()
{

	printf( "Welcome to the Infix to Postfix converting program\n" );
	printf( "Type \"QUIT\" to leave.\n" );
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
		printf("Please input an equation:\n");
		getline(std::cin, input);

		if( input.compare("QUIT") == 0 )
		{
			break;
		}
		std::istringstream infix (input);
		flag = check_equation( infix );		
		infix.clear();
		if( flag )
		{
			infix.clear();
			infix.str(input);
			infix_to_command( infix, commands );
		}
		 
		if( flag )
		{
			printf( "%d\n", evaluate( commands ) );
		}

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

bool infix_to_command(std::istringstream & infix, Queue<Command*> & queue)
{
	std::string token;
	Stack<Command*> stack;
	Command *cmd = NULL;
	Stack_Factory factory;
	while(!infix.eof())
	{
		infix >> token;
		
		if( token.compare("+") == 0 )
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
			break;
		}
		else
		{
			cmd = factory.create_num_command(std::stoi(token));
			queue.enqueue(cmd);
		}
	}
	while( !stack.is_empty() )
	{
		queue.enqueue( stack.pop() );
	}
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
int evaluate(Queue<Command*> queue)
{
	Command * cmd;
	Stack<int> stack;
	while( !queue.is_empty() )
	{
		cmd = queue.dequeue();
		cmd->execute(stack);
	}
	if( !stack.is_empty() )
	{
		return stack.pop();
	}
}
