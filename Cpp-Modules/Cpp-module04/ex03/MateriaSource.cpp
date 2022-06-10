#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _sources()
{
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < SOURCES_SIZE; i++)
		delete this->_sources[i];
}

MateriaSource::MateriaSource(const MateriaSource &obj) : _sources()
{
	*this = obj;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &rhs)
{
	(void)rhs;
	return *this;
}

void 	MateriaSource::learnMateria(AMateria *m)
{
	int	i;

	i = 0;
	while (i < SOURCES_SIZE && this->_sources[i] != NULL)
		i++;
	if (i >= SOURCES_SIZE)
		return ;
	this->_sources[i] = m;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	int	i;

	i = 0;
	while (i < SOURCES_SIZE && this->_sources[i] != NULL && this->_sources[i]->getType() != type)
		i++;
	if (i >= SOURCES_SIZE)
		return NULL;
	return this->_sources[i]->clone();
}

