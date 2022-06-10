#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm","none", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : Form("ShrubberyCreationForm", _target, 145, 137){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreationForm){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ShrubberyCreationForm){ return (*this);}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor)
{
	if (!this->getIsSigned())
		throw Form::IsnotSigned();
	if (executor.getGrade() > this->getExecuteGrade())
		throw Form::GradeTooLowException();
	std::ofstream	ofs((Form::getTarget() + "_shrubbery").c_str());
	if (!ofs)
	{
		std::cerr << "An error occured while opening the file..." << std::endl;
		return ;
	}
	ofs << "            ,@@@@@@@," << std::endl;
	ofs << "    ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	ofs << " ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	ofs << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	ofs << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	ofs << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	ofs << "`&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	ofs << "    |o|        | |         | |" << std::endl;
	ofs << "    |.|        | |         | |" << std::endl;
	ofs << " \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	ofs.close();
}
