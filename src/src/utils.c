/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:12:11 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/22 11:15:33 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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
	return ((time.tv_sec) + (time.tv_usec * 0.000001));
}
