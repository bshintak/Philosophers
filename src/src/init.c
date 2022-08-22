/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:18:37 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/22 12:01:53 by bshintak         ###   ########.fr       */
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

void	init_philo(t_philo *wtv, int i, pthread_mutex_t *forks)
{
	wtv->index = i + 1;
	wtv->l_fork = forks + i;
	wtv->r_fork = forks + i - 1;
	printf("aqui!\n");
}

void	init_fork_mutex(t_philo *wtv)
{
	int				n_ph;
	pthread_mutex_t	*tmp;

	n_ph = wtv->n_philo;
	tmp = (pthread_mutex_t *)malloc(sizeof
			(pthread_mutex_t ) * n_ph);
	if (!tmp)
		errors("error in mutex memory allocation\n");
	while (n_ph--)
	{
		if (pthread_mutex_init(&tmp[n_ph], NULL))
			errors("error to initialize fork mutex!\n");
	}
	pthread_mutex_init(&wtv->lock_print, NULL);
	// wtv->mutex_fork = tmp;
	create_threads(wtv);
	pthread_mutex_destroy(tmp);
	free(tmp);
}

void	*routine_function(void *arg)
{
	// t_philo	*wtv;

	(void)arg;
	printf("thread\n");
	// print_info(wtv, "is thinking");
	// pthread_mutex_lock(wtv->l_fork);
	// print_info(wtv, "has taken a fork");
	// pthread_mutex_lock(wtv->r_fork);
	// print_info(wtv, "has taken a fork");
	// print_info(wtv, "is eating");
	// pthread_mutex_unlock(wtv->r_fork);
	// pthread_mutex_unlock(wtv->l_fork);
	return(NULL);
}

void	create_threads(t_philo *wtv)
{
	int			i;
	// wtv->t_start = getting_time();
	// wtv->l_fork = wtv->n_forks;
	// wtv->r_fork = wtv->n_forks - 1;
	i = 0;
	while (i++ < wtv->n_philo)
	{
		if (pthread_create((&(wtv + i)->creat_th), NULL, &routine_function, wtv + i))
			errors("error to create threads!\n");
		pthread_join((wtv + i)->creat_th, NULL);
		usleep(100);
	}
	// i = 0;
	// while (i++ < wtv->n_forks)
	// 	pthread_mutex_destroy(&wtv->mutex_fork[i]);
}

void	print_info(t_philo *wtv, char *str)
{
	pthread_mutex_lock(&wtv->print);
	printf("%lld %d %s\n", getting_time() - wtv->t_start, wtv->n_philo, str);
	//printf("%d\n", wtv->n_philo);
	pthread_mutex_unlock(&wtv->print);
}
