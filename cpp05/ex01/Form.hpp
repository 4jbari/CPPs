#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;
class Form
{
	private :

		const std::string	name;
		bool				isSigned;
		const int					gradeToSign;
		const int					gradeToExecute;
	
	public :
		Form();
		~Form();
		Form(std::string name, int gtsGiven, int gteGiven);
		Form(const Form& other);

		Form& operator=(const Form& other);

		class GradeTooHighException : public std::exception{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			const char* what() const throw();
		};

		std::string	getName() const;
		int			getGradeToSign() const;
		int 		getGradeToExecute() const;
		bool		getStatus() const;
		void	beSigned(const Bureaucrat& bureaucrat);

};

std::ostream& operator<<(std::ostream& os, const Form& form);



#endif