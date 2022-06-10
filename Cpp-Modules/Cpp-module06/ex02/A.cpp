#include "A.hpp"

A::A(void) : Base()
{
}

A::~A(void)
{
}

A::A(const A &obj) : Base(obj)
{
	*this = obj;
}

A	&A::operator=(const A &rhs)
{
	(void)rhs;
	return *this;
}

Base	*A::build(void)
{
	return new A;
}
