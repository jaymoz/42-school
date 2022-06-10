#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Bureaucrat;

class PresidentialPardonForm: public virtual Form
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string _target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &PresidentialPardonForm);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &PresidentialPardonForm);

	void execute(Bureaucrat const &executor);
};

#endif
