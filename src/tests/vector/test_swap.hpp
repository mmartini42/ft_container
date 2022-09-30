// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_VECTOR_SWAP_HPP
# define TEST_VECTOR_SWAP_HPP

#include "test_vector.hpp"

template <class Vector>
void	test_vector_swap(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_swap *************" << std::endl << std::endl;
	Vector vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<typename Vector::value_type>(i * 10));
	vect.swap(vect2);
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

#endif