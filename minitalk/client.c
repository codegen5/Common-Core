/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:51:29 by msamilog          #+#    #+#             */
/*   Updated: 2023/08/05 00:00:08 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	pid_t	pid;
	size_t	i;

	pid = getpid();
	printf("%i\n", pid);
	kill(pid, SIGUSR1);
}