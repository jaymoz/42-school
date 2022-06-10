#ifndef A_HPP
# define A_HPP

# include <iostream>
# include "Base.hpp"

class A : public Base
{
	public:
		A(void);
		~A(void);
		A(const A &obj);

		A			&operator=(const A &rhs);

		static Base	*build(void);
};

#endif
