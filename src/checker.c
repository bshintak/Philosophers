/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:31:34 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/26 18:04:32 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	eat_check(t_ph *idk)
{
	pthread_mutex_lock(&idk->r_fork);
	print_info(idk, "has taken a fork right");
	pthread_mutex_lock(idk->l_fork);
	print_info(idk, "has taken a fork left");
	pthread_mutex_lock(&idk->arg->meal_check);
	print_info(idk, "is eating");
	idk->t_of_last_meal = getting_time();
	pthread_mutex_unlock(&idk->arg->meal_check);
	check_time(idk->arg->t_eat, idk);
	(idk->total_n_of_meals)++;
	pthread_mutex_unlock(&idk->r_fork);
	pthread_mutex_unlock(idk->l_fork);
}

void	death_check(t_philo *wtv)
{
	int	i;
	int	time;
	t_ph	*idk;

	idk = (t_ph *)wtv;
	time = getting_time();
	while (!idk->all_ate)
	{
		printf("entrou\n");
		i = -1;
		while (++i < idk->arg->n_philo && !(idk->died))
		{
			pthread_mutex_lock(&idk->arg->meal_check);
			if ((getting_time() - time) > idk->arg->t_die)
			{
				printf("heeeeyyy\n");
				print_info(idk, "died");
				idk->died = 1;
			}
			pthread_mutex_unlock(&idk->arg->meal_check);
			// usleep(100);
			if (idk->died)
			break;
		}
		if (idk->died)
			break;
	}
	while (idk->arg->n_t_philo_must_eat != -1 && i < idk->arg->n_philo 
		&& idk[i].total_n_of_meals >= idk->arg->n_t_philo_must_eat)
			i++;
	if (i == idk->arg->n_philo)
		idk->all_ate = 1;
	
}