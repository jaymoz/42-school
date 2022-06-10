#include "libft.h"

int	ft_toupper(int letter)
{
	if (letter >= 'a' && letter <= 'z')
		letter -= 32;
	return (letter);
}
