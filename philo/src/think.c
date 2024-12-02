/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:45:26 by nfigueir          #+#    #+#             */
/*   Updated: 2024/12/02 08:48:40 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	go_think(t_status *philo)
{
	if (is_philo_died(philo->config) || is_all_eat(philo->config->philo))
		return (set_ph_stop(philo), 0);
	ft_print_state(philo, "is thinking\n");
	if (philo->config->n_philo % 2 != 0)
		ft_usleep(philo->config->t_eat / 10, philo->config->philo);
	return (1);
}
