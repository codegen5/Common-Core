/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:26:57 by msamilog          #+#    #+#             */
/*   Updated: 2023/08/07 23:22:32 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	ft_receiver(int sig)
{
	
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putpid(pid);
	while (1)
	{
		signal(SIGUSR1, ft_receiver);
		signal(SIGUSR2, ft_receiver);
		pause();
	}
}