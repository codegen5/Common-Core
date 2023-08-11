/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:26:57 by msamilog          #+#    #+#             */
/*   Updated: 2023/08/08 16:41:55 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static inline
void	ft_putpid(long nb)
{
	char	buffer[11];
	size_t	i;

	write(1, "PID: ", 5);
	if (nb == 0)
	{
		write(1, "0\n", 2);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	i = 0;
	while (nb)
	{
		buffer[i++] = nb % 10 + 48;
		nb /= 10;
	}
	while (i--)
		write(1, &buffer[i], 1);
	write(1, "\n", 1);
}

static inline
void	ft_receiver(int sig, siginfo_t *info, void *context)
{
	static unsigned char	bit = 0;
	static unsigned char	c = 0;

	(void)context;
	kill(info->si_pid, SIGUSR1);
	if (sig == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_receiver;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	ft_putpid(pid);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}
