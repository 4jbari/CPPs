#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;

	std::cout << "FragTrap " << name << "'s default constructor called" << std::endl;

}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << "'s destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << "'s constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other.name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;

	std::cout << "FragTrap " << name << "'s copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{

	std::cout << "FragTrap " << name << "'s copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}


void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " says :GIVE ME A HIGH FIVE!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if ( hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "FragTrap " << name <<  ": not enough hitPoints/energyPoints to attack" << std::endl;
		return ;
	}
	std::cout << "FragTrap " <<  name <<  " attacks " <<   target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

