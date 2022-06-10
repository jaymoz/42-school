#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal assignment operator called." << std::endl;
    if (this != &other)
	    this->type = other.type;
	return *this;
}

std::string	WrongAnimal::getType(void)const {return this->type;}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal says wrong sound" << std::endl;
}