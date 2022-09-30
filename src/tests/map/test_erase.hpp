// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_MAP_ERASE_HPP
# define TEST_MAP_ERASE_HPP

#include "test_map.hpp"

template < class Map >
void	test_map_erase_key(Map &map, std::ofstream &file)
{
	file << std::endl << "************* test_map_erase_key *************" << std::endl << std::endl;
	typename Map::iterator it = map.begin();
	for (size_t i = 0; i < ERASE_COUNT; i++)
	{
		it++;
		if (it == map.end())
		{
			it--;
			break;
		}
	}
	file << "Key erased:" << it->first << std::endl;
 	map.erase(it->first);
 	show_map_infos(map, file);
}

template < class Map >
void	test_map_erase_position(Map &map, std::ofstream &file)
{
	file << std::endl << "************* test_map_erase_position *************" << std::endl << std::endl;
	typename Map::iterator it = map.begin();
	for (size_t i = 0; i < ERASE_COUNT; i++)
	{
		it++;
		if (it == map.end())
		{
			it--;
			break;
		}
	}
	file << "Key erased:" << it->first << std::endl;
	if (map.size() > 0)
 		map.erase(it);
 	show_map_infos(map, file);
}

template < class Map >
void	test_map_erase_first_last(Map &map, std::ofstream &file)
{
	file << std::endl << "************* test_map_erase_first_last *************" << std::endl << std::endl;
	typename Map::iterator it = map.begin();
	typename Map::iterator it_1 = it;
	for (size_t i = 0; i < 3; i++)
	{
		it++;
		if (it == map.end())
		{
			it--;
			break;
		}
	}
	typename Map::iterator it_2 = it;
	if (map.size() > 0 && it_1 != it_2 && it != it_2)
	{
		it_2--;
		if (it_1 != it_2)
		{
			
		file << "Key erased first:" << it_1->first << " | Key erased last:" << it_2->first << std::endl;
			map.erase(it_1, it_2);
			show_map_infos(map, file);
		}
	}
}

template < class Map >
void	test_map_erase(Map &map, std::ofstream &file)
{
 	file << "____________________________________________________________" << std::endl;
 	file << "___________________________Erase___________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;

	test_map_erase_key(map, file);
	test_map_erase_position(map, file);
	test_map_erase_first_last(map, file);
}

#endif