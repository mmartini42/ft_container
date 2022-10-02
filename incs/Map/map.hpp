// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 22/09/2022.
//

#ifndef FT_CONTAINER_MAP_HPP
#define FT_CONTAINER_MAP_HPP

#include <algorithm>
#include "iterator/iteratorMap.hpp"
#include "Pair.hpp"
#include "TreeStruct.hpp"
#include "rbTree.hpp"

namespace ft {

    template<class Key,
			class T,
					class Compare = std::less<Key>,
							class Allocator = std::allocator<ft::pair<Key, T> > >
	class map {
		typedef Allocator                   allocator_type;
		typedef ft::pair<T,Key>             value_type;
		typedef ft::node<value_type>		node;

	};

} // ft

#endif //FT_CONTAINER_MAP_HPP
