#include "Zombie.hpp"

int main(){
	int N = 10;

	Zombie *Horde = zombieHorde(N, "3ashira");
	for (int i = 0; i < N; i++ )
	{
		Horde[i].announce();
	}
	delete[] Horde;
}