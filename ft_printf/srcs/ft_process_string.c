#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_str(t_list *list)
{
	char	*output;
	int		i;
	int		len;

	i = 0;
	len = 0;
	output = va_arg(list->args, char *);
	if (!output)
		output = "(null)";
	if (output && list->point == 1 && list->precision == 0)
		return (ft_output_blank(list));
	len = ft_set_list_data_string(output, list, len);
	if (!list->minus && list->width > len)
		ft_right_justify_char_str(list, len);
	if (list->precision > 0)
		while (output[i] && list->precision--)
			list->total += write(1, &output[i++], 1);
	else
		while (output[i])
			list->total += write(1, &output[i++], 1);
	if (output && list->minus && list->width)
		ft_left_justify_char_str(list, len);
}
