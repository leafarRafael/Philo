/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09.4_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:44:52 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 11:28:14 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include "philo.h"
#include <stdio.h>

void	ft_output(t_no *no, char *msg)
{
	if (!(*no->is_dead))
	{
		pthread_mutex_lock(no->out_mutex);
		printf("%ld %d %s\n", elapsed(no->philo->start) / 1000, no->nbr_philo,
			msg);
		pthread_mutex_unlock(no->out_mutex);
	}
}
