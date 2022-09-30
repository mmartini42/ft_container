// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_VECTOR_POP_BACK_HPP
# define TEST_VECTOR_POP_BACK_HPP

#include "test_vector.hpp"

template <class Vector>
void test_vector_pop_back(Vector &vect, std::ofstream &file)
{
	file << "____________________________________________________________" << std::endl;
 	file << "__________________________Pop Back__________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
	file << std::endl << "************* test_vector_pop_back *************" << std::endl << std::endl;
	if (vect.size() > 0)
	{
 		vect.pop_back();
 		show_vector_infos(vect, file);
	}
	else
 		file << "Vector empty" << std::endl;
}

#endif