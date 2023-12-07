/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:48:41 by ddemarco          #+#    #+#             */
/*   Updated: 2022/09/17 18:04:00 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../ft_libft/libft.h"
# include <sys/types.h>
# include <signal.h>

//SEND 8 BIT BINARY
int		send_digit(int digit, int pid);

void	send_binary(char c, int pid);

//EXTRAS
int		convert(int binary);

#endif
