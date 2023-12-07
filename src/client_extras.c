/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:51:27 by ddemarco          #+#    #+#             */
/*   Updated: 2022/09/08 17:38:26 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	convert(int binary)
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
