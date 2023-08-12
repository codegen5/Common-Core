/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:51:29 by msamilog          #+#    #+#             */
/*   Updated: 2023/08/08 16:33:07 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_ack;

static inline
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * sign);
}

static inline
int	ft_checkpid(char *pid)
{
	size_t	i;

	i = 0;
	if (pid[0] == '0')
		return (0);
	while (pid[i])
	{
		if (pid[i] < '0' || pid[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_handshake(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
}

static inline
void	ft_transmitter(pid_t pid, char c)
{
	unsigned char	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack = 0;
		if (1 & (c >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack)
			pause();
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	size_t	i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 1 || !ft_checkpid(argv[1]))
		{
			write(1, "Invalid PID!\n", 13);
			return (1);
		}	
		signal(SIGUSR1, ft_handshake);
		i = 0;
		while (argv[2][i])
			ft_transmitter(pid, argv[2][i++]);
		ft_transmitter(pid, '\0');
	}
	else
	{
		write(1, "Usage: ./client PID \"string\"\n", 29);
		return (1);
	}
	return (0);
}
