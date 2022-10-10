// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 27/09/2022.
//

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <stack>
#include <map>
#include <fstream>
#include <sys/stat.h>
#include "../incs/Vector/vector.hpp"
#include "../incs/Map/map.hpp"
#include "../incs/stack.hpp"
#include "./tests/vector/test_vector.hpp"
#include "./tests/stack/test_stack.hpp"
#include "./tests/map/test_map.hpp"

#if 1
	int main(int argc, char** argv)
	{
		std::ofstream	my_file_vector;
		std::ofstream	file_vector;
		std::ofstream	my_file_map;
		std::ofstream	file_map;
		std::ofstream	my_file_stack;
		std::ofstream	file_stack;
		int rand_value;
		int my_tests = -1;
		int tests_type = -1;
		
		mkdir("./result", 0777);
		mkdir("./result/vector", 0777);
		mkdir("./result/map", 0777);
		mkdir("./result/stack", 0777);

		if(argc == 2)
			my_tests = atoi(argv[1]);
		if(argc == 3)
			tests_type = atoi(argv[2]);
			
		if (my_tests != 0)
		{
			if (tests_type == -1 || tests_type == 0)
				my_file_vector.open("./result/vector/MyVector.txt");
			if (tests_type == -1 || tests_type == 1)
				my_file_map.open("result/map/MyMap.txt");
			if (tests_type == -1 || tests_type == 2)
				my_file_stack.open("result/stack/MyStack.txt");
		}
		if (my_tests != 1)
		{
			if (tests_type == -1 || tests_type == 0)
				file_vector.open("result/vector/RealVector.txt");
			if (tests_type == -1 || tests_type == 1)
				file_map.open("result/map/RealMap.txt");
			if (tests_type == -1 || tests_type == 2)
				file_stack.open("result/stack/RealStack.txt");
		}

	/**
	 * TESTS VECTOR
	 */
		if (tests_type == -1 || tests_type == 0)
		{
			for (size_t seed = 0; seed < 200; seed++)
			{
				srand(seed);
				rand_value = rand() % 100;
				if (my_tests != 1)
					test_vector<std::vector<int> >(rand_value, seed, file_vector);
				if (my_tests != 0)
					test_vector<ft::vector<int> >(rand_value, seed, my_file_vector);
			}
		}

	/**
	 * TESTS MAP
	 */
		if (tests_type == -1 || tests_type == 1)
		{
			for (size_t seed = 0; seed < 50; seed++)
			{
				srand(seed);
				rand_value = rand() % 100;
				if (my_tests != 1)
					test_map<std::map<int, char> >(rand_value, seed, file_map);
				if (my_tests != 0)
					test_map<ft::map<int, char> >(rand_value, seed, my_file_map);
			}
		}

	/**
	 * TESTS STACK
	 */
		if (tests_type == -1 || tests_type == 2)
		{
			for (size_t seed = 0; seed < 50; seed++)
			{
				srand(seed);
				rand_value = rand() % 100;
				if (my_tests != 1)
					test_stack<std::stack<int> >(rand_value, seed, file_stack);
				if (my_tests != 0)
					test_stack<ft::stack<int> >(rand_value, seed, my_file_stack);
			}
		}
		
		return 0;
	}

#else

	#if 0 //CREATE A REAL STL EXAMPLE
		#include <map>
		#include <stack>
		#include <vector>
		namespace ft = std;
	#else
		#include <../incs/Map/Map.hpp>
		#include <../incs/Stack/Stack.hpp>
		#include <../incs/Vector/Vector.hpp>
	#endif

	#include <stdlib.h>

	#define MAX_RAM 4294967296
	#define BUFFER_SIZE 4096
	struct Buffer
	{
		int idx;
		char buff[BUFFER_SIZE];
	};


	#define COUNT (MAX_RAM / (int)sizeof(Buffer))

	template<typename T>
	class MutantStack : public ft::stack<T>
	{
	public:
		MutantStack() {}
		MutantStack(const MutantStack<T>& src) { *this = src; }
		MutantStack<T>& operator=(const MutantStack<T>& rhs)
		{
			this->c = rhs.c;
			return *this;
		}
		~MutantStack() {}

		typedef typename ft::stack<T>::container_type::iterator iterator;

		iterator begin() { return this->_c.begin(); }
		iterator end() { return this->_c.end(); }
	};

	int main(int argc, char** argv) {
		if (argc != 2)
		{
			std::cerr << "Usage: ./test seed" << std::endl;
			std::cerr << "Provide a seed please" << std::endl;
			std::cerr << "Count value:" << COUNT << std::endl;
			return 1;
		}
		const int seed = atoi(argv[1]);
		srand(seed);

		ft::vector<std::string> vector_str;
		ft::vector<int> vector_int;
		ft::stack<int> stack_int;
		ft::vector<Buffer> vector_buffer;
		ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
		ft::map<int, int> map_int;

		for (int i = 0; i < COUNT; i++)
		{
			vector_buffer.push_back(Buffer());
		}

		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer[idx].idx = 5;
		}
		ft::vector<Buffer>().swap(vector_buffer);

		try
		{
			for (int i = 0; i < COUNT; i++)
			{
				const int idx = rand() % COUNT;
				vector_buffer.at(idx);
				std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
			}
		}
		catch(const std::exception& e)
		{
			//NORMAL ! :P
		}

		for (int i = 0; i < COUNT; ++i)
		{
			map_int.insert(ft::make_pair(rand(), rand()));
		}

		int sum = 0;
		for (int i = 0; i < 10000; i++)
		{
			int access = rand();
			sum += map_int[access];
		}
		std::cout << "should be constant with the same seed: " << sum << std::endl;

		{
			ft::map<int, int> copy = map_int;
		}
		MutantStack<char> iterable_stack;
		for (char letter = 'a'; letter <= 'z'; letter++)
			iterable_stack.push(letter);
		for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
		{
			std::cout << *it;
		}
		std::cout << std::endl;
		return (0);
	}
#endif