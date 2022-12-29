#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	// typedef typename (c from stack<T>)::iterator	iterator;
	// 이런식으로 정의가 되어야 할 것 같은데 도저히 못하겠음. syntax error 어쩔꺼야
	typedef typename std::deque<T>::iterator	iterator;
	iterator	begin();
	iterator	end();
	iterator	rbegin();
	iterator	rend();
	MutantStack();
	MutantStack(MutantStack const& src);
	~MutantStack();
	MutantStack&	operator=(MutantStack const& src);
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
typename MutantStack<T>::iterator	MutantStack<T>::rbegin() {
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::rend() {
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
