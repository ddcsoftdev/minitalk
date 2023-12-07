/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:05:13 by ddemarco          #+#    #+#             */
/*   Updated: 2022/09/25 17:28:48 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server_bonus.h"

static t_message	g_messg;

void	reset_g_variable(int fullreset)
{
	g_messg.index = 0;
	g_messg.binary = 0;
	g_messg.multiplier = 1;
	if (fullreset == 1)
	{
		g_messg.b_pid_recieved = 0;
	}
	else if (fullreset == 2)
	{
		g_messg.clnt_pid = 0;
		g_messg.pid_len = 0;
		g_messg.clnt_index = 1;
		g_messg.bslash = 0;
	}
	else if (fullreset == 3)
	{
		g_messg.b_pid_recieved = 0;
		g_messg.clnt_pid = 0;
		g_messg.pid_len = 0;
		g_messg.clnt_index = 1;
		g_messg.bslash = 0;
	}
}

int	check_client_pid(int binary)
{
	char	c;

	c = (char)convert_to_dec(binary);
	if (!g_messg.b_pid_recieved)
	{
		if (g_messg.pid_len <= 0)
		{
			g_messg.pid_len = c - '0';
		}
		else if (c == 'A')
		{
			g_messg.b_pid_recieved = 1;
			g_messg.clnt_pid = reverse_int(g_messg.clnt_pid, g_messg.pid_len);
		}
		else
		{
			g_messg.clnt_pid += (c - '0') * g_messg.clnt_index;
			g_messg.clnt_index *= 10;
		}
		reset_g_variable(0);
		return (1);
	}
	return (0);
}

void	process_signal(int sig)
{
	if (sig == SIGUSR1)
	{
		g_messg.binary += (g_messg.multiplier * 0);
		g_messg.multiplier *= 10;
	}
	else if (sig == SIGUSR2)
	{
		g_messg.binary += (g_messg.multiplier * 1);
		g_messg.multiplier *= 10;
	}
}

void	read_byte(int sig)
{
	process_signal(sig);
	if (g_messg.index >= 7)
	{
		if (!check_client_pid(g_messg.binary))
		{
			if ((char)convert_to_dec(g_messg.binary) == 0)
			{
				kill(g_messg.clnt_pid, SIGUSR1);
				ft_printf("\n");
				reset_g_variable(3);
			}
			else
			{
				print_messg_b(g_messg.binary, &g_messg.bslash);
				reset_g_variable(0);
			}
		}
	}
	else
		g_messg.index += 1;
}

int	main(void)
{
	reset_g_variable(3);
	signal(SIGUSR1, &read_byte);
	signal(SIGUSR2, &read_byte);
	ft_printf("Server ID: %d\n", getpid());
	while (1)
	{
	}
	return (0);
}
