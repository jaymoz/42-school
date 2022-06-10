#include "libft.h"

void	ft_lstclear(t_stack **ptr_lst)
{
	t_stack	*temp;

	if (!ptr_lst || !*ptr_lst)
		return ;
	while (*ptr_lst)
	{
		temp = (*ptr_lst)->next;
		free(*ptr_lst);
		*ptr_lst = temp;
	}
	return ;
}
