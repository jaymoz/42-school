#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

class Bureaucrat;


class ShrubberyCreationForm : public virtual Form
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string _target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreationForm);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ShrubberyCreationForm);
		void execute(Bureaucrat const &executor);
};

#endif
