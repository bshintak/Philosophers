/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:14:36 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/16 17:15:56 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_mutex
{
	int					eating;
	int					sleeping;
	int					thinking;
	int					died;
}				t_mutex;

typedef struct s_philo
{
	pthread_mutex_t		*mutex_fork;
	pthread_mutex_t		print;
	pthread_t			thr_id;
	t_mutex				mutex;
	int					forks;
	int					n_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					n_t_philo_must_eat;
	long long int		t_start;
}				t_philo;

int			ft_atoi(const char *str);

/*	INIT	*/

void		separate_arguments(t_philo	*wtv, int argc, char **argv);
void		print_info(t_philo *wtv, char *str);
void		init_fork_mutex(t_philo *wtv);
void		create_threads(t_philo *wtv);

/*	UTILS	*/

int			errors(char *str);
long long	getting_time(void);

#endif