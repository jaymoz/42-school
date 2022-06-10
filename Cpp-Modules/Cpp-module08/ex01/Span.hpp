#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <climits>
#include <algorithm>

class Span
{
private:
	unsigned int n;
	std::vector<int> vec;
	Span();
public:
	Span(unsigned int _n);
	~Span();
	Span(const Span &_span);
	Span &operator=(const Span &_span);

	void addNumber(int n);
	void addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);
	int shortestSpan(void);
	int longestSpan(void);

	class SpanIsFullException : public std::exception
	{
		virtual const char *what() const throw(){return "Already contains maximum number of elements"; }
	};

	class NotEnoughElementException : public std::exception
	{
		virtual const char *what() const throw() {return "Not enough elements";}
	};
};

#endif 