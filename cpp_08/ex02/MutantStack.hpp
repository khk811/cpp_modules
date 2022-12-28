#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	// iterator	begin();
	// iterator	end();
	MutantStack();
	MutantStack(MutantStack const& src);
	~MutantStack();
	MutantStack&	operator=(MutantStack const& src);
};

// template<typename T>
// iterator	MutantStack<T>::begin() {
// 	return this->c.begin();
// }

// template<typename T>
// iterator	MutantStack<T>::end() {
// 	return this->c.end();
// }

template<typename T>
MutantStack<T>::MutantStack() {
	std::cout << "MutantStack Default Constructor Called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const& src) {
	std::cout << "MutantStack Copy Constructor Called" << std::endl;
	*this = src;
}

template<typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "MutantStack Destructor Called" << std::endl;
}

template<typename T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack<T> const& src) {
	std::cout << "MutantStack Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->c = src.c;
	}
	return *this;
}


#endif
