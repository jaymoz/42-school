#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_int(t_list *list)
{
	int		i;
	int		j;
	char	*output;
	int		len;

	i = 0;
	j = va_arg(list->args, int);
	if (!j)
	{
		ft_write_zero(list);
		return ;
	}
	if (j < 0)
		j = ft_set_sign(list, j);
	output = ft_itoa(j);
	if (!output)
		return ;
	len = ft_strlen(output);
	ft_set_list_data(list, len);
	ft_right_justify_values(list);
	while (j && output[i])
		list->total += write(1, &output[i++], 1);
	ft_left_justify_values(list);
	free(output);
}
