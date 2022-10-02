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

		node*	_findFromNode(Key key, node* x) {
			if (x == NULL)
				return NULL;
			else if (x->data._first == key) {
				if (x->color == -1) { return NULL; }
				return x;
			}
			else if (x->data._first >= key) { return _findFromNode(key, x->left); }
			else if (x->data._first <= key) { return _findFromNode(key, x->right); }
			return NULL;
		}

		void	_insertBalanced(node* x) {
			node	*p,*g;

			if (getParent(x) == NULL || getParent(x) == _emptyNode) {
				if (getParent(x) == _emptyNode)
					_root = x;
				x->color = black;
			} else if (getParent(x)->color == black)
				return;
			else if (getUncle(x) != NULL && getUncle(x)->color == red) {
				getParent(x)->color = black;
				getUncle(x)->color = black;
				g = getGrandParent(x);
				g->color = red;
				_insertBalanced(g);
			} else {
				p = getParent(x);
				g = getGrandParent(x);
				if (g->left != NULL && g->left->right != NULL && x == g->left->right) {
					_rotateLeft(p);
					x = x->left;
				} else if (g->right != NULL && g->right->left != NULL && x == g->right->left) {
					_rotateRight(p);
					x = x->right;
				}
				p = getParent(x);
				g = getGrandParent(x);
				if (x == p->left) { _rotateRight(x); }
				else { _rotateLeft(x); }
				p->color = black;
				g->color = red;
			}
		}

		void 	_eraseBalanced(node* x) {
			node*	tmp = x;
			node*	y	= x;
			node*	p	= getParent(tmp);

			while (tmp != _root && tmp->color == black && y != NULL) {
				if (tmp == p->left) {
					y = p->right;

					if (y != NULL && y->color == red) {
						y->color = black;
						p->color = red;
						_rotateLeft(p);
						y = p->right;
					} if (y != NULL) {
						if ((y->left || y->left->color == black) && (y->right || y->right->color == black)) {
							y->color = red;
							tmp = p;
						} else {
							if (y->right->color == black) {
								y->left->color = black;
								y->color = red;
								_rotateRight(y);
								y = p->right;
							}
						}
					}
				} else {
					y = p->left;

					if (y !=  NULL && y->color == red) {
						y->color = black;
						p->color = red;
						_rotateRight(p);
						y = p->left;
					} if (y != NULL) {
						if ((y->left || y->left->color == black) && (y->right || y->right->color == black)) {
							y->color = red;
							tmp = p;
						} else {
							if (y->left != NULL && y->left->color == black) {
								if (y->right != NULL) { y->right->color = black; }
								y->color = red;
								_rotateLeft(y);
								y = p->left;
							}
							y->color = p->color;
							p->color = black;
							if (y->left != NULL)
								y->left->color = black;
							_rotateRight(p);
							tmp = _root;
						}
					}
				}
				if (tmp->color != -1) { tmp->color = black; }
			}
		}

		node*	_insertFromRoot(node* root, node* x) {
			_insertRecursive(root, x);
			++_size;
			_insertBalanced(x);
			root = x;
			while (getParent(root) != NULL)
				root = getParent(root);
			return root;
		}

		void	_replaceNullNode() {
			node *tmp = _root;

			if (_emptyNode == NULL)	{
				_emptyNode = _alloc.allocate(1);
				_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
				_emptyNode->color = -1;
			} if (_root == NULL) {
				_root = _emptyNode;
				return;
			}
			while (tmp->right != NULL)
				tmp = tmp->right;
			tmp->right = _emptyNode;
			_emptyNode->parent = tmp;
		}

		void 	_detachNullNode() {
			if (_emptyNode == NULL) {
				_emptyNode = _alloc.allocate(1);
				_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
				_emptyNode->color = -1;
			} if (_emptyNode->parent != NULL && _emptyNode->parent->right == _emptyNode) {
				_emptyNode->parent->right = NULL;
				_emptyNode->parent = NULL;
			} if (_emptyNode == _root)
				_root = NULL;
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

		/** TODO: insert ...
		 * Insert pair "p" in root.
		 *
		 * @param p - pair pointer
		 * @return true if pair inserted
		 */
		bool	insert(ft::pair<const Key, T> *p) {

		}

		bool insert(const ft::pair<const Key, T> *p) {

		}

		/** TODO: insert ...
		 * Insert pair "p" at position in tree.
		 * Start insertion from "position".
		 *
		 * @param position - pair
		 * @param p - pair pointer
		 * @return node inserted
		 */
		node *insert(ft::pair<const Key, T> position, const ft::pair<const Key, T> *p) {

		}

		/** TODO
		 * Delete node with "key".
		 * After node are deleted, balance tree.
		 *
		 * @param key - key of node
		 * @return true if key erased
		 */
		bool	erase(Key key) {

		}
	};

} // ft

/* **************************************************************************** */
/*									Memo										*/
/* **************************************************************************** */

/**
		 * Find the best place of the node "n" and insert it in tree.
		 *
		 * @param root - actual pointer of tree's node
		 * @param n - node to add
		 * @return void
		 * void	_insertRecursive(node* root, node* x)
		 */

/**
		 * Swap two nodes in tree.
		 *
		 * @param u - first node
		 * @param v - second node
		 * @return void
		 * void		_swapNode(node* t, node* g)
		 */

/**
		 * Find the node with "key" number from "n".
		 *
		 * @param key - Key to search for
		 * @param n - starting node
		 * @return found node
		 * node*	_findFromNode(Key key, node* x)
		 */

/**
		 * Balance tree after insert node.
		 *
		 * @param n - starting node
		 * @return void
		 * void		_insertBalanced(node* x)
		 */

/**
		 * Insert in "root" the node "n" and balance the tree.
		 *
		 * @param root - root in whitch we want to insert the node
		 * @param n - node to insert
		 * @return new root
		 * node*	_insertFromRoot(node* root, node* x)
		 */

/**
		 * Replace end node to the end of the tree
		 *
		 * @return void
		 * void	_replaceNullNode()
		 */

/**
		 * Detach end node
		 *
		 * @return void
		 * void 	_detachNullNode()
		 */

#endif //FT_CONTAINER_RBTREE_HPP
