// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 25/09/2022.
//

#ifndef FT_CONTAINER_ENABLE_IF_HPP
#define FT_CONTAINER_ENABLE_IF_HPP

namespace ft {

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> {	typedef T type;	};

} // ft

#endif //FT_CONTAINER_ENABLE_IF_HPP
