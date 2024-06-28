/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:50:37 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/27 15:18:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "defines.h"

static int	is_nbr(char c);
static int	put_msg(void);

int	valid_arguments(int argc, char *argv[])
{
	int	i;
	int	x;

	if (argc <= 4 || argc >= 7)
		return (put_msg());
	i = 1;
	while (argv[i])
	{
		x = 0;
		while (argv[i][x])
		{
			if (is_nbr(argv[i][x]))
				return (put_msg());
			x++;
		}
		i++;
	}
	return (0);
}

static int	is_nbr(char c)
{
	return (c < '0' || c > '9');
}

static int	put_msg(void)
{
	printf("The program expects to receive");
	printf(" up to 5 positive numerical arguments:\n");
	printf("First:			%s\n", ARG1);
	printf("Second:			%s\n", ARG2);
	printf("Third:			%s\n", ARG3);
	printf("Fourth:			%s\n", ARG4);
	printf("Fifth (optional):	%s\n", ARG5);
	return (1);
}
