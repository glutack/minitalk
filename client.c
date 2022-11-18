/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:57:21 by irmoreno          #+#    #+#             */
/*   Updated: 2022/11/16 18:27:21 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "./libft/libft.h"

static void	send_bit(int pid, char *str)
{
	int	bit;
	int	ch;

	bit = 7;
	while (*str)
	{
		ch = *str++;
		while (bit >= 0)
		{
			if (ch >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit--;
			usleep(200);
		}
		bit = 7;
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR2);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	send_bit(ft_atoi(argv[1]), argv[2]);
	return (0);
}
