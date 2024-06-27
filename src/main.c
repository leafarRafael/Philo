/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:48:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 15:30:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_struct.h"
#include "philo_struct.h"
#include "get_time.h"
#include "init_thread.h"
#include "destroy.h"
#include "init_lst.h"
#include "add_back.h"
#include "set_args.h"
#include "valid_arg.h"

static int	init_lst_philos(t_input *input, t_lst *lst);

int	main(int argc, char *argv[])
{
	t_input	input;
	t_lst	lst;

	if (valid_arguments(argc, argv))
		return (1);
	if (ft_set_arg(&input, argc, argv))
		return (1);
	if (init_lst_philos(&input, &lst))
		return (1);
	if (ft_init_thread(&lst))
		return (1);
	if (ft_destroy_philos(&lst))
		return (1);
	return (0);
}

static int	init_lst_philos(t_input *input, t_lst *lst)
{
	int	i;

	if (!input)
		return (1);
	if (init_lst(lst))
		return (1);
	i = 0;
	input->start = get_time();
	while (i < input->amount_philos)
	{
		if (add_back(lst, input))
			return (1);
		i++;
	}
	return (0);
}
