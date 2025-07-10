#include "Intern.hpp"



Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{

	(void)other;
	return (*this);
}


AForm*  Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm* newForm = NULL;

	int i = 0;
	while (i < 3 && forms[i] != name)
		i++;
	switch (i)
	{
		case(0):
			newForm = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << "PresidentialPardonForm" << std::endl; 
			break;
		case(1):
			newForm = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << "RobotomyRequestForm" << std::endl; 
			break;
		case(2):
			newForm = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << "ShrubberyCreationForm" << std::endl; 
			break;
		default:
			std::cerr << "no form found with the name :" << name << std::endl;
	}
	return newForm;

}
