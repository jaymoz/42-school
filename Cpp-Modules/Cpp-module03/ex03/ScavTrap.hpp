#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		~ScavTrap(void);
		ScavTrap(const ScavTrap &obj);
		ScavTrap(const std::string &name);

		ScavTrap	&operator=(const ScavTrap &rhs);

		void		attack(const std::string &target);
		void		guardGate(void);
};

#endif
