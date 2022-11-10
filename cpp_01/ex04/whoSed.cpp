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

bool	whoSed::hasValidVariables()
{
	if (this->getFileName() == "")
	{
		std::cout << "Error: Empty infile name" << std::endl;
		return (false);
	}
	else if (this->getTargetString() == "")
	{
		std::cout << "Error: Empty target string" << std::endl;
		return (false);
	}

	std::ifstream	ifs(this->getFileName());

	if (ifs.good() == false)
	{
		std::cout << "Error: Cannot open infile" << std::endl;
		ifs.close();
		return (false);
	}
	return (true);
}

void	whoSed::putResultLineInFile()
{
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
