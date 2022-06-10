#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_process_fmt(t_list *list, const char *fmt, int position)
{
	while (!(ft_isalpha(fmt[position]) || fmt[position] == '%'))
	{
		if (fmt[position] == '.')
			position = ft_process_precision(list, fmt, position);
		if (fmt[position] == ' ')
			position = ft_process_space(list, position);
		if (ft_isdigit(fmt[position]))
			position = ft_process_width(list, fmt, position);
		if (fmt[position] == '*')
			position = ft_process_asterik(list, fmt, position);
		if (fmt[position] == '0')
			position = ft_process_zero(list, fmt, position);
		if (fmt[position] == '-')
			position = ft_process_minus(list, fmt, position);
	}
	ft_check_specifier(list, fmt, position);
	ft_set_list_default(list);
	return (position);
}
