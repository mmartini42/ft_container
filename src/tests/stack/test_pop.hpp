// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_STACK_POP_HPP
# define TEST_STACK_POP_HPP

#include "test_stack.hpp"

template <class Stack>
void test_stack_pop(Stack &stk, std::ofstream &file)
{
	file << "____________________________________________________________" << std::endl;
 	file << "_____________________________Pop____________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
	file << std::endl << "************* test_stack_pop *************" << std::endl << std::endl;
	if (stk.size() > 0)
	{
 		stk.pop();
 		show_stack_infos(stk, file);
	}
	else
 		file << "Stack empty" << std::endl;
}

#endif