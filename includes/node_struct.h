/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:08:52 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 15:51:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_STRUCT_H
# define NODE_STRUCT_H

# include "node_struct.h"
# include "philo_struct.h"
# include <pthread.h>
# include <sys/time.h>

typedef struct s_no
{
	int				*is_dead;
	int				nbr_eat;
	int				nbr_philo;
	t_input			*philo;
	pthread_t		th_philo;
	suseconds_t		leat_time;
	pthread_mutex_t	forks;
	pthread_mutex_t	*out_mutex;
	pthread_mutex_t	*dead_mutex;
	struct s_no		*next;
	struct s_no		*prev;
}					t_no;

#endif