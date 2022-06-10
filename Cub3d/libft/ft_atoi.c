/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:45:56 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 18:45:58 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str, int *n)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	else if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '\0')
		return (-1);
	while (str[i] && ft_isdigit(str[i]))
		nbr = nbr * 10 + (str[i++] - '0');
	if (i == 0 || (str[i] && !ft_isdigit(str[i])))
		return (-1);
	*n = nbr * sign;
	return (i);
}
