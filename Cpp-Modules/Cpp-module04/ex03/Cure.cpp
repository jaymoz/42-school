#include "Cure.hpp"

Cure::Cure(void) : AMateria()
{
	this->_type = "cure";
}

Cure::~Cure(void){}

Cure::Cure(const Cure &obj) : AMateria(){ *this = obj;}

Cure	&Cure::operator=(const Cure &other)
{
	if(this != &other)
		this->_type = other._type;
	return *this;
}

AMateria	*Cure::clone(void) const { return new Cure(*this); }

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
