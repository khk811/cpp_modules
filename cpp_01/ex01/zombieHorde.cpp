#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie*	the_horde;

	the_horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		the_horde[i].setZombieName(name);
	}
	return the_horde;
}
