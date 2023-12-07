/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:44:58 by ddemarco          #+#    #+#             */
/*   Updated: 2022/09/25 17:23:02 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H
# include "../ft_libft/libft.h"
# include <sys/types.h>
# include <signal.h>

# ifndef S_MESSAGE
#  define S_MESSAGE

typedef struct s_message
{
	int		binary;
	int		index;
	int		multiplier;
	int		bslash;
	int		clnt_pid;
	int		pid_len;
	int		clnt_index;
	int		b_pid_recieved;
}	t_message;
# endif

int		convert_to_dec(int binary);

void	process_signal(int sig);

void	read_byte(int sig);

int		reverse_int(int num, int lenght);

void	print_messg_b(int binary, int *flag);

void	read_bslash_b(char c, int *flag);
#endif
