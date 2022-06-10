#include "push_swap.h"

static void	ft_error_free(t_stack **stack_a)
{
	ft_lstfree(stack_a);
	ft_error();
}

void	ft_check_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
	{
		if (i == 0 && str[i] != '-' && ft_isdigit(str[i]) == 0)
			ft_error();
		else if (i != 0 && ft_isdigit(str[i]) == 0)
			ft_error();
	}
	if (str[0] == '-' && str[1] == 0)
		ft_error();
	if (ft_isint(str) == 0)
		ft_error();
}

static void	ft_check_doubles(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*rest;

	current = stack_a;
	while (current)
	{
		rest = current->next;
		while (rest)
		{
			if (current->number == rest->number)
			{
				ft_error_free(&stack_a);
			}
			rest = rest->next;
		}
		current = current->next;
	}
}

static void	ft_helper(char *argv[], t_stack **stack_a, t_stack *new, int i)
{
	char	**split_str;
	int		j;
	int		num;

	j = 0;
	split_str = ft_strsplit(argv[i], ' ');
	while (split_str[j])
	{
		if (!ft_isint(split_str[j]))
			ft_error();
		num = ft_atoi_push(split_str[j]);
		new = ft_lstnew(num);
		if (!new)
			ft_error_free(stack_a);
		ft_lstadd_back(stack_a, new);
		++j;
	}
	ft_strsplit_free(&split_str);
}

t_stack	*ft_parse(char *argv[], t_global *global)
{
	int			i;
	t_stack		*stack_a;
	t_stack		*new;

	i = 1;
	new = NULL;
	stack_a = global->stack_a;
	while (argv[i])
	{
		ft_helper(argv, &stack_a, new, i);
		++i;
	}
	ft_check_doubles(stack_a);
	(global)->size_a = ft_lstsize(stack_a);
	return (stack_a);
}
