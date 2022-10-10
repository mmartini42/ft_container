// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 22/09/2022.
//

#ifndef FT_CONTAINER_MAP_HPP
#define FT_CONTAINER_MAP_HPP

#include <algorithm>
#include "Pair.hpp"
#include "TreeStruct.hpp"
#include "rbTree.hpp"
#include "iterator/Bidirectional_Const_iterator.hpp"
#include "iterator/Bidirectional_iterator.hpp"
#include "iterator/map_reverseConstIterator.hpp"
#include "iterator/map_reverseIterator.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class A = std::allocator< ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef Compare key_compare;
		typedef A allocator_type;
		typedef typename A::template rebind< ft::RBTree<Key, T> >::other new_alloc;
		typedef typename ft::BiTreeNode< ft::pair<const Key, T> > node;
		typedef typename A::value_type value_type;
		typedef typename A::reference reference;
		typedef typename A::const_reference const_reference;
		typedef typename A::pointer pointer;
		typedef typename A::difference_type difference_type;
		typedef typename A::size_type size_type;
		typedef map_reverseIterator<node> reverse_iterator;
		typedef map_reverseConstIterator<node> const_reverse_iterator;
		typedef bidirectional_iterator<node> iterator;
		typedef bidirectional_const_iterator<node> const_iterator;

		class value_compare	{
		protected:
			Compare _comp;
		public:
			value_compare(): _comp(new Compare()){}
			~value_compare(){}
			bool operator()( const value_type& lhs, const value_type& rhs ) const {	return _comp(lhs.first, rhs.first); }
		};

		explicit map (const key_compare& comp = key_compare(), const new_alloc& alloc = new_alloc()): _alloc(alloc), _comp(comp) {
			_tree = _alloc.allocate(1);
			_alloc.construct(_tree, RBTree<Key, T>());
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const new_alloc& alloc = new_alloc()): _alloc(alloc), _comp(comp)	{
			_tree =_alloc.allocate(1);
			_alloc.construct(_tree, RBTree<Key, T>());
			for ( ;first != last; first++)
				_tree->insert(first);
		}

		map (const map &x) {
			_alloc = x._alloc;
			_comp = x._comp;
			_tree =_alloc.allocate(1);
			_alloc.construct(_tree, RBTree<Key, T>());
			insert(x.begin(), x.end());
		}

		~map() { clear(); }

		map& operator= (const map& x) {
			if (&x == this)
				return (*this);
			clear();
			insert(x.begin(), x.end());
			return (*this);
		}

	private:
		new_alloc _alloc;
		key_compare _comp;
		ft::RBTree<Key, T> *_tree;

	public:
		iterator begin() { return iterator(_tree->find_min(_tree->getRoot())); }
		const_iterator begin() const { return const_iterator(_tree->find_min(_tree->getRoot())); }
		iterator end() { return iterator(_tree->getEmptyNode()); }
		const_iterator end() const { return const_iterator(_tree->getEmptyNode()); }

		reverse_iterator rbegin() {	return reverse_iterator(_tree->getEmptyNode());	}
		const_reverse_iterator rbegin() const {	return const_reverse_iterator(_tree->getEmptyNode()); }
		reverse_iterator rend()	{ return reverse_iterator(_tree->find_min(_tree->getRoot())); }
		const_reverse_iterator rend() const	{ return const_reverse_iterator(_tree->find_min(_tree->getRoot())); }

		bool empty() const { return (_tree->getSize() == 0) ? true : false; }
		size_type size() const { return _tree->getSize(); }
		size_type max_size() const { return  _alloc.max_size();	}

		mapped_type& operator[] (const key_type& k) const {
			node *tmp = _tree->find(k);
			if (tmp == NULL) {
				insert(ft::pair<Key, T>(k, _tree->getEmptyNode()->data.second));
				tmp = _tree->find(k);
			}
			return tmp->data.second;
		}

		ft::pair<iterator,bool> insert (const value_type &val) const {
			bool is_inserted = _tree->insert(&val);
			iterator it = iterator(_tree->find(val.first));
			return ft::pair<iterator, bool>(it, is_inserted);
		}

		iterator insert (iterator position, const value_type& val) const {
			if (find(val.first) == _tree->getEmptyNode())	{
				node *tmp = position.get_node();
				if ((_tree->getRoot()->data.first < tmp->data.first) && (_tree->getRoot()->data.first < val.first))	{
					while (tmp != _tree->getRoot() && tmp->data.first < tmp->parent->data.first)
						tmp = tmp->parent;
					return _tree->insert(tmp->data, &val);
				} else if ((_tree->getRoot()->data.first < tmp->data.first) && (_tree->getRoot()->data.first > val.first)) {
					while (tmp != _tree->getRoot() && tmp->data.first < tmp->parent->data.first)
						tmp = tmp->parent;
					return _tree->insert(tmp->data, &val);
				}
				return _tree->insert(_tree->getRoot()->data, &val);
			}
			return NULL;
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) const {
			for ( ;first != last; first++)
				_tree->insert(&*first);
		}

		void erase (iterator position) const {
			ft::pair<const Key, T> tmp = *position;
			while (_tree->erase(tmp.first)){}
		}

		size_type erase (const key_type& k) const {
			key_type tmp = k;
			size_t res = 0;
			while (_tree->erase(tmp))
				res++;
			return res;
		}

		void erase (iterator first, iterator last) const {
			for ( ;first != last; first++)
				_tree->erase(first->first);
		}

		void swap (map& x) const {
			map *tmp = this;
			_tree = x._tree;
			x._tree = tmp->_tree;
		}

		void clear() {
			if (_tree != NULL && _tree->getRoot() != NULL) {
				_tree->clear(_tree->getRoot());
				_alloc.destroy(_tree);
				_alloc.deallocate(_tree, 1);
				_tree = NULL;
			}
		}

		key_compare key_comp() const { key_compare kcomp; return kcomp;	}
		value_compare value_comp() const { value_compare vcomp; return vcomp; }

		iterator find (const key_type& k) {
			node *tmp = _tree->find(k);
			if (tmp == NULL)
				return end();
			return iterator(tmp);
		}

		const_iterator find (const key_type& k) const {
			node *tmp = _tree->find(k);
			if (tmp == NULL)
				return end();
			return const_iterator(tmp);
		}

		size_type count (const key_type& k) const {
			node *tmp = _tree->find(k);
			if (tmp == NULL)
				return 0;
			return 1;
		}

		iterator lower_bound (const key_type& k) {
			iterator tmp = find(k);
			if (tmp == _tree->getEmptyNode()) {
				tmp = end();
				tmp--;
				if (k > tmp->first)
					return end();
				tmp = begin();
				while (tmp->first < k)
					tmp++;
				return tmp;
			}
			return tmp;
		}

		const_iterator lower_bound (const key_type& k) const {
			const_iterator tmp = find(k);
			if (tmp == _tree->getEmptyNode()) {
				tmp = end();
				tmp--;
				if (k > tmp->first)
					return end();
				tmp = begin();
				while (tmp->first < k)
					tmp++;
				return tmp;
			}
			return tmp;
		}

		iterator upper_bound (const key_type& k) {
			iterator tmp = find(k);
			if (tmp == _tree->getEmptyNode()) {
				tmp = end();
				tmp--;
				if (k > tmp->first)
					return end();
				tmp = begin();
				while (tmp->first < k)
					tmp++;
				return tmp;
			}
			tmp++;
			return tmp;
		}

		const_iterator upper_bound (const key_type& k) const {
			const_iterator tmp = find(k);
			if (tmp == _tree->getEmptyNode()) {
				tmp = end();
				tmp--;
				if (k > tmp->first)
					return end();
				tmp = begin();
				while (tmp->first < k)
					return tmp;
			}
			return tmp;
		}

		ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			return ft::pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k));
		}

		ft::pair<iterator,iterator> equal_range (const key_type& k)	{
			return ft::pair<iterator,iterator>(lower_bound(k), upper_bound(k));
		}

		new_alloc get_allocator() const	{ return _alloc; }
		ft::RBTree<Key, T> *get_tree() { return _tree; }
	};

} // ft

#endif //FT_CONTAINER_MAP_HPP
