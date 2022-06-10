#include "push_swap.h"

static	void	rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = (*head)->next;
	tmp->prev = NULL;
	last = ft_lstlast(*head);
	last->next = (*head);
	(*head)->prev = last;
	(*head)->next = NULL;
	(*head) = tmp;
}

void	ra(t_stack **stack_a, t_global *global)
{
	if (global->size_a > 1)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **stack_b, t_global *global)
{
	if (global->size_b > 1)
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_global *global)
{
	if (global->size_b > 1 && global->size_a > 1)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
}
