/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:12:04 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:12:05 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
