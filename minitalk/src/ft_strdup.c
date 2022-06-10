#include "../minitalk.h"

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
