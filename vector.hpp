// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 22/09/2022.
//

#ifndef FT_CONTAINER_VECTOR_HPP
#define FT_CONTAINER_VECTOR_HPP

#include <iostream>
#include <iomanip>
#include <memory>

#include "iterator/iterator.hpp"
#include "iterator/enable_if.hpp"
#include "iterator/is_integral.hpp"

namespace ft {

	template<class T, class A = std::allocator<T> >
	class vector {

	public:
		typedef	T			value_type;
		typedef A		 	allocator_type;
		typedef	size_t		size_type;
		typedef ptrdiff_t	difference_type;
		typedef typename A::reference		reference;
		typedef typename A::const_reference	const_reference;
		typedef typename A::pointer			pointer;
		typedef typename A::const_pointer	const_pointer;
		typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const value_type>    const_iterator;
		typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
		typedef ft::reverse_iterator<iterator>                  reverse_iterator;

	private:
		allocator_type	_allocator;
		value_type		*_data;
		size_type		_capacity;
		size_type		_size;

	public:
		explicit vector( const allocator_type& alloc = allocator_type()):
				_allocator(alloc),
				_capacity(1),
				_data(alloc.allocate(_capacity)),
				_size(0)
				{}

		explicit vector(size_type n, const value_type& value = value_type(),
						const allocator_type& alloc = allocator_type()): _allocator(alloc)	{
			_capacity = n;
			_size = n;
			_data = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(&_data[i], value);
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				InputIterator>::type * = NULL): _allocator(alloc) {
			_size = 0;
			_capacity = 1;
			_data = _allocator.allocate(_capacity);
			for ( ; first != last; first++)
				push_back(*first);
		}

		vector(const vector &instance) {
			if (*this != instance) {
				_capacity = instance._capacity;
				_allocator = instance._allocator;
				_size = instance._size;
				_data = _allocator.allocate(_capacity);
				for (size_t i = 0; i < instance.size(); i++)
					push_back(instance[i]);
			}
		}

		vector &operator=(vector const &rhs) {
			if (this != &rhs) {
				_capacity = rhs._capacity;
				_allocator = rhs._allocatorator;
				_size = rhs._size;
				_data = rhs._data;
			}
			return *this;
		}

		~vector() { clear(); }

		iterator		begin() 		{ return iterator(&_data[0]); }
		iterator		end() 			{ return iterator(&_data[_size]); }
		const_iterator 	begin() const	{ return const_iterator(&_data[0]); }
		const_iterator	end()	const	{ return const_iterator(&_data[_size]); }

		reverse_iterator		rbegin()		{ return reverse_iterator(&_data[_size]); }
		reverse_iterator		rend()			{ return reverse_iterator(&_data[0]); }
		const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(&_data[_size]); }
		const_reverse_iterator	rend()	 const	{ return const_reverse_iterator(&_data[0]); }

		size_type	size()		 const 	{ return _size; }
		size_type	max_size()			{ return  std::numeric_limits<size_type>::max() / sizeof(value_type); }
		size_type	capacity()	const	{ return _capacity; }
		bool 		empty()		const 	{ _size == 0; }

		void	resize(size_type n, value_type val = value_type()) {
			if (_capacity < n) {
				value_type *tmp = _data;
				_data = _allocator.allocate(n);

				for (size_type i = 0; i < _size; i++) {
					_allocator.construct(&_data[i], tmp[i]);
					_allocator.destroy(&tmp[i]);
				} for (size_type i = _size; i < n; i++)
					_allocator.construct(&_data[i], val);

				_allocator.deallocate(tmp, _capacity);
				_capacity = n;
				_size = n;
			} else if (_size > n) {
				value_type *tmp = _data;
				_data = _allocator.allocate(_capacity);

				for (size_type i = 0; i < n; i++) {
					_allocator.construct(&_data[i], tmp[i]);
					_allocator.destroy(&tmp[i]);
				} for (size_type i = n; i < _size; i++)
					_allocator.destroy(&tmp[i]);

				_allocator.deallocate(tmp, _capacity);
				_size = n;
			} else if (_size < n) {
				for (size_type i = _size; i < n; i++)
					_allocator.construct(&_data[i], val);
				_size = n;
			}
		}

		void 	reserve(size_type n) {
			if (_capacity < n || _data == NULL) {
				pointer tmp = _data;
				_data = _allocator.allocate(n);

				for (size_type i = 0; i < _size; i++) {
					_allocator.construct(&_data[i], tmp[i]);
					_allocator.destroy(&tmp[i]);
				}

				if (_data != NULL)
					_allocator.deallocate(tmp, _capacity);
				_capacity = n;
			}
		}

		reference			operator[](size_type nb)		 { return _data[nb]; }
		const_reference 	operator[](size_type nb) const	 { return _data[nb]; }

		reference	at(size_type nb) {
			if (nb >= _size)
				throw std::out_of_range("vector");
			return _data[nb];
		}

		const_reference	at(size_type nb) const {
			if (nb >= _size)
				throw std::out_of_range("vector");
			return _data[nb];
		}

		reference		front() 		{ return _data[0]; }
		reference		back()			{ return _data[_size - 1]; }
		const_reference	front() const 	{ return _data[0]; }
		const_reference back()	const	{ return _data[_size - 1]; }


		template <class InputIterator>
		void	assign(InputIterator first,
					 InputIterator last,
					 typename ft::enable_if<!ft::is_integral<InputIterator>::value,
					 InputIterator>::type * = NULL)	{
			clear();
			check_capacity();
			for ( ; first != last; first++)
				push_back(*first);
		}

		void 	assign(size_type nb, const value_type& val) {
			clear();
			check_capacity();
			for ( size_type i = 0; i < nb; i++)
				push_back(val);
		}

		void 	push_back(const value_type& val) {
			check_capacity();
			_allocator.construct(&_data[_size], val);
			_size++;
		}

		void 	pop_back() {
			_allocator.destroy(&_data[_size - 1]);
			_size;
		}

		iterator	insert(iterator position, const value_type& val) {
			size_type index = position - begin();
			if (index <= _capacity)	{
				check_capacity();
				for (size_type i = _size; i >= 0; i--) {
					if (i == index)	{
						_allocator.construct(&_data[i + 1], _data[i]);
						_allocator.destroy(&_data[i]);
						_allocator.construct(&_data[i], val);
						break;
					} else {
						_allocator.construct(&_data[i + 1], _data[i]);
						_allocator.destroy(&_data[i]);
					}
				}
				_size++;
			}
			return iterator(&_data[index]);
		}

		void	insert(iterator position, size_type n, const value_type& val) {
			size_type index = position - begin();
			if (index <= _capacity) {
				if (_capacity - _size < n)
					reserve(_capacity + n);
				else
					check_capacity();

				for (size_type i = _size; i >= 0; i--) {
					if (i == index)	{
						_allocator.construct(&_data[i + n], _data[i]);
						_allocator.destroy(&_data[i]);
						for (size_type j = 0; j < n; j++)
							_allocator.construct(&_data[i + j], val);
						break;
					} else {
						_allocator.construct(&_data[i + n], _data[i]);
						_allocator.destroy(&_data[i]);
					}
				}
				_size += n;
			}
		}

		void 	swap(vector &toSwap) {
			std::swap(_allocator, toSwap._allocator);
			std::swap(_data, toSwap._data);
			std::swap(_capacity, toSwap._capacity);
			std::swap(_size, toSwap._size);
		}

		void	clear() {
			if (_data != NULL) {
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(&_data[i]);

				_allocator.deallocate(_data, _capacity);
				_data = NULL;
				_size = 0;
			}
		}

		void check_capacity() {
			if (_size == _capacity)
				reserve(_capacity * 2);
			if (_data == NULL)
				reserve(_capacity);
		}

		void check_capacity (size_type n) {
			if (_capacity < n)
				reserve(n);
			else if (_size == _capacity)
				reserve(_capacity * 2);
			else if (_data == NULL)
				reserve(_capacity);
		}

	};

} // ft

#endif //FT_CONTAINER_VECTOR_HPP
