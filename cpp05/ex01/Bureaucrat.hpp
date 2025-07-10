#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>


class Form;
class Bureaucrat
{
	private :
		const std::string	name;
		int 				grade;

	
	public 	:
		class GradeTooLowException;
		class GradeTooHighException;

		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);


		std::string getName()	const;
		int			getGrade()	const;
		void		incrementGrade();
		void		decrementGrade();
		
		void		signForm(Form& form) const ;


};

class  Bureaucrat::GradeTooLowException : public std::exception
{
	const char* what() const throw();
};


class  Bureaucrat::GradeTooHighException : public std::exception
{
	const char* what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif