#include "libft.h"

int	ft_isascii(int check)
{
	if (check >= 0 && check <= 127)
		return (1);
	return (0);
}
