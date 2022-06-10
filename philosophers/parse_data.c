/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:10:47 by lross             #+#    #+#             */
/*   Updated: 2021/10/28 17:55:44 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_args(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	fill_data(char *argv[], int argc, t_data *data)
{
	if ((argc == 5 || argc == 6) && ft_check_args(argv))
	{
		data->num_philo = ft_atoi(argv[1]);
		data->time_die = ft_atoi(argv[2]);
		data->time_eat = ft_atoi(argv[3]);
		data->time_sleep = ft_atoi(argv[4]);
		data->one_has_died = 0;
		if (argc == 6)
			data->must_eat = ft_atoi(argv[5]);
		if (data->num_philo <= 0 || data->time_eat <= 0
			|| data->time_die <= 0 || data->time_sleep <= 0)
		{
			return (0);
		}
		return (1);
	}
	return (0);
}

void	init_mutex(t_data *data)
{
	pthread_mutex_init(&data->output, NULL);
	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->eat, NULL);
	pthread_mutex_init(&data->finish, NULL);
}

int	parse_data(char *argv[], int argc, t_philo *philo, t_data *data)
{
	long	time;
	int		i;

	data->timer = ft_time();
	data->end_p = 0;
	data->nb_p_finish = 0;
	init_mutex(data);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].id = i + 1;
		philo[i].time_last_meal = data->timer;
		philo[i].num_meal = 0;
		philo[i].finish = 0;
		philo[i].data = data;
		philo[i].right_fork = NULL;
		pthread_mutex_init(&philo[i].left_fork, NULL);
		if (i == data->num_philo - 1)
			philo[i].right_fork = &philo[0].left_fork;
		else
			philo[i].right_fork = &philo[i + 1].left_fork;
		i++;
	}
	return (0);
}
