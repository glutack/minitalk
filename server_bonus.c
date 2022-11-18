
#include <stdlib.h> //exit
#include <signal.h>
#include <unistd.h> //getpid, pause, sleep
#include "./libft/libft.h"

//which data we receive from signals
static void	get_str(int signal, siginfo_t *clinfo, void *ucontext)
{
	static int 	count;
	static char	ch;

	(void)ucontext;
	kill(clinfo->si_pid, SIGUSR1)
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
			kill(clinfo->si_pid, SIGUSR2)
			ft_putchar_fd('\n', 1);
		}
		else
			ft_putchar_fd(ch, 1);
		count = 1;
		ch = 0;
	}
}

//starts signals
static void	set_signals(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = get_str;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &get_str, NULL);
	sigaction(SIGUSR2, &get_str, NULL);
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
