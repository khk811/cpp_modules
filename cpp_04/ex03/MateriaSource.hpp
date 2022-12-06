#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*		materias[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource const& src);
	~MateriaSource();
	void			learnMateria(AMateria* m);
	AMateria*		createMateria(std::string const & type);
	MateriaSource&	operator=(MateriaSource const& src);
};

#endif
