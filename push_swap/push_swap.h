#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

void		ft_error(void);
t_stack		*ft_parse(char *argv[], t_global *global);
t_stack		*ft_get_param(int argc, char *argv[]);
int			*ft_copy_array(int arr[], int len);
int			*ft_copy_to_arr(int argc, char *argv[]);
void		insertionSort(int arr[], int n);
void		pa(t_stack **stack_a, t_stack **stack_b, t_global *global);
void		pb(t_stack **stack_a, t_stack **stack_b, t_global *global);
void		rra(t_stack **stack_a, t_global *global);
void		rrb(t_stack **stack_b, t_global *global);
void		rrr(t_stack **stack_a, t_stack **stack_b, t_global *global);
void		ra(t_stack **stack_a, t_global *global);
void		rb(t_stack **stack_b, t_global *global);
void		rr(t_stack **stack_a, t_stack **stack_b, t_global *global);
void		sa(t_stack **head_a);
void		sb(t_stack **head_b);
void		ss(t_stack **head_a, t_stack **head_b);
void		ft_choose_sort(t_stack **stack_a,
				t_stack **stack_b, t_global *global);
int			ft_get_min(t_stack **stack);
int			ft_get_max(t_stack **stack);
void		ft_sort_three(t_stack **stack_a, t_global *global);
void		ft_sort_four(t_stack **stack_a,
				t_stack **stack_b, t_global *global);
int			ft_check_lst_sorted(t_stack *lst);
void		ft_sort_middle(t_stack **stack_a,
				t_stack **stack_b, t_global *global);
int			ft_is_in_group(t_stack **stack, int max_group);
void		ft_complex_sort(t_stack **stack_a,
				t_stack **stack_b, t_global *global);
void		ft_set_stack_b(t_stack **stack_a, t_stack **stack_b,
				t_global *global);

#endif