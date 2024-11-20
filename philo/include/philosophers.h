/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:12:23 by nfigueir          #+#    #+#             */
/*   Updated: 2024/11/21 09:41:12 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "error_message.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define PHILO_MAX 200

enum s_error
{
	ARG_ERR =	-42,
	MEM_ERR =	-43,
	MUTEX_ERR =	-44
};


typedef struct s_config
{
	int						n_philo;
	int						t_die;
	int						t_eat;
	int						t_sleep;
	int						stop;
	long long int			start_time;
	int						n_meals;
	struct s_philosophers	*philo;
	pthread_mutex_t			mutex_console;
	pthread_mutex_t			mutex_eat;
	pthread_mutex_t			mutex_stop;
}							t_config;

typedef struct s_status
{
	int				pos;
	int				meals_count; //TODO: Verificar depois
	int				is_eating;
	int				is_dead;
	long long int	t_meal;
	int				stop;
	pthread_t		thread;
	pthread_mutex_t	mutex_t_meal;
	pthread_mutex_t	mutex_stop;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	t_config		*config;
}					t_status;

typedef struct	s_philosophers
{
	t_config	config;
	t_status	*philo;
}				t_philosophers;

void	ft_exit(t_philosophers *data, int error, int mutex, int th);
void	ft_putstr_fd(char *s, int fd);
int		get_args(const char *str);
long long int	get_timestamp(void);
#endif
