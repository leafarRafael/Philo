/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09.1_eat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:25:22 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/26 17:35:46 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdio.h>
#include <unistd.h>

static int	ft_take_fork(t_no *no);
static int	ft_drop_fork(t_no *no);
//static int	philo_must_die(t_no *no);

int	ft_eat(t_no *no)
{
	if (ft_take_fork(no))
		return (1);
	//philo_must_die(no);
	ft_output(no, EAT);
	if (usleep(no->philo->time_eat))
		return (printf("error usleep()\n"));
	if (ft_drop_fork(no))
		return (1);
	return (0);
}

static int	ft_take_fork(t_no *no)
{	
	if (no->nbr_philo % 2 == 0)
	{
		if (ft_lock(&no->forks))
			return (1);
		ft_output(no, TAKE);
		if (ft_lock(&no->next->forks))
			return (1);
		ft_output(no, TAKE);
	}
	else
	{
		if (ft_lock(&no->next->forks))
			return (1);
		ft_output(no, TAKE);
		if (ft_lock(&no->forks))
			return (1);
		ft_output(no, TAKE);
	}
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

/* static int	philo_must_die(t_no *no)
{
	if (ft_lock(no->dead))
		return (1);
	no->leat_time = elapsed_time(no->philo->start);
	no->nbr_eat++;
	if (ft_unlock(no->dead))
		return (1);
	return (0);
} */