/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:45:20 by nfigueir          #+#    #+#             */
/*   Updated: 2024/11/20 10:35:14 by nfigueir         ###   ########.fr       */
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

int	init_data(t_philosophers *data, int ac, char **av)
{
	if (!init_config(data, ac, av))
		return (0);
}
