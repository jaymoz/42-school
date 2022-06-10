#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# define SOURCES_SIZE 4

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(const MateriaSource &obj);

		MateriaSource		&operator=(const MateriaSource &rhs);

		virtual void 		learnMateria(AMateria *m);
		virtual AMateria	*createMateria(const std::string &type);

	private:
		AMateria	*_sources[SOURCES_SIZE];
};

#endif
