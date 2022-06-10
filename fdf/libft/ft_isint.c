#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

static	int	ft_minus(char *s)
{
	if (ft_strcmp(SINT_MIN, s) < 0)
		return (FALSE);
	else
		return (TRUE);
}

static int	ft_plus(char *s)
{
	if (ft_strcmp(SINT_MAX_P, s) < 0)
		return (FALSE);
	else
		return (TRUE);
}

int	ft_isint(char *s)
{
	int	str_len;

	if (!s || !*s)
		return (FALSE);
	str_len = ft_strlen(s);
	if (str_len > 11 || !ft_isnum(s))
		return (FALSE);
	if (str_len == 10)
	{
		if (*s == '-' || *s == '+')
			return (TRUE);
		else if (ft_strcmp(SINT_MAX, s) < 0)
			return (FALSE);
	}
	if (str_len == 11)
	{
		if (*s == '-')
			ft_minus(s);
		else if (*s == '+')
			ft_plus(s);
		else
			return (FALSE);
	}
	return (TRUE);
}
