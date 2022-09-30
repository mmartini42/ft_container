// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_VECTOR_CLEAR_HPP
# define TEST_VECTOR_CLEAR_HPP

#include "test_vector.hpp"

template <class Vector>
void	test_vector_clear(Vector &vect, std::ofstream &file)
{	 
 	file << "____________________________________________________________" << std::endl;
 	file << "__________________________Clear_____________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
	file << std::endl << "************* test_vector_clear *************" << std::endl << std::endl;
 	vect.clear();
 	file << "is empty ?:" << vect.empty() << std::endl;
 	file << "size: " << vect.size() << std::endl; 
}

#endif