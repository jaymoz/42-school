/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 02:04:13 by lross             #+#    #+#             */
/*   Updated: 2021/10/28 17:54:53 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int						num_philo;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	int						must_eat;
	long int				timer;
	pthread_mutex_t			output;
	pthread_mutex_t			dead;
	pthread_mutex_t			eat;
	pthread_mutex_t			finish;
	int						nb_p_finish;
	int						end_p;
	int						one_has_died;
}							t_data;

typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			left_fork;
	long int				time_last_meal;
	unsigned int			num_meal;
	int						finish;
	t_data					*data;
}							t_philo;

void	end_one_philo(t_data *data, t_philo *philo);
int		ft_strlen(char *str);
void	*philo_has_died(void	*data);
int		is_philo_dead(t_philo *philo, int arg);
void	philo_life_cycle(t_philo *philo);
void	print_message(char *str, t_philo *philo);
int		ft_start_thread(char *argv[], t_philo *philo, t_data *data);
long	ft_time(void);
void	ft_usleep(int length);
int		arg_check(int ac, char **av);
int		parse_data(char *argv[], int argc, t_philo *philo, t_data *data);
int		fill_data(char *argv[], int argc, t_data *data);
int		ft_atoi(char *str);
int		ft_str_is_numeric(char *str);

#endif