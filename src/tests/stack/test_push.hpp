// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_STACK_PUSH_HPP
# define TEST_STACK_PUSH_HPP

#include "test_stack.hpp"

template <class Stack>
void test_stack_push(Stack &stk, std::ofstream &file, size_t count, int seed)
{
	file << "____________________________________________________________" << std::endl;
 	file << "____________________________Push____________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
	file << std::endl << "************* test_stack_push *************" << std::endl << std::endl;
	srand(seed);
 	for (size_t i = 0; i < count; i++)
 	{
 		const int idx = rand() % count;
		file << "value added: " << idx << std::endl;
 		stk.push(f<typename Stack::value_type>(idx));
		show_stack_infos(stk, file);
 	}
}

#endif