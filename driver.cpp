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
	bool flag = true;
	while(true)
	{	
		Queue<Command*> commands;
		std::istringstream infix ("");
		flag = false;
		printf("Please input an equation:\n");
		getline(std::cin, input);
		if( input.compare("QUIT") == 0 )
		{
			break;
		}
		
		if( input.compare("") != 0 )
		{// make sure the user doesn't just input nothing.
			flag = true;
		}
		
		if( flag )
		{//check the equation to make sure it's valid
			infix.clear();
			infix.str( input );
			flag = check_equation( infix );		
		}
		
		if( flag )
		{//run the evaluation on the equation
			infix.clear();
			infix.str( input );
			infix_to_command( infix, commands );
			evaluate( commands );
		}
	}
	printf("Goodbye.\n");
}

/*
 * Checks the input equation to make sure it can be accepted by the other
 * methods as a valid equation.
 */

bool check_equation( std::istringstream & check )
{
	std::string token;
	bool num_next = true; //used to make sure the equation is in proper order
	int parens = 0;//used to make sure there is an equivalent number of parens
	while( !check.eof() )
	{
		check >> token;
		
		if( is_integer(token) )
		{
			if ( num_next )
			{//if a number is supposed to be next, we're good
				num_next = false;
			}
			else
			{//a problem has emerged
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
			{//if an operator is supposed to be next, we're good
				num_next = true;
			}
			else
			{//a problem has emerged
				printf( "Error: \"%s\" Operator without numbers.\n", 
					token.c_str() );
				return false;
			}
		}
		else if ( token.compare("(") == 0 )
		{
			parens += 1;
			if ( num_next ) 
			{//if a number is supposed to be next, a "(" will work fine
				num_next = true;
			}
			else
			{//a problem has emerged
				printf( "Error: Expected Operator.\n" );
				return false;
			}
		}
		else if ( token.compare(")") == 0 )
		{
			parens -= 1;
			if ( !num_next )
			{//if an operator is supposed to be next, a ")" will work fine.
				if ( parens < 0 )
				{//if more closed parens than open parens have been encountered
				//at any time, something has gone wrong.
					printf( "Error: \")\" without \"(\"\n" );
					return false;
				}
			}
			else
			{//a problem has emerged
				printf( "Error: Invalid equation inside parenthesis.\n" );
				return false;
			}
		}
		else
		{//unrecognized token will not be accepted
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
// FIXED: Tested


/*
 * Takes in a stringstream object and updates the queue 
 * to have the equation in postfix form
 */

bool infix_to_command(std::istringstream & infix, Queue<Command*> & queue)
{
	std::string token;
	Stack<Command*> stack;//fresh stack for every recursion of this method
	Command *cmd = NULL;//command pointer for adding to queue or stack
	Stack_Factory factory;//factory to create commands.
	while(!infix.eof())
	{
		infix >> token;
		
		// For any operator,
		// create command based on token
		// clear stack based on token
		// push command onto stack 
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
		{//recurse onto itself if "(" is found
			infix_to_command( infix, queue );
		}
		else if( token.compare(")") == 0 )
		{//end recurse when ")" is found
			break;
		}
		else
		{
			cmd = factory.create_num_command(std::stoi(token));
			queue.enqueue(cmd);
		}
	}
	//clear the stack, either at the end of recursion or just the end of the
	//function
	clear_stack( 5, stack, queue );
	return true;
}

/*
 * Clear the stack, with rules based on the string passed in. If the string
 * is a + or - sign, pop until you see a plus or a minus sign. If the string
 * is a *, / or % sign, pop until an equivalent is found. 
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
	bool flag = true;
	// Iterate until the queue is empty or a problem emerges
	while( !queue.is_empty() && flag )
	{
		cmd = queue.dequeue();
		flag = cmd->execute(stack);
		delete cmd;
	}
	// If everything went fine and there's an element on the stack, print it.
	if( !stack.is_empty() && flag )
	{
		printf( "%d\n", stack.pop() );
	}
	// If something went wrong, empty the queue and print the error.
	if( !flag )
	{
		while( !queue.is_empty() )
		{
			cmd = queue.dequeue();
			delete cmd;
		}
		printf( "Undefined error: cannot divide or mod by 0\n" );
	}
}
