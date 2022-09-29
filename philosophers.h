/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:14:36 by bshintak          #+#    #+#             */
/*   Updated: 2022/09/29 15:26:16 by bshintak         ###   ########.fr       */
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

# define EAT "\033[;33mis eating\033[0m"
# define DIED  "\033[;31mdied\033[0m"
# define SLEEP "\033[;34mis sleeping\033[0m"
# define THINK "\033[;35mis thinking\033[0m"
# define FORK "\033[;32mhas taken a fork\033[0m"

typedef struct s_ph
{
	int					all_ate;
	int					philo_id;
	int					total_n_of_meals;
	time_t				t_of_last_meal;
	pthread_t			self;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		r_fork;
	struct s_philo		*arg;
}				t_ph;

typedef struct s_philo
{
	int					died;
	int					n_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					n_t_philo_must_eat;
	long long			first_time;
	pthread_mutex_t		death;
}				t_philo;

/*		LIBFT		*/
int			ft_atoi(const char *str);

/*		INIT		*/
t_ph		*init_philo(t_philo *idk);
void		separate_arguments(t_philo	*wtv, int argc, char **argv);
void		init_fork_mutex(t_philo *wtv, t_ph *philos);

/*		THREAD		*/
void		create_threads(t_philo *wtv);
void		*routine_function(void *arg);
void		join_threads(t_ph *philos, t_philo *wtv);

/*		PRINT		*/
int			print_info(t_ph *wtv, char *str);
int			print_info_eat(t_ph *wtv, char *str);

/*		TIME		*/
int			ft_usleep(long long time, t_ph *wtv);
long long	pres_less_past(long long past, long long pres);
long long	getting_time(void);

/*		FINISH		*/
int			errors(char *str);
int			finish_program(t_ph *idk);

/*		ARGS_CHECKER		*/
int			check_is_valid(char **argv);

/*		EAT_CHECKER		*/
int			eat_check(t_ph *idk);

/*		DEATH_CHECKER		*/
int			t_all_eat(t_ph *idk);
void		death_check(t_ph *wtv);

#endif