/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:48:43 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 15:16:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_input
{
	int			amount_philos;
	int			ntm_eat;
	suseconds_t	time_die;
	suseconds_t	time_eat;
	suseconds_t	time_sleep;
	suseconds_t	start;
}				t_input;

#endif