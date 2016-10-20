#include "Array.h"
#include "Base_Array.h"
#include "Stack.h"
#include "Abstract_Factory.h"
#include "Stack_Factory.h"
#include "Command.h"
#include "Num_Command.h"
//#include "Invoker.cpp"

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cstdlib>

//void array_test();
//void stack_test();
//void base_array_test();
void pre_run_tests();
void post_run_code();
bool infix_to_postfix(std::string, Array<Command*>);
bool evaluate(Array<Command*>);
void check_command(std::string token, Command &command, Array<Command*> &array);

int main()
{

	printf( "Welcome to the Infix to Postfix converting program\n" );
	printf( "Let me just run some tests here...\n" );
	
	pre_run_tests();
	
	printf( "OK, done.\n" );

	post_run_code();
	
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

void post_run_code()
{
	std::string input;


//	input = "+";
//	std::string test = "+";
//	if(input.compare(test) == 0)
//	{
//		printf("It worked!\n");
//	}
	
}

void pre_run_tests()
{
	//infix_to_postfix("1 + 2 - 3");
	Stack <int> stack;
	Num_Command command (5);
	command.execute(stack);
	
	std::cout << stack.pop() << "\n";
//	stack_test();
}

bool infix_to_postfix(std::string input, Array<Command*> &array)
{
	if(input.compare("QUIT") == 0)
	{
		return false;
	}
	std::string work;
	int i = 0;
	std::istringstream infix (input);
	std::string token;
	Command *cmd = NULL;
	while(!infix.eof())
	{
		infix >> token;
	
		check_command(token, *cmd, array);
	}
}

void check_command(std::string token, Command &command, Array<Command*> &array)
{
	if(token.compare("+") == 0)
	{
		
	}
}

bool evaluate(Array<Command*> &array)
{
	
}

/*
void base_array_test()
{
	Base_Array<int> barr1 (11, 9);
	barr1.set(5, 12);
	std::cout << barr1.get(5) << std::endl;
	std::cout << barr1.find(12) << std::endl;
	std::cout << barr1.find(9) << std::endl;
	std::cout << barr1.find(9, 3) << std::endl;
	std::cout << barr1.find(9, 5) << std::endl;
	std::cout << barr1.find(9, 7) << std::endl;
	std::cout << barr1.find(8) << std::endl;
	Base_Array<int> barr2 (7, 3);
	std::cout << barr2[3] << std::endl << std::endl;

//	std::cout << barr1.size() << std::endl;
//	std::cout << barr2.size() << std::endl;
	barr2 = barr1;
	for(int i = 0; i < barr1.size(); i++)
	{
		std::cout << barr1[i] << barr2[i] << std::endl;
	}
	std::cout << barr1.size() << std::endl;
	std::cout << barr2.size() << std::endl << std::endl << std::endl;

}

void array_test()
{
	Array<int> arr1 (11, 9);
	Array<int> arr3 (11, 9);
	arr1.set(5, 12);
	arr1.set(7, 9.0);

//	std::cout << arr1.get(5) << std::endl;
//	std::cout << arr1.find(12) << std::endl;
//	std::cout << arr1.find(9) << std::endl;
//	std::cout << arr1.find(9, 3) << std::endl;
//	std::cout << arr1.find(9, 5) << std::endl;
//	std::cout << arr1.find(9, 7) << std::endl;
//	std::cout << arr1.find(8) << std::endl;
//	std::cout << arr2[3] << std::endl << std::endl;

	Array<int> arr2 (7, 3);
	std::cout << arr1.size() << std::endl;
	std::cout << arr2.size() << std::endl;
	arr2 = arr1;
	if(arr2 == arr1)
	{
		std::cout << "They are equal [expected]" << std::endl;	
	}
	else
	{
		std::cout << "They are not equal" << std::endl;	
	}

	if(arr2 != arr1)
	{
		std::cout << "They are not equal" << std::endl;
	}
	else
	{
		std::cout << "They are equal [expected]" << std::endl;
	}

	if(arr3 == arr1)
	{
		std::cout << "They are equal" << std::endl;
	}
	else
	{
		std::cout << "They are not equal [expected]" << std::endl;
	}

	if(arr3 != arr1)
	{
		std::cout << "They are not equal [expected]" << std::endl;
	}
	else
	{
		std::cout << "They are equal" << std::endl;
	}

	for(int i = 0; i < arr1.size(); i++)
	{
		std::cout << arr1[i] << arr2[i] << std::endl;
	}
	std::cout << arr1.size() << std::endl;
	std::cout << arr2.size() << std::endl << std::endl << std::endl;

}

void stack_test()
{
	Stack <int> s1;
	Stack <int> s2;
	for(int i = 0; i < 7; i++)
	{
		s1.push(i);
	}
	Stack <char> ch;
	for(int i = 34; i < 87; i++)
	{
		ch.push(i);
	}
	s2 = s1;
	Stack <int> s3 (s1);
	Stack <int> s4 (s1);
	Stack <char> ch2 (ch);
	Stack <char> ch3;
	ch3 = ch2;
	std::cout << "First Stack" << std::endl;
	while(!s1.is_empty())
	{
		std::cout << s1.size() << std::endl;
		std::cout << s1.pop() << std::endl;
	}
	std::cout << s1.size() << std::endl;

	std::cout << "Second Stack" << std::endl;
	while(!s2.is_empty())
	{
		std::cout << s2.size() << std::endl;
		std::cout << s2.pop() << std::endl;
	}
	std::cout << s2.size() << std::endl;

	std::cout << "Third Stack" << std::endl;
	while(!s3.is_empty())
	{
		std::cout << s3.size() << std::endl;
		std::cout << s3.pop() << std::endl;
	}
	std::cout << s3.size() << std::endl;

	s4.clear();
	std::cout << "Fourth Stack" << std::endl;
	while(!s4.is_empty())
	{
		std::cout << s4.size() << std::endl;
		std::cout << s4.pop() << std::endl;
	}
	std::cout << s4.size() << std::endl;

	Stack<int> s5 (s4);

	std::cout << "Char Stack" << std::endl;
	while(!ch.is_empty())
	{
		std::cout << ch.size() << std::endl;
		std::cout << ch.pop() << std::endl;
	}
	std::cout << ch.size() << std::endl;

	std::cout << "Char Stack" << std::endl;
	while(!ch2.is_empty())
	{
		std::cout << ch2.size() << std::endl;
		std::cout << ch2.pop() << std::endl;
	}
	std::cout << ch2.size() << std::endl;

	std::cout << "Char Stack" << std::endl;
	while(!ch3.is_empty())
	{
		std::cout << ch3.size() << std::endl;
		std::cout << ch3.pop() << std::endl;
	}
	std::cout << ch.size() << std::endl;
}
*/
