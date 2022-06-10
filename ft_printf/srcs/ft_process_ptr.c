#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_ptr(t_list *list)
{
	unsigned long	j;
	int				l;

	l = 2;
	j = (unsigned long)va_arg(list->args, void *);
	if (!j && list->point && list->precision > 0)
	{
		ft_print_null_pointer(list);
		return ;
	}
	if (!(!j && list->point))
		l += ft_numlen_base(j, 16);
	if (!list->precision || list->width > list->precision)
	{
		ft_set_list_data(list, l);
		ft_right_justify_values(list);
	}
	else
		list->precision = list->precision + 2 - l;
	list->total += write(1, "0x", 2);
	while (list->precision-- > 0)
		list->total += ft_putchar('0');
	if (!(!j && list->point))
		list->total += ft_putnbr_base(j, "0123456789abcdef");
	ft_left_justify_values(list);
}

void	ft_print_null_pointer(t_list *list)
{
	if (list->width > list->precision)
	{
		while (list->width-- > (list->precision + 2))
			list->total += ft_putchar(' ');
	}
	list->total += write(1, "0x", 2);
	while (list->precision-- > 0)
		list->total += ft_putchar('0');
}
