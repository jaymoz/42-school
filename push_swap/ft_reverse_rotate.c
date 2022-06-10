#include "push_swap.h"

static	void	rev_rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	last = ft_lstlast(*head);
	first = last;
	last->prev->next = NULL;
	last->next = NULL;
	first->prev = NULL;
	first->next = (*head);
	(*head)->prev = first;
	(*head) = first;
}

void	rra(t_stack **stack_a, t_global *global)
{
	if (global->size_a > 1)
	{
		rev_rotate(stack_a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **stack_b, t_global *global)
{
	if (global->size_b > 1)
	{
		rev_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_global *global)
{
	if (global->size_b > 1 && global->size_a > 1)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}
