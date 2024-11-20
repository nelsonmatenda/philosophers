/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:04:53 by nfigueir          #+#    #+#             */
/*   Updated: 2024/11/20 10:19:09 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	erro_print(int error)
{
	if (error == ARG_ERR)
		ft_putstr_fd(ARG_ERR_MSG, 2);
}

void	ft_exit(t_philosophers *data, int error, int mutex, int th)
{
	if (error < 0)
		erro_print(error);
	if (data->status)
		free(data->status);
}
