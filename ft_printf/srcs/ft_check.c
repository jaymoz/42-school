#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_set_width(t_list *list)
{
	if (list->width < 0)
	{
		list->width *= -1;
		list->minus = 1;
		list->zero = 0;
	}
}

int	ft_check_flag(char c)
{
	if (c == '-' || c == '.')
		return (1);
	return (0);
}

void	ft_set_precision(t_list *list)
{
	if (list->precision == 0 && list->zero == 1)
	{
		list->zero = 0;
		list->percentage = 1;
	}
	if (list->precision < 0)
	{
		list->precision = 0;
		list->point = 0;
	}
}

int	ft_set_sign(t_list *list, int j)
{
	list->sign = 1;
	list->space = 0;
	return (j * -1);
}
