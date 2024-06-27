/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.un_lock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:01:55 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 15:24:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

int	ft_lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex))
		return (printf("error pthread_mutex_lock()\n"));
	return (0);
}

int	ft_unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex))
		return (printf("error pthread_mutex_unlock()\n"));
	return (0);
}
