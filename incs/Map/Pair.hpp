// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by Mathis Martini on 9/30/22.
//

#ifndef FT_CONTAINER_PAIR_H
#define FT_CONTAINER_PAIR_H

#include <algorithm>

namespace ft {

    template<class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;

		pair() : first(), second() {}
		template<class U, class V>
		pair (const ft::pair<U,V>& pr) : first(pr.first), second(pr.second) {}
		pair (const first_type& a, const second_type& b) : first(a) ,second(b) {}
		~pair () {}

		void swap (pair& pr) {
			swap(first, pr.first);
			swap(second, pr.second);
		}

		pair& operator= (const pair& pr) {
			first = pr.first;
			second = pr.second;
			return *this;
		}

		friend bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return lhs.first==rhs.first && lhs.second==rhs.second; }
		friend bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return !(lhs==rhs); }
		friend bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }
		friend bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return !(rhs<lhs); }
		friend bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return rhs<lhs; }
		friend bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return !(lhs<rhs); }

	};

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 first, T2 second) {
		return pair<T1, T2>(first, second);
	}
}


#endif //FT_CONTAINER_PAIR_H
