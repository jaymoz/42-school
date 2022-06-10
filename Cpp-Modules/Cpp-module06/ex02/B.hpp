#ifndef B_HPP
# define B_HPP

# include <iostream>
# include "Base.hpp"

class B : public Base
{
	public:
		B(void);
		~B(void);
		B(const B &obj);

		B			&operator=(const B &rhs);

		static Base	*build(void);
};

#endif
