#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_right_justify_values(t_list *list)
{
	if (list->space)
		list->total += ft_putchar(' ');
	if (list->sign && (list->zero
			|| list->minus || (!list->width && !list->precision)))
	{
		list->total += ft_putchar('-');
		list->sign = 0;
	}
	if (!list->minus)
	{
		while (!list->zero && --list->width > -1)
			list->total += ft_putchar(' ');
		while (list->zero && --list->width > -1)
			list->total += ft_putchar('0');
		if (list->sign)
			list->total += ft_putchar('-');
	}
	while (--list->precision > -1)
		list->total += ft_putchar('0');
}

void	ft_left_justify_values(t_list *list)
{
	if (list->minus)
	{
		while (list->minus && list->zero && --list->precision > -1)
			list->total += ft_putchar('0');
		while (list->minus && --list->width > -1)
			list->total += ft_putchar(' ');
	}
}

void	ft_right_justify_char_str(t_list *list, int len)
{
	while (list->zero && list->width-- > len)
		list->total += ft_putchar('0');
	if (!list->zero && list->precision && list->precision < len)
		while (list->width-- > list->precision)
			list->total += ft_putchar(' ');
	else
		while (!list->zero && list->width-- > len)
			list->total += ft_putchar(' ');
}

void	ft_left_justify_char_str(t_list *list, int len)
{
	while (list->zero && list->width-- > len)
		list->total += ft_putchar('0');
	while (!list->zero && list->width-- > len)
		list->total += ft_putchar(' ');
}

void	ft_right_zero(t_list *list)
{
	if (list->width && (list->point || list->zero))
	{
		if (!list->precision)
		{
			while (list->zero && list->width-- > 0)
				list->total += ft_putchar('0');
			while (!list->zero && list->width-- > 0)
				list->total += ft_putchar(' ');
		}
		else
		{
			list->width -= list->precision;
			while (list->minus && list->precision-- > 0)
				list->total += ft_putchar('0');
			while (list->width-- > 0)
				list->total += ft_putchar(' ');
			while (!list->minus && list->precision-- > 0)
				list->total += ft_putchar('0');
		}
	}
	else if (list->point)
		ft_write_zero_point(list);
}
