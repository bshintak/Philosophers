/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:18:42 by bshintak          #+#    #+#             */
/*   Updated: 2022/09/29 12:46:35 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	wtv;

	if (check_is_valid(argv) == 1)
	{
		printf("\033[;31mINVALID ARGUMENTS!\033[0m\n");
		return (0);
	}
	if (argc != 5 && argc != 6)
	{
		printf("\033[;31mWRONG NUMBER OF ARGUMENTS!\033[0m\n");
		printf("\033[;32mRight arguments :\033[0m\n");
		printf("\033[1;35m%s %s \033[0m", FIRST_ARG, SECOND_ARG);
		printf("\033[1;35m%s %s \033[0m", THIRD_ARG, FOURTH_ARG);
		printf("\033[1;35m%s\n\033[0m", FIFTH_ARG);
		return (0);
	}
	separate_arguments(&wtv, argc, argv);
	create_threads(&wtv);
}
