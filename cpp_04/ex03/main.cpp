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

void	inventoryTest(void) {
	std::cout << "\n===Inventory Test===" << std::endl;
	IMateriaSource*	random_materia = new MateriaSource();
	AMateria*		cure_arr[5];

	std::cout << "---MateriaSource inventory test---" << std::endl;
	random_materia->learnMateria(new Cure());
	random_materia->learnMateria(new Cure());
	random_materia->learnMateria(new Cure());
	random_materia->learnMateria(new Cure());

	std::cout << "---try to learn 5th Materia---" << std::endl;
	Cure*			last_cure = new Cure();

	random_materia->learnMateria(last_cure);

	ICharacter*		random_character = new Character();

	std::cout << "---Character inventory test---" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		cure_arr[i] = random_materia->createMateria("cure");
	}
	for (int i = 0; i < 4; i++)
	{
		random_character->equip(cure_arr[i]);
	}

	std::cout << "---try to equip 5th Materia---" << std::endl;
	random_character->equip(cure_arr[4]);

	for (int i = 0; i < 4; i++)
	{
		random_character->unequip(i);
	}
	std::cout << "---try to unequip Materia from empty inventory---" << std::endl;
	random_character->unequip(0);

	for (int i = 0; i < 5; i++)
	{
		delete cure_arr[i];
	}
	delete last_cure;
	delete random_character;
	delete random_materia;
}

int	main(void) {
	exampleTest();
	copyTest();
	inventoryTest();
	std::cout << "\n===Check Memory Leaks===" << std::endl;
	system("leaks a.out");
	return 0;
}
