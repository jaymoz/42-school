#include "push_swap.h"

void	ft_sort_two(t_stack **stack_a, t_global *global)
{
	if (global->size_a == 2 && (*stack_a)->number < (*stack_a)->next->number)
		return ;
	else if (global->size_a == 2
		&& (*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
}

void	ft_sort_three(t_stack **stack_a, t_global *global)
{
	int		a;
	int		b;
	int		c;

	if (ft_check_lst_sorted(*stack_a))
		return ;
	a = (*stack_a)->number;
	b = (*stack_a)->next->number;
	c = (*stack_a)->next->next->number;
	if (a < b && a < c && b > c)
	{
		rra(stack_a, global);
		sa(stack_a);
	}
	else if (a > b && a < c && b < c)
		sa(stack_a);
	else if (a < b && a > c && b > c)
		rra(stack_a, global);
	else if (a > b && a > c && b < c)
		ra(stack_a, global);
	else if (a > b && a > c && b > c)
	{
		ra(stack_a, global);
		sa(stack_a);
	}
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b, t_global *global)
{
	int	min;

	min = ft_get_min(stack_a);
	while ((*stack_a)->number != min)
	{
		ra(stack_a, global);
	}
	pb(stack_a, stack_b, global);
	ft_sort_three(stack_a, global);
	pa(stack_a, stack_b, global);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b, t_global *global)
{
	int	min;

	min = ft_get_min(stack_a);
	while ((*stack_a))
	{
		if ((*stack_a)-> number == min)
		{
			pb(stack_a, stack_b, global);
			break ;
		}
		ra(stack_a, global);
	}
	min = ft_get_min(stack_a);
	while ((*stack_a))
	{
		if ((*stack_a)-> number == min)
		{
			pb(stack_a, stack_b, global);
			break ;
		}
		ra(stack_a, global);
	}
	ft_sort_three(stack_a, global);
	pa(stack_a, stack_b, global);
	pa(stack_a, stack_b, global);
}

void	ft_choose_sort(t_stack **stack_a, t_stack **stack_b, t_global *global)
{
	if (ft_check_lst_sorted(*stack_a))
		return ;
	else if (global->size_a == 2)
		ft_sort_two(stack_a, global);
	else if (global->size_a == 3)
		ft_sort_three(stack_a, global);
	else if (global->size_a == 4)
		ft_sort_four(stack_a, stack_b, global);
	else if (global->size_a == 5)
		ft_sort_five(stack_a, stack_b, global);
	else if (global->size_a <= 20)
		ft_sort_middle(stack_a, stack_b, global);
	else
		ft_complex_sort(stack_a, stack_b, global);
}
