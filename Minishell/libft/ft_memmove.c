/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:10:42 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:10:42 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr1;

	if (!dst && !src)
		return (NULL);
	ptr = (unsigned char *)dst;
	ptr1 = (unsigned char *)src;
	i = 0;
	if (ptr1 < ptr)
		while (++i <= len)
			ptr[len - i] = ptr1[len - i];
	else
		while (len-- > 0)
			*(ptr++) = *(ptr1++);
	return (dst);
}
