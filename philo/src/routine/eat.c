/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:25:22 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/29 10:40:33 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_struct.h"
#include "defines.h"
#include "get_time.h"
#include "mutex_un_lock.h"
#include <stdio.h>
#include <unistd.h>
#include "output.h"

static int	ft_take_fork(t_no *no);
static int	ft_drop_fork(t_no *no);
static int	philo_must_die(t_no *no);

int	ft_eat(t_no *no)
{
	if (ft_take_fork(no))
		return (1);
	ft_output(no, EAT);
	no->nbr_eat++;
	philo_must_die(no);
	if (usleep(no->philo->time_eat))
		return (printf("error usleep()\n"));
	if (ft_drop_fork(no))
		return (1);
	return (0);
}

static int	ft_take_fork(t_no *no)
{
	pthread_mutex_lock(&no->forks);
	ft_output(no, TAKE);
	pthread_mutex_lock(&no->next->forks);
	ft_output(no, TAKE);
	return (0);
}

static int	ft_drop_fork(t_no *no)
{
	if (ft_unlock(&no->next->forks))
		return (1);
	if (ft_unlock(&no->forks))
		return (1);
	return (0);
}

static int	philo_must_die(t_no *no)
{
	if (ft_lock(no->dead_mutex))
		return (1);
	no->leat_time = elapsed(no->philo->start);
	if (ft_unlock(no->dead_mutex))
		return (1);
	return (0);
}
