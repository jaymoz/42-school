#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	symb;

	result = 0;
	symb = 1;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\f')
		|| (str[i] == ' ') || (str[i] == '\r') || (str[i] == '\v'))
		i++;
	if (str[i] == '-')
		symb = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		result = result * 10 + ((int)str[i] - '0');
		i++;
	}
	return (symb * result);
}
