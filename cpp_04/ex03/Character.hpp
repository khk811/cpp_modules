#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string			name;
	AMateria*			inventory[4];
public:
	Character();
	Character(Character const& src);
	Character(std::string chr_name);
	~Character();
	std::string const&	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
	Character&			operator=(Character const& src);
};


#endif
