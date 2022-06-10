#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

Form::Form()
{
	isSigned_ = 0;
	requiredGrade_ = 0;
	executedGrade_ = 0;
}

Form::Form(std::string _FormName,int _requiredGrade, int _executedGrade)
{
	isSigned_ = 0;
	FormName_ = _FormName;
	if (_requiredGrade < 1 || _executedGrade < 1 )
		throw GradeTooHighException();
	else if (_requiredGrade > 150 || _executedGrade > 150 )
		throw GradeTooLowException();

	requiredGrade_ = _requiredGrade;
	executedGrade_ = _executedGrade;
}

Form::~Form()
{

}

Form::Form(const Form &target) {
	FormName_ = target.FormName_;
	isSigned_ = target.isSigned_;
	executedGrade_ = target.executedGrade_;
	requiredGrade_ = target.requiredGrade_;
}

Form &Form::operator=(const Form &target)
{
	FormName_ = target.FormName_;
	isSigned_ = target.isSigned_;
	executedGrade_ = target.executedGrade_;
	requiredGrade_ = target.requiredGrade_;
	return (*this);
}

std::string Form::getFormName() const
{
	return (FormName_);
}
bool Form::getIsSigned() const
{
	return (isSigned_);
}

int Form::getRequiredGrade() const
{
	return (requiredGrade_);
}

int Form::getExecuteGrade() const
{
	return (executedGrade_);
}

void Form::beSigned(Bureaucrat &target)
{
	if (target.getGrade() <= requiredGrade_ && target.getGrade() <= executedGrade_)
		isSigned_ = 1;
}

std::ostream	&operator<<(std::ostream &os, const Form &other)
{
	os << other.getFormName() << ", form is " << (other.getIsSigned() ? "" : "not ") << "signed (sign: " << other.getRequiredGrade() << ", exec: " << other.getExecuteGrade() << ")";
	return os;
}


