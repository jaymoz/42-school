#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Unknown_clap_name"), FragTrap("unknown FragTrap"), ScavTrap("unknown ScavTrap"), _name("Unknown DiamondTrap")
{
	std::cout << "DiamonTrap default constructor called "  << std::endl;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj), _name(obj._name)
{
	*this = obj;
	std::cout << "DiamonTrap copy constructor called " << std::endl;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamonTrap (" << this->_name << ") constructor called"  << std::endl;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitpoints = rhs._hitpoints;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}

	return *this;
}

void	DiamondTrap::attack(const std::string &target) { ScavTrap::attack(target);}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "ClapTrap: " << this->ClapTrap::_name << "   DiamondTrap: " << this->_name << std::endl;
}