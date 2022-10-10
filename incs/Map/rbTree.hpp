#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <iostream>
#include <iterator>
#include <stdexcept> 
#include <memory>
#include <algorithm>
#include <functional>
#include "Pair.hpp"
#include "TreeStruct.hpp"

#define BLACK 0
#define RED 1

namespace ft
{

	template < class Key, class T, class A = std::allocator< ft::BiTreeNode< ft::pair<const Key, T> > > >
	class RBTree
	{
		public:
			typedef A allocator_type;
			typedef typename ft::BiTreeNode< ft::pair<const Key, T> > node;
			
		private:
			node *_root;
			node *_emptyNode;
			size_t _size;

			void _rotateLeft(node *x) {
				node *y = x->right;

				x->right = y->left;
				if (y->left != NULL)
					y->left->parent = x;

				y->parent = x->parent;

				if (x->parent == NULL)
					_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;

				y->left = x;
				x->parent = y;
			}

			void _rotateRight(node *x) {
				node *y = x->left;

				x->left = y->right;
				if (y->right != NULL)
					y->right->parent = x;

				y->parent = x->parent;

				if (x->parent == NULL)
					_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;

				y->right = x;
				x->parent = y;
			}

			void _insertRecursive(node *root, node *n)	{
				if (root != NULL) {
					if (n->data.first < root->data.first)	{
						if (root->left != NULL)	{
							_insertRecursive(root->left, n);
							return;
						} else
							root->left = n;
					} else {
						if (root->right != NULL) {
							_insertRecursive(root->right, n);
							return;
						} else
							root->right = n;
					}
				}

				n->parent = root;
				n->left = NULL;
				n->right = NULL;
				n->color = RED;
			}

			void _swapNodes(node *u, node *v) {
				if (u->parent == NULL)
					_root = v;
				else if (u == getParent(u)->left)
					getParent(u)->left = v;
				else
					getParent(u)->right = v;
				
				if (u->parent == NULL)
					v->parent = NULL;
				else if (v != NULL)
					v->parent = u->parent;
			}

			node *_findFromNode(Key key, node *n) {
				if (n == NULL)
					return NULL;
				else if (n->data.first == key) {
					if (n->color == -1)
						return NULL;
					return n;
				} else if (n->data.first >= key)
					return _findFromNode(key, n->left);
				else if (n->data.first <= key)
					return _findFromNode(key, n->right);
				return NULL;
			}

			node *_insertFromRoot(node *root, node *n) {
				_insertRecursive(root, n);
				_size++;
				_insertBalanced(n);
				root = n;
				while(getParent(root) != NULL)
					root = getParent(root);
				return root;
			}

			void _replaceNullNode() {
				node *tmp = _root;
				if (_emptyNode == NULL) {
					_emptyNode = _alloc.allocate(1);
					_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
					_emptyNode->color = -1;
				} if (_root == NULL) {
					_root = _emptyNode;
					return;
				} while (tmp->right != NULL)
					tmp = tmp->right;
				tmp->right = _emptyNode;
				_emptyNode->parent = tmp;
			}

			void _detachNullNode() {
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

			void _insertBalanced(node *n) {
				node *p;
				node *g;

				if(getParent(n) == NULL || getParent(n) == _emptyNode) {
					if (getParent(n) == _emptyNode)
						_root = n;
					n->color = BLACK;
				} else if (getParent(n)->color == BLACK)
					return;
				else if (getUncle(n) != NULL && getUncle(n)->color == RED) {
					getParent(n)->color = BLACK;
					getUncle(n)->color = BLACK;
					g = getGrandParent(n);
					g->color = RED;
					_insertBalanced(g);
				} else {
					p = getParent(n);
					g = getGrandParent(n);
					if(g->left != NULL && g->left->right != NULL && n == g->left->right) {
						_rotateLeft(p);
						n = n->left;
					} else if (g->right != NULL && g->right->left != NULL && n == g->right->left) {
						_rotateRight(p);
						n = n->right;
					}
					p = getParent(n);
					g = getGrandParent(n);
					if (n == p->left)
						_rotateRight(g);
					else
						_rotateLeft(g);
					p->color = BLACK;
					g->color = RED;
				}
			}

			void _eraseBalanced(node *n) {
				node *tmp = n;
				node *w = n;
				node *p = getParent(tmp);
				while (tmp != _root && tmp->color == BLACK && w != NULL) {
					if (tmp == p->left) {
						w = p->right;
						if (w != NULL && w->color == RED) {
							w->color = BLACK;
							p->color = RED;
							_rotateLeft(p);
							w = p->right;
						} if (w != NULL) {
							if ((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK)) {
								w->color = RED;
								tmp = p;
							} else {
								if (w->right->color == BLACK) {
									w->left->color = BLACK;
									w->color = RED;
									_rotateRight(w);
									w = p->right;
								}
								w->color = p->color;
								p->color = BLACK;
								w->right->color = BLACK;
								_rotateLeft(p);
								tmp = _root;
							}
						}
					} else {
						w = p->left;
						if (w != NULL && w->color == RED) {
							w->color = BLACK;
							p->color = RED;
							_rotateRight(p);
							w = p->left;
						} if (w != NULL) {
							if ((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK)) {
								w->color = RED;
								tmp = p;
							} else {
								if (w->left != NULL && w->left->color == BLACK) {
									if (w->right != NULL)
										w->right->color = BLACK;
									w->color = RED;
									_rotateLeft(w);
									w = p->left;
								}
								w->color = p->color;
								p->color = BLACK;
								if (w->left != NULL)
									w->left->color = BLACK;
								_rotateRight(p);
								tmp = _root;
							}
						}
					}
				} if (tmp->color != -1)
					tmp->color = BLACK;
			}

		private:
			allocator_type _alloc;
		
		public:
			RBTree(const allocator_type& alloc = allocator_type()): _root(NULL), _size(0), _alloc(alloc) {
				_emptyNode = _alloc.allocate(1);
				_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
				_emptyNode->color = -1;
			}

			RBTree(node *n, const allocator_type& alloc = allocator_type()): _root(n), _size(0), _alloc(alloc) {
				_emptyNode = _alloc.allocate(1);
				_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
				_emptyNode->color = -1;
			}

			RBTree(RBTree const &instance): _root(instance._root), _size(0), _alloc(instance._alloc) {
				_emptyNode = _alloc.allocate(1);
				_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
				_emptyNode->color = -1;
			}

			RBTree &operator=(RBTree const &rhs) {
				if (&rhs == this)
					return (*this);
				clear();
				insert(rhs.begin(), rhs.end());
				return (*this);
			}

			~RBTree(void) {
				if (getSize() > 0 && _root != NULL) {
					clear(_root); 
					_root = NULL;
				}
			}

			node *getRoot() { return _root; }
			node *getEmptyNode() { return _emptyNode; }
			size_t getSize() { return _size; }
			node *getParent(node *n){ return n->parent; }
			node *getGrandParent(node *n) {
				node *p = getParent(n);
				if (p == NULL)
					return NULL;
				return getParent(p);
			}

			node *getSibling(node *n) {
				node *p = getParent(n);
				if (p == NULL)
					return NULL;
				else if (p->left == n)
					return p->right;
				else
					return p->left;
			}

			node *getUncle(node *n) {
				node *p = getParent(n);
				node *g = getGrandParent(n);

				if (g == NULL)
					return NULL;
				return getSibling(p);
			}

			bool insert(ft::pair<const Key, T> *p) {
				_detachNullNode();
				node *tmp = NULL;
				if (find(p->first) == NULL)
					tmp = _insertFromRoot(_root, createNode(p));
				else {
					_replaceNullNode();
					return false;
				} if (tmp == NULL) {
					_replaceNullNode();
					return false;
				}
				_root = tmp;
				_replaceNullNode();
				return true;
			}

			bool insert(const ft::pair<const Key, T> *p) {
				_detachNullNode();
				node *tmp = NULL;
				if (find(p->first) == NULL)
					tmp = _insertFromRoot(_root, createNode(p));
				else {
					_replaceNullNode();
					return false;
				} if (tmp == NULL) {
					_replaceNullNode();
					return false;
				}
				_root = tmp;
				_replaceNullNode();
				return true;
			}

			node *insert(ft::pair<const Key, T> position, const ft::pair<const Key, T> *p) {
				_detachNullNode();
				node *tmp = _insertFromRoot(find(position.first), createNode(p));
				_replaceNullNode();
				return tmp;
			}

			bool erase(Key key)	{
				node *z;
				z = find(key);
				node *y = z;
				node *x;
				
				if (z == _emptyNode || z == NULL)
					return false;
				int y_original_color = y->color;
				if (z->left == NULL) {
					x = z->right;
					_swapNodes(z, z->right);
				} else if (z->right == NULL || z->right == _emptyNode) {
					x = z->left;
					_swapNodes(z, z->left);
				} else {
					y = find_min(z->right);
					y_original_color = y->color;
					x = y->right;
					if (x != NULL && y->parent == z)
						x->parent = y;
					else if (z->right != NULL) {
						_swapNodes(y, y->right);
						y->right = z->right;
						if (z->right != NULL)
							z->right->parent = y;
					}
					_swapNodes(z, y);
					y->left = z->left;
					if (y->left != NULL)
						y->left->parent = y;
					y->color = z->color;
				}
				delete z;
				z = NULL;
				_size--;
				_emptyNode->color = -1;
				if (y->color == -1 && y->parent != _root) {
					y->parent->right = y->left;
					y->left->parent = y->parent;
					y->left = NULL;
					y->right = NULL;
				} if (y_original_color == BLACK && x != NULL)
					_eraseBalanced(x);
				_detachNullNode();
				_replaceNullNode();
				return true;
			}

			void clear(node *n) {
				if (n != NULL && (n->color == 0 || n->color == 1)) {
					if (n->left != NULL)
						clear(n->left);
					if (n->right != NULL)
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
				}
				_alloc.destroy(_emptyNode);
				_alloc.deallocate(_emptyNode, 1);
				_emptyNode = NULL;
			}

			node *find(Key key) { node *tmp = _findFromNode(key, _root); return tmp; }
			node *find_min(node *n) {
				assert(n != NULL);
				node *tmp = n;
				while (tmp->left != NULL)
					tmp = tmp->left;
				return tmp;
			}

			node *find_max(node *n) {
				assert(n != NULL);
				node 	*tmp = n;
				while (tmp->right != NULL && tmp->right->color != -1)
					tmp = tmp->right;
				return tmp;
			}

		node *createNode(const ft::pair<const Key, T> *p) {
			node *n = _alloc.allocate(1);
			_alloc.construct(n, node(NULL, *p));
			return n;
		}
	};

	template < class Key, class T >
	void print_tree(ft::BiTreeNode< ft::pair<const Key, T> > *n) {
		if (n != NULL) {
			if (n->left != NULL)
				print_tree(n->left);
			if (n != NULL && n->color != -1)
				std::cout << "Data:[" << n->data.first << "," << n->data.second << "] | color:" << ((n->color == 0) ? "BLACK" : "RED") << std::endl;
			if (n->right != NULL)
				print_tree(n->right);
		}
	}
}

#endif