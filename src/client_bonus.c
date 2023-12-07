/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:48:14 by ddemarco          #+#    #+#             */
/*   Updated: 2022/09/25 17:29:59 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client_bonus.h"

void	server_connection(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Server: Signal recieved.\n");
	}
}

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
	int		num;

	index = 8;
	mask = 1;
	num = c - '0';
	while (--index >= 0)
	{
		send_digit((c & mask) - 0, pid);
		c = c >> 1;
		usleep(100);
	}
}

void	send_pid(char *client_pid, int pid)
{
	int	index;

	index = 0;
	while (client_pid[index])
		index++;
	send_binary(index + '0', pid);
	while (*client_pid)
	{
		send_binary(*client_pid, pid);
		client_pid++;
	}
	send_binary('A', pid);
}

int	main(int argc, char*argv[])
{
	int	index;

	signal(SIGUSR1, &server_connection);
	if (argc >= 3)
	{
		index = 0;
		send_pid(ft_itoa(getpid()), ft_atoi(argv[1]));
		while (argv[2][index])
		{
			send_binary(argv[2][index], ft_atoi(argv[1]));
			index++;
		}
		send_binary(0, ft_atoi(argv[1]));
	}
	return (0);
}
