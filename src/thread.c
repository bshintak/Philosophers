/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:50:46 by bshintak          #+#    #+#             */
/*   Updated: 2022/09/30 15:53:43 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	create_threads(t_philo *wtv)
{
	int			i;
	t_ph		*ph;

	ph = init_philo(wtv);
	wtv->first_time = getting_time();
	i = -1;
	while (++i < wtv->n_philo)
	{
		if (pthread_create(&ph[i].self, NULL, &routine_function, &ph[i]))
			errors("error to create threads!\n");
	}
	death_check(ph);
	join_threads(ph, wtv);
}

void	*routine_function(void *arg)
{
	t_ph	*wtv;

	wtv = (t_ph *)arg;
	while (1)
	{
		if (eat_check(wtv))
			break ;
		if (print_info(wtv, SLEEP))
			break ;
		ft_usleep(wtv->arg->t_sleep, wtv);
		if (print_info(wtv, THINK))
			break ;
	}
	return (NULL);
}

void	join_threads(t_ph *philos, t_philo *wtv)
{
	int	i;

	i = -1;
	while (++i < wtv->n_philo)
	{
		if (pthread_join(philos[i].self, NULL))
			errors("error to join threads!\n");
	}
	finish_program(philos);
}
