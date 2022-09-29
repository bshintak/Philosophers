/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:12:11 by bshintak          #+#    #+#             */
/*   Updated: 2022/09/29 13:19:22 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	getting_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	pres_less_past(long long past, long long pres)
{
	return (pres - past);
}

int	ft_usleep(long long time, t_ph *wtv)
{
	long long	i;
	long long	wake_up;

	i = getting_time();
	wake_up = getting_time() + time;
	while (getting_time() < wake_up)
	{
		pthread_mutex_lock(&wtv->arg->death);
		if (wtv->arg->died == 1)
		{
			pthread_mutex_unlock(&wtv->arg->death);
			return (1);
		}
		pthread_mutex_unlock(&wtv->arg->death);
		if (pres_less_past(i, getting_time()) >= time)
			break ;
	}
	return (0);
}
