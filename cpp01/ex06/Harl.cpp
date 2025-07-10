#include "Harl.hpp"


void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}


void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."  << std::endl;
	
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now."  << std::endl;

}


void Harl::complain( std::string level )
{
	std::string msg[4];
	msg[0] = "DEBUG";
	msg[1] = "INFO";
	msg[2] = "WARNING";
	msg[3] = "ERROR";
	int i = 0;
	while ( i < 4 && level != msg[i])
		i++;
	switch (i)
	{
		case (0):
			std::cout << "[ DEBUG ]" << std::endl;
			debug();
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			info();
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			warning();
			std::cout << std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			error();
			std::cout << std::endl;
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
