/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:18:42 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/22 12:02:52 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	wtv;

	if (argc == 5 || argc == 6)
	{
		printf("%lld\n", getting_time());
		separate_arguments(&wtv, argc, argv);
		init_fork_mutex(&wtv);
		// create_threads(&wtv);
	}
	else
	{
		printf("\033[;31mWrong number of arguments!\033[0m\n");
		printf("\033[;32mRight arguments :\033[0m\n");
		printf("\033[1;35m%s %s \033[0m", FIRST_ARG, SECOND_ARG);
		printf("\033[1;35m%s %s \033[0m", THIRD_ARG, FOURTH_ARG);
		printf("\033[1;35m%s\n\033[0m", FIFTH_ARG);
	}
}
