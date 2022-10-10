// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

#ifndef BIDIRECTIONAL_CONST_ITERATOR_HPP
# define BIDIRECTIONAL_CONST_ITERATOR_HPP

# include <memory>

namespace ft
{
	template <class Node>
	class bidirectional_const_iterator { 
		public:
			typedef typename Node::reference reference;
			typedef typename Node::pointer pointer;
			typedef std::bidirectional_iterator_tag iterator_category;

			bidirectional_const_iterator() : _node(nullptr) {}
			bidirectional_const_iterator(const bidirectional_const_iterator &it) : _node(it._node) {}
			bidirectional_const_iterator(Node *n): _node(n) {}
			~bidirectional_const_iterator(){}

			Node *get_node() {return _node;}

			bidirectional_const_iterator& operator=(const bidirectional_const_iterator &it)
			{
				_node = it._node;
				return *this;
			}

			bool operator==(const bidirectional_const_iterator &it) const
			{
				if(_node != NULL && it._node != NULL)
				{				
					if (it._node->color == -1 || _node->color == -1)
						return (_node->data.first == it._node->data.first) && (_node->data.second == it._node->data.second) && (_node->color == it._node->color);
					return (_node->data.first == it._node->data.first) && (_node->data.second == it._node->data.second);
				}
				return false;
			}

			bool operator!=(const bidirectional_const_iterator &it) const
			{
				if(_node != NULL && it._node != NULL)
				{
					if (it._node->color == -1 || _node->color == -1)
						return (_node->data.first != it._node->data.first) || (_node->data.second != it._node->data.second) || (_node->color != it._node->color);
					return (_node->data.first != it._node->data.first) || (_node->data.second != it._node->data.second);
				}
				return false;
			}

			bidirectional_const_iterator& operator++()
			{
				Node *tmp = _node;
			
				if (tmp->color == -1)
					return *this;
				if (tmp->right == NULL)
				{
					if (tmp == tmp->parent->right)
					{
						while (tmp->parent != NULL && tmp == tmp->parent->right)
							tmp = tmp->parent;
						if (tmp->parent == NULL)
						{
							_node = _node->right;
							return *this;
						}
						tmp = tmp->parent;
					}
					else
						tmp = tmp->parent;
				}
				else if (tmp->right != NULL)
				{
					tmp = tmp->right;
					while (tmp->left != NULL && tmp->color != -1)
						tmp = tmp->left;
				}
				if (tmp != NULL)
					_node = tmp;
				return *this;
			}

			bidirectional_const_iterator operator++(int)
			{
				Node *tmp = _node;
			
				if (tmp->color == -1)
					return *this;
				if (tmp->right == NULL)
				{
					if (tmp == tmp->parent->right)
					{
						while (tmp->parent != NULL && tmp == tmp->parent->right)
							tmp = tmp->parent;
						if (tmp->parent == NULL)
						{
							_node = _node->right;
							return *this;
						}
						tmp = tmp->parent;
					}
					else
						tmp = tmp->parent;
				}
				else if (tmp->right != NULL)
				{
					tmp = tmp->right;
					while (tmp->left != NULL && tmp->color != -1)
						tmp = tmp->left;
				}
				if (tmp != NULL)
					_node = tmp;
				return *this;
			}

			bidirectional_const_iterator& operator--()
			{
				Node *tmp = _node;
				if(tmp->color == -1 && tmp->parent == NULL)
					return *this;
				if (tmp->left == NULL && tmp->parent != NULL)
				{
					if (tmp == tmp->parent->left)
					{
						while (tmp == tmp->parent->left)
							tmp = tmp->parent;
						if (tmp->parent == NULL)
						{
							_node = _node->left;
							return *this;
						}
						tmp = tmp->parent;
					}
					else
						tmp = tmp->parent;
				}
				else if (tmp->left != NULL)
				{
					tmp = tmp->left;
					while (tmp->right != NULL)
						tmp = tmp->right;
				}
				if (tmp != NULL)
					_node = tmp;
				return *this;
			}

			bidirectional_const_iterator operator--(int)
			{
				Node *tmp = _node;
				if (tmp->left == NULL && tmp->parent != NULL)
				{
					if (tmp == tmp->parent->left)
					{
						while (tmp == tmp->parent->left)
							tmp = tmp->parent;
						if (tmp->parent == NULL)
						{
							_node = _node->left;
							return *this;
						}
						tmp = tmp->parent;
					}
					else
						tmp = tmp->parent;
				}
				else if (tmp->left != NULL)
				{
					tmp = tmp->left;
					while (tmp->right != NULL)
						tmp = tmp->right;
				}
				if (tmp != NULL)
					_node = tmp;
				return *this;
			}

			reference operator*() const
			{
				return _node->data;
			}

			pointer operator->() const
			{
				return &_node->data;
			}

		private:
			Node *_node;
	};
}

#endif