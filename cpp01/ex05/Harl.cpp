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
	void (Harl::*func[4]) ( void );
	func [0] = &Harl::debug;
	func [1] = &Harl::info;
	func [2] = &Harl::warning;
	func [3] = &Harl::error;
	int i = 0;
	while (i < 4 && level != msg[i])
		i++;
	if ( i < 4 && level == msg[i])
		(this->*func[i])();
}
