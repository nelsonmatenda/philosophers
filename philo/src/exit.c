/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:04:53 by nfigueir          #+#    #+#             */
/*   Updated: 2024/11/21 09:23:24 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	erro_print(int error)
{
	if (error == ARG_ERR)
		ft_putstr_fd(ARG_ERR_MSG, 2);
	else if (error = MEM_ERR)
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

void	ft_exit(t_philosophers *data, int error, int mutex, int th)
{
	if (error < 0)
		erro_print(error);
	if (data->status)
		free(data->status);
	if (mutex > 0)
		destroy_mutex(data, mutex);
}
