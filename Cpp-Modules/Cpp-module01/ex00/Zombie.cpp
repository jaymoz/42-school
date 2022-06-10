#include"Zombie.hpp"

Zombie::Zombie( void ) {}

Zombie::~Zombie( void ) {

	std::cout << this->name << " Zombie has been killed" << std::endl;
}

void	Zombie::setName( std::string Name ) {this->name = Name;}

void	Zombie::announce( void ) {

	std::cout << this->name <<  " BraiiiiiiinnnzzzZ..." << std::endl;
}