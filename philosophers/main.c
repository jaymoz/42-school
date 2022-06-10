/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:10:34 by lross             #+#    #+#             */
/*   Updated: 2021/10/25 20:48:28 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_finish(t_data *data)
{
	pthread_mutex_lock(&data->dead);
	if (data->end_p)
	{
		pthread_mutex_unlock(&data->dead);
		return (1);
	}
	pthread_mutex_unlock(&data->dead);
	return (0);
}

void	end_p_simulation(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (!ft_finish(data))
		;
	while (++i < data->num_philo)
		pthread_join(philo[i].thread_id, NULL);
	pthread_mutex_destroy(&data->output);
	i = -1;
	while (++i < data->num_philo)
		pthread_mutex_destroy(&philo[i].left_fork);
	if (data->end_p == 2)
		printf("Everyone has eaten enough!!!\n");
	free(philo);
}

void	philo_life_cycle_2(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->output);
	print_message("is sleeping 😴\n", philo);
	pthread_mutex_unlock(&philo->data->output);
	ft_usleep(philo->data->time_sleep);
	pthread_mutex_lock(&philo->data->output);
	print_message("is thinking 🤔\n", philo);
	pthread_mutex_unlock(&philo->data->output);
}

void	philo_life_cycle(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->data->output);
	print_message("has taken a fork 🍴\n", philo);
	pthread_mutex_unlock(&philo->data->output);
	if (!philo->right_fork)
	{
		ft_usleep(philo->data->time_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->data->output);
	print_message("has taken a fork 🍴\n", philo);
	pthread_mutex_unlock(&philo->data->output);
	pthread_mutex_lock(&philo->data->output);
	print_message("is eating 🍜\n", philo);
	pthread_mutex_lock(&philo->data->eat);
	philo->time_last_meal = ft_time();
	pthread_mutex_unlock(&philo->data->eat);
	pthread_mutex_unlock(&philo->data->output);
	ft_usleep(philo->data->time_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	philo_life_cycle_2(philo);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philo;

	if (!(fill_data(argv, argc, &data)))
	{
		printf("sorry cant pass data\n");
		exit (1);
	}
	philo = (t_philo *)malloc(sizeof(t_philo) * data.num_philo);
	if (!philo)
	{
		printf("Could not allocate memory\n");
		exit (1);
	}
	parse_data(argv, argc, philo, &data);
	if (!(ft_start_thread(argv, philo, &data)))
	{
		printf("COuld not create threads!!\n");
		exit (1);
	}
	if (data.num_philo == 1)
		end_one_philo(&data, philo);
	else
		end_p_simulation(&data, philo);
	return (0);
}
