// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 25/09/2022.
//

#ifndef FT_CONTAINER_VECTOR_CONST_ITERATOR_HPP
#define FT_CONTAINER_VECTOR_CONST_ITERATOR_HPP

#include <memory>

namespace ft {

	template <class T, class A = std::allocator<T> >
	class const_iterator {
	public:
		typedef typename A::difference_type difference_type;
		typedef typename A::value_type value_type;
		typedef typename A::reference reference;
		typedef typename A::pointer pointer;
		typedef typename A::size_type size_type;
		typedef std::random_access_iterator_tag iterator_category;

	private:
		T *_ptr;

	public:
		const_iterator() : _ptr(nullptr) {}

		const_iterator(const const_iterator &it) : _ptr(it._ptr) {}

		const_iterator(pointer pt) : _ptr(pt) {}

		~const_iterator() {}


		const_iterator &operator=(const const_iterator &it) {
			_ptr = it._ptr;
			return *this;
		}

		bool operator==(const const_iterator &it) const { return _ptr == it._ptr; }

		bool operator!=(const const_iterator &it) const { return _ptr != it._ptr; }

		bool operator>=(const const_iterator &it) const { return _ptr >= it._ptr; }

		bool operator<=(const const_iterator &it) const { return _ptr <= it._ptr; }

		bool operator>(const const_iterator &it) const { return _ptr > it._ptr; }

		bool operator<(const const_iterator &it) const { return _ptr < it._ptr; }


		const_iterator operator+(size_type rhs) const { return const_iterator(_ptr + rhs); }

		const_iterator operator-(size_type rhs) const { return const_iterator(_ptr - rhs); }

		friend const_iterator operator+(size_type lhs, const const_iterator &rhs) { return const_iterator(lhs + rhs); }

		difference_type operator-(const_iterator it) const { return _ptr - it._ptr; }

		reference operator*() const { return *_ptr; }

		reference operator[](size_type rhs) const { return _ptr[rhs]; }

		pointer operator->() const { return _ptr; }

		const_iterator &operator--() {
			--_ptr;
			return *this;
		}

		const_iterator &operator++() {
			++_ptr;
			return *this;
		}

		const_iterator operator++(int) {
			const_iterator tmp(*this);
			_ptr++;
			return tmp;
		}

		const_iterator operator--(int) {
			const_iterator tmp(*this);
			_ptr--;
			return tmp;
		}

		const_iterator &operator+=(size_type rhs) {
			_ptr += rhs;
			return *this;
		}

		const_iterator &operator-=(size_type rhs) {
			_ptr -= rhs;
			return *this;

		};

	};
	template<typename T, typename A = std::allocator<T> >
	class const_reverse_iterator {
		typedef typename A::difference_type difference_type;
		typedef typename A::value_type value_type;
		typedef typename A::reference reference;
		typedef typename A::pointer pointer;
		typedef typename A::size_type size_type;
		typedef std::random_access_iterator_tag iterator_category;

		const_reverse_iterator(void) : _ptr(nullptr) {}
		const_reverse_iterator(const_reverse_iterator const &instance) : _ptr(instance._ptr) {}
		const_reverse_iterator(pointer pt) : _ptr(pt) {}
		~const_reverse_iterator(void){}

		const_reverse_iterator& operator=(const const_reverse_iterator &it)	{
			_ptr = it._ptr;
			return *this;
		}

	private:
		T *_ptr;

		void movePtr(T &val, size_type nb, bool sign) const
		{
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

		bool operator==(const const_reverse_iterator &it) const	{ return _ptr == it._ptr; }
		bool operator!=(const const_reverse_iterator &it) const	{ return _ptr != it._ptr; }
		bool operator<=(const const_reverse_iterator &it) const { return _ptr >= it._ptr; }
		bool operator>=(const const_reverse_iterator &it) const { return _ptr <= it._ptr; }
		bool operator>(const const_reverse_iterator &it) const { return _ptr < it._ptr;	}
		bool operator<(const const_reverse_iterator &it) const { return _ptr > it._ptr;	}

		difference_type	operator-(const_reverse_iterator it) const { return it._ptr - _ptr;	}
		reference 		operator*() const { return *--_ptr; }
		pointer 		operator->() const { return _ptr; }

		const_reverse_iterator& operator++() {
			--_ptr;
			return *this;
		}

		const_reverse_iterator operator++(int) {
			const_reverse_iterator tmp(*this);
			--_ptr;
			return tmp;
		}

		const_reverse_iterator& operator--() {
			++_ptr;
			return *this;
		}

		const_reverse_iterator operator--(int) {
			const_reverse_iterator tmp(*this);
			++(*_ptr);
			return tmp;
		}

		const_reverse_iterator& operator+=(size_type rhs) {
			movePtr(_ptr, rhs, 1);
			return *this;
		}

		const_reverse_iterator operator+(size_type rhs) const {
			const_reverse_iterator it(*this);
			movePtr(it._ptr, rhs, 1);
			return it;
		}

		friend const_reverse_iterator operator+(size_type lhs, const const_reverse_iterator &rhs) {
			const_reverse_iterator it(rhs);
			return it += lhs;
		}

		const_reverse_iterator& operator-=(size_type rhs) {
			movePtr(_ptr, rhs, 0);
			return *this;
		}

		const_reverse_iterator operator-(size_type rhs) const {
			const_reverse_iterator it(*this);
			movePtr(it._ptr, rhs, 0);
			return 0;
		}

		friend const_reverse_iterator operator-(size_type lhs, const const_reverse_iterator &rhs) {
			const_reverse_iterator it(rhs);
			return it -= lhs;
		}

		reference operator[](size_type rhs) const {
			value_type *tmp(_ptr);
			movePtr(tmp, rhs, 1);
			return *tmp;
		}

	};

} // ft

#endif //FT_CONTAINER_VECTOR_CONST_ITERATOR_HPP
