// Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

//
// Created by mathis martini on 27/09/2022.
//

#ifndef FT_CONTAINER_ALGORITHM_HPP
#define FT_CONTAINER_ALGORITHM_HPP

namespace ft {
	template < class it1, class it2 >
	bool	lexicographical_compare (it1 first1, it1 last1, it2 first2, it2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

	template < class it1, class it2, class Compare >
	bool	lexicographical_compare (it1 first1, it1 last1, it2 first2, it2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			first1++;
			first2++;
		}
		return (first2 != last2);
	}
} //ft

/* **************************************************************************** */
/*									Memo										*/
/* **************************************************************************** */

/**
		 * A lexicographical comparison is the kind of comparison generally used to sort words alphabetically in dictionaries.
		 * default
		 * @param first1 - initial position of the first sequence
		 * @param last1 - final position of the first sequence
		 * @param first2 - initial position of the second sequence
		 * @param last2 - final position of the second sequence
		 * @return true if the first range compares lexicographically less than the second.
		 *
		 * template < class it1, class it2 >
	     * bool	lexicographical_compare (it1 first1, it1 last1, it2 first2, it2 last2)
		 */

/**
		 * A lexicographical comparison is the kind of comparison generally used to sort words alphabetically in dictionaries.
		 * custom
		 * @param first1 - initial position of the first sequence
		 * @param last1 - final position of the first sequence
		 * @param first2 - initial position of the second sequence
		 * @param last2 - final position of the second sequence
		 * @param comp - binary function that accepts two arguments of the types pointed by the iterators, and returns a value convertible to bool
		 * @return true if the first range compares lexicographically less than the second.
		 *
		 * template < class it1, class it2, class Compare >
		 * bool	lexicographical_compare (it1 first1, it1 last1, it2 first2, it2 last2, Compare comp)
		 */
#endif //FT_CONTAINER_ALGORITHM_HPP
