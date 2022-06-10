#include"Zombie.hpp"

int main() {
	
	Zombie*  newZom = newZombie( "Jaymos" );
	newZom->announce();
	randomChump( "jack" );

	delete newZom;
	return (0);
}