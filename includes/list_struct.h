/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:08:52 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 15:51:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_STRUCT_H
# define LIST_STRUCT_H

# include "node_struct.h"
# include <pthread.h>

typedef struct s_lst
{
	pthread_mutex_t	output_mutex;
	pthread_mutex_t	dead_mutex;
	int				is_dead;
	t_no			*head;
	t_no			*last;
	int				size;
}					t_lst;

#endif