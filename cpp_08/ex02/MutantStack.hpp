#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator			iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;
	iterator			begin();
	iterator			end();
	reverse_iterator	rbegin();
	reverse_iterator	rend();
	MutantStack();
	MutantStack(MutantStack const& src);
	~MutantStack();
	MutantStack&		operator=(MutantStack const& src);
};

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin() {
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend() {
	return this->c.rend();
}

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
