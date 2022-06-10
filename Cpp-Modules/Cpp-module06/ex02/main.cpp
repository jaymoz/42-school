#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	Base	*(*builders[3])(void);

	srand(time(NULL));
	builders[0] = A::build;
	builders[1] = B::build;
	builders[2] = C::build;
	return (builders[rand() % 3])();
}

void	identify(Base *p)
{
	A	*a = dynamic_cast<A *>(p);
	B	*b = dynamic_cast<B *>(p);
	C	*c = dynamic_cast<C *>(p);

	if (a != NULL)
		std::cout << "A" << std::endl;
	else if (b != NULL)
		std::cout << "B" << std::endl;
	else if (c != NULL)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try {
		A	a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
		
	}
	try {
		B	b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
		
	}
	try {
		C	c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
		
	}
}

int	main(void)
{
	Base	*base = new B;
	identify(base);
	identify(*base);
	delete base;
	return 0;

}
