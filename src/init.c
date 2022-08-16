/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:18:37 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/16 17:19:40 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	separate_arguments(t_philo	*wtv, int argc, char **argv)
{
	wtv->n_philo = ft_atoi(argv[1]);
	wtv->forks = wtv->n_philo;
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

void	init_fork_mutex(t_philo *wtv)
{
	int	i;

	wtv->mutex_fork = (pthread_mutex_t *)malloc(sizeof
			(pthread_mutex_t) * wtv->forks);
	if (!wtv->mutex_fork)
		errors("error in mutex memory allocation\n");
	i = 0;
	while (i++ < wtv->forks)
	{
		if (pthread_mutex_init(wtv->mutex_fork, NULL))
			errors("error to initialize fork mutex!\n");
	}
}

void	*thread_function(void *arg)
{
	t_philo	*wtv;

	wtv = (t_philo *)arg;
	print_info(wtv, "tooopp");
	printf("thread\n");
	return (NULL);
}

void	create_threads(t_philo *wtv)
{
	int	i;

	i = 0;
	wtv->t_start = getting_time();
	while (i++ < wtv->forks)
	{
		if (pthread_create(&(wtv + i)->thr_id, NULL, &thread_function, wtv + i))
			errors("error to create threads!\n");
		pthread_detach((wtv + i)->thr_id);
		usleep(100);
	}
	i = 0;
	while (i++ < wtv->forks)
		pthread_mutex_destroy(&wtv->mutex_fork[i]);
}

void	print_info(t_philo *wtv, char *str)
{
	pthread_mutex_lock(&wtv->print);
	printf("%lld %d %s\n", getting_time() - wtv->t_start, wtv->n_philo, str);
	printf("%d\n", wtv->n_philo);
}