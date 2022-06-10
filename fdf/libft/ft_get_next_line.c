#include "libft.h"

char	*copy_uptil_new_line(char *remainder)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!remainder)
		return (0);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (0);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		new_line[i] = remainder[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int	find_new_line(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_remainder(char *remainder)
{
	int		i;
	char	*new;
	int		j;

	i = 0;
	j = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\0')
	{
		free(remainder);
		return (0);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(remainder + i + 1)) + 1);
	if (!new)
		return (NULL);
	i++;
	while (remainder[i] != '\0')
	{
		new[j++] = remainder[i++];
	}
	new[j] = '\0';
	free(remainder);
	return (new);
}

int	get_next_line(int fd, char **line)
{
	char			*buf;
	int				read_data;
	static char		*remainder;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_data = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0 || !buf)
		return (-1);
	while (!(find_new_line(remainder)) && read_data != 0)
	{
		read_data = read(fd, buf, BUFFER_SIZE);
		if (read_data == -1)
		{
			free(buf);
			return (-1);
		}
		buf[read_data] = '\0';
		remainder = ft_strjoin(remainder, buf);
	}
	free(buf);
	*line = copy_uptil_new_line(remainder);
	remainder = get_remainder(remainder);
	if (read_data == 0)
		return (0);
	return (1);
}
