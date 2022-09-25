// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 22/09/2022.
//

#ifndef FT_CONTAINER_STACK_HPP
#define FT_CONTAINER_STACK_HPP

#include "vector.hpp"

namespace ft {

	template<class T, class Container = ft::vector<T> >
	class stack {

	public:
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;

	protected:
		container_type c;

	public:
		explicit stack<T, Container>(const Container &container = Container()) : c(container) {}

		stack<T, Container>(const stack<T> &src) { *this = src; }

		~stack<T, Container>(void) {}

		stack &operator=(const stack<T> &ref) {
			if (this->c != &ref)
				this->c = ref.c;
			return *this;
		}

		friend bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.c == rhs.c; }
		friend bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.c != rhs.c; }
		friend bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.c <= rhs.c; }
		friend bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.c >= rhs.c; }
		friend bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.c > rhs.c; }
		friend bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.c < rhs.c; }

		reference top(void) { return c.back(); }

		const_reference top(void) const { return c.back(); }

		bool empty(void) const { return c.empty(); }

		size_type size(void) const { return c.size(); }

		void push(const value_type &value) { c.push_back(value); }

		void pop(void) { c.pop(); }
	};
} //ft
#endif //FT_CONTAINER_STACK_HPP
