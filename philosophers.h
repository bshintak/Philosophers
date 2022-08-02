/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:14:36 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/02 16:38:41 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_mutex
{
	int		fork;
	int		eating;
	int		sleeping;
	int		thinking;
	int		died;
}				t_mutex;

typedef struct s_philo
{
	pthread_t	thr_id;
	t_mutex		mutex;
	int			n_philo;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_t_philo_must_eat;
}				t_philo;

int		ft_atoi(const char *str);

void	separate_arguments(t_philo	*wtv, int argc, char **argv);
void	create_threads(t_philo *wtv);

#endif