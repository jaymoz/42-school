#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		~Ice(void);
		Ice(const Ice &obj);

		Ice					&operator=(const Ice &other);

		virtual AMateria	*clone(void) const;
		void				use(ICharacter &target);
};

#endif
