/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:50:46 by bshintak          #+#    #+#             */
/*   Updated: 2022/09/29 15:32:24 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	create_threads(t_philo *wtv)
{
	int			i;
	t_ph		*ph;

	ph = init_philo(wtv);
	wtv->first_time = getting_time();
	/*PTHREAD CREATE
		- first arg: guarda o ID da thread que vai ser criada
		- second arg: nos permite mudar os atributos padrão da nova thread
			> mas isso esta alem do projeto, então NULL
		- third arg: função que inicia a execução
		- fourth arg: um ponteiro para um argumento p/ passar para a função no 3º arg
			> ponteiro para uma estrutura de dados*/
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
		if (wtv->all_ate == 1)
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
	/*PTHREAD JOIN
		> bloqueia a execução de uma thread ate a outra finalizar
		- first arg: ID da thread que a outra thread deve esperar por
		- second arg: um ponteiro para uma variavel que contem o retorno da routine_function
			> não precisamos desse valor, então NULL*/
}
