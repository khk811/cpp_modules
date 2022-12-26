#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>

class ItemCannotFound : public std::exception {
	const char	*what() const throw();
};

template <typename Container>
int	easyfind(Container& ctain, int target) {
	for (typename Container::iterator itr = ctain.begin(); itr !=  ctain.end(); itr++)
	{
		if (*(itr) == target) {
			return *(itr);
		}
	}
	throw ItemCannotFound();
}

#endif

