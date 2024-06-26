/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09.4_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:44:52 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/26 15:57:23 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "lst.h"
# include <stdio.h>

void	ft_output(t_no *no, char *msg)
{
	if (!(*no->is_dead))
	{
		pthread_mutex_lock(no->out_mutex);
		printf("%ld %d %s\n", elapsed_time(no->philo->start) / 1000, no->nbr_philo, msg);
		pthread_mutex_unlock(no->out_mutex);
	}
}