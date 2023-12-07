/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:48:14 by ddemarco          #+#    #+#             */
/*   Updated: 2022/09/25 16:52:40 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	send_digit(int digit, int pid)
{
	if (digit == 0)
		kill(pid, SIGUSR1);
	else if (digit == 1)
		kill(pid, SIGUSR2);
	if (digit == 0 || digit == 1)
		return (0);
	else
		return (6);
}

void	send_binary(char c, int pid)
{
	int		mask;
	int		index;

	index = 8;
	mask = 1;
	while (--index >= 0)
	{
		send_digit((c & mask) - 0, pid);
		usleep(100);
		c = c >> 1;
	}
}

int	main(int argc, char*argv[])
{
	int	index;

	if (argc >= 3)
	{
		index = 0;
		while (argv[2][index])
		{
			send_binary(argv[2][index], ft_atoi(argv[1]));
			index++;
		}
		send_binary('\n', ft_atoi(argv[1]));
	}
	return (0);
}
