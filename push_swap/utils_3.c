#include "push_swap.h"

int	ft_is_in_group(t_stack **stack, int max_group)
{
	t_stack	*s;

	s = (*stack);
	while (s)
	{
		if (s->number <= max_group)
			return (1);
		s = s->next;
	}
	return (0);
}

static int	ft_get_position(t_stack **stack, int num)
{
	int			position;
	t_stack		*tmp;

	tmp = *stack;
	position = 0;
	while (tmp->number != num)
	{
		tmp = tmp->next;
		position++;
	}
	return (position);
}

static void	ft_send_to_top_stack_a(t_global *global, t_stack **stack, int num)
{
	int	position;

	position = ft_get_position(stack, num);
	if (position < (global -> size_a / 2))
		while ((*stack)->number != num)
			ra(stack, global);
	else
		while ((*stack)->number != num)
			rra(stack, global);
}

void	ft_sort_middle(t_stack **stack_a, t_stack **stack_b, t_global *global)
{
	int	min;

	while (global->size_a > 3)
	{
		min = ft_get_min(stack_a);
		ft_send_to_top_stack_a(global, stack_a, min);
		pb(stack_a, stack_b, global);
		if (ft_check_lst_sorted((*stack_a)))
			break ;
	}
	ft_sort_three(stack_a, global);
	while (global->size_b)
		pa(stack_a, stack_b, global);
}
