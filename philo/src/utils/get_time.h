/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:08:27 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 15:50:39 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_TIME_H
# define GET_TIME_H

# include <sys/time.h>
# include <unistd.h>

suseconds_t	get_time(void);
suseconds_t	elapsed(suseconds_t start);

#endif