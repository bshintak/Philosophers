/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:05:31 by bshintak          #+#    #+#             */
/*   Updated: 2022/09/29 17:21:46 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int one_philo(t_ph *wtv)
{
	if (wtv->arg->n_philo == 1)
	{
		usleep(wtv->arg->t_die * 1000);
		printf("%lld %d %s\n", getting_time() - wtv->arg->first_time,
				wtv->philo_id, DIED);
		wtv->arg->died = 1;
		pthread_mutex_unlock(&wtv->arg->death);
		return (1);
	}
	return (0);
}

void	death_check(t_ph *wtv)
{
	int		i;

	while (wtv->all_ate != 1)
	{
		i = -1;
		pthread_mutex_lock(&wtv->arg->death);
		while (++i < wtv->arg->n_philo && wtv->arg->died != 1)
		{
			if (pres_less_past(wtv[i].t_of_last_meal,
					getting_time()) > wtv->arg->t_die)
			{
				printf("%lld %d %s\n", getting_time() - wtv->arg->first_time,
					wtv[i].philo_id, DIED);
				wtv->arg->died = 1;
				pthread_mutex_unlock(&wtv->arg->death);
				return ;
			}
			if (t_all_eat(wtv) == 1)
				return ;
			if (one_philo(wtv) == 1)
				return ;
		}
		pthread_mutex_unlock(&wtv->arg->death);
		usleep(1960);
	}
}

int	t_all_eat(t_ph *wtv)
{
	int	j;

	j = 0;
	while (wtv->arg->n_t_philo_must_eat != -1 && j < wtv->arg->n_philo
		&& wtv[j].total_n_of_meals >= wtv->arg->n_t_philo_must_eat)
		j++;
	if (j == wtv->arg->n_philo)
	{
		printf("\033[;31mAll philosophers ate at least %d times\033[0m\n",
			wtv->arg->n_t_philo_must_eat);
		wtv->arg->died = 1;
		pthread_mutex_unlock(&wtv->arg->death);
		return (1);
	}
	return (0);
}
