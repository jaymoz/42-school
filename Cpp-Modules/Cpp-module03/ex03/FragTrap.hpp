#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		~FragTrap(void);
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &obj);

		FragTrap	&operator=(const FragTrap &rhs);

		void		attack(const std::string &target);
		void		highFivesGuys(void);
};

#endif
