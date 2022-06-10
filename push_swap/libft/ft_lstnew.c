#include "libft.h"

t_stack	*ft_lstnew(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> number = number;
	new -> next = NULL;
	new -> prev = NULL;
	new -> order = 0;
	new -> keep = 0;
	return (new);
}
