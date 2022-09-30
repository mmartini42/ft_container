// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_MAP_OPERATOR_HPP
# define TEST_MAP_OPERATOR_HPP

#include "test_map.hpp"

template < class Map >
void	test_map_operator(Map &map, std::ofstream &file)
{
	file << "____________________________________________________________" << std::endl;
	file << "________________________Operator[]__________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	for (size_t i = 0; i < 100; i++)
		file << "Operator[" << i << "]:" << map[i] << std::endl;
		
	file << "Operator[-5]:" << map[-5] << std::endl;
	file << "Operator[-6]:" << map[-6] << std::endl;
}

#endif