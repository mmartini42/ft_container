// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_MAP_COUNT_HPP
# define TEST_MAP_COUNT_HPP

#include "test_map.hpp"

template < class Map >
void	test_map_count(Map &map, std::ofstream &file)
{
	file << "____________________________________________________________" << std::endl;
	file << "___________________________Count____________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;

	for (size_t i = 0; i < 500; i++)
		file << "Count " << i << ":" << map.count(i) << std::endl;

	file << "Count -10:" << map.count(-10) << std::endl;
	file << "Count 90000000:" << map.count(90000000) << std::endl;
}

#endif