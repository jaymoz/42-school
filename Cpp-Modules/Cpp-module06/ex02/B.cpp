#include "B.hpp"

B::B(void) : Base()
{
}

B::~B(void)
{
}

B::B(const B &obj) : Base(obj)
{
	*this = obj;
}

B	&B::operator=(const B &rhs)
{
	(void)rhs;
	return *this;
}

Base	*B::build(void)
{
	return new B;
}
