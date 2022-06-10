#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
}

Cat::~Cat() {std::cout << "Cat destructor called" << std::endl;}

Cat::Cat(const Cat &other)
{
    std::cout << "Cat copy constructor called"<<std::endl;
    (*this) = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat has been assigned" <<std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void Cat::makeSound(void) const {std::cout << "Cat says meow meow" << std::endl;}
