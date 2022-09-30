// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_MAP_FIND_HPP
# define TEST_MAP_FIND_HPP

#include "test_map.hpp"

template < class Map >
void	test_map_find(Map &map, std::ofstream &file)
{
	file << "____________________________________________________________" << std::endl;
	file << "___________________________Find_____________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	typename Map::iterator it;
	for (size_t i = 200; i < 300; i++)
	{
		it = map.find(i);
		if (it == map.end())
			file << "Find " << i << ": Not Found" << std::endl;
		else
			file << "Find " << i << ": First=" << it->first << " | Second=" << it->second << std::endl;
	}
	it = map.find(-100);
	if (it == map.end())
		file << "Find -100: Not Found" << std::endl;
	else
		file << "Find -100: First=" << it->first << " | Second=" << it->second << std::endl;
	it = map.find(5000000);
	if (it == map.end())
		file << "Find 5000000: Not Found" << std::endl;
	else
		file << "Find 5000000: First=" << it->first << " | Second=" << it->second << std::endl;
}

#endif