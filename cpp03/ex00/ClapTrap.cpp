	#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
		: name(name) , hitPoints(10), energyPoints(10) , attackDamage(0)
{
	std::cout << "ClapTrap " << name << "'s constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & other) 
	: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints),
		attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap " << name << "'s copy constructor called" << std::endl;
}

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10) , attackDamage(0)
{
	std::cout << "ClapTrap " << name << "'s default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << "'s destructor called" << std::endl;
}


ClapTrap & ClapTrap::operator=(const ClapTrap & other)
{
	std::cout << "ClapTrap " << name << "'s copy assignment operator called" << std::endl;
	
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}


void ClapTrap::attack(const std::string& target)
{
	if ( hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << name << ": not enough hitPoints/energyPoints to attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " <<  name <<  " attacks " <<   target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ( hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << name << ": not enought hitPoints/energyPoints to repair" << std::endl;
		return ;
	}
	std::cout <<  "ClapTrap " << name << " repaired itself, gaining " << amount << " of hitPoints" << std::endl;
	hitPoints += amount;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout <<  "ClapTrap " << name << " took " << amount << " of damage" << std::endl;
	hitPoints -= amount;
}