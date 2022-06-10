#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Form * maison = new ShrubberyCreationForm("Maison");
		Form * walle = new RobotomyRequestForm("Wall-E");
		Form * sarkozy = new PresidentialPardonForm("Sarkozy");

		Bureaucrat sean("Sean Paul", 1);

		std::cout << sean << std::endl;
		std::cout << *maison << std::endl;
		std::cout << *walle << std::endl;
		std::cout << *sarkozy << std::endl;

		sean.signForm(*maison);
		maison->beSigned(sean);

		sean.signForm(*walle);
		walle->beSigned(sean);

		sean.signForm(*sarkozy);
		sarkozy->beSigned(sean);

		std::cout << *maison << std::endl;
		std::cout << *walle << std::endl;
		std::cout << *sarkozy << std::endl;

		sean.executeForm(*maison);
		maison->execute(sean);

		sean.executeForm(*walle);
		walle->execute(sean);

		sean.executeForm(*sarkozy);
		sarkozy->execute(sean);

		delete maison;
		delete walle;
		delete sarkozy;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);

}