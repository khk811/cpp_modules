#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource Default Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const& src) {
	std::cout << "MateriaSource Copy Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src.materias[i] != NULL) {
			this->materias[i] = src.materias[i]->clone();
		}
		else {
			this->materias[i] = NULL;
		}
	}

}
MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource Destructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] != NULL) {
			delete this->materias[i];
		}
	}
}
void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->materias[i] == NULL) {
			std::cout << "MateriaSource learned " << m->getType() << std::endl;
			this->materias[i] = m;
			return;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->materias[i] != NULL) {
			if (this->materias[i]->getType() == type) {
				std::cout << "MateriaSource cloned " << this->materias[i]->getType() << std::endl;
				return this->materias[i]->clone();
			}
		}
	}
	return NULL;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& src) {
	std::cout << "MateriaSource Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		for (int i = 0; i < 4; i++)
		{
			if (src.materias[i] != NULL) {
				if (this->materias[i] != NULL) {
					delete this->materias[i];
				}
				this->materias[i] = src.materias[i]->clone();
			}
			else {
				if (this->materias[i] != NULL) {
					delete this->materias[i];
				}
				this->materias[i] = NULL;
			}
		}
	}
	return *this;
}
