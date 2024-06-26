/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:44:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/26 17:23:15 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdio.h>

static int	ft_destroy(pthread_mutex_t *mutex);
static int	mutex_destroy(t_lst *lst);

int	ft_destroy_philos(t_lst *lst)
{
	if (mutex_destroy(lst))
		return (1);
	if (del_lst(lst))
		return (1);
	return (0);
}

static int	mutex_destroy(t_lst *lst)
{
	int		i;
	t_no	*no;
	
	if (!lst || lst->size == 0)
		return (1);
	i = 0;
	no = lst->head;
	while (i < lst->size)
	{
		if (ft_destroy(&no->forks))
			return (1);
		no = no->next;
		i++;
	}
	if (ft_destroy(&lst->output_mutex))
		return (1);
	if (ft_destroy(&lst->dead))
		return (1);
	if (ft_destroy(&lst->mutex))
		return (1);
	return (0);
}

static int	ft_destroy(pthread_mutex_t *mutex)
{
	if (pthread_mutex_destroy(mutex))
		return (printf("error pthread_mutex_destroy()\n"));
	return (0);
}
