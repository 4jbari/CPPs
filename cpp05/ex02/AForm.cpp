#include "Bureaucrat.hpp"
#include "AForm.hpp"


const char* AForm::GradeTooHighException::what() const throw(){
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw(){
	return ("Grade too low");
}


AForm::AForm() : name ("default"), isSigned(0), gradeToSign(150), gradeToExecute(150)
{}

AForm::~AForm()
{}

AForm::AForm(std::string name, int gtsGiven, int gteGiven) : name(name), 	gradeToSign(gtsGiven), gradeToExecute(gteGiven)
{
	if (gtsGiven > 150 || gteGiven > 150  )
		throw GradeTooLowException();
	if (gtsGiven < 1 || gteGiven < 1)
		throw GradeTooHighException();

	isSigned = 0;
}

AForm::AForm(const AForm& other) : name(other.getName()) , gradeToSign(other.getGradeToSign()), gradeToExecute (other.getGradeToExecute())
{

	if (other.getGradeToExecute() > 150 || other.getGradeToSign() > 150  )
		throw GradeTooLowException();
	if (other.getGradeToSign() < 1 || other.getGradeToExecute() < 1)
		throw GradeTooHighException();
	
	isSigned = other.isSigned;
}

AForm& AForm::operator=(const AForm& other)
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

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm :" << form.getName() << ", gradeToSign :" <<  form.getGradeToSign()
	 << ", gradeToExecute :" << form.getGradeToExecute() << ", is it signed :" << std::boolalpha  << form.getStatus();
	return (os);
}

std::string	AForm::getName() const 
{
	return name;
}

int		AForm::getGradeToSign() const 
{
	return gradeToSign;
}

int		AForm::getGradeToExecute() const 
{
	return gradeToExecute;
}

bool	AForm::getStatus() const 
{
	return isSigned;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if ( gradeToSign < bureaucrat.getGrade() )
		throw GradeTooLowException();
	isSigned = true;
}


void 	AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	else if (!this->isSigned)
		throw FormIsNotSigned();
}

const char* AForm::FormIsNotSigned::what() const throw()
{
	return ("Form is not signed");
}
