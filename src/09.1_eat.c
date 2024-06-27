/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09.1_eat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:25:22 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 11:24:20 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdio.h>
#include <unistd.h>

static int	ft_take_fork(t_no *no);
static int	ft_drop_fork(t_no *no);
static int	philo_must_die(t_no *no);

int	ft_eat(t_no *no)
{
	if (ft_take_fork(no))
		return (1);
	ft_output(no, EAT);
	philo_must_die(no);
	if (usleep(no->philo->time_eat))
		return (printf("error usleep()\n"));
	if (ft_drop_fork(no))
		return (1);
	return (0);
}

static int	ft_take_fork(t_no *no)
{
	if (ft_lock(&no->forks))
		return (1);
	ft_output(no, TAKE);
	if (ft_lock(&no->next->forks))
		return (1);
	ft_output(no, TAKE);
	return (0);
}

static int	ft_drop_fork(t_no *no)
{
	if (ft_unlock(&no->forks))
		return (1);
	if (ft_unlock(&no->next->forks))
		return (1);
	return (0);
}

static int	philo_must_die(t_no *no)
{
	if (ft_lock(no->dead_mutex))
		return (1);
	no->nbr_eat++;
	no->leat_time = elapsed(no->philo->start);
	if (ft_unlock(no->dead_mutex))
		return (1);
	return (0);
}
