// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_STACK_OPERATOR_OVERLOAD_HPP
# define TEST_STACK_OPERATOR_OVERLOAD_HPP

#include "test_stack.hpp"

template <class Stack>
void	test_stack_operator_overload_equal(Stack &stk, std::ofstream &file)
{
	file << std::endl << "************* test_stack_operator_overload_equal *************" << std::endl << std::endl;
	Stack stk2;
	for (size_t i = 0; i < 5; i++)
		stk2.push(f<typename Stack::value_type>(i * 100));
	Stack stk3;
	for (size_t i = 0; i < 5; i++)
		stk2.push(f<typename Stack::value_type>(i * 10));

	file << "same" << std::endl;
	if (stk == stk)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (stk == stk2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (stk == stk3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class Stack>
void	test_stack_operator_overload_not_equal(Stack &stk, std::ofstream &file)
{
	file << std::endl << "************* test_stack_operator_overload_not_equal *************" << std::endl << std::endl;
	Stack stk2;
	for (size_t i = 0; i < 5; i++)
		stk2.push(f<typename Stack::value_type>(i * 100));
	Stack stk3;
	for (size_t i = 0; i < 5; i++)
		stk2.push(f<typename Stack::value_type>(i * 10));

	file << "same" << std::endl;
	if (stk != stk)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (stk != stk2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (stk != stk3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class Stack>
void	test_stack_operator_overload_inf(Stack &stk, std::ofstream &file)
{
	file << std::endl << "************* test_stack_operator_overload_inf *************" << std::endl << std::endl;
	Stack stk2;
	for (size_t i = 0; i < 5; i++)
		stk2.push(f<typename Stack::value_type>(i * 100));
	Stack stk3;
	for (size_t i = 0; i < 5; i++)
		stk2.push(f<typename Stack::value_type>(i * 10));

	file << "same" << std::endl;
	if (stk < stk)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (stk < stk2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (stk < stk3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class Stack>
void	test_stack_operator_overload_inf_equal(Stack &stk, std::ofstream &file)
{
	file << std::endl << "************* test_stack_operator_overload_inf_equal *************" << std::endl << std::endl;
	Stack stk2;
	for (size_t i = 0; i < 5; i++)
		stk2.push(f<typename Stack::value_type>(i * 100));
	Stack stk3;
	for (size_t i = 0; i < 5; i++)
		stk2.push(f<typename Stack::value_type>(i * 10));

	file << "same" << std::endl;
	if (stk <= stk)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (stk <= stk2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (stk <= stk3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class Stack>
void	test_stack_operator_overload_sup(Stack &stk, std::ofstream &file)
{
	file << std::endl << "************* test_stack_operator_overload_sup *************" << std::endl << std::endl;
	Stack stk2;
	for (size_t i = 0; i < 5; i++)
		stk2.push(f<typename Stack::value_type>(i * 100));
	Stack stk3;
	for (size_t i = 0; i < 5; i++)
		stk2.push(f<typename Stack::value_type>(i * 10));

	file << "same" << std::endl;
	if (stk > stk)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (stk > stk2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (stk > stk3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class Stack>
void	test_stack_operator_overload_sup_equal(Stack &stk, std::ofstream &file)
{
	file << std::endl << "************* test_stack_operator_overload_sup_equal *************" << std::endl << std::endl;
	Stack stk2;
	for (size_t i = 0; i < 5; i++)
		stk2.push(f<typename Stack::value_type>(i * 100));
	Stack stk3;
	for (size_t i = 0; i < 5; i++)
		stk2.push(f<typename Stack::value_type>(i * 10));

	file << "same" << std::endl;
	if (stk >= stk)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (stk >= stk2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (stk >= stk3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class Stack>
void	test_stack_operator_overload(Stack &stk, std::ofstream &file)
{
	file << "____________________________________________________________" << std::endl;
	file << "___________________Operators Overload_______________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	test_stack_operator_overload_equal(stk, file);
	test_stack_operator_overload_not_equal(stk, file);
	test_stack_operator_overload_inf(stk, file);
	test_stack_operator_overload_inf_equal(stk, file);
	test_stack_operator_overload_sup(stk, file);
	test_stack_operator_overload_sup_equal(stk, file);
}

#endif