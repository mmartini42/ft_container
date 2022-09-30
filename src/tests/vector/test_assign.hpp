// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_VECTOR_ASSIGN_HPP
# define TEST_VECTOR_ASSIGN_HPP

#include "test_vector.hpp"

template <class Vector>
void	test_vector_assign_nv(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_assign_nv *************" << std::endl << std::endl;
 	vect.assign((size_t)15, f<typename Vector::value_type>(8));
 	show_vector_datas(vect, file);
 	show_vector_infos(vect, file);
}

template <class Vector>
void	test_vector_assign_fl(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_assign_fl *************" << std::endl << std::endl;
	Vector vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 10));
	vect.assign(vect2.begin(), vect2.end());
 	show_vector_datas(vect, file);
	show_vector_infos(vect, file);

}

template <class Vector>
void	test_vector_assign(Vector &vect, std::ofstream &file)
{
	file << "____________________________________________________________" << std::endl;
 	file << "__________________________Assign____________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;

	test_vector_assign_nv(vect, file);
	test_vector_assign_fl(vect, file);
}

#endif