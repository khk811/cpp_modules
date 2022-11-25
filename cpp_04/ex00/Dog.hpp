#ifndef DOG_HPP
#define DOG_HPP

class Dog
{
public:
	Dog();
	Dog(Dog const& src);
	~Dog();
	Dog&	operator=(Dog const& src);
};

#endif
