#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		~Cure(void);
		Cure(const Cure &obj);

		Cure	&operator=(const Cure &other);
		virtual AMateria	*clone(void) const;
		void				use(ICharacter &target);
};

#endif
