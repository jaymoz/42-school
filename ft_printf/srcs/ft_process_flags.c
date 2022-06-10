#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_process_asterik(t_list *list, const char *fmt, int position)
{
	position++;
	if (!list->point)
	{
		list->width = va_arg(list->args, int);
		ft_set_width(list);
	}
	else
	{
		list->precision = va_arg(list->args, int);
		ft_set_precision(list);
	}
	if (fmt[position] == '.')
		position = ft_process_precision(list, fmt, position);
	if (fmt[position] == '*')
		position = ft_process_asterik(list, fmt, position);
	while (fmt[position] == '*')
		position++;
	return (position);
}

int	ft_process_precision(t_list *list, const char *fmt, int position)
{
	int	i;

	i = 0;
	position++;
	list->point = 1;
	if (ft_isalpha(fmt[position]) || fmt[position] == '%')
		ft_set_precision(list);
	while (fmt[position] == '0' || ft_check_flag(fmt[position]))
	{
		position++;
		ft_set_precision(list);
	}
	if (ft_isdigit(fmt[position]))
	{
		i = ft_atoi(&fmt[position]);
		position += ft_numlen(i);
	}
	list->precision = i;
	if (fmt[position] == '*')
		position = ft_process_asterik(list, fmt, position);
	while (fmt[position] == '*')
		position++;
	return (position);
}

int	ft_process_zero(t_list *list, const char *fmt, int position)
{
	int	i;

	i = 0;
	position++;
	list->zero = 1;
	while (fmt[position] == '0')
		position++;
	if (ft_isdigit(fmt[position]))
	{
		i = ft_atoi(&fmt[position]);
		position += ft_numlen(i);
	}
	list->width = i;
	return (position);
}

int	ft_process_minus(t_list *list, const char *fmt, int position)
{
	position++;
	if (list->minus == 1)
	{
		while (fmt[position] == '-' || fmt[position] == '0')
			position++;
		return (position);
	}
	list->minus = 1;
	list->zero = 0;
	while (fmt[position] == '-' || fmt[position] == '0')
		position++;
	position = ft_process_width(list, fmt, position);
	return (position);
}

int	ft_process_width(t_list *list, const char *fmt, int position)
{
	int	i;

	i = 0;
	if (ft_isdigit(fmt[position]))
	{
		i = ft_atoi(&fmt[position]);
		position += ft_numlen(i);
	}
	list->width = i;
	if (fmt[position] == '.')
		position = ft_process_precision(list, fmt, position);
	return (position);
}
