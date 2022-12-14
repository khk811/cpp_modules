#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string		ideas[100];
	unsigned int	idea_idx;
public:
	Brain();
	Brain(Brain const& src);
	~Brain();
	void			printIdeaNAddr(unsigned int idx) const;
	void			printAllIdeas() const;
	void			setIdea(std::string idea);
	Brain&			operator=(Brain const& src);
};


#endif
