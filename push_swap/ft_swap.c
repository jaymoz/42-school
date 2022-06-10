#include "push_swap.h"

static	void	swap(t_stack **head, int *confirm)
{
	t_stack	*rest;
	t_stack	*first;
	t_stack	*second;
	int		size;

	size = ft_lstsize(*head);
	if (size > 1)
	{
		(*confirm)++;
		first = (*head);
		second = first->next;
		rest = second->next;
		second->next = NULL;
		second->prev = NULL;
		first->next = rest;
		first->prev = second;
		if (rest)
			rest->prev = first;
		second->next = first;
		(*head) = second;
	}
}

void	sa(t_stack **head_a)
{
	int	confirm;

	confirm = 0;
	swap(head_a, &confirm);
	if (confirm == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **head_b)
{
	int	confirm;

	confirm = 0;
	swap(head_b, &confirm);
	if (confirm == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **head_a, t_stack **head_b)
{
	int	confirm;

	confirm = 0;
	swap(head_a, &confirm);
	swap(head_b, &confirm);
	if (confirm == 2)
		write(1, "ss\n", 3);
}
