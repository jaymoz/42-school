/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:09:55 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:09:56 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*p_save_next;

	if (lst == NULL || del == NULL)
		return ;
	p = *lst;
	while (p != NULL)
	{
		p_save_next = p->next;
		del(p->content);
		free(p);
		p = p_save_next;
	}
	*lst = NULL;
}
