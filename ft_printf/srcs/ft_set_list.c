#include "../includes/ft_printf.h"

t_list	*ft_set_list_default(t_list *list)
{
	list->zero = 0;
	list->precision = 0;
	list->point = 0;
	list->is_num_zero = 0;
	list->percentage = 0;
	list->sign = 0;
	list->minus = 0;
	list->space = 0;
	list->width = 0;
	return (list);
}

t_list	*ft_set_list(t_list *list)
{
	list->sign = 0;
	list->width = 0;
	list->zero = 0;
	list->precision = 0;
	list->point = 0;
	list->space = 0;
	list->minus = 0;
	list->total = 0;
	list->is_num_zero = 0;
	list->percentage = 0;
	return (list);
}
