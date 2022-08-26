/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:14:36 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/26 18:02:53 by bshintak         ###   ########.fr       */
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

typedef struct s_ph
{
	int					all_ate;
	int					died;
	int					philo_id;
	int					total_n_of_meals;
	time_t				limit_of_life;
	time_t				t_of_last_meal;
	pthread_t			self;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		r_fork;
	struct s_philo		*arg;
}				t_ph;

typedef struct s_philo
{
	int					n_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					n_t_philo_must_eat;
	pthread_mutex_t		print;
	pthread_mutex_t		meal_check;
	long long			first_time;
	struct s_ph			*str;
}				t_philo;

/*		LIBFT		*/

int			ft_atoi(const char *str);

/*		INIT		*/

void		separate_arguments(t_philo	*wtv, int argc, char **argv);
void		init_fork_mutex(t_philo *wtv, t_ph *philos);
void		create_threads(t_philo *wtv);
t_ph		*init_philo(t_philo *idk);

/*		CHECKER		*/

void	eat_check(t_ph *idk);
void	death_check(t_philo *idk);

/*		UTILS		*/

void		print_info(t_ph *wtv, char *str);
long long	check_time(long long t, t_ph *wtv);
int			check_is_valid(char **argv);
int			errors(char *str);
long long	getting_time(void);

#endif