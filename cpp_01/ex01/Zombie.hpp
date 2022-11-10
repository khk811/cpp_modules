#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string	name;

	std::string	getZombieName(void);

public:
	Zombie();
	~Zombie();
	void		setZombieName(std::string name);
	void		announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
