/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:05:13 by ddemarco          #+#    #+#             */
/*   Updated: 2022/09/21 17:52:14 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

static t_message	g_messg;

int	convert_to_dec(int binary)
{
	int	decimal;
	int	index;
	int	reminder;

	decimal = 0;
	index = 0;
	while (binary != 0)
	{
		reminder = binary % 10;
		binary /= 10;
		decimal += reminder * ft_pow(2, index);
		index++;
	}
	return (decimal);
}

void	read_byte(int sig)
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
	if (g_messg.index >= 7)
	{
		if ((char)convert_to_dec(g_messg.binary) == '\\' && !g_messg.bslash)
			g_messg.bslash = 1;
		else
			print_messg();
		g_messg.index = 0;
		g_messg.binary = 0;
		g_messg.multiplier = 1;
	}
	else
		g_messg.index += 1;
}

void	read_bslash(char c, int *flag)
{
	if (c == 't')
		ft_printf("%c", 9);
	else if (c == 'n')
		ft_printf("%c", 10);
	else if (c == 'v')
		ft_printf("%c", 11);
	else if (c == 'f')
		ft_printf("%c", 12);
	else if (c == 'r')
		ft_printf("%c", 13);
	else if (c == 92)
		ft_printf("%c", 92);
	else
		ft_printf("\\%c", c);
	*flag = 0;
}

void	print_messg(void)
{
	if (g_messg.bslash)
		read_bslash((char)convert_to_dec(g_messg.binary), &g_messg.bslash);
	else
		ft_printf("%c", (char)convert_to_dec(g_messg.binary));
}

int	main(void)
{
	g_messg.binary = 0;
	g_messg.index = 0;
	g_messg.multiplier = 1;
	g_messg.bslash = 0;
	signal(SIGUSR1, &read_byte);
	signal(SIGUSR2, &read_byte);
	ft_printf("Server ID: %d\n", getpid());
	while (1)
	{
	}
	return (0);
}
