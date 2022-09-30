// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_VECTOR_PUSH_BACK_HPP
# define TEST_VECTOR_PUSH_BACK_HPP

#include "test_vector.hpp"

template <class Vector>
void test_vector_push_back(Vector &vect, std::ofstream &file, size_t count, int seed)
{
	file << "____________________________________________________________" << std::endl;
 	file << "_________________________Push Back__________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
	file << std::endl << "************* test_vector_push_back *************" << std::endl << std::endl;
	srand(seed);
 	for (size_t i = 0; i < count; i++)
 	{
 		const int idx = rand() % count;
		file << "value added: " << idx << std::endl;
 		vect.push_back(f<typename Vector::value_type>(idx));
		show_vector_infos(vect, file);
 	}
}

#endif