/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:04:53 by nfigueir          #+#    #+#             */
/*   Updated: 2024/11/15 12:43:40 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_exit(t_philosophers *data, int error, char *msg)
{
	if (data->philo)
		free(data->philo);
	if (msg)
		ft_putstr_fd(msg, 3);
}
