#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
private:
	T*				arr;
	unsigned int	arr_size;
public:
	Array();
	Array(unsigned int n);
	Array(Array const& src);
	~Array();
	unsigned int	size() const;
	T&				operator[](unsigned int idx);
	T const&		operator[](unsigned int idx) const;
	Array&			operator=(Array const& src);
	class IndexOutOfBound : public std::exception {
		const char*	what() const throw();
	};
};

template<typename T>
Array<T>::Array() : arr_size(0) {
	std::cout << "Array Default Constructor Called" << std::endl;
	this->arr = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n) : arr_size(n) {
	std::cout << "Array Parametic Constructor Called" << std::endl;
	this->arr = new T[this->arr_size];
}

template<typename T>
Array<T>::Array(Array const& src) {
	std::cout << "Array Copy Constructor Called" << std::endl;
	this->arr = NULL;
	this->arr_size = 0;
	*this = src;
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->arr;
	std::cout << "Array Destructor Called" << std::endl;
}

template<typename T>
unsigned int	Array<T>::size() const {
	return this->arr_size;
}

template<typename T>
T&	Array<T>::operator[](unsigned int idx) {
	if (idx >= this->arr_size) {
		throw IndexOutOfBound();
	} else {
		return this->arr[idx];
	}
}

template<typename T>
T const&	Array<T>::operator[](unsigned int idx) const {
	if (idx >= this->arr_size) {
		throw IndexOutOfBound();
	} else {
		// std::cout << "[] const op" << std::endl;
		return this->arr[idx];
	}
}

template<typename T>
Array<T>&	Array<T>::operator=(Array<T> const& src) {
	std::cout << "Array Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		delete[] this->arr;
		this->arr_size = src.arr_size;
		this->arr = new T[this->arr_size];
		for (unsigned int i = 0; i < this->arr_size; i++)
		{
			this->arr[i] = src.arr[i];
		}
	}
	return *this;
}

template<typename T>
const char*	Array<T>::IndexOutOfBound::what() const throw() {
	return "the index is out of bound";
}


#endif

