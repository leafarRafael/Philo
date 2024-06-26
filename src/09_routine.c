/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:40:22 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/26 17:35:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdio.h>
#include <unistd.h>

static int	recursion_ctrl(t_no *no);
static int	valid_nbr_meals(t_no *no);
static int	valid_dead(t_no *no);
static int	case_one(t_no *no);
static int	philo_must_die(t_no *no);

void	*routine(void *ptr)
{
	t_no	*no;

	no = (t_no*) ptr;
	if (recursion_ctrl(no))
		return (NULL);
	if (ft_eat(no) && (*no->is_dead))
		return (NULL);
	philo_must_die(no);
	if (ft_sleep(no) && (*no->is_dead))
		return (NULL);
	if (ft_think(no) && (*no->is_dead))
		return (NULL);
	if (!(*no->is_dead))
		routine(ptr);
	return (NULL);
}

static int	recursion_ctrl(t_no *no)
{
	if (ft_lock(no->dead))
		return (1);
	if (case_one(no))
		return (ft_unlock(no->dead) +1);
	if (valid_nbr_meals(no))
		return (ft_unlock(no->dead) +1);
	if (valid_dead(no))
		return (ft_unlock(no->dead) +1);
	if ((*no->is_dead))
		return (ft_unlock(no->dead) +1);
	return (ft_unlock(no->dead));
}

static int	case_one(t_no *no)
{
	if (no == no->next)
	{
		if (ft_lock(&no->forks))
			return (1);
		ft_output(no, TAKE);
		usleep(no->philo->time_die);
		ft_output(no, DIED);
		if (ft_unlock(&no->forks))
			return (1);
		return (1);
	}
	return (0);
}

static int	valid_nbr_meals(t_no *no)
{
	if (no->philo->ntm_eat != -1 && no->nbr_eat >= no->philo->ntm_eat)
		return (1);
	return (0);
}

static int valid_dead(t_no *no)
{
	suseconds_t	last_meal;
	suseconds_t	time;
	
	time = elapsed_time(no->philo->start);
	last_meal = no->leat_time + no->philo->time_die;
	printf("philo = %d | ultimo ali= %ld | tempo = %ld\n", no->nbr_philo, last_meal, time);
	if (last_meal < time)
	{
		ft_output(no, DIED);
		(*no->is_dead)++;
		return (1);
	}
	return (0);
}

static int	philo_must_die(t_no *no)
{
	if (ft_lock(no->dead))
		return (1);
	no->leat_time = elapsed_time(no->philo->start);
	no->nbr_eat++;
	if (ft_unlock(no->dead))
		return (1);
	return (0);
}