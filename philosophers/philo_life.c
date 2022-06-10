/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:10:54 by lross             #+#    #+#             */
/*   Updated: 2021/10/28 17:37:47 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->data->output);
	print_message("has taken a fork 🍴\n", philo);
	pthread_mutex_unlock(&philo->data->output);
	ft_usleep(philo->data->time_die);
	pthread_mutex_lock(&philo->data->output);
	print_message("has died 💀\n", philo);
	pthread_mutex_unlock(&philo->data->output);
	ft_usleep(philo->data->time_die);
}

void	helper(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->finish);
	philo->finish = 1;
	philo->data->nb_p_finish++;
	if (philo->data->nb_p_finish == philo->data->num_philo)
	{
		pthread_mutex_unlock(&philo->data->finish);
		is_philo_dead(philo, 2);
	}
	pthread_mutex_unlock(&philo->data->finish);
}

void	*philosophers(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_eat / 10);
	if (philo->data->num_philo == 1)
		handle_one_philo((void *)philo);
	else
	{
		while (!is_philo_dead(philo, 0))
		{
			pthread_create(&philo->thread_death_id, NULL, philo_has_died, arg);
			philo_life_cycle(philo);
			pthread_detach(philo->thread_death_id);
			if ((int)++philo->num_meal == philo->data->must_eat)
			{
				helper(philo);
				return (NULL);
			}
		}
	}
	return (NULL);
}

int	ft_start_thread(char *argv[], t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&philo[i].thread_id, NULL, philosophers,
				(void *)&philo[i]) != 0)
		{
			printf("Could not create thread!\n");
			return (0);
		}
		i++;
	}
	return (1);
}
