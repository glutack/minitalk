#include <stdlib.h> //exit
#include <signal.h>
#include <unistd.h> //getpid, pause, sleep

//starts signals
static void	set_signals(void)
{
	struct	sigaction	sa;

	sa.sa_data = data;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL)
}

//which data we receive from signals
static void	data(int signal)
{

	if (signal == SIGUSR1)
		bit = 1;
	else if (signal == SIGUSR 2)
		bit = 2;
	else
		exit(EXIT_FAILURE)
}

int	main(void)
{
	set_signals();
	ft_putstr_fd("Server ON - PID:", 1)
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}