#include "Bureaucrat.hpp"
#include "Form.hpp"


Bureaucrat::Bureaucrat() : name("default") , grade(150)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150 )
		throw  GradeTooLowException();
	if (grade < 1 )
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.getName())
{
	if (other.getGrade() > 150 )
		throw  GradeTooLowException();
	if (other.getGrade() < 1 )
		throw  GradeTooHighException();
	this->grade = other.grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return *this;
	if (other.getGrade() > 150 )
		throw  GradeTooLowException();
	if (other.getGrade() < 1 )
		throw  GradeTooHighException();
	grade = other.getGrade();
	return *this;
}

std::string Bureaucrat::getName() const
{
	return name;
}

int			Bureaucrat::getGrade() const 
{
	return (grade);
}

void		Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	this->grade--;
}

void		Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	this->grade++;
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;

}

void	Bureaucrat::signForm(Form& form) const 
{
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e){
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because  " << e.what() << std::endl;
	}


}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low";
}