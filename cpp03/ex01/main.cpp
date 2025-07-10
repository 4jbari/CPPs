#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("4rbi");
	a.attack("enemy");
	a.takeDamage(10);
	a.attack("enemy");
	// a.beRepaired(1);
	a.takeDamage(90);
	a.attack("enemy");

}