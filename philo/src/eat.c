/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:52:21 by nfigueir          #+#    #+#             */
/*   Updated: 2024/11/29 09:52:52 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	go_eat_even(t_status *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	ft_print_state(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->right_fork);
	ft_print_state(philo, "has taken a fork\n");
	ft_print_state(philo, "is eating\n");
	pthread_mutex_lock(&philo->mutex_t_meal);
	philo->t_meal = get_timestamp();
	pthread_mutex_unlock(&philo->mutex_t_meal);
	pthread_mutex_lock(&philo->config->mutex_eat);
	philo->meals_count++;
	pthread_mutex_unlock(&philo->config->mutex_eat);
	ft_usleep(philo->config->t_eat, philo->config->philo);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	go_eat(t_status *philo)
{
	if (is_philo_died(philo->config) || is_all_eat(philo->config->philo))
		return (se_ph_stop(philo), 0);
	if (philo->pos % 2 == 0)
		go_eat_even(philo);
	else
		if (!go_eat_odd(philo))
			return (set_ph_stop(philo), 0);
	return (1);

}
