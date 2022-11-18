#include <unistd.h>
#include <signal.h>
#include "./libft/libft.h"

static void	ft_chars_sent(int chsent)
{
	ft_putstr_fd("Chars sent: ", 1);
	ft_putnbr_fd((chsent), 1);
	ft_putchar_fd('\n', 1);
}

static void	ft_send_bit(int pid, char *str)
{
	int	bit;
	int	ch;
	int	chsent;

	chsent = 0;
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
			usleep(100);
		}
		bit = 7;
		chsent++;
	}
	ft_chars_sent(chsent);
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

static void	ft_get_signal(int signal)
{
	static int	bits;

	if (!bits)
		bits = 0;
	if (signal == SIGUSR2)
	{
		ft_putstr_fd("Chars received: ", 1);
		ft_putnbr_fd((bits / 8), 1);
		ft_putchar_fd('\n', 1);
	}
	else
		bits++;
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	signal(SIGUSR1, ft_get_signal);
	signal(SIGUSR2, ft_get_signal);
	ft_send_bit(ft_atoi(argv[1]), argv[2]);
	return (0);
}
