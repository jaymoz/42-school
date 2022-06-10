#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) 
{
	ScavTrap clown("clown");
	FragTrap goatman("goatman");

	clown.attack("goatman");
	goatman.takeDamage(50);
	goatman.takeDamage(2);
	goatman.beRepaired(2);
	clown.takeDamage(50);
	goatman.attack("clown");
	goatman.attack("clown");
	goatman.attack("clown");
	goatman.attack("clown");
	clown.guardGate();
	goatman.highFivesGuys();
	return 0;
}