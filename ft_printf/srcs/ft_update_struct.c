#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_set_list_data_string(char *s, t_list *list, int len)
{
	if (s)
		len = ft_strlen(s);
	if (list->precision > 0 && len > list->precision)
		len = list->precision;
	return (len);
}

void	ft_set_list_data(t_list *list, int len)
{
	if (list->sign)
	{
		if (list->width)
			list->width -= 1;
	}
	if (list->precision > 0)
		list->zero = 0;
	if (list->width && list->width >= list->precision)
	{
		if (list->precision > len)
			list->precision -= len;
		else
			list->precision = 0;
		if (!list->is_num_zero)
			list->width = list->width - list->precision - len;
	}
	else if (list->precision > list->width)
	{
		list->width = 0;
		list->precision -= len;
	}
}

void	ft_output_blank(t_list *list)
{
	ft_set_list_data_string(NULL, list, 0);
	while (list->width--)
		list->total += ft_putchar(' ');
}

void	ft_write_zero_point(t_list *list)
{
	if (list->precision < 0)
		list->total += ft_putchar('0');
	while (!list->width && list->precision-- > 0)
		list->total += ft_putchar('0');
}

void	ft_write_zero(t_list *list)
{
	list->is_num_zero = 1;
	if ((list->width && list->zero) || list->point)
	{
		ft_right_zero(list);
		return ;
	}
	ft_set_list_data(list, 1);
	while (!list->minus && --list->width > 0)
		list->total += ft_putchar(' ');
	list->total += ft_putchar('0');
	while (list->minus && --list->width > 0)
		list->total += ft_putchar(' ');
}
