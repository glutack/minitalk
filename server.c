/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:57:11 by irmoreno          #+#    #+#             */
/*   Updated: 2022/11/16 18:36:46 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //exit
#include <signal.h>
#include <unistd.h> //getpid, pause, sleep
#include "utils.h"

//starts signals
static void	set_signals(void)
{
	struct	sigaction	sa;

	sa.sa_str = get_str;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

//which data we receive from signals
static void	get_str(int signal)
{
	int	bit;

	if (signal == SIGUSR1)
		bit = 1;
	else if (signal == SIGUSR2)
		bit = 0;
	else
		exit(EXIT_FAILURE);

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
