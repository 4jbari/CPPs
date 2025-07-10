#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"



class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	name;
	public :
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
		void attack(const std::string& target);

		void whoAmI();

};


#endif