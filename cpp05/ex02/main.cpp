#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
	std::srand(time(NULL));
	{
		Bureaucrat trump("trump", 5);
		PresidentialPardonForm a("hamza");
		trump.signForm(a);
		trump.executeForm(a);
	}

	{
		Bureaucrat trump("trump", 45);
		RobotomyRequestForm a("hamza");
		trump.signForm(a);
		trump.executeForm(a);
	}

	{
		Bureaucrat trump("trump", 1);
		ShrubberyCreationForm a("hamza");
		trump.signForm(a);
		trump.executeForm(a);
	}
}