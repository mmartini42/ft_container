// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_VECTOR_ELEMENTS_ACCESS_HPP
# define TEST_VECTOR_ELEMENTS_ACCESS_HPP

#include "test_vector.hpp"

template <class Vector>
void test_vector_elements_access(Vector &vect, std::ofstream &file)
{
 	file << "____________________________________________________________" << std::endl;
 	file << "______________________Elements Access_______________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
	if (vect.size() > 3)
 		file << "index 3 -> operator[]:" << vect[3] << std::endl;	
 	try
 	{
 		file << "index 15 -> at:" << vect.at(15) << std::endl;
 	}
 	catch(const std::exception& e)
 	{
 		file << e.what() << '\n';
 	}
 	try
 	{
 		file << "index 4 -> at:" << vect.at(4) << std::endl;
 	}
 	catch(const std::exception& e)
 	{
 		file << e.what() << '\n';
 	}
}

#endif