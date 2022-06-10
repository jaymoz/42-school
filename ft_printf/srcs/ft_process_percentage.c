#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_process_percentage(t_list *list)
{
	if (list->percentage)
		list->zero = 1;
	while (list->zero && !list->minus && --list->width > 0)
		list->total += ft_putchar('0');
	while (!list->minus && --list->width > 0)
		list->total += ft_putchar(' ');
	list->total += ft_putchar('%');
	while (list->minus && --list->width > 0)
		list->total += ft_putchar(' ');
}

int	ft_process_space(t_list *list, int position)
{
	position++;
	list->space = 1;
	return (position);
}
