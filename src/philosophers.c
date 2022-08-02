/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:18:42 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/02 15:56:42 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
    t_philo	wtv;

	if (argc == 5 || argc == 6)
	{
        separate_arguments(&wtv, argc, argv);
       create_threads(&wtv);
    }
	else
	{
		printf("\033[;31mWrong number of arguments!\033[0m\n");
		printf("\033[;32mRight arguments :\033[0m\n");
		printf("\033[1;35m[number of philosophers]\033[0m ");
		printf("\033[1;35m[time to die]\033[0m ");
		printf("\033[1;35m[time to eat]\033[0m ");
		printf("\033[1;35m[time to sleep]\033[0m ");
		printf("\033[1;35m[number of times each philosopher must eat]\033[0m");
		printf("\033[1;35m->(OPTIONAL)\033[0m\n");
	}
}
// void	*myThreadFun(void *vargp)
// {
// 	(void)vargp;
//     sleep(1);
//     printf("Printing GeeksQuiz from Thread \n");
//     return NULL;
// }
  
// int main(void)
// {
//     pthread_t thread_id;
//     printf("Before Thread\n");
//     pthread_create(&thread_id, NULL, myThreadFun, NULL);
//     pthread_join(thread_id, NULL);
//     printf("After Thread\n");
//     exit(0);
// }
