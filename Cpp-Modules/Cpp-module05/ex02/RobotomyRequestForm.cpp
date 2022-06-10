#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form::Form("RobotomyRequestForm", "unknown", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : Form::Form("RobotomyRequestForm", _target, 72, 45){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &RobotomyRequestForm){ return (*this);}

void RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	if (getIsSigned() == false)
		throw IsnotSigned();
	if (getExecuteGrade() < executor.getGrade())
		throw LowGrade();
	srand(time(NULL));
	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << Form::getTarget() << " was successfully robotomized !" << std::endl;
	else
		std::cerr << "Well, " << Form::getTarget() << "'s robotomy was a failure..." << std::endl;
}
