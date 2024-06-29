/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:41:13 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/29 10:32:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_struct.h"
#include <stdio.h>
#include <unistd.h>
#include "routine.h"
#include "monitor.h"
#include <get_time.h>

static int	init_mutex(t_lst *lst);
static int	init_tread(t_lst *lst, t_input *input);
static int	init_join(t_lst *lst);

int	ft_init_thread(t_lst *lst, t_input *input)
{
	if (!lst || lst->size == 0)
		return (1);
	if (init_mutex(lst))
		return (1);
	if (init_tread(lst, input))
		return (1);
	monitor(lst);
	if (init_join(lst))
		return (1);
	return (0);
}

static int	init_mutex(t_lst *lst)
{
	int		i;
	t_no	*no;

	i = 0;
	no = lst->head;
	if (pthread_mutex_init(&lst->output_mutex, NULL))
		return (printf("error pthread_mutex_init()\n"));
	if (pthread_mutex_init(&lst->dead_mutex, NULL))
		return (printf("error pthread_mutex_init()\n"));
	while (i < lst->size)
	{
		if (pthread_mutex_init(&no->forks, NULL))
			return (printf("error pthread_mutex_init()\n"));
		no = no->next;
		i++;
	}
	return (0);
}

static int	init_tread(t_lst *lst, t_input *input)
{
	int		i;
	t_no	*no;

	i = 0;
	no = lst->head;
	input->start = get_time();
	while (i < lst->size)
	{
		if (pthread_create(&no->th_philo, NULL, &routine, no))
			return (printf("error pthread_create()\n"));
		usleep(0001000);
		no = no->next;
		i++;
	}
	return (0);
}

static int	init_join(t_lst *lst)
{
	int		i;
	t_no	*no;

	i = 0;
	no = lst->head;
	while (i < lst->size)
	{
		if (pthread_join(no->th_philo, NULL))
			return (printf("error pthread_join()\n"));
		no = no->next;
		i++;
	}
	return (0);
}
