#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try{
		Form a("attack", 150, 2);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try {
		Form a("attack", 1, 2);
		Bureaucrat trump("trump", 1);
		trump.signForm(a);
		std::cout << a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try {
		Form a("attack", 1, 1);
		const Bureaucrat trump("trump", 2);
		trump.signForm(a);
		std::cout << a << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}