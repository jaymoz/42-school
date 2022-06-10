#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	ft_trycatch_alloc_form(const std::string &name, int grade)
{
	try
	{
		Form	form(name, grade, grade);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}


int	main(void)
{
	Bureaucrat	micheal("Micheal Scott", 1);
	Form	form("Paperwork", 21, 42);
	std::cout << form << std::endl;
	form.beSigned(micheal);
	std::cout << form << std::endl;

	ft_trycatch_alloc_form("Form", 1);
	ft_trycatch_alloc_form("Form", 150);
	ft_trycatch_alloc_form("Form", 0);
	ft_trycatch_alloc_form("Form", 151);

	{
	Bureaucrat	bureaucrat("Bureaucrat", 7);
	Form		form("Form", 8, 17);
	
	bureaucrat.signForm(form);
	}

	return 0;
}

