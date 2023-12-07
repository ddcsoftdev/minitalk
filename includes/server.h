/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:44:58 by ddemarco          #+#    #+#             */
/*   Updated: 2022/09/21 17:36:22 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "../ft_libft/libft.h"
# include <sys/types.h>
# include <signal.h>

# ifndef S_MESSAGE
#  define S_MESSAGE

typedef struct s_message
{
	char	*string;
	int		binary;
	int		index;
	int		multiplier;
	int		bslash;
}	t_message;
# endif

int		convert_to_dec(int binary);

void	read_byte(int sig);

void	print_messg(void);

void	read_bslash(char c, int *flag);
#endif
