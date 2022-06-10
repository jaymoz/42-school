#include "libft.h"

int	ft_tolower(int letter)
{
	if (letter >= 'A' && letter <= 'Z')
		letter += 32;
	return (letter);
}
