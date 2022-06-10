#include "minitalk_bonus.h"

static void	ft_put_char(char c)
{
	write(1, &c, 1);
}

static int	ft_convert_to_decimal(char *binary)
{
	int	i;
	int	number;
	int	base;

	i = 7;
	number = 0;
	base = 1;
	while (i >= 0)
	{
		if (binary[i] == '1')
			number = number + base;
		base = base * 2;
		i--;
	}
	return (number);
}

static void	ft_process_signal(int signum)
{
	static char	*binary;

	if (binary == NULL)
		binary = ft_strdup("");
	if (signum == SIGUSR2)
		binary = ft_strjoin(binary, "1\0");
	if (signum == SIGUSR1)
		binary = ft_strjoin(binary, "0\0");
	if (ft_strlen(binary) == 8)
	{
		ft_put_char(ft_convert_to_decimal(binary));
		free(binary);
		binary = NULL;
	}
}

int	main(void)
{
	pid_t				pid;
	char				*id;
	struct sigaction	sa;

	sa.sa_handler = &ft_process_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	id = ft_itoa(pid);
	ft_putstr_fd("PID = ", 1);
	ft_putstr_fd(id, 1);
	ft_putstr_fd("\n", 1);
	free(id);
	while (1)
		pause();
	return (0);
}
