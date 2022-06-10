#include "libft.h"

int	ft_isnum(char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
		{
			if (i == 0 && s[++i])
				;
			else
				return (0);
		}
		if (!ft_isdigit(s[i]))
			return (0);
		++i;
	}
	return (1);
}
