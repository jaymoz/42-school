#include "libft.h"

t_stack	*ft_get_param(int argc, char *argv[])
{
	int		number;
	t_stack	*list;
	t_stack	*stack_a;

	while (argc > 1)
	{
		number = ft_atoi(argv[argc - 1]);
		list = ft_lstnew(number);
		if (!list)
			exit(1);
		ft_lstadd_front(&stack_a, list);
		argc--;
	}
	return (stack_a);
}
