#include "Ice.hpp"

Ice::Ice(void) : AMateria()
{
	this->_type = "ice";
}

Ice::~Ice(void)
{
}

Ice::Ice(const Ice &obj) : AMateria()
{
	*this = obj;
}

Ice	&Ice::operator=(const Ice &other)
{
	if  (this != &other)
		this->_type = other._type;
	return *this;
}

AMateria	*Ice::clone(void) const { return new Ice(*this); }

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
