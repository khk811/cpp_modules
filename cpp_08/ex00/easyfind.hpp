#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

class ItemCannotFound : public std::exception {
	const char	*what() const throw();
};

template <typename T>
typename T::iterator	easyfind(T& ctain, int target) {
	typename T::iterator	find_result;
	find_result = std::find(ctain.begin(), ctain.end(), target);
	if (find_result != ctain.end()) {
		return find_result;
	} else {
		throw ItemCannotFound();
	}
}

#endif

