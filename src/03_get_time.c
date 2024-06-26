/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:00:27 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/26 17:38:11 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

suseconds_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 * 1000 + tv.tv_usec);
}

suseconds_t elapsed_time(suseconds_t start)
{
	return (get_time() - start);
}