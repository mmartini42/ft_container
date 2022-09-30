// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_VECTOR_ERASE_HPP
# define TEST_VECTOR_ERASE_HPP

#include "test_vector.hpp"

template <class Vector>
void	test_vector_erase_p(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_erase_p *************" << std::endl << std::endl;
	typename Vector::iterator it = vect.begin() + 2;
	vect.erase(it);
 	show_vector_datas(vect, file);
	show_vector_infos(vect, file);
}

template <class Vector>
void	test_vector_erase_fl(Vector &vect, std::ofstream &file)
{
	file << std::endl << "************* test_vector_erase_fl *************" << std::endl << std::endl;
	vect.erase(vect.begin() + 1, vect.begin() + 3);
 	show_vector_datas(vect, file);
	show_vector_infos(vect, file);
}

template <class Vector>
void	test_vector_erase(Vector &vect, std::ofstream &file)
{
	file << "____________________________________________________________" << std::endl;
	file << "__________________________Erase_____________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;

	test_vector_erase_p(vect, file);
	test_vector_erase_fl(vect, file);
}

#endif