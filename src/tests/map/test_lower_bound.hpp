// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_MAP_LOWER_BOUND_HPP
# define TEST_MAP_LOWER_BOUND_HPP

#include "test_map.hpp"

template < class Map >
void	test_map_lower_bound(Map &map, std::ofstream &file)
{
	file << "____________________________________________________________" << std::endl;
	file << "________________________Lower Bound_________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;

	typename Map::iterator it;
	for (size_t i = 0; i < 500; i++)
	{
		it = map.lower_bound(i);
		if (it == map.end())
			file << "Lower bound " << i << ": Not Found" << std::endl;
		else
			file << "Lower bound " << i << ": First=" << it->first << " | Second=" << it->second << std::endl;
	}
	it = map.lower_bound(-100);
	if (it == map.end())
		file << "Lower bound -100: Not Found" << std::endl;
	else
		file << "Lower bound -100: First=" << it->first << " | Second=" << it->second << std::endl;
	it = map.lower_bound(5000000);
	if (it == map.end())
		file << "Lower bound 5000000: Too hight" << std::endl;
	else
		file << "Lower bound 5000000: First=" << it->first << " | Second=" << it->second << std::endl;
}

#endif