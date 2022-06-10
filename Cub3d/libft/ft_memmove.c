/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:46:03 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 18:51:39 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t size)
{
	int				i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dest;

	tmp_src = (unsigned char *)src;
	tmp_dest = (unsigned char *)dest;
	if (tmp_src == tmp_dest || size == 0)
		return (dest);
	if (tmp_dest > tmp_src && tmp_dest - tmp_src < (int)size)
	{
		i = (int)size;
		while (--i >= 0)
			tmp_dest[i] = tmp_src[i];
	}
	else if (tmp_src > tmp_dest && tmp_src - tmp_dest < (int)size)
	{
		i = -1;
		while (++i < (int)size)
			tmp_dest[i] = tmp_src[i];
	}
	else
		ft_memcpy(dest, src, size);
	return (dest);
}
