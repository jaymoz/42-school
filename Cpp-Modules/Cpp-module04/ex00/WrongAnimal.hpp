#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
		std::string	type;
	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal(const WrongAnimal &other);

		WrongAnimal	&operator=(const WrongAnimal &other);

		std::string	getType(void) const;
		void		makeSound(void) const;

};

#endif