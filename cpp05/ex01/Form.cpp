#include "Bureaucrat.hpp"
#include "Form.hpp"


const char* Form::GradeTooHighException::what() const throw(){
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw(){
	return ("Grade too low");
}


Form::Form() : name ("default"), isSigned(0), gradeToSign(150), gradeToExecute(150)
{}

Form::~Form()
{}

Form::Form(std::string name, int gtsGiven, int gteGiven) : name(name), 	gradeToSign(gtsGiven), gradeToExecute(gteGiven)
{
	if (gtsGiven > 150 || gteGiven > 150  )
		throw GradeTooLowException();
	if (gtsGiven < 1 || gteGiven < 1)
		throw GradeTooHighException();

	isSigned = 0;
}

Form::Form(const Form& other) : name(other.getName()) , gradeToSign(other.getGradeToSign()), gradeToExecute (other.getGradeToExecute())
{

	if (other.getGradeToExecute() > 150 || other.getGradeToSign() > 150  )
		throw GradeTooLowException();
	if (other.getGradeToSign() < 1 || other.getGradeToExecute() < 1)
		throw GradeTooHighException();
	
	isSigned = other.isSigned;
}

Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return *this;

	if (other.getGradeToExecute() > 150 || other.getGradeToSign() > 150  )
		throw GradeTooLowException();
	if (other.getGradeToSign() < 1 || other.getGradeToExecute() < 1)
		throw GradeTooHighException();

	isSigned = other.isSigned;

	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form :" << form.getName() << ", gradeToSign :" <<  form.getGradeToSign()
	 << ", gradeToExecute :" << form.getGradeToExecute() << ", is it signed :" << std::boolalpha  << form.getStatus();
	return (os);
}

std::string	Form::getName() const 
{
	return name;
}

int		Form::getGradeToSign() const 
{
	return gradeToSign;
}

int		Form::getGradeToExecute() const 
{
	return gradeToExecute;
}

bool	Form::getStatus() const 
{
	return isSigned;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if ( gradeToSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	isSigned = true;
}
