/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:37:21 by ddemarco          #+#    #+#             */
/*   Updated: 2022/09/25 16:57:29 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server_bonus.h"

int	reverse_int(int num, int lenght)
{
	int	rev;
	int	rem;
	int	index;

	rev = 0;
	index = 1;
	while (num != 0)
	{
		rem = num % 10;
		rev = rev * 10 + rem;
		num /= 10;
		index++;
	}
	if (index < lenght)
	{
		rev = rev * (10 * (lenght - index));
	}
	return (rev);
}

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

void	read_bslash_b(char c, int *flag)
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

void	print_messg_b(int binary, int *flag)
{
	if ((char)convert_to_dec(binary) == '\\' && !*flag)
		*flag = 1;
	else
	{
		if (*flag)
			read_bslash_b((char)convert_to_dec(binary), flag);
		else
			ft_printf("%c", (char)convert_to_dec(binary));
	}	
}
