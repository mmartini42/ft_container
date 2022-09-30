// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_VECTOR_RESIZE_HPP
# define TEST_VECTOR_RESIZE_HPP

#include "test_vector.hpp"

template <class Vector>
void	test_vector_resize(Vector &vect, std::ofstream &file)
{
 	file << "____________________________________________________________" << std::endl;
 	file << "___________________________Resize___________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
	file << std::endl << "************* test_vector_resize *************" << std::endl << std::endl;
 	vect.resize(3);
 	file << "resize 3" << std::endl;
 	show_vector_datas(vect, file);
 	show_vector_infos(vect, file);
 	vect.resize(18);
 	file << "resize 18" << std::endl;
 	show_vector_datas(vect, file);
 	show_vector_infos(vect, file);
 	vect.resize(20, f<typename Vector::value_type>(5));
 	file << "resize 20 - 5" << std::endl;
 	show_vector_datas(vect, file);
 	show_vector_infos(vect, file);
}

#endif