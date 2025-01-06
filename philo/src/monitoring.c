/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:50:26 by nfigueir          #+#    #+#             */
/*   Updated: 2024/12/10 10:02:57 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ph_died(t_status *philo)
{
	pthread_mutex_lock(&philo->config->mutex_stop);
	philo->config->stop = 1;
	pthread_mutex_unlock(&philo->config->mutex_stop);
	pthread_mutex_lock(&philo->config->mutex_console);
	printf("%lld %d %s", get_timestamp() - philo->config->start_time, \
		philo->pos, "died\n");
	pthread_mutex_unlock(&philo->config->mutex_console);
}

static void	print_all_eat(t_philosophers *data)
{
	pthread_mutex_lock(&data->config.mutex_console);
	if (data->config.n_meals > 1)
		printf("%lld All philosophers has eaten their %d meals\n", \
			get_timestamp() - data->config.start_time, data->config.n_meals);
	else
		printf("%lld All philosophers has eaten their %d meal\n", \
			get_timestamp() - data->config.start_time, data->config.n_meals);
	pthread_mutex_unlock(&data->config.mutex_console);
}

void	*monitoring(void *void_data)
{
	t_philosophers	*data;
	int				i;

	data = (t_philosophers *)void_data;
	while(!data->config.stop)
	{
		i = -1;
		while (++i < data->config.n_philo)
		{
			pthread_mutex_lock(&data->philo[i].mutex_t_meal);
			if ((get_timestamp() - data->philo[i].t_meal) >= \
				data->config.t_die)
			{
				ph_died(&data->philo[i]);
				pthread_mutex_unlock(&data->philo[i].mutex_t_meal);
				return (NULL);
			}
			pthread_mutex_unlock(&data->philo[i].mutex_t_meal);
		}
		if (is_all_eat(data))
			return (print_all_eat(data), NULL);
		usleep(1000);
	}
	return (NULL);
}
