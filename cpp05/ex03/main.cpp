#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main()
{
	std::srand(time(NULL));
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat someExecutor("someExecutor", 1);
		someExecutor.signForm(*rrf);
		someExecutor.executeForm(*rrf);
		delete rrf;
	}
	{
		Intern hamza;
		AForm *someForm = hamza.makeForm("shrubbery creation", "john");
		std::cout << *someForm << std::endl;
		Bureaucrat a("somone", 2);
		a.signForm(*someForm);
		a.executeForm(*someForm);
		delete someForm;
		std::cout << std::endl;
	}
	{
		Intern hamza;
		AForm *someForm = hamza.makeForm("independence", "john");
		std::cout << someForm << std::endl;
	}
}