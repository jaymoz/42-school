#include "Array.hpp"
#include <iostream>

int	main(void)
{
	{
		Array<int> arr;
	}
	{
		Array<int>	arr(5);
		arr[0] = 42;
		std::cout << arr[0] << std::endl;
		arr[1] = 1337;
		std::cout << arr[1] << std::endl;
		arr[2] = 0;
		std::cout << arr[2] << std::endl;
		arr[3] = 100;
		std::cout << arr[3] << std::endl;
		arr[4] = 21;
		std::cout << arr[4] << std::endl;
		try
		{
			arr[5] = -42;
			std::cout << arr[5] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		Array<int>	new_arr(arr);
		new_arr[0] = 5;
		std::cout << new_arr[0] << " vs " << arr[0] << std::endl;
	}
	return 0;
}