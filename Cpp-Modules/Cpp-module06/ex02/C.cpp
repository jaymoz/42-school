#include "C.hpp"

C::C(void) : Base()
{
}

C::~C(void)
{
}

C::C(const C &obj) : Base(obj)
{
	*this = obj;
}

C	&C::operator=(const C &rhs)
{
	(void)rhs;
	return *this;
}

Base	*C::build(void)
{
	return new C;
}
