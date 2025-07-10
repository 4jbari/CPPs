#include "Bureaucrat.hpp"


int main()
{
	Bureaucrat	John;
	try {
		John = Bureaucrat("john", 1);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try {
		John.incrementGrade();
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << John << std::endl;



	Bureaucrat Alex;
	try {
		Alex = Bureaucrat("Alex", 1500);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try {
		Alex.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << Alex << std::endl;


}