/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:04:53 by nfigueir          #+#    #+#             */
/*   Updated: 2024/11/22 08:11:40 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	erro_print(int error)
{
	if (error == ARG_ERR)
		ft_putstr_fd(ARG_ERR_MSG, 2);
	if (error == MEM_ERR)
		ft_putstr_fd(MEM_ERR_MSG, 2);
}

int	destroy_mutex(t_philosophers *data, int count)
{
	if (count == 3)
		pthread_mutex_destroy(&(data->config.mutex_stop));
	if (count >= 2)
		pthread_mutex_destroy(&(data->config.mutex_eat));
	if (count >= 1)
		pthread_mutex_destroy(&(data->config.mutex_console));
	return (1);
}

int destroy_thread(t_philosophers *data, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		pthread_mutex_destroy(&data->philo[i].left_fork);
		pthread_mutex_destroy(&data->philo[i].mutex_t_meal);
		pthread_mutex_destroy(&data->philo[i].mutex_stop);
		pthread_join(data->philo[i].thread, NULL);
	}
	return (1);
}

void	ft_exit(t_philosophers *data, int error, int mutex, int th)
{
	pthread_mutex_lock(&data->config.mutex_stop);
	if (data->config.stop == 0)
		data->config.stop = 1;
	pthread_mutex_unlock(&data->config.mutex_stop);
	if (error < 0)
		erro_print(error);
	if (mutex > 0)
		destroy_mutex(data, mutex);
	if (th > 0)
		destroy_thread(data, th);
	if (data->philo)
		free(data->philo);
}
