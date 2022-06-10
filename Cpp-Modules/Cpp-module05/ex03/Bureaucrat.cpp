#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "High Grade maximum is 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "low Grade maximum is 1";
}

Bureaucrat::Bureaucrat()
{
	grade_ = 0;
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name_(_name), grade_(_grade)
{
	if (_grade < 1)
		throw GradeTooHighException();

	else if (_grade > 150)
		throw GradeTooLowException();
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
		throw GradeTooHighException();
}

void Bureaucrat::setDecreaseGrade()
{
	if (grade_ < 150)
		grade_++;
	else if (grade_ == 150)
		throw GradeTooLowException();
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


void Bureaucrat::executeForm(Form const &form)
{
	if (grade_ >= form.getExecuteGrade())
	{
		std::cout << name_ << " cannot sign " << form.getFormName() << " because ";
		std::cout << "execute grade is low.";
	}
	else
	{
		std::cout << name_ << " executes " << form.getFormName() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat &ref)
{
	outputStream << ref.getName() << ", grade : " << ref.getGrade();
	return (outputStream);
}

