#include "whoSed.hpp"

whoSed::whoSed()
{
}

whoSed::~whoSed()
{
}

std::string	whoSed::getFileName()
{
	return (this->file_name);
}

std::string	whoSed::getTargetString()
{
	return (this->target_string);
}

std::string	whoSed::getReplaceString()
{
	return (this->to_replace);
}

std::string	whoSed::replaceTargetString(std::string single)
{
	int			index = 0;
	size_t		found = single.find(this->getTargetString(), index);
	std::string	ret;

	if (found != std::string::npos)
	{
		while (found != std::string::npos)
		{
			ret.append(single.substr(index, found - index));
			ret.append(this->getReplaceString());
			index = found + this->getTargetString().length();
			found = single.find(this->getTargetString(), index);
		}
		ret.append(single.substr(index));
		return (ret);
	}
	else
		return (single);
}

int	whoSed::putResultLineInFile()
{
	if (this->getFileName() == "")
	{
		std::cout << "Error: infile name is empty" << std::endl;
		return (1);
	}

	std::ifstream	ifs(this->getFileName());
	std::ofstream	ofs(this->getFileName().append(".replace"));
	std::string		single_line;

	while (ifs.eof() == false)
	{
		std::getline(ifs, single_line);
		if (ifs.eof() == true)
			break ;
		ofs << this->replaceTargetString(single_line) << std::endl;
		single_line.clear();
	}
	ifs.close();
	ofs.close();
	return (0);
}

void	whoSed::setFileName(std::string name)
{
	this->file_name = name;
}

void	whoSed::setTargetString(std::string target)
{
	this->target_string = target;
}

void	whoSed::setReplaceString(std::string replace)
{
	this->to_replace = replace;
}
