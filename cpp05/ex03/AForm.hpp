#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;
class AForm
{
	private :

		const std::string	name;
		bool				isSigned;
		const int					gradeToSign;
		const int					gradeToExecute;
	
	public :
		AForm();
		virtual ~AForm();
		AForm(std::string name, int gtsGiven, int gteGiven);
		AForm(const AForm& other);

		AForm& operator=(const AForm& other);

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


		virtual void execute(Bureaucrat const & executor) const = 0;
		
		class FormIsNotSigned : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);



#endif