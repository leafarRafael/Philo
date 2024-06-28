/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:11:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 14:45:56 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_lst.h"

static int	case_zero(t_lst *lst, t_no *node);
static int	case_one(t_lst *lst, t_no *node);
static int	case_two_more(t_lst *lst, t_no *node);

int	add_back(t_lst *lst, t_input *philo)
{
	t_no	*no;

	if (!lst || !philo)
		return (1);
	no = init_node(philo);
	if (!no)
		return (1);
	if (lst->size == 0)
		return (case_zero(lst, no));
	if (lst->size == 1)
		return (case_one(lst, no));
	return (case_two_more(lst, no));
}

static int	case_zero(t_lst *lst, t_no *node)
{
	node->dead_mutex = &lst->dead_mutex;
	node->out_mutex = &lst->output_mutex;
	node->is_dead = &lst->is_dead;
	lst->head = node;
	lst->last = node;
	lst->size++;
	node->nbr_philo = lst->size;
	return (0);
}

static int	case_one(t_lst *lst, t_no *node)
{
	node->dead_mutex = &lst->dead_mutex;
	node->out_mutex = &lst->output_mutex;
	node->is_dead = &lst->is_dead;
	node->prev = lst->head;
	node->next = lst->head;
	lst->head->next = node;
	lst->head->prev = node;
	lst->last = node;
	lst->size++;
	node->nbr_philo = lst->size;
	return (0);
}

static int	case_two_more(t_lst *lst, t_no *node)
{
	node->dead_mutex = &lst->dead_mutex;
	node->out_mutex = &lst->output_mutex;
	node->is_dead = &lst->is_dead;
	node->prev = lst->last;
	node->next = lst->head;
	lst->last->next = node;
	lst->head->prev = node;
	lst->last = node;
	lst->size++;
	node->nbr_philo = lst->size;
	return (0);
}
