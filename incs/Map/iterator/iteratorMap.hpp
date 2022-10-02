// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 01/10/2022.
//

#ifndef FT_CONTAINER_ITERATORMAP_HPP
#define FT_CONTAINER_ITERATORMAP_HPP

#include "../Pair.hpp"
#include "../TreeStruct.hpp"
#include "../../Vector/iterator/iterator.hpp"
#include <memory>

namespace ft {

	template<class T, class G>
	class mapIterator {

	public:
		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef T                              node_ptr;
		typedef std::ptrdiff_t                 difference_type;
		typedef G             	               value_type;
		typedef value_type&                    reference;
		typedef const value_type&              const_reference;
		typedef value_type*                    pointer;

	private:
		node_ptr	_ptr;

	public:

		explicit mapIterator(const node_ptr& ptr = NULL) : _ptr(ptr) {}
		mapIterator(const mapIterator<T,G>& ref) : _ptr(ref._ptr) {}
		~mapIterator() {}

		node_ptr	getNode() const { return _ptr; }

		mapIterator&	operator++(){
			_ptr = nextIter(_ptr);
			return	*this;
		}

		mapIterator&	operator--(){
			_ptr = prevIter(_ptr);
			return *this;
		}

		mapIterator		operator++(int) {
			mapIterator	tmp(*this);
			++(*this);
			return tmp;
		}

		mapIterator		operator--(int) {
			mapIterator		tmp(*this);
			--(*this);
			return tmp;
		}

		pointer		operator->() const 	{ return _ptr->key; }
		reference	operator*() const	{ return *_ptr->key; }

	private:

		bool		isLeftChild(node_ptr node) { return node == node->parent->left; }

		node_ptr	nextIter(node_ptr node) {
			if (!node->right->is_leaf)
				return (minPos(node->right));
			while (!isLeftChild(node))
				node = node->parent;
			return node->parent;
		}

		node_ptr	prevIter(node_ptr node) {
			if (!node->left->is_leaf)
				return (maxPos(node->left));
			//auto in CXX11
			node_ptr	new_node = static_cast<node_ptr>(node);

			while (isLeftChild(new_node))
				new_node = new_node->parent;
			return new_node->parent;
		}

	};

	template<class T, class G>
	bool 	operator==(const mapIterator<T,G>& first, const mapIterator<T,G>& second) { return first.getNode() == second.getNode(); }

	template<class T, class G>
	bool 	operator!=(const mapIterator<T,G>& first, const mapIterator<T,G>& second) { return first != second; }

	template <class T>
	node<T> *maxPos(node<T> *x) {
		while (!x->right->is_leaf)
			x = x->right;
		return (x);
	}

	template <class T>
	node<T> *minPos(node<T> *x) {
		while (!x->left->is_leaf)
			x = x->left;
		return (x);
	}

	template<class T, class G>
	class const_MapIterator {
	public:
		typedef ft::bidirectional_iterator_tag  iterator_category;
		typedef T                               const_node_ptr;
		typedef std::ptrdiff_t                  difference_type;
		typedef G        	                  	value_type;
		typedef const value_type&          	    reference;
		typedef const value_type*          	    pointer;

		typedef ft::mapIterator<typename ft::node<value_type>::node_pointer, value_type>
				mapIt;

	private:
		 const_node_ptr _ptr;

	public:
		explicit const_MapIterator(const_node_ptr ptr = NULL) : _ptr(ptr) {}
		const_MapIterator(const const_MapIterator<T,G>& ref) : _ptr(ref._ptr) {}
		const_MapIterator(const mapIt& ref) : _ptr(ref.getNode()) {}
		~const_MapIterator() {}

		const_MapIterator	getNode() const { return _ptr; }

		const_MapIterator&	operator++() {
			_ptr = nextIter(_ptr);
			return *this;
		}

		const_MapIterator&	operator--() {
			_ptr = prevIter(_ptr);
			return *this;
		}

		const_MapIterator	operator++(int) {
			const_MapIterator	*tmp(*this);
			++*(this);
			return tmp;
		}

		const_MapIterator	operator--(int) {
			const_MapIterator	*tmp(*this);
			--*(this);
			return tmp;
		}

	private:

		bool		isLeftChild(const_node_ptr node) { return node == node->parent->left; }

		const_node_ptr	nextIter(const_node_ptr node) {
			if (!node->right->is_leaf)
				return (minPos(node->right));
			while (!isLeftChild(node))
				node = node->parent;
			return node->parent;
		}

		const_node_ptr	prevIter(const_node_ptr node) {
			if (!node->left->is_leaf)
				return (maxPos(node->left));
			//auto in CXX11
			const_node_ptr	new_node = static_cast<const_node_ptr>(node);

			while (isLeftChild(new_node))
				new_node = new_node->parent;
			return new_node->parent;
		}

	};

	template <class T, class G>
	bool operator==(const const_MapIterator<T, G>& x, const const_MapIterator<T, G>& y) {
		return (x.getNode() == y.getNode());
	}

	template <class T, class G>
	bool operator!=(const const_MapIterator<T, G>& x, const const_MapIterator<T, G>& y) {
		return !(x.getNode() == y.getNode());
	}

	template <class node_ptr, class const_node_ptr, class G>
	bool operator==(const mapIterator<node_ptr, G>& x, const const_MapIterator<const_node_ptr, G>& y) {
		return (x.getNode() == y.getNode());
	}

	template <class node_ptr, class const_node_ptr, class G>
	bool operator!=(const mapIterator<node_ptr, G>& x, const const_MapIterator<const_node_ptr, G>& y) {
		return (x.getNode() != y.getNode());
	}

	template <class node_ptr, class const_node_ptr, class G>
	bool operator==(const const_MapIterator<const_node_ptr, G>& x, const mapIterator<node_ptr, G>& y) {
		return (x.getNode() == y.getNode());
	}

	template <class node_ptr, class const_node_ptr, class G>
	bool operator!=(const const_MapIterator<const_node_ptr, G>& x, const mapIterator<node_ptr, G>& y) {
		return (x.getNode() != y.getNode());
	}
} // ft

#endif //FT_CONTAINER_ITERATORMAP_HPP
