#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "High Grade maximum is 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "low Grade maximum is 1";
}

Bureaucrat::Bureaucrat():name_("Unknown")
{
	grade_ = 0;
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name_(_name), grade_(_grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();

	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}


Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &target) : name_(target.name_)
{
	grade_ = target.grade_;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &target)
{
	grade_ = target.grade_;
	return(*this);
}

std::string Bureaucrat::getName() const
{
	return (name_);
}

unsigned Bureaucrat::getGrade() const
{
	return (grade_);
}

void Bureaucrat::setIncreaseGrade()
{
	if (grade_ > 1)
		grade_--;
	else if (grade_ == 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::setDecreaseGrade()
{
	if (grade_ < 150)
		grade_++;
	else if (grade_ == 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cerr << *this << " cannot sign " << form << " because " << e.what() << std::endl;
	}
	std::cout << *this << " signs " << form << std::endl;
}

std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat &ref)
{
	outputStream << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return (outputStream);
}

