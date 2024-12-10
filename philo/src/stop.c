/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:39:32 by nfigueir          #+#    #+#             */
/*   Updated: 2024/12/10 09:43:26 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_stop_state(t_philosophers *data)
{
	int	i;
	int	ph_stopped;

	ph_stopped = 0;
	i = -1;
	while (++i < data->config.n_philo)
	{
		pthread_mutex_lock(&data->philo[i].mutex_stop);
		if (data->philo[i].stop)
			ph_stopped++;
		pthread_mutex_unlock(&data->philo[i].mutex_stop);
	}
	if (ph_stopped == data->config.n_philo)
		return (1);
	return (0);
}
