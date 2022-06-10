/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:11:39 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:11:40 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	rsl;

	i = ft_strlen(dest);
	rsl = ft_strlen((char *)src);
	j = 0;
	if (size == 0)
		return (rsl);
	if (size < i)
		rsl += size;
	else
		rsl += i;
	while (src[j] != '\0' && i < size - 1 && dest != src)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (rsl);
}
