#include "Span.hpp"

Span::Span(unsigned int _n)	: n(_n) { }

Span::~Span(){ }

Span::Span(const Span &_span) { *this = _span;}

Span &Span::operator=(const Span &_span)
{
	if (this == &_span)
		return (*this);
	this->n = _span.n;
	this->vec.clear();
	this->vec.assign(_span.vec.begin(), _span.vec.end());
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->vec.size() < this->n)
		this->vec.push_back(n);
	else
		throw Span::SpanIsFullException();
}

void Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	int len = end - begin - 1;
	if (this->vec.size() + len < this->n)
	{
		for (std::vector<int>::iterator iter = begin; iter < end; iter++)
			this->vec.push_back(*iter);
	}
	else
		throw Span::SpanIsFullException();
}

int Span::shortestSpan(void)
{
	if (this->vec.size() == 0 || this->vec.size() == 1)
		throw Span::NotEnoughElementException();
	std::sort(this->vec.begin(), this->vec.end());
	int min = INT_MAX;
	for (unsigned long i = 1; i < this->vec.size(); i++)
	{
		if (min > this->vec[i] - this->vec[i - 1])
			min = this->vec[i] - this->vec[i - 1];
	}
	return (min);
}

int Span::longestSpan(void)
{
	if (this->vec.size() == 0 || this->vec.size() == 1)
		throw Span::NotEnoughElementException();
	std::sort(this->vec.begin(), this->vec.end());
	return (vec[vec.size() - 1] - vec[0]);
}
