#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# define INVENTORY_SIZE 4

# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character(void);
		~Character(void);
		Character(const Character &obj);
		Character(const std::string &name);

		Character			&operator=(const Character &rhs);

		const std::string	&getName() const;
		void				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);

	private:
		std::string	_name;
		AMateria	*_inventory[INVENTORY_SIZE];
};

#endif
