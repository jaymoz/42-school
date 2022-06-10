#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form()
{
	isSigned_ = 0;
	requiredGrade_ = 0;
	executedGrade_ = 0;
}

Form::Form(std::string _formName, const std::string _formTarget, int _requiredGrade, int _executedGrade)
{
	isSigned_ = 0;
	formName_ = _formName;
	if (_requiredGrade < 1 || _executedGrade < 1 )
		throw GradeTooHighException();
	else if (_requiredGrade > 150 || _executedGrade > 150 )
		throw GradeTooLowException();

	requiredGrade_ = _requiredGrade;
	executedGrade_ = _executedGrade;
	formTarget_ = _formTarget;
}

Form::~Form(){}

Form::Form(const Form &target)
{
	formName_ = target.formName_;
	isSigned_ = target.isSigned_;
	executedGrade_ = target.executedGrade_;
	requiredGrade_ = target.requiredGrade_;
}

Form &Form::operator=(const Form &target)
{
	if (this != &target)
	{
		formName_ = target.formName_;
		isSigned_ = target.isSigned_;
		executedGrade_ = target.executedGrade_;
		requiredGrade_ = target.requiredGrade_;
	}
	return (*this);
}

std::string Form::getFormName() const
{
	return (formName_);
}
bool Form::getIsSigned() const
{
	return (isSigned_);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* Form::IsnotSigned::what() const throw()
{
	return ("It's not signed");
}

const char* Form::LowGrade::what() const throw()
{
	return ("Grade is too low");
}
int Form::getRequiredGrade() const
{
	return (requiredGrade_);
}

int Form::getExecuteGrade() const
{
	return (executedGrade_);
}

std::string Form::getTarget() const
{
	return(formTarget_);
}

void Form::beSigned(Bureaucrat &target) {
	if (target.getGrade() <= requiredGrade_)
		isSigned_ = 1;
}

std::ostream	&operator<<(std::ostream &os, const Form &other)
{
	os << other.getFormName() << ", form is " << (other.getIsSigned() ? "" : "not ") << "signed (sign: " << other.getRequiredGrade() << ", exec: " << other.getExecuteGrade() << ")";
	return os;
}

