#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap("Default"), FragTrap("Default")
{
	name = "Default";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << name << "'s default constructor called" << std::endl;
	
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << "'s destructor called" << std::endl;
}

// Parameter constructor
DiamondTrap::DiamondTrap(std::string name)  
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << name << "'s constructor called" << std::endl;

}

// Copy constructor 
DiamondTrap::DiamondTrap(const DiamondTrap& other) 
	: ClapTrap(other.ClapTrap::name), ScavTrap(other.name), FragTrap(other.name)
{
	this->name = other.name;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << name << "'s copy constructor called" << std::endl;

}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap " << name << "'s copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::name = other.ClapTrap::name;
		name = other.name;
		hitPoints = FragTrap::hitPoints;
		energyPoints = ScavTrap::energyPoints;
		attackDamage = FragTrap::attackDamage;
	}
	return (*this);
}


void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}


void DiamondTrap::whoAmI()
{
	std::cout << "my name      :" << name << std::endl;
	std::cout << "ClapTrap name:" << ClapTrap::name << std::endl;
}
