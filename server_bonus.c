#include <stdlib.h> //exit
#include <signal.h>
#include <unistd.h> //getpid, pause, sleep
#include "./libft/libft.h"

//which data we receive from signals
void	ft_get_str(int signal, siginfo_t *clinfo, void *ucontext)
{
	static int	count;
	static char	ch;

	(void)ucontext;
	kill(clinfo->si_pid, SIGUSR1);
	if (signal == SIGUSR1)
		ft_putchar_fd('1', 1);
	else
		ft_putchar_fd('0', 1);
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
		{
			kill(clinfo->si_pid, SIGUSR2);
			ft_putchar_fd('\n', 1);
		}
		else
			ft_putchar_fd(ch, 1);
		count = 1;
		ch = 0;
	}
}

/*
static void	ft_set_signals(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = ft_get_str;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
}
*/
int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = ft_get_str;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_putstr_fd("Server ON - PID:", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
