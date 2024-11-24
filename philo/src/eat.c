/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:52:21 by nfigueir          #+#    #+#             */
/*   Updated: 2024/11/24 12:04:45 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	go_eat(t_status *philo)
{
	if (is_philo_died(philo->config) || is_all_eat(philo->config->philo))
		
}
