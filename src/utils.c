/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:12:11 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/26 17:58:04 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_is_valid(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (argv[i][j] == 32 || (argv[i][j] >= 9 && argv[i][j] <= 13))
				j++;
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return(1);
			j++;
		}
		i++;
	}
	return(0);
}

int	errors(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
	return (-1);
}

long long	getting_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	// return (time.tv_sec);
}

long long	check_time(long long t, t_ph *wtv)
{
	long long	i;

	i = getting_time();
	while (!wtv->died)
	{
		// if ((getting_time() - i) < t)
		// 	wtv->arg->stop = 1;
		if ((getting_time() - i) >= t)
			break ;
		usleep(100);
	}
	return (0);
}

void	print_info(t_ph *wtv, char *str)
{
	pthread_mutex_lock(&wtv->arg->print);
	printf("%lld %d %s\n", getting_time() - wtv->arg->first_time, wtv->philo_id, str);
	usleep(1000000);
	pthread_mutex_unlock(&wtv->arg->print);
}
