#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	subject_example(void) {
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");

	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter*	bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	copy_test() {
	/* test copy constructor and copy assignment operator */
	ICharacter*		alex = new Character("Alex");

	IMateriaSource*	src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	AMateria	*tmp;

	tmp = src->createMateria("ice");
	alex->equip(tmp);
	tmp = src->createMateria("cure");
	alex->equip(tmp);

	Character		jacob = Character();

	Character const	romeo = Character("Romeo");

	tmp = src->createMateria("cure");
	jacob.equip(tmp);
	jacob.unequip(0);
	delete tmp;
	tmp = src->createMateria("cure");
	jacob.equip(tmp);
	jacob = romeo;
	alex->use(0, jacob);
	alex->use(1, jacob);
	tmp = src->createMateria("ice");
	jacob.equip(tmp);
	jacob.use(0, *alex);

	delete alex;
	delete src;
}

int	main(void) {
	subject_example();
	copy_test();
	system("leaks a.out");
	return 0;
}
