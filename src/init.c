/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:18:37 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/23 14:32:39 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	separate_arguments(t_philo	*wtv, int argc, char **argv)
{
	wtv->n_philo = ft_atoi(argv[1]);
	wtv->n_forks = wtv->n_philo;
	wtv->t_die = ft_atoi(argv[2]);
	wtv->t_eat = ft_atoi(argv[3]);
	wtv->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		wtv->n_t_philo_must_eat = ft_atoi(argv[5]);
	else
		wtv->n_t_philo_must_eat = 0;
	printf("n_philo    = %d\n", wtv->n_philo);
	printf("time die   = %d\n", wtv->t_die);
	printf("time eat   = %d\n", wtv->t_eat);
	printf("time sleep = %d\n", wtv->t_sleep);
	printf("must eat   = %d\n", wtv->n_t_philo_must_eat);
}

t_ph	*init_philo(t_philo *idk)
{
	int		i;
	t_ph	*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * idk->n_philo);
	while (i < idk->n_philo)
	{
		philos[i].philo_id = i + 1;
		philos[i].n_philo = idk->n_philo;
		philos[i].total_n_of_meals = 0;
		// philos[i].total_n_of_meals_1 = idk->n_of_meals;
		philos[i].t_to_eat = idk->t_eat;
		philos[i].t_to_sleep = idk->t_sleep;
		philos[i].t_to_die = idk->t_die;
		// philos[i].t_of_last_meal = getting_time();
		philos[i].limit_of_life = idk->t_die;
		philos[i].stop = 0;
		philos[i].arg = idk;
		i++;
	}
	init_fork_mutex(idk, philos);

	printf ("----------------------------------------\n");
	printf ("philo id = %d\n", philos->philo_id);
	printf ("num philo = %d\n", philos->n_philo);
	printf ("total meals = %d\n", philos->total_n_of_meals);
	// printf ("meals 2 = %d\n", philos->total_n_of_meals_1);
	printf ("time eat = %d\n", philos->t_to_eat);
	printf ("time sleep = %d\n", philos->t_to_sleep);
	printf ("time die = %d\n", philos->t_to_die);
	// printf ("last meal = %ld\n", philos->t_of_last_meal);
	printf ("limit life = %ld\n", philos->limit_of_life);
	printf ("stop = %d\n", philos->stop);
	// printf ("%d\n", philos->l_fork);
	// printf ("%d\n", philos->r_fork);
	//free (philos);
// 	wtv->index = i + 1;
// 	wtv->l_fork = forks + i;
// 	wtv->r_fork = forks + i - 1;
// 	printf("aqui!\n");
	return (philos);
}

void	init_fork_mutex(t_philo *wtv, t_ph *philos)
{
	int	i;
	
	i = -1;
	// pthread_mutex_t	*tmp;
	// t_ph	*idk;
	// idk = (t_ph *)wtv;
	// tmp = (pthread_mutex_t *)malloc(sizeof
	// 		(pthread_mutex_t ) * n_ph);
	// if (!tmp)
	// 	errors("error in mutex memory allocation\n");
	// while (n_ph--)
	// {
	// 	if (pthread_mutex_init(&tmp[n_ph], NULL))
	// 		errors("error to initialize fork mutex!\n");
	// }
	while(++i < wtv->n_philo)
	{
		pthread_mutex_init(&philos[i].r_fork, NULL);
		// pthread_mutex_init(philos->r_fork, NULL);
		if (i != 0)
			philos[i].l_fork = &philos[i - 1].r_fork;
		else if (i == 0)
			philos[i].l_fork = &philos[wtv->n_philo - 1].r_fork;
	}
	//pthread_mutex_init(&wtv->lock_print, NULL);
	pthread_mutex_init(&wtv->print, NULL);
	// wtv->mutex_fork = tmp;
	//create_threads(wtv);
	//pthread_mutex_destroy(&wtv->lock_print);
	// n_ph = wtv->n_philo;
	// while(n_ph--)
	// {
	// }
	// pthread_mutex_destroy(tmp);
	//free(tmp);
}

void	*routine_function(void *arg)
{
	t_ph	*idk;
	// t_ph	*wtv;

	// (void)arg;
	idk = (t_ph *)arg;
	// wtv = (t_ph *)arg;
	// print_info(idk, "is thinking");
	// pthread_mutex_lock(&idk->arg->lock_print);
	// print_info(idk, "has taken a fork");
	// pthread_mutex_unlock(&idk->arg->lock_print);
	pthread_mutex_lock(&idk->r_fork);
	print_info(idk, "has taken a fork right");
	pthread_mutex_lock(idk->l_fork);
	print_info(idk, "has taken a fork left");
	pthread_mutex_unlock(idk->l_fork);
	pthread_mutex_unlock(&idk->r_fork);
	print_info(idk, "is eating");
	print_info(idk, "is sleeping");
	print_info(idk, "is thinking");
	// pthread_mutex_destroy(&wtv->arg->lock_print);
	return(NULL);
}

void	create_threads(t_philo *wtv)
{
	int			i;
	t_ph		*philos;

	philos = init_philo(wtv);
	// wtv->t_start = getting_time();
	// wtv->l_fork = wtv->n_forks;
	// wtv->r_fork = wtv->n_forks - 1;
	i = -1;
	while (++i < wtv->n_philo)
	{
		// printf("new thread\n");
		// if (pthread_create((&(wtv + i)->creat_th), NULL, &routine_function, wtv + i))
		// 	errors("error to create threads!\n");
		if (pthread_create(&philos[i].self, NULL, &routine_function, &philos[i]))
			errors("error to create threads!\n");
		usleep(1000000);
	}
	i = -1;
	while (++i < wtv->n_philo)
		pthread_join(philos[i].self, NULL);
	// i = 0;
	// while (i++ < wtv->n_philo)
	// 	pthread_mutex_destroy(wtv->creat_th);
}

void	print_info(t_ph *wtv, char *str)
{
	pthread_mutex_lock(&wtv->arg->print);
	printf("%lld %d %s\n", getting_time(), wtv->philo_id, str);
	//printf("%d\n", wtv->n_philo);
	usleep(1000000);
	pthread_mutex_unlock(&wtv->arg->print);
}
