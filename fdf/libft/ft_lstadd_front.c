#include "libft.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if ((*lst) != NULL)
	{
		(*lst)->prev = new;
		new -> prev = NULL;
		new -> next = (*lst);
		(*lst) = new;
	}
	else
	{
		new -> next = NULL;
		new -> prev = NULL;
		(*lst) = new;
	}
}
