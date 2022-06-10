#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	t_list	*list;
	int		i;
	int		total_char;

	if (!fmt)
		return (0);
	total_char = 0;
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (-1);
	ft_set_list(list);
	i = -1;
	va_start(list->args, fmt);
	while (fmt[++i])
	{
		if (fmt[i] == '%')
			i = ft_process_fmt(list, fmt, i + 1);
		else
			total_char += write(1, &fmt[i], 1);
	}
	total_char += list->total;
	va_end(list->args);
	free(list);
	return (total_char);
}
