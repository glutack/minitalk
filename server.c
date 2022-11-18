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
static void	get_str(int signal)
{
	static int 	count;
	static char	ch;

	/*if (signal == 	SIGUSR1)
		ft_putchar_fd('1', 1);
	if (signal == 	SIGUSR2)
		ft_putchar_fd('0', 1);*/
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
		if (ch == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(ch, 1);
		count = 1;
		ch = 0;
	}
}

//starts signals
static void	set_signals(void)
{
	signal(SIGUSR1, get_str);
	signal(SIGUSR2, get_str);
}

int	main(void)
{
	set_signals();
	ft_putstr_fd("Server ON - PID:", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
