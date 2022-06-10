#include "libft.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = new;
			(*lst)->next = NULL;
			(*lst)->prev = NULL;
		}
		else
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
			new -> prev = tmp;
			new -> next = NULL;
		}
	}
}
