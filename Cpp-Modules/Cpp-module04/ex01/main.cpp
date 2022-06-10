#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define NUM 4

int	main(void)
{
	if (NUM < 4)
	{
		std::cout << "Input should not be less than 4" << std::endl;
		return 1;
	}
	Animal	*animals[NUM];
	for (int i = 0; i < NUM; i++)
	{
		if (i < NUM / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		animals[i]->makeSound();
		std::cout << "-----" << std::endl;
	}
	Dog	*dog1 = (Dog*)animals[0];
	Dog	*dog2 = (Dog*)animals[1];
	dog1->ideaSet("I should bark and bite", 0);
	dog2->ideaSet("lets get started already", 0);
	dog1->ideaGet(0);
	dog2->ideaGet(0);

	for (int i = 0; i < NUM; i++)
	{
		std::cout << "=====" << std::endl;
		delete animals[i];
	}
	return 0;
}
