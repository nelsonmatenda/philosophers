/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:03:27 by nfigueir          #+#    #+#             */
/*   Updated: 2024/11/24 10:43:01 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	get_args(const char *str)
{
	long int	n;

	while (*str == ' ' || *str == '\f' || *str == '\n' || \
			*str == '\r' || *str == '\t' || *str == '\v')
		str++;
	n = 0;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		n = n * 10 + *str - '0';
		if (n > INT_MAX)
			return (-1);
		str++;
	}
	if (*str != '\0')
		return (-1);
	return ((int)n);
}

long long int	get_timestamp(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long int time_in_ms, t_philosophers *data)
{
	long int	cur_time;

	cur_time = 0;
	cur_time = get_timestamp();
	while ((get_timestamp() - cur_time) < time_in_ms)
	{
		pthread_mutex_lock(&data->config.mutex_stop);
		if (data->config.stop)
		{
			pthread_mutex_unlock(&data->config.mutex_stop);
			break ;
		}
		pthread_mutex_unlock(&data->config.mutex_stop);
		if (time_in_ms > 10000000)
			usleep(time_in_ms / 100000);
		else
			usleep(time_in_ms / 10);
	}
}
