#ifndef C_HPP
# define C_HPP

# include <iostream>
# include "Base.hpp"

class C : public Base
{
	public:
		C(void);
		~C(void);
		C(const C &obj);

		C			&operator=(const C &rhs);

		static Base	*build(void);
};

#endif
