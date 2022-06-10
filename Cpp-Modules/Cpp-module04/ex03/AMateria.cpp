#include "AMateria.hpp"

AMateria::AMateria(void) : _type("amateria"){}

AMateria::~AMateria(void){}

AMateria::AMateria(const AMateria &obj){*this = obj;}

AMateria::AMateria(const std::string &type) : _type(type){}

AMateria	&AMateria::operator=(const AMateria &rhs)
{
	(void)rhs;
	return *this;
}

const std::string	&AMateria::getType(void) const
{
	return this->_type;
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "* but nothing happened *" << std::endl;
}
