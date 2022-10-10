// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 30/09/2022.
//

#ifndef TEST_MAP_MAP_HPP
# define TEST_MAP_MAP_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <typeinfo>
#include <cxxabi.h>
#include "../../../incs/Map/map.hpp"

size_t INSERT_COUNT = 1;
size_t ERASE_COUNT = 1;

template <class Map>
void show_map_infos(Map &map, std::ofstream &file)
{
	typename Map::iterator ittt = map.end();
	(void)ittt;
	for(typename Map::iterator it = map.begin(); it != map.end(); it++)
		file << "key:" << it->first << " | value:" << it->second << " | size:" << map.size() << std::endl;
}

#include "test_insert.hpp"
#include "test_erase.hpp"
#include "test_operator.hpp"
#include "test_find.hpp"
#include "test_count.hpp"
#include "test_lower_bound.hpp"
#include "test_upper_bound.hpp"

template < class Map >
void test_map(size_t count, int seed, std::ofstream &file)
{
	Map map;
	int status;
	char *key_type = abi::__cxa_demangle(typeid(typename Map::key_type).name(), 0, 0, &status);
	char *value_type = abi::__cxa_demangle(typeid(typename Map::mapped_type).name(), 0, 0, &status);

	file << "############################################################" << std::endl;
	file << "############################################################" << std::endl;
	file << "#################### Key:"<< key_type << "  Value:" << value_type << "  ###################" << std::endl;
	file << "######################### SEED:"<< seed << " #########################" << std::endl;
	file << "######################## COUNT:"<< count << " ########################" << std::endl;
	file << "############################################################" << std::endl;
	file << "############################################################" << std::endl;


	file << "____________________________________________________________" << std::endl;
	file << "__________________________Empty ?___________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	file << "Empty?:" << map.empty() << std::endl;


	for (size_t i = 1; i < count; i++)
	{
		INSERT_COUNT = i;
		test_map_insert(map, file, seed);
	}

	test_map_operator(map, file);
	test_map_find(map, file);
	test_map_count(map, file);
	test_map_lower_bound(map, file);
	test_map_upper_bound(map, file);

	ERASE_COUNT = 10;
	test_map_erase(map, file);
	ERASE_COUNT = 20;
	test_map_erase(map, file);
	ERASE_COUNT = 30;
	test_map_erase(map, file);

	file << "____________________________________________________________" << std::endl;
	file << "__________________________Empty ?___________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	file << "Empty?:" << map.empty() << std::endl;

	map.clear();
	delete key_type;
	delete value_type;
}

#endif