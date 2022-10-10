// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_STACK_HPP
# define TEST_STACK_HPP

#include <sstream>
#include <iostream>
#include <stack>
#include <fstream>
#include <typeinfo>
#include <cxxabi.h>
#include "../../../incs/stack.hpp"

template <class Stack>
void show_stack_infos(Stack &stk, std::ofstream &file)
{
	if (stk.size() > 0)
	{
		file << "size: " << stk.size() << " | top:" << stk.top() << std::endl << std::endl;
	}
}

#include "test_operator_overload.hpp"
#include "test_pop.hpp"
#include "test_push.hpp"

template <class Stack>
void test_stack(size_t count, int seed, std::ofstream &file)
{
	Stack stk;
	int status;
	char *type = abi::__cxa_demangle(typeid(typename Stack::value_type).name(), 0, 0, &status);

	file << "############################################################" << std::endl;
	file << "############################################################" << std::endl;
	file << "########################### "<< type << " ############################" << std::endl;
	file << "########################## SEED:"<< seed << " ##########################" << std::endl;
	file << "############################################################" << std::endl;
	file << "############################################################" << std::endl;
	
	file << "Empty ?: " << stk.empty() << std::endl;
	test_stack_pop(stk, file);
	test_stack_push(stk, file, count, seed);
	test_stack_pop(stk, file);
	test_stack_operator_overload(stk, file);
	file << "Empty ?: " << stk.empty() << std::endl;
	
	delete type;
}

#endif