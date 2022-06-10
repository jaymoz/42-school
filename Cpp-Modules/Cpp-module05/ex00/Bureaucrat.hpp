#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {

private:
	const std::string name_ ;
	int grade_;
public:
	Bureaucrat();
	Bureaucrat(const std::string _name, int _grade);

	virtual ~Bureaucrat();

	Bureaucrat(const Bureaucrat &target);

	Bureaucrat &operator=(const Bureaucrat &target);

	std::string getName() const;
	unsigned getGrade() const;
	void setIncreaseGrade();
	void setDecreaseGrade();

	class GradeTooHighException : public std::exception {
	public:
		const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what(void) const throw();
	};

};

std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat &ref);

#endif
