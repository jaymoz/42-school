#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		std::string FormName_;
		bool isSigned_;
		int requiredGrade_;
		int executedGrade_;
	public:
		Form();
		Form(std::string _FormName,int _requiredGrade, int _executedGrade);
		virtual ~Form();
		Form(const Form &target);
		Form &operator=(const Form &target);
		void beSigned(Bureaucrat &target);

		std::string getFormName() const;
		bool getIsSigned() const;
		int getRequiredGrade() const;
		int getExecuteGrade() const;

		class GradeTooHighException : public std::exception {
		public:
			const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			const char *what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Form &other);


#endif
