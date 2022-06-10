/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:46:03 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 18:51:19 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	n;
	size_t	dlen;
	char	*tmp;

	tmp = (char *)src;
	dlen = ft_strlen(dst);
	if (size <= dlen)
		return (size + ft_strlen(src));
	n = size - dlen;
	while (*dst)
		dst++;
	while (*tmp)
	{
		if (n != 1)
		{
			*dst++ = *tmp;
			n--;
		}
		tmp++;
	}
	*dst = '\0';
	return (dlen + ft_strlen(src));
}
