#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_uint(t_list *list)
{
	int				i;
	unsigned int	j;
	char			*output;
	int				len;

	i = 0;
	j = va_arg(list->args, int);
	if (!j)
	{
		ft_write_zero(list);
		return ;
	}
	output = ft_uitoa(j);
	if (!output)
		return ;
	len = ft_numlen(j);
	ft_set_list_data(list, len);
	ft_right_justify_values(list);
	while (output[i])
		list->total += write(1, &output[i++], 1);
	ft_left_justify_values(list);
	free(output);
}
