/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:41:59 by nfigueir          #+#    #+#             */
/*   Updated: 2024/12/10 10:10:10 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	go_sleep(t_status *philo)
{
	if (is_philo_died(philo->config) \
		|| is_all_eat(philo->config->philo))
		return (set_ph_stop(philo), 0);
	ft_print_state(philo, "is sleeping\n");
	ft_usleep(philo->config->t_sleep, philo->config->philo);
	return (1);
}
