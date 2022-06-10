#include "get_next_line.h"

char	*ft_strchr(char *str, int symbol)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == symbol)
			return ((char *)&str[i]);
		i++;
	}
	if (symbol == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(char *src)
{
	int			i;
	int			len;
	char		*str;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (src && (i < len))
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	char		*letter;

	i = 0;
	if (s1 == NULL)
	{
		return (ft_strdup(s2));
	}
	letter = (char *)malloc(sizeof(char)
			*(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!letter)
		return (NULL);
	while (s1[i])
	{
		letter[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
	{
		letter[i] = *s2++;
		i++;
	}
	letter[i] = '\0';
	return (letter);
}
