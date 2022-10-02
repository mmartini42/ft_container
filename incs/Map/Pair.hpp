// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by Mathis Martini on 9/30/22.
//

#ifndef FT_CONTAINER_PAIR_H
#define FT_CONTAINER_PAIR_H

#include <algorithm>

namespace ft {

    template<class T1, class T2>
    class pair {
    public:
        typedef T1  first_type;
        typedef T2  second_type;

        first_type  _first;
        second_type _second;

        pair() : _first(), _second() {}

        template<class T, class G>
        pair(const ft::pair<T,G>& ref) : _first(ref.first), _second(ref.second) {}
        pair(const first_type &t, const second_type &g) : _first(t), _second(g) {}
        ~pair() {}

        pair    &operator=(const pair& src) {
            _first = src.first;
            _second = src.second;
            return *this;
        }

        void    swap(pair &toSwap) {
            std::swap(_first, toSwap.first);
            std::swap(_second, toSwap.second);
        }

        bool    operator==(const ft::pair<T1, T2>& rhs) { return _first == rhs._first && _second == rhs._second; }
        bool    operator!=(const ft::pair<T1, T2>& rhs) { return _first != rhs._first && _second != rhs._second; }
        bool    operator<(const ft::pair<T1, T2>& rhs) { return _first < rhs._first && _second < rhs._second; }
        bool    operator>(const ft::pair<T1, T2>& rhs) { return _first > rhs._first && _second > rhs._second; }

        friend bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return lhs <= rhs; }
        friend bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return lhs >= rhs; }

    };

    template<class T, class G>
    pair<T,G>   makePair(T first, G second) {
        return pair<T,G>(first, second);
    }
}


#endif //FT_CONTAINER_PAIR_H
