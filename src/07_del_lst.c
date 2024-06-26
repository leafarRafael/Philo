/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_del_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:13:46 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/26 14:19:16 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

static int	case_one(t_lst *lst);
static int	case_two(t_lst *lst);
static int	case_three_more(t_lst *lst);
static int	del_front(t_lst *lst);

int	del_lst(t_lst *lst)
{
	if (!lst)
		return (1);
	if (lst->size == 0)
		return (1);
	while (lst->size > 0)
		del_front(lst);
	lst = NULL;
	return (0);
}

static int	del_front(t_lst *lst)
{
	if (!lst)
		return (1);
	if (lst->size == 0)
		return (1);
	if (lst->size == 1)
		return (case_one(lst));
	if (lst->size == 2)
		return (case_two(lst));
	return (case_three_more(lst));
}

static int	case_one(t_lst *lst)
{
	free(lst->head);
	lst->head = NULL;
	lst->last = NULL;
	lst->size = 0;
	return (0);
}

static int	case_two(t_lst *lst)
{
	free(lst->head);
	lst->last->next = lst->last;
	lst->last->prev = lst->last;
	lst->head = lst->last;
	lst->size--;
	return (0);
}

static int	case_three_more(t_lst *lst)
{
	t_no	*no;

	no = lst->head->next;
	no->prev = lst->last;
	lst->last->next = no;
	free(lst->head);
	lst->head = no;
	lst->size--;
	return (0);
}
