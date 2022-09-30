/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:31:34 by bshintak          #+#    #+#             */
/*   Updated: 2022/09/30 16:13:26 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	eat_1(t_ph *wtv)
{
	pthread_mutex_lock(wtv->l_fork);
	if (print_info(wtv, FORK))
	{
		pthread_mutex_unlock(wtv->l_fork);
		return (1);
	}
	pthread_mutex_lock(&wtv->r_fork);
	if (print_info(wtv, FORK))
	{
		pthread_mutex_unlock(wtv->l_fork);
		pthread_mutex_unlock(&wtv->r_fork);
		return (1);
	}
	return (0);
}

int	eat_2(t_ph *wtv)
{
	pthread_mutex_lock(&wtv->r_fork);
	if (print_info(wtv, FORK))
	{
		pthread_mutex_unlock(&wtv->r_fork);
		return (1);
	}
	pthread_mutex_lock(wtv->l_fork);
	if (print_info(wtv, FORK))
	{
		pthread_mutex_unlock(&wtv->r_fork);
		pthread_mutex_unlock(wtv->l_fork);
		return (1);
	}
	return (0);
}

int	eat_check(t_ph *wtv)
{
	if (wtv->philo_id % 2 == 0)
	{
		if (eat_1(wtv) == 1)
			return (1);
	}
	else
	{
		if (eat_2(wtv) == 1)
			return (1);
	}
	print_info_eat(wtv, EAT);
	ft_usleep(wtv->arg->t_eat, wtv);
	if (wtv->arg->n_philo != 1)
	{
		pthread_mutex_unlock(wtv->l_fork);
		pthread_mutex_unlock(&wtv->r_fork);
	}
	else
		return (1);
	return (0);
}
