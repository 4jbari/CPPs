#include "Zombie.hpp"

int main(){
	Zombie zombie1("zombie1");
	zombie1.announce();



	Zombie *zombie4 = newZombie("zombie4");
	zombie4->announce();
	delete zombie4;

	randomChump("zombie3");
}