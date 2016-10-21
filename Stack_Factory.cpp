// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//The factory that creates commands that operate on the stack

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

Num_Command * Stack_Factory::create_num_command(int n)
{
	return new Num_Command(n);
}
Add_Command * Stack_Factory::create_add_command(void)
{
	return new Add_Command();
}
Sub_Command * Stack_Factory::create_sub_command(void)
{
	return new Sub_Command();
}
Mul_Command * Stack_Factory::create_mul_command(void)
{
	return new Mul_Command();
}
Div_Command * Stack_Factory::create_div_command(void)
{
	return new Div_Command();
}
Mod_Command * Stack_Factory::create_mod_command(void)
{
	return new Mod_Command();
}
//Neg_Command * Stack_Factory::create_neg_command(void)
//{
//	return new Neg_Command();
//}
