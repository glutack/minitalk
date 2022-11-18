/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2022/11/16 17:57:11 by irmoreno          #+#    #+#             */
/*   Updated: 2022/11/16 18:36:46 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //exit
#include <signal.h>
#include <unistd.h> //getpid, pause, sleep
#include "./libft/libft.h"

//which data we receive from signals
void	get_str(int signal)
{
	static int	count;
	static char	ch;

	/*if (signal == SIGUSR1)
		ft_putnbr_fd(1, 1);
	else
		ft_putnbr_fd(0, 1);*/
	if (!count)
	{
		ch = 0;
		count = 1;
	}
	ch |= (signal == SIGUSR1);
	if (count++ < 8)
		ch <<= 1;
	else
	{
		if (!ch)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(ch, 1);
		count = 1;
		ch = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("Server ON - PID:", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, get_str);
	signal(SIGUSR2, get_str);
	while (1)
		pause();
	return (0);
}
