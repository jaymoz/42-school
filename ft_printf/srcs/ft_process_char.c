#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_char(t_list *list)
{
	char	c;

	c = va_arg(list->args, int);
	ft_set_list_data(list, 1);
	if (list->width && !list->minus)
	{
		ft_right_justify_char_str(list, 0);
	}
	list->total += write(1, &c, 1);
	if (list->width && list->minus)
	{
		ft_left_justify_char_str(list, 0);
	}
}
