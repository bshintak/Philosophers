/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:18:37 by bshintak          #+#    #+#             */
/*   Updated: 2022/09/30 15:18:11 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	separate_arguments(t_philo	*wtv, int argc, char **argv)
{
	wtv->n_philo = ft_atoi(argv[1]);
	wtv->t_die = ft_atoi(argv[2]);
	wtv->t_eat = ft_atoi(argv[3]);
	wtv->t_sleep = ft_atoi(argv[4]);
	if (wtv->n_philo < 1 || wtv->t_die < 1 || wtv->t_eat < 1
		|| wtv->t_sleep < 1)
	{
		printf("\033[;31mINVALID ARGUMENTS!\033[0m\n");
		return (1);
	}
	if (argc == 6 && ft_atoi(argv[5]) < 1)
	{
		printf("\033[;31mNO ONE CAN EAT!\033[0m\n");
		return (1);
	}
	if (argc == 6)
		wtv->n_t_philo_must_eat = ft_atoi(argv[5]);
	else
		wtv->n_t_philo_must_eat = -1;
	return (0);
}

t_ph	*init_philo(t_philo *wtv)
{
	int		i;
	t_ph	*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * wtv->n_philo);
	if (!philos)
		errors("error in memory allocation\n");
	while (i < wtv->n_philo)
	{
		philos[i].philo_id = i + 1;
		philos[i].total_n_of_meals = 0;
		philos[i].t_of_last_meal = getting_time();
		philos[i].arg = wtv;
		i++;
	}
	init_fork_mutex(wtv, philos);
	return (philos);
}

void	init_fork_mutex(t_philo *wtv, t_ph *philos)
{
	int	i;

	i = -1;
	while (++i < wtv->n_philo)
	{
		pthread_mutex_init(&philos[i].r_fork, NULL);
		if (i != 0)
			philos[i].l_fork = &philos[i - 1].r_fork;
		else if (i == 0)
			philos[i].l_fork = &philos[wtv->n_philo - 1].r_fork;
	}
	pthread_mutex_init(&wtv->death, NULL);
}
