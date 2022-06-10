#include "../minitalk.h"

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
