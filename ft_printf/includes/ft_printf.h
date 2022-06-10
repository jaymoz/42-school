#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct s_printf_list
{
	va_list	args;
	int		percentage;
	int		space;
	int		is_num_zero;
	int		total;
	int		point;
	int		width;
	int		zero;
	int		minus;
	int		sign;
	int		precision;

}			t_list;

int		ft_printf(const char *fmt, ...);
int		ft_process_width(t_list *list, const char *fmt, int position);
int		ft_process_precision(t_list *list, const char *fmt, int position);
int		ft_process_fmt(t_list *list, const char *fmt, int position);
int		ft_check_specifier(t_list *list, const char *fmt, int position);
int		ft_process_minus(t_list *list, const char *fmt, int position);
int		ft_process_zero(t_list *list, const char *fmt, int position);
int		ft_process_asterik(t_list *list, const char *fmt, int position);
void	ft_print_char(t_list *list);
void	ft_print_str(t_list *list);
void	ft_print_int(t_list *list);
void	ft_print_uint(t_list *list);
void	ft_print_ptr(t_list *list);
void	ft_print_hex(t_list *list, int c);
void	ft_right_justify_values(t_list *list);
void	ft_left_justify_values(t_list *list);
void	ft_right_zero(t_list *list);
void	ft_right_justify_char_str(t_list *list, int len);
void	ft_left_justify_char_str(t_list *list, int len);
void	ft_set_list_data(t_list *list, int len);
int		ft_set_list_data_string(char *s, t_list *list, int len);
void	ft_output_blank(t_list *list);
void	ft_write_zero(t_list *list);
void	ft_write_zero_point(t_list *list);
void	ft_print_null_pointer(t_list *list);
void	ft_process_percentage(t_list *list);
int		ft_process_space(t_list *list, int position);
void	ft_set_width(t_list *list);
void	ft_set_precision(t_list *list);
int		ft_set_sign(t_list *list, int j);
int		ft_check_flag(char c);
t_list	*ft_set_list(t_list *list);
t_list	*ft_set_list_default(t_list *list);

#endif
