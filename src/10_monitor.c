/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:31:36 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 12:39:50 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <unistd.h>

static int	valid_dead(t_no *no, t_lst *lst);

int	monitor(t_lst *lst)
{
	t_no	*node;

	node = lst->head;
	while (1)
	{
		if (lst->is_dead)
			break ;
		if (valid_dead(node, lst))
			break ;
		node = node->next;
		usleep(0000300);
	}
	return (0);
}

static int	valid_dead(t_no *no, t_lst *lst)
{
	suseconds_t	last_meal;

	last_meal = no->leat_time + no->philo->time_die;
	if (last_meal < elapsed(no->philo->start))
	{
		ft_lock(&lst->dead_mutex);
		if (!valid_nbr_meals(no))
			ft_output(no, DIED);
		lst->is_dead++;
		ft_unlock(&lst->dead_mutex);
		return (1);
	}
	return (0);
}

int	valid_nbr_meals(t_no *no)
{
	if (no->philo->ntm_eat != -1 && no->nbr_eat == no->philo->ntm_eat)
		return (1);
	return (0);
}
