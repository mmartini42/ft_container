// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_VECTOR_OPERATOR_OVERLOAD_HPP
# define TEST_VECTOR_OPERATOR_OVERLOAD_HPP

#include "test_vector.hpp"

template <class Vector>
void	test_vector_operator_overload_equal(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_operator_overload_equal *************" << std::endl << std::endl;
	Vector vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 100));
	Vector vect3;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 10));

	file << "same" << std::endl;
	if (vect == vect)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (vect == vect2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (vect == vect3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class Vector>
void	test_vector_operator_overload_not_equal(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_operator_overload_not_equal *************" << std::endl << std::endl;
	Vector vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 100));
	Vector vect3;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 10));

	file << "same" << std::endl;
	if (vect != vect)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (vect != vect2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (vect != vect3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class Vector>
void	test_vector_operator_overload_inf(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_operator_overload_inf *************" << std::endl << std::endl;
	Vector vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 100));
	Vector vect3;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 10));

	file << "same" << std::endl;
	if (vect < vect)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (vect < vect2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (vect < vect3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class Vector>
void	test_vector_operator_overload_inf_equal(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_operator_overload_inf_equal *************" << std::endl << std::endl;
	Vector vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 100));
	Vector vect3;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 10));

	file << "same" << std::endl;
	if (vect <= vect)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (vect <= vect2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (vect <= vect3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class Vector>
void	test_vector_operator_overload_sup(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_operator_overload_sup *************" << std::endl << std::endl;
	Vector vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 100));
	Vector vect3;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 10));

	file << "same" << std::endl;
	if (vect > vect)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (vect > vect2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (vect > vect3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class Vector>
void	test_vector_operator_overload_sup_equal(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_operator_overload_sup_equal *************" << std::endl << std::endl;
	Vector vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 100));
	Vector vect3;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 10));

	file << "same" << std::endl;
	if (vect >= vect)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (vect >= vect2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (vect >= vect3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class Vector>
void	test_vector_external_function_swap(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_external_function_swap *************" << std::endl << std::endl;
	Vector vect2;
	for (size_t i = 0; i < 10; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 100));
	swap(vect, vect2);
	file << "Vect 1" << std::endl;
 	show_vector_datas(vect, file);
	show_vector_infos(vect, file);
	file << "Vect 2" << std::endl;
	for (size_t i = 0; i < vect2.size(); i++)
	{
		file << "index:" << i << " | value:" << vect2[i] << std::endl;
	}
	show_vector_infos(vect2, file);
}


template <class Vector>
void	test_vector_operator_overload(Vector &vect, std::ofstream &file)
{
	file << "____________________________________________________________" << std::endl;
	file << "___________________Operators Overload_______________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	test_vector_operator_overload_equal(vect, file);
	test_vector_operator_overload_not_equal(vect, file);
	test_vector_operator_overload_inf(vect, file);
	test_vector_operator_overload_inf_equal(vect, file);
	test_vector_operator_overload_sup(vect, file);
	test_vector_operator_overload_sup_equal(vect, file);
	test_vector_external_function_swap(vect, file);
}

#endif