#include "Dog.hpp"

Dog::Dog(): Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::~Dog(){std::cout << "Dog destructor  called" << std::endl;}

Dog    &Dog::operator=(const Dog &other)
{
    std::cout << "Dog has been assigned" << std::endl;
    this->type = other.type;
    return (*this);
}

Dog::Dog(const Dog &other)
{
    std::cout << "Dog is copied" <<std::endl;
    *this = other;
}

void    Dog::makeSound(void) const { std::cout << "Dog says woof woof" << std::endl;}