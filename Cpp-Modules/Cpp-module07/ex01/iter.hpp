#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T *arr, size_t len, void (*fct)(T &))
{
	for (size_t i = 0; i < len; i++)
		fct(arr[i]);
}

#endif