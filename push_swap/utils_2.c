#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_get_min(t_stack **stack)
{
	int		min;
	t_stack	*lst;

	lst = *stack;
	min = 0;
	if (lst)
		min = lst->number;
	while (lst)
	{
		if (lst->number < min)
			min = lst->number;
		lst = lst->next;
	}
	return (min);
}

int	ft_get_max(t_stack **stack)
{
	int		max;
	t_stack	*lst;

	lst = *stack;
	max = 0;
	if (lst)
		max = lst->number;
	while (lst)
	{
		if (lst->number > max)
			max = lst->number;
		lst = lst->next;
	}
	return (max);
}

int	ft_check_lst_sorted(t_stack *lst)
{
	t_stack	*head;

	head = lst;
	while (lst && lst->next)
	{
		if (lst->number > lst->next->number)
			return (0);
		lst = lst->next;
	}
	if (lst && head)
	{
		if (lst->number < head->number)
			return (0);
	}
	return (1);
}
