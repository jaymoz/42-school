#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int 	ft_check_specifier(t_list *list, const char *fmt, int position)
{
	if (fmt[position] == 'p')
		ft_print_ptr(list);
	else if (fmt[position] == 'c')
		ft_print_char(list);
	else if (fmt[position] == 's')
		ft_print_str(list);
	else if (fmt[position] == 'x' || fmt[position] == 'X')
		ft_print_hex(list, fmt[position] - 23);
	else if (fmt[position] == '%')
		ft_process_percentage(list);
	else if (fmt[position] == 'u')
		ft_print_uint(list);
	else if (fmt[position] == 'd' || fmt[position] == 'i')
		ft_print_int(list);
	return (position);
}
