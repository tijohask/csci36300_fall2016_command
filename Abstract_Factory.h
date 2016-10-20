#ifndef _ABSTRACT_FACTORY_H_
#define _ABSTRACT_FACTORY_H_

#include "Command.h"
#include "Num_Command.h"
#include "Add_Command.h"
#include "Sub_Command.h"
#include "Mul_Command.h"
#include "Div_Command.h"
#include "Mod_Command.h"
#include "Neg_Command.h"
#include <iostream>

class Abstract_Factory
{
public:
	virtual Num_Command * create_num_command (int n) = 0;
	virtual Add_Command * create_add_command () = 0;
	virtual Sub_Command * create_sub_command () = 0;
	virtual Mul_Command * create_mul_command () = 0;
	virtual Div_Command * create_div_command () = 0;
	virtual Mod_Command * create_mod_command () = 0;
	virtual Neg_Command * create_neg_command () = 0;
};

#endif
