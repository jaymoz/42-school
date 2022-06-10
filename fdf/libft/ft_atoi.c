#include "libft.h"

static void	ft_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_atoi(char *str)
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

int	ft_atoi_push(char *str)
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
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			ft_err();
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (symb * result > 2147483647 || symb * result < -2147483648
		|| (symb == -1 && result == 0))
		ft_err();
	return (symb * result);
}
