
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
		}
		bit = 7;
		usleep(800);
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR2);
	}
}

static void	get_signal(int signal)
{
	int	bits;

	if (!bits)
		bits = 0;
	if (signal == SIGUSR2)
	{
		bits -= 8;
		ft_putnbr_fd(bits, 1);
	}
	else
		bits++;
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	signal(SIGUSR1, get_signal);
	signal(SIGUSR2, get_signal);
	send_bit(ft_atoi(argv[1]), argv[2]);
	return (0);
}
