// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_VECTOR_INSERT_HPP
# define TEST_VECTOR_INSERT_HPP

#include "test_vector.hpp"

template <class Vector>
void	test_vector_insert_pv(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_insert_pv *************" << std::endl << std::endl;
	typename Vector::iterator it = std::begin(vect);
	vect.insert(it, f<typename Vector::value_type>(5));
 	show_vector_datas(vect, file);
	show_vector_infos(vect, file);
}

template <class Vector>
void	test_vector_insert_pnv(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_insert_pnv *************" << std::endl << std::endl;
	typename Vector::iterator it = std::begin(vect) + 3;
	vect.insert(it, (size_t)30, f<typename Vector::value_type>(10));
 	show_vector_datas(vect, file);
	show_vector_infos(vect, file);
}

template <class Vector>
void	test_vector_insert_pfl(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_insert_pfl *************" << std::endl << std::endl;
	typename Vector::iterator it = vect.begin() + 5;
	Vector vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 10));
	vect.insert(it, vect2.begin(), vect2.end());
 	show_vector_datas(vect, file);
	show_vector_infos(vect, file);
}

template <class Vector>
void	test_vector_insert(Vector &vect, std::ofstream &file)
{
	file << "____________________________________________________________" << std::endl;
	file << "__________________________Insert____________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	test_vector_insert_pv(vect, file);
	test_vector_insert_pnv(vect, file);
	test_vector_insert_pfl(vect, file);
}

#endif