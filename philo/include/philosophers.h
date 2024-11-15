/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:12:23 by nfigueir          #+#    #+#             */
/*   Updated: 2024/11/15 12:17:17 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdlib.h>

typedef enum s_error
{
	ARG_ERR = -42,
};


typedef struct s_status
{
	/* data */
}	t_status;

typedef struct s_philo
{
	/* data */
}	t_philo;

typedef struct	s_philosophers
{
	t_status	status;
	t_philo		*philo;
}				t_philosophers;

void	ft_exit(t_philosophers *data, int error, char *msg);
void	ft_putstr_fd(char *s, int fd);

#endif
