/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:40:22 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 11:24:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdio.h>
#include <unistd.h>

static int	case_one(t_no *no);

void	*routine(void *ptr)
{
	t_no	*no;

	no = (t_no *)ptr;
	if (case_one(no))
		return (NULL);
	if (*no->is_dead)
		return (NULL);
	if (ft_eat(no))
		return (NULL);
	if (ft_sleep(no))
		return (NULL);
	if (ft_think(no))
		return (NULL);
	if (valid_nbr_meals(no))
		return (NULL);
	routine(ptr);
	return (NULL);
}

static int	case_one(t_no *no)
{
	if (no == no->next)
	{
		if (ft_lock(&no->forks))
			return (1);
		ft_output(no, TAKE);
		usleep(no->philo->time_die);
		if (ft_unlock(&no->forks))
			return (1);
		return (1);
	}
	return (0);
}
