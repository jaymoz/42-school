#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog &other);

		Dog		&operator=(const Dog &other);
		void	makeSound(void) const;
		void			ideaGet(int index) const;
		void			ideaSet(const std::string &idea, int index);
};

#endif