/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_un_lock.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:07:36 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 15:48:49 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_UN_LOCK_H
# define MUTEX_UN_LOCK_H

# include <pthread.h>

int	ft_lock(pthread_mutex_t *mutex);
int	ft_unlock(pthread_mutex_t *mutex);

#endif