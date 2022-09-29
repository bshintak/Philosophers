/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:08:02 by bshintak          #+#    #+#             */
/*   Updated: 2022/09/29 15:28:19 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	errors(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
	return (-1);
}

int	finish_program(t_ph *wtv)
{
	int	i;

	i = -1;
	while (++i < wtv->arg->n_philo)
		pthread_mutex_destroy(&wtv[i].r_fork);
	pthread_mutex_destroy(&wtv->arg->death);
	free(wtv);
	return (0);
}
