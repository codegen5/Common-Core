/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:51:29 by msamilog          #+#    #+#             */
/*   Updated: 2023/08/12 03:31:31 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

static inline
void	ft_transmitter(pid_t pid, char c)
{
	unsigned char	bit;

	bit = 0;
	while (bit < 8)
	{
		if (1 & (c >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
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
