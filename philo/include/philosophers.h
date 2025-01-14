/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:12:23 by nfigueir          #+#    #+#             */
/*   Updated: 2024/12/10 10:16:03 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include "error_message.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define PHILO_MAX 200

enum e_error
{
	ARG_ERR =	-42,
	MEM_ERR =	-43,
	MUTEX_ERR =	-44,
	TH_ERR = -45,
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
	int				meals_count;
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

typedef struct s_philosophers
{
	t_config	config;
	t_status	*philo;
}				t_philosophers;

void			ft_exit(t_philosophers *data, int error, int mutex, int th);
void			ft_putstr_fd(char *s, int fd);
int				get_args(const char *str);
long long int	get_timestamp(void);
int				ft_isdigit(int c);
int				init_data(t_philosophers *data, int ac, char **av);
int				is_philo_died(t_config *config);
int				is_all_eat(t_philosophers *data);
void			*set_ph_stop(t_status *philo);
void			ft_print_state(t_status *philo, char *s);
void			ft_usleep(long int time_in_ms, t_philosophers *data);
int				go_eat(t_status *philo);
int				go_sleep(t_status *philo);
int				go_think(t_status *philo);
void			*monitoring(void *void_data);
int				start(t_philosophers *data);
int				check_stop_state(t_philosophers *data);

#endif
