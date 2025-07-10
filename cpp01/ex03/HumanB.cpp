#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	weapon = NULL;
}

void	HumanB::setWeapon( Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (this->weapon)
	{
		std::cout << name << " attacks with their "	
			  << weapon->getType() << std::endl;
	}
}
