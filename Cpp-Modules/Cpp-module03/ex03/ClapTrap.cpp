#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("unknown"), _hitpoints(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap default  consstructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	*this = obj;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitpoints(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap (" << this->_name << ") constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != & rhs)
	{
		this->_name = rhs._name;
		this->_hitpoints = rhs._hitpoints;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}

	return *this;
}

const std::string	&ClapTrap::getName(void) const { return this->_name;}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " does not have enough energy points to attack..." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitpoints -= amount;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is already KO..." << std::endl;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " recovers " << amount << " points of damage!" << std::endl;
	this->_hitpoints += amount;
}
