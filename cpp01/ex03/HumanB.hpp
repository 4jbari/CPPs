#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB{

	public :


		void	setWeapon( Weapon& weapon);
		void	attack();
		HumanB(std::string name);

	private :
		std::string		name;
		Weapon*			weapon;

};

#endif
