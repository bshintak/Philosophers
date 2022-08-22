/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:14:36 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/22 14:30:06 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define FIRST_ARG "[number of philosophers]"
# define SECOND_ARG "[time to die]"
# define THIRD_ARG "[time to eat]"
# define FOURTH_ARG "[time to sleep]"
# define FIFTH_ARG "[number of times each philosopher must eat] -> OPTIONAL"

typedef struct s_mutex
{
	int					eating;
	int					sleeping;
	int					thinking;
	int					died;
}				t_mutex;

typedef struct s_philo
{
	pthread_mutex_t		lock_print;
	pthread_mutex_t		*mutex_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		print;
	pthread_t			creat_th;
	t_mutex				mutex;
	int					ph_id;
	int					total_n_of_meals;
	int					limit_of_life;
	int					t_of_last_meal;
	int					t_to_eat;
	int					t_to_sleep;
	int					t_to_die;
	int					stop;
	int					n_forks;
	int					n_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					n_t_philo_must_eat;
	int					index;
	long long int		t_start;
}				t_philo;

/*	LIBFT	*/

int			ft_atoi(const char *str);

/*	INIT	*/

void		separate_arguments(t_philo	*wtv, int argc, char **argv);
void		print_info(t_philo *wtv, char *str);
void		init_fork_mutex(t_philo *wtv);
void		create_threads(t_philo *wtv);

/*	UTILS	*/

int			check_is_valid(char **argv);
int			errors(char *str);
long long	getting_time(void);

#endif