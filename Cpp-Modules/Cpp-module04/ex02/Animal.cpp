#include "Animal.hpp"

Animal::Animal():type("Animal"){std::cout << "Animal default constructor called" << std::endl;}

Animal::~Animal(){std::cout << "Animal default destructor called" << std::endl;}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal has been assigned" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Animal ::Animal(const Animal &other)
{
    std::cout <<"Animal copy constructor called" << std::endl;
    *this = other;
}

void Animal::makeSound(void) const
{
    std::cout << "Animal says sound sound" << std::endl;
}

std::string Animal::getType(void) const {return this->type;}

