#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*position;

	position = NULL;
	while (*s)
	{
		if (*s == c)
		{
			position = (char *)s;
		}
		++s;
	}
	if (position)
		return (position);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
