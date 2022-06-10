#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form::Form("PresidentialPardonForm", "none", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : Form::Form("PresidentialPardonForm", _target, 25, 5){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &PresidentialPardonForm){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ShrubberyCreationForm){ return (*this); }

void PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	if (getIsSigned() == false)
		throw IsnotSigned();
	if (getExecuteGrade() < executor.getGrade())
		throw LowGrade();
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

