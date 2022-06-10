#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain &other);
		Brain				&operator=(const Brain &other);
		const std::string	&getIdea(int index) const;
		void				setIdea(const std::string &idea, int index);

	private:
		std::string	_ideas[100];
};

#endif
