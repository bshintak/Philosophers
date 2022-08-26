/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:18:37 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/26 18:05:39 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	separate_arguments(t_philo	*wtv, int argc, char **argv)
{
	wtv->n_philo = ft_atoi(argv[1]);
	wtv->t_die = ft_atoi(argv[2]);
	wtv->t_eat = ft_atoi(argv[3]);
	wtv->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		wtv->n_t_philo_must_eat = ft_atoi(argv[5]);
	else
		wtv->n_t_philo_must_eat = 0;
}

t_ph	*init_philo(t_philo *idk)
{
	int		i;
	t_ph	*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * idk->n_philo);
	if (!philos)
		errors("error in memory allocation\n");
	while (i < idk->n_philo)
	{
		philos[i].philo_id = i + 1;
		philos[i].total_n_of_meals = 0;
		philos[i].t_of_last_meal = getting_time();
		philos[i].limit_of_life = idk->t_die;
		philos[i].arg = idk;
		i++;
	}
	init_fork_mutex(idk, philos);
	return (philos);
}

void	init_fork_mutex(t_philo *wtv, t_ph *philos)
{
	int	i;
	
	i = -1;
	while(++i < wtv->n_philo)
	{
		pthread_mutex_init(&philos[i].r_fork, NULL);
		if (i != 0)
			philos[i].l_fork = &philos[i - 1].r_fork;
		else if (i == 0)
			philos[i].l_fork = &philos[wtv->n_philo - 1].r_fork;
	}
	pthread_mutex_init(&wtv->print, NULL);
	pthread_mutex_init(&wtv->meal_check, NULL);
}

void	*routine_function(void *arg)
{
	t_ph	*idk;

	idk = (t_ph *)arg;
	idk->all_ate = 0;
	idk->died = 0;
	while (!(idk->died))
	{
		eat_check(idk);
		if (idk->all_ate)
			break ;
		print_info(idk, "is sleeping");
		check_time(idk->arg->t_sleep, idk);
		print_info(idk, "is thinking");
	}
	return(NULL);
}

void	create_threads(t_philo *wtv)
{
	int			i;
	t_ph		*philos;

	philos = init_philo(wtv);
	wtv->first_time = getting_time();
	i = 0;
	while (i < wtv->n_philo)
	{
		if (pthread_create(&philos[i].self, NULL, &routine_function, &philos[i]))
			errors("error to create threads!\n");
		philos[i].t_of_last_meal = getting_time();
		i++;
		usleep(1000000);
	}
	// death_check(wtv);
	i = -1;
	while (++i < wtv->n_philo)
		pthread_join(philos[i].self, NULL);
	while (++i < wtv->n_philo)
		pthread_mutex_destroy(&philos[i].r_fork);
	pthread_mutex_destroy(&philos[i].arg->meal_check);
	free (philos);
}
