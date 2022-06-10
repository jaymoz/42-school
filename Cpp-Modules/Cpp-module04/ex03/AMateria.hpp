#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		virtual ~AMateria(void);
		AMateria(const AMateria &obj);
		AMateria(const std::string &type);
		AMateria			&operator=(const AMateria &rhs);
		const std::string	&getType(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
		
	protected:
		std::string	_type;
};

#endif
