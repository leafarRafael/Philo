/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:48:43 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 11:25:02 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

# define ARG1 "number of philosophers;"
# define ARG2 "time to die;"
# define ARG3 "time to eat;"
# define ARG4 "time to sleep;"
# define ARG5 "number of times each philosopher must eat"
# define TAKE "has taken a fork"
# define EAT "is eating"
# define SPLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

typedef unsigned int	t_uint;

typedef struct s_input
{
	int					amount_philos;
	int					ntm_eat;
	suseconds_t			time_die;
	suseconds_t			time_eat;
	suseconds_t			time_sleep;
	suseconds_t			start;
}						t_input;

int						valid_arguments(int argc, char *argv[]);
int						ft_set_arg(t_input *input, int argc, char *argv[]);
suseconds_t				get_time(void);
suseconds_t				elapsed(suseconds_t start);
long int				ft_atol(const char *nptr);
int						ft_unlock(pthread_mutex_t *mutex);
int						ft_lock(pthread_mutex_t *mutex);

#endif