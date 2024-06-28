/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:57:44 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 15:18:33 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atol.h"
#include "philo_struct.h"

int	ft_set_arg(t_input *input, int argc, char *argv[])
{
	input->amount_philos = ft_atol(argv[1]);
	input->time_die = (suseconds_t)(ft_atol(argv[2]) * 1000);
	input->time_eat = (suseconds_t)(ft_atol(argv[3]) * 1000);
	input->time_sleep = (suseconds_t)(ft_atol(argv[4]) * 1000);
	input->ntm_eat = -1;
	if (argc == 6)
		input->ntm_eat = ft_atol(argv[5]);
	return (0);
}