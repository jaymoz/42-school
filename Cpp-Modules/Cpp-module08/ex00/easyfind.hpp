#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

class NotFound : public std::exception
{
	virtual const char *what() const throw() { return ("Not Found!!!"); }
};

template <typename T> 
int &easyfind(T &container, int n)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), n);

	if (iter == container.end())
		throw NotFound();
	
	return (*iter);
}

#endif
