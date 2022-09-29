/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:06:55 by bshintak          #+#    #+#             */
/*   Updated: 2022/09/29 15:19:24 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	print_info(t_ph *wtv, char *str)
{
	pthread_mutex_lock(&wtv->arg->death);
	if (wtv->arg->died == 1)
	{
		pthread_mutex_unlock(&wtv->arg->death);
		return (1);
	}
	printf("%lld %d %s\n", getting_time() - wtv->arg->first_time,
		wtv->philo_id, str);
	pthread_mutex_unlock(&wtv->arg->death);
	return (0);
}

int	print_info_eat(t_ph *wtv, char *str)
{
	pthread_mutex_lock(&wtv->arg->death);
	if (wtv->arg->died == 1)
	{
		pthread_mutex_unlock(&wtv->arg->death);
		return (1);
	}
	printf("%lld %d %s\n", getting_time() - wtv->arg->first_time,
		wtv->philo_id, str);
	wtv->total_n_of_meals++;
	wtv->t_of_last_meal = getting_time();
	pthread_mutex_unlock(&wtv->arg->death);
	return (0);
}
