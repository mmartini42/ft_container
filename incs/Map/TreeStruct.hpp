// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 02/10/2022.
//

#ifndef FT_CONTAINER_TREESTRUCT_HPP
#define FT_CONTAINER_TREESTRUCT_HPP

#include <iostream>

namespace ft {
	template < class Pair >
	struct BiTreeNode
	{
		BiTreeNode *parent;
		Pair data;
		BiTreeNode *left;
		BiTreeNode *right;
		int color;
		typedef Pair& reference;
		typedef Pair* pointer;
		BiTreeNode(void) : data(Pair()) {}
		BiTreeNode(BiTreeNode const &instance): parent(instance.parent), data(instance.data), left(instance.left), right(instance.right), color(instance.color){}
		BiTreeNode(BiTreeNode *getParents, Pair datas) : parent(getParents), data(datas), left(NULL), right(NULL), color(0) {}
		~BiTreeNode(){}
	};
} // ft

#endif //FT_CONTAINER_TREESTRUCT_HPP
