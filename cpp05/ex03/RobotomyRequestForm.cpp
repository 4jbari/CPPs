#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target ("Default")
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	target = other.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	target = other.target;
	return (*this);

}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);

	bool success  = std::rand() % 2;
	if (success)
		std::cout << "Vrrrrrrrr... " << target << " has been robotomized successfully." << std::endl;
	else 
		std::cout << "Vrrrrrrrr... " << "the robotomy on " << target << " failed." << std::endl;
}

