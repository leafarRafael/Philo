/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:10:32 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 15:22:53 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list_struct.h"
#include "node_struct.h"
#include "philo_struct.h"

int	init_lst(t_lst *lst)
{
	lst->is_dead = 0;
	lst->head = NULL;
	lst->last = NULL;
	lst->size = 0;
	return (0);
}

t_no	*init_node(t_input *philo)
{
	t_no	*no;

	no = malloc(sizeof(t_no));
	if (!no)
		return (NULL);
	no->next = no;
	no->prev = no;
	no->philo = philo;
	no->nbr_eat = 0;
	no->leat_time = -1;
	return (no);
}
