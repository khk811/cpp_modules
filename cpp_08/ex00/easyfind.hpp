#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

class ItemCannotFound : public std::exception {
	const char	*what() const throw();
};

template <typename Container>
typename Container::iterator	easyfind(Container& ctain, int target) {
	// find 함수를 써야 한다;; 와 미친...평가표에는 for문 금지!!
	// 반복자를 쓴 매뉴얼 서치 금지!! 우와웅 ㅠㅠㅠㅠㅠ
	// for (typename Container::iterator itr = ctain.begin(); itr !=  ctain.end(); itr++)
	// {
	// 	if (*(itr) == target) {
	// 		return itr;
	// 	}
	// }
	// throw ItemCannotFound();
	typename Container::iterator	target_occur;
	target_occur = std::find(ctain.begin(), ctain.end(), target);
	if (target_occur != ctain.end()) {
		return target_occur;
	} else {
		throw ItemCannotFound();
	}
}

#endif

