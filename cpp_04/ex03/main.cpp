#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	exampleTest(void) {
	IMateriaSource*	src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*		me = new Character("me");

	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter*		bob = new Character("bob");

	std::cout << "\n===Using Materias to bob===" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "" << std::endl;

	delete bob;
	delete me;
	delete src;
}

void	copyTest() {
	/* test copy constructor and copy assignment operator */
	std::cout << "\n===Copy Test===" << std::endl;
	MateriaSource* 	ice_src = new MateriaSource();
	AMateria*		ice_materia = new Ice();

	ice_src->learnMateria(ice_materia->clone());
	ice_src->learnMateria(ice_materia);

	MateriaSource*		copy_ice_src = new MateriaSource();

	copy_ice_src->learnMateria(new Cure());
	*(copy_ice_src) = *(ice_src);

	AMateria*		tmp;
	tmp = copy_ice_src->createMateria("ice");
	std::cout << "copy_ice_src createMateria('ice') result: " << tmp->getType() << std::endl;
	delete tmp;
	tmp = copy_ice_src->createMateria("cure");
	if (tmp == NULL) {
		std::cout << "Copy Operator Successfully Copies Ice(s)" << std::endl;
	}

	const Ice*			const_ice = new Ice();
	std::cout << "---Copy Constructor Test(1)---" << std::endl;
	AMateria*			ice_clone = new Ice(*(const_ice));

	std::cout << "const_ice address: " << const_ice << std::endl;
	std::cout << "ice_clone address: " << ice_clone << std::endl;

	const Character*	alex = new Character("Alex");
	std::cout << "---Copy Constructor Test(2)---" << std::endl;
	Character*			clone_alex = new Character(*(alex));

	std::cout << "alex address: " << alex << std::endl;
	std::cout << "clone_alex address: " << clone_alex << std::endl;

	clone_alex->equip((AMateria *)const_ice); // upcasting ?
	clone_alex->equip(ice_clone);

	Character*			dummy = new Character("dummy");

	clone_alex->use(0, *(dummy));
	clone_alex->unequip(1);

	*(dummy) = *(clone_alex);
	dummy->use(0, *(clone_alex));
	dummy->use(1, *(clone_alex));

	delete dummy;
	delete clone_alex;
	delete alex;
	delete ice_clone;
	delete copy_ice_src;
	delete ice_src;
}

int	main(void) {
	exampleTest();
	copyTest();
	std::cout << "\n===Check Memory Leaks===" << std::endl;
	system("leaks a.out");
	return 0;
}
