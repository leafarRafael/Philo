/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:44:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 15:24:27 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_struct.h"
#include "del_lst.h"

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
		pthread_mutex_destroy(&no->forks);
		no = no->next;
		i++;
	}
	pthread_mutex_destroy(&lst->output_mutex);
	pthread_mutex_destroy(&lst->dead_mutex);
	return (0);
}
