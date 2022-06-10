/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:11:00 by lross             #+#    #+#             */
/*   Updated: 2021/10/28 17:57:55 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *str, t_philo *philo)
{
	long int		time;

	time = ft_time() - philo->data->timer;
	if (time >= 0 && time <= 2147483647 && !is_philo_dead(philo, 0))
	{
		printf("%ld-----Philo(%d)---%s", time, philo->id, str);
	}
}

int	is_philo_dead(t_philo *philo, int arg)
{
	pthread_mutex_lock(&philo->data->dead);
	if (arg)
		philo->data->end_p = arg;
	if (philo->data->end_p)
	{
		pthread_mutex_unlock(&philo->data->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (0);
}

void	*philo_has_died(void	*data)
{
	t_philo					*philo;

	philo = (t_philo *)data;
	ft_usleep(philo->data->time_die + 1);
	pthread_mutex_lock(&philo->data->eat);
	pthread_mutex_lock(&philo->data->finish);
	if (!is_philo_dead(philo, 0) && !philo->finish && ((ft_time()
				- philo->time_last_meal) >= (long)(philo->data->time_die)))
	{
		pthread_mutex_unlock(&philo->data->eat);
		pthread_mutex_unlock(&philo->data->finish);
		pthread_mutex_lock(&philo->data->output);
		if (philo->data->one_has_died == 0)
		{
			print_message("died 💀\n", philo);
			philo->data->one_has_died = 1;
		}
		pthread_mutex_unlock(&philo->data->output);
		is_philo_dead(philo, 1);
	}
	pthread_mutex_unlock(&philo->data->eat);
	pthread_mutex_unlock(&philo->data->finish);
	return (NULL);
}

void	end_one_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
		pthread_join(philo[i].thread_id, NULL);
	pthread_mutex_destroy(&data->output);
	i = -1;
	while (++i < data->num_philo)
		pthread_mutex_destroy(&philo[i].left_fork);
	free(philo);
}
