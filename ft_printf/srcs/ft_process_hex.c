#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_hex(t_list *list, int c)
{
	unsigned int	j;
	int				len;
	char			*num;

	j = va_arg(list->args, unsigned int);
	if (!j)
	{
		ft_write_zero(list);
		return ;
	}
	len = ft_numlen_base(j, 16);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return ;
	num = ft_itoa_base(num, j, 16, c);
	ft_set_list_data(list, len);
	ft_right_justify_values(list);
	while (num && len-- > 0)
		list->total += write(1, &num[len], 1);
	ft_left_justify_values(list);
	free(num);
}
