/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:24:52 by nfigueir          #+#    #+#             */
/*   Updated: 2024/12/10 10:15:41 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*set_ph_stop(t_status *philo)
{
	pthread_mutex_lock(&(philo->mutex_stop));
	philo->stop = 1;
	pthread_mutex_unlock(&(philo->mutex_stop));
	return (NULL);
}

int	is_philo_died(t_config *config)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&config->mutex_stop);
	if (config->stop)
		res = 1;
	pthread_mutex_unlock(&config->mutex_stop);
	return (res);
}

int	is_all_eat(t_philosophers *data)
{
	int	i;
	int	ph_has_eat;

	if (data->config.n_meals == -1)
		return (0);
	ph_has_eat = 0;
	i = -1;
	while (++i < data->config.n_philo)
	{
		pthread_mutex_lock(&data->config.mutex_eat);
		if (data->philo[i].meals_count >= data->config.n_meals)
			ph_has_eat++;
		pthread_mutex_unlock(&data->config.mutex_eat);
	}
	return (ph_has_eat == data->config.n_philo);
}

static void	*ph_life(void *void_philo)
{
	t_status	*philo;

	philo = (t_status *)void_philo;
	if (philo->pos % 2 == 0)
		ft_usleep(philo->config->t_eat / 10, philo->config->philo);
	while (!is_philo_died(philo->config))
	{
		if (!go_eat(philo))
			return (NULL);
		if (!go_sleep(philo))
			return (NULL);
		if (!go_think(philo))
			return (NULL);
	}
	return (set_ph_stop(philo));
}

int	start(t_philosophers *data)
{
	int			i;
	pthread_t	th_monitoring;

	i = -1;
	while (++i < data->config.n_philo)
	{
		if (pthread_create(&(data->philo[i].thread), NULL, ph_life, \
			&data->philo[i]))
			return (ft_exit(data, TH_ERR, 3, i), 0);
	}
	pthread_create(&th_monitoring, NULL, monitoring, data);
	pthread_join(th_monitoring, NULL);
	i = -1;
	while (++i < data->config.n_philo)
		pthread_join(data->philo[i].thread, NULL);
	return (1);
}
