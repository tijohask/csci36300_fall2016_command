// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _ABSTRACT_FACTORY_H_
#define _ABSTRACT_FACTORY_H_

#include "Command.h"
#include "Binary_Command.h"
#include "Num_Command.h"
#include "Add_Command.h"
#include "Sub_Command.h"
#include "Mul_Command.h"
#include "Div_Command.h"
#include "Mod_Command.h"
// Ryan: Why is this necessary?
// FIXED: It's not.
// #include <iostream>

// Ryan: Please include comments in each file.
class Abstract_Factory
{
public:
	virtual Num_Command * create_num_command (int n) = 0;
	virtual Add_Command * create_add_command () = 0;
	virtual Sub_Command * create_sub_command () = 0;
	virtual Mul_Command * create_mul_command () = 0;
	virtual Div_Command * create_div_command () = 0;
	virtual Mod_Command * create_mod_command () = 0;
};

#endif
