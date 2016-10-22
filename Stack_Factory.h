// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _STACK_FACTORY_H_
#define _STACK_FACTORY_H_

#include "Abstract_Factory.h"
#include "Command.h"
#include "Num_Command.h"
#include "Add_Command.h"
#include "Sub_Command.h"
#include "Mul_Command.h"
#include "Div_Command.h"
#include "Mod_Command.h"
#include "Neg_Command.h"
// Ryan: Why is this necessary?
#include <iostream>

// Ryan: Please include comments in each file.
class Stack_Factory : public Abstract_Factory
{
public:
	virtual Num_Command * create_num_command (int n);
	virtual Add_Command * create_add_command ();
	virtual Sub_Command * create_sub_command ();
	virtual Mul_Command * create_mul_command ();
	virtual Div_Command * create_div_command ();
	virtual Mod_Command * create_mod_command ();
//	virtual Neg_Command * create_neg_command ();
};

#endif
