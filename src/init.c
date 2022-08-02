/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:18:37 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/02 16:58:16 by bshintak         ###   ########.fr       */
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
		wtv->n_t_philo_must_eat = -1;
	printf("n_philo    = %d\n", wtv->n_philo);
	printf("time die   = %d\n", wtv->t_die);
	printf("time eat   = %d\n", wtv->t_eat);
	printf("time sleep = %d\n", wtv->t_sleep);
	printf("must eat   = %d\n", wtv->n_t_philo_must_eat);
}

void	*thread_function(void *arg)
{
	(void)arg;
	printf("thread\n");
	return (NULL);
}

void	create_threads(t_philo *wtv)
{
	int		i;
	//t_philo	*philo;
	

	i = 0;
	//philo = malloc(sizeof(t_philo) * wtv->n_philo + 1);
	while (i < wtv->n_philo)
	{
		pthread_create(&(wtv + i)->thr_id, NULL, &thread_function, wtv + i);
		pthread_join((wtv + i)->thr_id, NULL);
		sleep(1);
		i++;
	}
	//free (philo);
}