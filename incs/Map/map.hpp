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
		typedef Key 		key_type;
		typedef T 			mapped_type;
		typedef Compare 	key_compare;
		typedef Allocator 	allocator_type;
		typedef typename Allocator::template rebind< ft::RBTree<Key, T> >::other	 new_alloc;
		typedef typename ft::TreeStruct< ft::pair<const Key, T> > 					node;
		typedef typename Allocator::value_type 			value_type;
		typedef typename Allocator::reference 			reference;
		typedef typename Allocator::const_reference 	const_reference;
		typedef typename Allocator::pointer 			pointer;
		typedef typename Allocator::difference_type 	difference_type;
		typedef typename Allocator::size_type 			size_type;
		typedef mapIterator<node, value_type> 		iterator;
		typedef const_MapIterator<node, value_type>	const_iterator;
		typedef reverse_iterator<iterator> 			reverseIterator;
		typedef reverse_iterator<const_iterator> 	const_reverse_iterator;

	private:
		new_alloc	_alloc;
		key_compare _comp;
		ft::RBTree<Key, T>*	_tree;

	public:

		ft::RBTree<Key, T>*	get_tree()				 { return _tree; }
		new_alloc			get_allocator() const	 { return _alloc; }

		class value_compare	{
		protected:
			Compare _comp;
		public:
			value_compare(): _comp(new Compare()){}
			~value_compare(){}

			bool operator()( const value_type& lhs, const value_type& rhs ) const { return _comp(lhs.first, rhs.first);}
		};

	};

} // ft

#endif //FT_CONTAINER_MAP_HPP
