// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 22/09/2022.
//

#ifndef FT_CONTAINER_VECTOR_ITERATOR_HPP
#define FT_CONTAINER_VECTOR_ITERATOR_HPP

#include <iostream>
#include <memory>

namespace ft {

	template<typename T, typename A = std::allocator<T> >
	class iterator {
	public:
		typedef typename A::difference_type difference_type;
		typedef typename A::reference reference;
		typedef typename A::pointer pointer;
		typedef typename A::size_type size_type;
		typedef std::random_access_iterator_tag iterator_category;

	private:
		T*	_ptr;

	public:
		iterator() : _ptr(NULL) {}
		iterator(iterator const &it) : _ptr(it._ptr) {}
		explicit iterator(pointer pt) : _ptr(pt) {}
		~iterator() {}

		iterator	&operator=(const iterator &it) {
			_ptr = it.ptr;
			return *this;
		}

		bool	operator==(const iterator &it) { return _ptr == it._ptr; }
		bool 	operator!=(const iterator &it) { return _ptr != it._ptr; }
		bool 	operator<=(const iterator &it) { return _ptr <= it._ptr; }
		bool 	operator>=(const iterator &it) { return _ptr >= it._ptr; }
		bool 	operator>(const iterator &it) { return _ptr > it._ptr; }
		bool 	operator<(const iterator &it) { return _ptr < it._ptr; }


		iterator		operator+(size_type rhs) const { return iterator(_ptr + rhs); }
		iterator		operator-(size_type rhs) const { return iterator(_ptr - rhs); }
		friend iterator	operator+(size_type lhs, const iterator& rhs) { return iterator(lhs + rhs); }
		difference_type	operator-(iterator it) const { return _ptr - it._ptr; }
		reference		operator*() const { return *_ptr; }
		reference		operator[](size_type rhs) const { return _ptr[rhs]; }
		pointer			operator->() const { return _ptr; }

		iterator	&operator--() {
			--_ptr;
			return *this;
		}

		iterator	&operator++() {
			++_ptr;
			return *this;
		}

		iterator	operator++(int) {
			iterator	tmp(*this);
			_ptr++;
			return tmp;
		}

		iterator	operator--(int) {
			iterator	tmp(*this);
			_ptr--;
			return tmp;
		}

		iterator	&operator+=(size_type rhs) {
			_ptr += rhs;
			return *this;
		}

		iterator	&operator-=(size_type rhs) {
			_ptr -= rhs;
			return *this;
		}

	};

	template<typename T, typename A = std::allocator<T> >
	class reverse_iterator {
	public:
		typedef typename A::difference_type difference_type;
		typedef typename A::value_type value_type;
		typedef typename A::reference reference;
		typedef typename A::pointer pointer;
		typedef typename A::size_type size_type;
		typedef std::random_access_iterator_tag iterator_category;

	private:
		T*	_ptr;

		void movePtr(T &val, size_type nb, bool sign) const	{
			int mov;

			if (sign == 1)
				mov = nb > 0 ? mov = -1: mov = 1;
			else
				mov = nb > 0 ? mov = 1: mov = -1;
			if (nb < 0)
				nb *= -1;
			for (; nb > 0; --nb)
				val += mov;
		}

	public:
		reverse_iterator() : _ptr(NULL) {}
		reverse_iterator(reverse_iterator const &it) : _ptr(it._ptr) {}
		reverse_iterator(pointer pt) : _ptr(pt) {}
		~reverse_iterator() {}

		reverse_iterator	&operator=(const reverse_iterator &it) {
			_ptr = it.ptr;
			return *this;
		}

		bool	operator==(const reverse_iterator &it) { return _ptr == it._ptr; }
		bool 	operator!=(const reverse_iterator &it) { return _ptr != it._ptr; }
		bool 	operator<=(const reverse_iterator &it) { return _ptr <= it._ptr; }
		bool 	operator>=(const reverse_iterator &it) { return _ptr >= it._ptr; }
		bool 	operator>(const reverse_iterator &it) { return _ptr > it._ptr; }
		bool 	operator<(const reverse_iterator &it) { return _ptr < it._ptr; }


		friend reverse_iterator	operator+(size_type lhs, const reverse_iterator& rhs) { reverse_iterator it(rhs); return it += lhs; }
		difference_type			operator-(reverse_iterator it) const { return it._ptr - _ptr; }
		reference				operator*() const { return *_ptr; }
		pointer					operator->() const { return _ptr; }

		reverse_iterator	operator+(size_type rhs) const
		{
			reverse_iterator it(*this);
			movePtr(it._ptr, rhs, 1);
			return it;
		}

		reference			operator[](size_type rhs) const {
			value_type *tmp(_ptr);
			movePtr(tmp, rhs, 1);
			return _ptr[rhs];
		}

		reverse_iterator	operator-(size_type rhs) const
		{
			reverse_iterator it(*this);
			movePtr(it._ptr, rhs, 0);
			return 0;
		}

		reverse_iterator	&operator--() {
			++_ptr;
			return *this;
		}

		reverse_iterator	&operator++() {
			--_ptr;
			return *this;
		}

		reverse_iterator	operator++(int) {
			reverse_iterator	tmp(*this);
			--_ptr;
			return tmp;
		}

		reverse_iterator	operator--(int) {
			reverse_iterator	tmp(*this);
			++_ptr;
			return tmp;
		}

		reverse_iterator	&operator+=(size_type rhs) {
			movePtr(_ptr, rhs, 1);
			return *this;
		}

		reverse_iterator	&operator-=(size_type rhs) {
			movePtr(_ptr, rhs, 0);
			return *this;
		}

	};


	template<typename T, typename A = std::allocator<T> >
	class const_reverse_iterator {

	};

} // ft




#endif //FT_CONTAINER_VECTOR_ITERATOR_HPP
