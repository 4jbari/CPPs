#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;

	std::cout << "ScavTrap " << name << "'s default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << "'s destructor called" << std::endl;
}


ScavTrap::ScavTrap(std::string name)
		: ClapTrap(name) 
{

	energyPoints = 50;

	std::cout << "ScavTrap " << name << "'s constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & other) 
	: ClapTrap(other.name)
{
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;

	std::cout << "ScavTrap " << name << "'s copy constructor called" << std::endl;
}



ScavTrap & ScavTrap::operator=(const ScavTrap & other)
{
	std::cout << "ScavTrap " << name << "'s copy assignment operator called" << std::endl;
	
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}


void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
	if ( hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ScavTrap " << name <<  ": not enough hitPoints/energyPoints to attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " <<  name <<  " attacks " <<   target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

