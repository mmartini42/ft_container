// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by Mathis Martini on 10/2/22.
//

#ifndef FT_CONTAINER_RBTREE_HPP
#define FT_CONTAINER_RBTREE_HPP

#include <memory>
#include "Pair.hpp"
#include "TreeStruct.hpp"

namespace ft {

    template<class Key, class T, class A = std::allocator<ft::TreeStruct<pair<const Key, T> > > >
    class RBTree {

    public:
        typedef std::allocator<ft::TreeStruct<pair<const Key, T> > >  allocator_type;
		typedef A		A_type;
        typedef typename ft::TreeStruct<ft::pair<const Key, T> > node;

    private:
        node*			_root;
		node*			_emptyNode;
		uint32_t		_size;
        allocator_type	_alloc;

	public:
		explicit RBTree(const allocator_type& alloc = allocator_type()) : _root(NULL), _size(0), _alloc(alloc) {
			_emptyNode = _alloc.allocate(1);
			_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
			_emptyNode->color = -1;
		}

		explicit RBTree(node* node, const allocator_type& alloc = allocator_type()) : _root(node), _size(0), _alloc(alloc) {
			_emptyNode = _alloc.allocate(1);
			_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
			_emptyNode->color = -1;
		}

		RBTree(const RBTree& ref) : _root(ref._root), _size(ref._size), _alloc(ref._alloc) {
			_emptyNode = _alloc.allocate(1);
			_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
			_emptyNode->color = -1;
		}

		~RBTree() {
			if (getSize() > 0 && _root != NULL) {
				clear(_root);
				_root = NULL;
			}
		}

		RBTree&	operator=(const RBTree<const Key, T>& ref) {
			if (&ref == this)
				return *this;
			clear();
			insert(ref.begin(), ref.end());
			return *this;
		}

		uint32_t		getSize() const { return _size; }
		node*			getRoot() const { return _root; }
		node*			getEmptyNode() const { return _emptyNode; }
		allocator_type	getAlloc() const { return _alloc; }

		node*	getParent(node* x) { return x->parent; }
		node*	getGrandParent(node* x) {
			node	*y = getParent(x);
			if (y == NULL) { return NULL; }
			return getParent(y);
		}
		node*	getSibling(node* x) {
			node*	y = parent(x);

			if (y == NULL) { return NULL; }
			else if (y->left == x) { return y->right; }
			else { return y->left; }
		}
		node*	getUncle(node* x) {
			node*	y = getParent(x);
			node*	tmp = getGrandParent(x);

			if (tmp == NULL) { return NULL; }
			return getSibling(y);
		}

	private:
		void	_rotateLeft(node* x) {
			node*	y = x->right;

			x->right = y->left;
			if (y->left)
				y->left->parent = x;
			y->parent = x->parent;
			if (!x->parent)
				_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}
		void	_rotateRight(node* x) {
			node*	y = x->left;

			x->left = y->right;
			if (y->right)
				y->right->parent = x;
			y->parent = x->parent;
			if (!x->parent)
				_root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->left = y;
		}

		void	_insertRecursive(node* root, node* x) {
			if (root) {
				if (x->data._first < root->data._first) {
					if (root->left) { _insertRecursive(root->left, x); return; }
					else
						root->left = x;
				} else {
					if (root->right) { _insertRecursive(root->right, x); return; }
					else
						root->right = x;
				}
			}
			x->parent	= root;
			x->left 	= NULL;
			x->left 	= NULL;
			x->color	= red;
		}

		void	_swapNode(node* t, node* g) {
			if (t->parent == NULL)
				_root = g;
			else if (t == getParent(t)->left) { getParent(t)->left = g; }
			else { getParent(t)->right = g; }
			if (t->parent == NULL) { g->parent = NULL; }
			else if (g != NULL) { g->parent = t->parent; }
		}

	public:
		void	clear(node* n) {
			if (n != NULL && (n->color == black || n->color == red)) {
				if (n->left)
					clear(n->left);
				if (n->right)
					clear(n->right);
				if (n == _root) {
					_alloc.destroy(_root);
					_alloc.deallocate(_root, 1);
					_root = NULL;
				} else {
					_alloc.destroy(n);
					_alloc.deallocate(n, 1);
					n = NULL;
				}
				_alloc.destroy(_emptyNode);
				_alloc.deallocate(_emptyNode, 1);
				_emptyNode = NULL;
			}
		}

	};

} // ft



#endif //FT_CONTAINER_RBTREE_HPP