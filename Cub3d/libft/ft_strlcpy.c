/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:46:03 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 18:51:18 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (dest == NULL || src == NULL)
		return (0);
	len = ft_strlen(src);
	i = 0;
	if (size == 0 || src == NULL)
		return (len);
	while (*src && i++ < size - 1)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (len);
}
