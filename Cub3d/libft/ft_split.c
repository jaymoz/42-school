/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:46:03 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 18:51:34 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_w(char const *s, char c)
{
	size_t	n;
	int		i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (c != s[i])
		{
			n++;
			while (s[i] && c != s[i])
				i++;
		}
		else
			i++;
	}
	return (n);
}

static void	ft_strcpy(char *dest, char *s1, char *s2)
{
	while (s1 < s2)
	{
		*dest = *s1;
		dest++;
		s1++;
	}
	*dest = 0;
}

char	**ft_free(char **s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*tmp;
	size_t	i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * (count_w(s, c) + 1));
	if (!s || str == NULL)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			tmp = (char *)s;
			while (*s && *s != c)
				s++;
			str[i] = (char *)malloc((s - tmp) + 1);
			if (str[i] == NULL)
				return (ft_free(str));
			ft_strcpy(str[i++], tmp, (char *)s);
		}
		else
			s++;
	}
	str[i] = 0;
	return (str);
}
