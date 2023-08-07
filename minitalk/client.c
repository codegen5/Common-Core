/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:51:29 by msamilog          #+#    #+#             */
/*   Updated: 2023/08/07 23:22:32 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	catch_int(int sig_num)
{
	printf("Don't do that\n");
	signal(SIGINT, SIG_IGN);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		while (1)
		{
			
		}
	}
}
