// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_MAP_INSERT_HPP
# define TEST_MAP_INSERT_HPP

#include "test_map.hpp"

template < class Map >
void	test_map_insert_value_type(Map &map, std::ofstream &file, int seed)
{
	file << std::endl << "************* test_map_insert_value_type *************" << std::endl << std::endl;
	srand(seed);
 	for (size_t i = 0; i < INSERT_COUNT; i++)
 	{
 		typename Map::key_type idx = rand() % (INSERT_COUNT);
		typename Map::mapped_type value = rand() % (INSERT_COUNT * 20);
 		map.insert(typename Map::value_type(idx, value));
 	}
 	show_map_infos(map, file);
}

template < class Map >
void	test_map_insert_position(Map &map, std::ofstream &file, int seed)
{
	file << std::endl << "************* test_map_insert_position *************" << std::endl << std::endl;
	srand(seed);
	typename Map::iterator it = map.begin();
 	for (size_t i = 0; i < INSERT_COUNT / 2; i++)
 	{
 		typename Map::key_type idx = rand() % (INSERT_COUNT * 10);
 		typename Map::mapped_type value = rand() % (INSERT_COUNT * 20);
 		map.insert(it, typename Map::value_type(idx, value));
 	}
 	show_map_infos(map, file);
}

template < class Map >
void	test_map_insert_first_last(Map &map, std::ofstream &file, int seed)
{
	file << std::endl << "************* test_map_insert_first_last *************" << std::endl << std::endl;
	srand(seed);
	typename Map::iterator it_1 = map.begin();
	typename Map::iterator it_2 = map.end();
	it_2--;
 	for (size_t i = 0; i < INSERT_COUNT; i++)
 	{
 		map.insert(it_1, it_2);
 	}
 	show_map_infos(map, file);
}

template < class Map >
void	test_map_insert(Map &map, std::ofstream &file, int seed)
{
 	file << "____________________________________________________________" << std::endl;
 	file << "___________________________Insert___________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;

	test_map_insert_value_type(map, file, seed);
	test_map_insert_position(map, file, seed);
	test_map_insert_first_last(map, file, seed);
}

#endif