#include "../minitalk.h"

void	ft_check_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] > '/' && s[i] < ':') && s[i] != '+' && s[i] != '-')
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd(s, 2);
			ft_putstr_fd("PID isn't an integer \n", 2);
			exit(1);
		}
		i++;
	}
}
