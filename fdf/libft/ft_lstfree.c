#include "libft.h"

void	ft_lstfree(t_stack **ptr)
{
	t_stack	*temp;

	if (!ptr || !*ptr)
		return ;
	while (*ptr)
	{
		temp = (*ptr)->next;
		free(*ptr);
		*ptr = temp;
	}
	return ;
}
