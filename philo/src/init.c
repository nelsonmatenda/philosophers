/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:45:20 by nfigueir          #+#    #+#             */
/*   Updated: 2024/11/21 09:57:05 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	init_config(t_philosophers *data, int ac, char **av)
{
	data->config.n_philo = get_args(av[1]);
	data->config.t_die = get_args(av[2]);
	data->config.t_eat = get_args(av[3]);
	data->config.t_sleep = get_args(av[4]);
	data->config.n_meals = -1;;
	if (ac == 6)
		data->config.n_meals = get_args(av[5]);
	data->config.start_time = -1;
	data->config.stop = 0;
	data->config.philo = data;
	if (data->config.n_philo < 1 \
		|| data->config.n_philo > PHILO_MAX \
		|| data->config.t_die <= 0 || data->config.t_eat <= 0 \
		|| data->config.t_sleep <= 0 \
		|| (ac == 6 && data->config.n_meals <= 0))
		return (ft_exit(data, ARG_ERR, 0, 0), 0);
	return (1);
}


static int	init_mutex_philo(t_status *philo)
{
	if (pthread_mutex_init(&philo->left_fork, NULL))
		return (pthread_mutex_destroy(&philo->left_fork), 0);
	if (pthread_mutex_init(&philo->mutex_stop, NULL))
		return (pthread_mutex_destroy(&philo->left_fork), \
		pthread_mutex_destroy(&philo->mutex_stop), 0);
	if (pthread_mutex_init(&philo->mutex_t_meal, NULL))
		return (pthread_mutex_destroy(&philo->left_fork), \
		pthread_mutex_destroy(&philo->mutex_stop), \
		pthread_mutex_destroy(&philo->mutex_t_meal));
	return (1);
}

static int	init_mutex(t_philosophers *data)
{
	if (pthread_mutex_init(&data->config.mutex_console, NULL))
		return (ft_exit(data, MUTEX_ERR, 1, 0), 0);
	if (pthread_mutex_init(&data->config.mutex_eat, NULL))
		return (ft_exit(data, MUTEX_ERR, 2, 0), 0);
	if (pthread_mutex_init(&data->config.mutex_stop, NULL))
		return (ft_exit(data, MUTEX_ERR, 3, 0), 0);
	return (1);
}

int	init_philos(t_philosophers *data)
{
	int	i;

	i = -1;
	data->config.start_time = get_timestamp();
	while (++i < data->config.n_philo)
	{
		data->philo[i].config = &data->config;
		data->philo[i].pos = i + 1;
		data->philo[i].t_meal = data->config.start_time;
		data->philo[i].is_eating = 0;
		data->philo[i].is_dead = 0;
		data->philo[i].meals_count = 0;
		data->philo[i].stop = 0;
		data->philo[i].right_fork = NULL;
		if (!init_mutex_philo(&data->philo[i]))
			return (ft_exit(data, MUTEX_ERR, 3, i - 1), 0);
		if (i == data->config.n_philo - 1)
			data->philo[i].right_fork = &data->philo[0].left_fork;
		else
			data->philo[i].right_fork = &data->philo[i + 1].left_fork;
	}
	return (1);
}

int	init_data(t_philosophers *data, int ac, char **av)
{
	if (!init_config(data, ac, av))
		return (0);
	data->philo = malloc(sizeof(t_status) * data->config.n_philo);
	if (!data->philo)
		return (ft_exit(data, MEM_ERR, 0, 0), 0);
	if (!init_mutex(data))
		return (0);
	if (!init_philos(data))
		return (0);
	return (1);
}
