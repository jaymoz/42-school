/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:35:40 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 19:12:48 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	print_err(int err_no)
{
	printf("ERROR : ");
	if (err_no == INVALID_ARG)
		return (printf("Invalid argument\n"));
	else if (err_no == OPEN_ERR)
		return (printf("Failed to open the file\n"));
	else if (err_no == INVALID_ELEMENT)
		return (printf("Invalid element in the file\n"));
	else if (err_no == NOENOUGH_ELEMENT)
		return (printf("Not enough element in the file\n"));
	else if (err_no == ALLOC_ERR)
		return (printf("Allocated error\n"));
	else if (err_no == INVALID_MAP)
		return (printf("Invalid map\n"));
	else if (err_no == INVALID_FILE)
		return (printf("Inavalid file\n"));
	else if (err_no == NONE_PLAYER)
		return (printf("No player found\n"));
	else if (err_no == TOO_MANY_PLAYER)
		return (printf("Too many player\n"));
	return (0);
}
