#include "minitalk.h"

static	int	ft_convert_to_binary(int c, int pid)
{
	int	i;
	int	status;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			status = kill(pid, SIGUSR2);
		else
			status = kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
	return (status);
}

static	void	ft_confirm_status(int status)
{
	if (status == 0)
		ft_putstr_fd("successfully sent!", 1);
	else
		ft_putstr_fd("There was an error!!", 1);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		pid;
	int		status;
	char	*line;

	i = 0;
	line = "\n";
	if (argc == 3)
	{
		ft_check_digit(argv[1]);
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			status = ft_convert_to_binary(argv[2][i], pid);
			i++;
		}
		while (*line)
		{
			status = ft_convert_to_binary(*line, pid);
			line++;
		}
		ft_confirm_status(status);
	}
	return (0);
}
