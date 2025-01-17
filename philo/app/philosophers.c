/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:11:02 by nfigueir          #+#    #+#             */
/*   Updated: 2024/12/10 10:17:34 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int ac, char **av)
{
	t_philosophers	data;

	memset(&data, 0, sizeof(data));
	if (ac < 5 || ac > 6)
		return (ft_exit(&data, ARG_ERR, 0, 0), EXIT_FAILURE);
	if (!init_data(&data, ac, av))
		return (EXIT_FAILURE);
	if (!start(&data))
		return (EXIT_FAILURE);
	while (1)
	{
		ft_usleep(data.config.t_eat / 10, &data);
		if (check_stop_state(&data))
			break ;
	}
	ft_exit(&data, 0, 3, data.config.n_philo);
	return (EXIT_SUCCESS);
}
