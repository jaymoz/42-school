#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != c)
	{
		if (!*ptr)
		{
			return (NULL);
		}
		ptr++;
	}
	return (ptr);
}
