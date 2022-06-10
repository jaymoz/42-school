#include "Dog.hpp"

Dog::Dog(): Animal(), brain(new Brain())
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::~Dog(){std::cout << "Dog destructor  called" << std::endl;}

Dog    &Dog::operator=(const Dog &other)
{
    std::cout << "Dog has been assigned" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        this->brain = new Brain(*other.brain);

    }
    
    return (*this);
}

Dog::Dog(const Dog &other)
{
    std::cout << "Dog is copied" <<std::endl;
    *this = other;
}

void    Dog::makeSound(void) const { std::cout << "Dog says woof woof" << std::endl;}

void	Dog::ideaGet(int index) const
{
	std::cout << this->brain->getIdea(index) << std::endl;
}

void	Dog::ideaSet(const std::string &idea, int index)
{
	this->brain->setIdea(idea, index);
}
