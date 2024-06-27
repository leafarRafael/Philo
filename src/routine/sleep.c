/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:27:58 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 15:26:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_struct.h"
#include "defines.h"
#include <stdio.h>
#include <unistd.h>
#include "output.h"

int	ft_sleep(t_no *no)
{
	ft_output(no, SPLEEP);
	if (usleep(no->philo->time_sleep))
		return (printf("error usleep()\n"));
	return (0);
}
