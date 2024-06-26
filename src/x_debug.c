/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_debug.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:36:01 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/26 15:44:18 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"
#include "lst.h"
#include <stdio.h>

void	print_philo(t_no no, int i);
void	put_philosos(t_input philo, int i);
void	print_philo(t_no no, int i);

void	put_philo(t_lst *lst)
{
	t_no	*no;
	int		i;

	no = lst->head;
	i = 0;
	while(i < lst->size)
	{
		printf("\n--------------------------------------------------------------\n");
		print_philo(*no, i);
		no = no->next;
		i++;
	}
	printf("--------------------------------------------------------------\n");
}

void	print_philo(t_no no, int i)
{
	printf("numero philo  = %d\n", no.nbr_philo);
	put_philosos(*no.philo,  i);
}

void	put_philosos(t_input philo, int i)
{
	if (i == 0)
		philo.start = 1111111111;
	printf("start program = %ld\n", philo.start);
	printf("tempo d morte = %ld\n", philo.time_die);
	printf("tempo d comer = %ld\n", philo.time_eat);
	printf("tempo d sleep = %ld\n", philo.time_sleep);
}