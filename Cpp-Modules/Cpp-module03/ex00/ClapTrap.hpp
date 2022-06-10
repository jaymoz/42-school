#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	private:
		std::string			_name;
		int					_hitpoints;
		int					_energy_points;
		int					_attack_damage;
	public:
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(const ClapTrap &obj);
		ClapTrap(const std::string &name);

		ClapTrap			&operator=(const ClapTrap &rhs);

		const std::string	&getName(void) const;
		void				attack(const std::string &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

};

#endif
