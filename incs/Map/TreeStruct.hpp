// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 02/10/2022.
//

#ifndef FT_CONTAINER_TREESTRUCT_HPP
#define FT_CONTAINER_TREESTRUCT_HPP

#include <iostream>

namespace ft {

	enum color { black = 0, red = 1 };

	template<class Pair>
	class TreeStruct {
	public:

		TreeStruct*		parent;
		TreeStruct*		left;
		TreeStruct*		right;
		Pair			data;
		color			color;

		typedef Pair&	ref;
		typedef Pair*	ptr;

		TreeStruct() : data(Pair()) {}
		TreeStruct(const TreeStruct& node) : parent(node.parent), left(node.left), right(node.right), color(node.color) {}
		TreeStruct(TreeStruct *parents, Pair datas) : parent(parents),left(NULL), right(NULL), data(datas), color(black) {}
		~TreeStruct() {}

		};

		template <class T>
		struct node {
			typedef T                       value_type;
			typedef value_type             *pointer;
			typedef node<value_type>       *node_pointer;
			typedef const node<value_type> *const_node_pointer;

			pointer      key;
			node_pointer parent;
			node_pointer left;
			node_pointer right;
			color		 color;
			bool         is_leaf;

			node(pointer _key, node *_parent = NULL, node *_left = NULL, node *_right = NULL, enum color _col = black, bool _is_leaf = false)
					: key(_key), parent(_parent), left(_left), right(_right), color(_col), is_leaf(_is_leaf) {}
		};

} // ft

#endif //FT_CONTAINER_TREESTRUCT_HPP
