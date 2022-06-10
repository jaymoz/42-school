#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	ryan;
	{
		Form	*form = ryan.makeForm("shrubbery creation", "Bender");
		delete form;
	}
	{
		Form	*form = ryan.makeForm("robotomy request", "Bender");
		delete form;
	}
	{
		Form	*form = ryan.makeForm("presidental pardon", "Bender");
		delete form;
	}
	return 0;
}