#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_global	global;
	int			size;

	size = argc - 1;
	global.stack_a = NULL;
	global.stack_b = NULL;
	global.size_a = 0;
	global.size_b = 0;
	global.stack_a = ft_parse(argv, &global);
	ft_choose_sort(&global.stack_a, &global.stack_b, &global);
	ft_lstfree(&(global.stack_a));
	ft_lstfree(&(global.stack_b));
}
