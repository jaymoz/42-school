#include "Bureaucrat.hpp"
#include <iostream>

void	try_catch(const std::string &name, int grade)
{
	try
	{
		Bureaucrat	bureaucrat(name, grade);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	increment_decrement(int grade, int crement)
{
	try
	{
		Bureaucrat	bureaucrat("Mr Johnson", grade);
		if (crement == -1)
			bureaucrat.setDecreaseGrade();
		else if (crement == 1)
			bureaucrat.setIncreaseGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	Bureaucrat	micheal("Jaymos", 1);
	std::cout << micheal << std::endl;

	try_catch("james", 3);
	try_catch("Moses", 0);
	try_catch("John", 151);

	std::cout << std::endl;

	increment_decrement(1, 1);
	increment_decrement(150, -1);
	increment_decrement(1, -1);
	increment_decrement(150, 1);
	return 0;
}

