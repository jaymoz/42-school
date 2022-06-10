#include "push_swap.h"

static void	ft_min_moves_to_top(t_stack **stack_b, t_global *global, int pos)
{
	int	i;

	i = -1;
	if (pos <= global->size_b / 2)
	{
		while (++i < pos)
			rb(stack_b, global);
	}
	else
	{
		while (++i < global->size_b - pos)
			rrb(stack_b, global);
	}
}

static void	move_max_to_top(t_stack **stack_b, t_global *global)
{
	int		pos;
	int		max;
	t_stack	*tmp;

	tmp = (*stack_b);
	max = ft_get_max(stack_b);
	pos = 0;
	while (tmp)
	{
		if (tmp->number == max)
			break ;
		pos++;
		tmp = tmp->next;
	}
	ft_min_moves_to_top(stack_b, global, pos);
}

void	ft_set_stack_b(t_stack **stack_a, t_stack **stack_b, t_global *global)
{
	t_stack	*tmp;
	int		pos;
	int		min_b;
	int		max_b;
	int		top_a;

	pos = 0;
	min_b = ft_get_min(stack_b);
	max_b = ft_get_max(stack_b);
	top_a = (*stack_a)->number;
	tmp = (*stack_b);
	if (top_a < min_b || top_a > max_b)
		return (move_max_to_top(stack_b, global));
	while (tmp)
	{
		pos++;
		if (tmp->next && (top_a < tmp->number && top_a > tmp->next->number))
			break ;
		tmp = tmp->next;
	}
	ft_min_moves_to_top(stack_b, global, pos);
}

static void	ft_sort_group(t_stack **stack_a, t_stack **stack_b,
				t_global *global, int max_group)
{
	while ((ft_is_in_group(stack_a, max_group)))
	{
		if ((*stack_a)->number <= max_group)
		{
			ft_set_stack_b(stack_a, stack_b, global);
			pb(stack_a, stack_b, global);
		}
		else
			ra(stack_a, global);
	}
	move_max_to_top(stack_b, global);
}

void	ft_complex_sort(t_stack **stack_a, t_stack **stack_b, t_global *global)
{
	int	max_group;
	int	groups;
	int	i;

	max_group = 0;
	i = 0;
	groups = 5;
	if (global->size_a > 200)
		groups = 11;
	max_group = (ft_get_max(stack_a) - ft_get_min(stack_a))
		/ groups;
	while (++i < groups)
		ft_sort_group(stack_a, stack_b, global, max_group * i);
	ft_sort_group(stack_a, stack_b, global, ft_get_max(stack_a) + 1);
	while (global->size_b)
		pa(stack_a, stack_b, global);
}
