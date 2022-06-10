#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain		&Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignment operataor called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}

	return *this;
}

const std::string	&Brain::getIdea(int index) const
{
	return this->_ideas[index];
}

void	Brain::setIdea(const std::string &idea, int index)
{
	this->_ideas[index] = idea;
}
