#include "Character.hpp"

Character::Character(void) : _name("personnage"), _inventory()
{
}

Character::~Character(void)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		delete this->_inventory[i];
}

Character::Character(const Character &obj) : _name(), _inventory()
{
	*this = obj;
}

Character::Character(const std::string &name) : _name(name), _inventory()
{
}

Character	&Character::operator=(const Character &rhs)
{
	this->_name = rhs._name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		delete this->_inventory[i];
		if (rhs._inventory[i] != NULL)
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
	return *this;
}

const std::string	&Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	int	i;

	i = 0;
	while (i < INVENTORY_SIZE && this->_inventory[i] != NULL)
		i++;
	if (i >= INVENTORY_SIZE)
		return ;
	this->_inventory[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
		return ;
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < INVENTORY_SIZE && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}
