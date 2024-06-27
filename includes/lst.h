/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:08:52 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 11:26:01 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include <philo.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_no
{
	suseconds_t		leat_time;
	int				*is_dead;
	int				nbr_eat;
	int				nbr_philo;
	t_input			*philo;
	pthread_t		th_philo;
	pthread_mutex_t	forks;
	pthread_mutex_t	*out_mutex;
	pthread_mutex_t	*dead_mutex;
	struct s_no		*next;
	struct s_no		*prev;
}					t_no;

typedef struct s_lst
{
	pthread_mutex_t	output_mutex;
	pthread_mutex_t	dead_mutex;
	int				is_dead;
	t_no			*head;
	t_no			*last;
	int				size;
}					t_lst;

int					init_lst(t_lst *lst);
t_no				*init_node(t_input *philo);
int					add_back(t_lst *lst, t_input *philo);
int					del_lst(t_lst *lst);
int					ft_init_thread(t_lst *lst);
void				*routine(void *ptr);
int					ft_eat(t_no *no);
int					ft_sleep(t_no *no);
int					ft_think(t_no *no);
void				ft_output(t_no *no, char *msg);
int					ft_destroy_philos(t_lst *lst);
int					monitor(t_lst *lst);
int					valid_nbr_meals(t_no *no);

#endif