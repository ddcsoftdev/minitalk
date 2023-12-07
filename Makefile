# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 21:20:30 by ddemarco          #+#    #+#              #
#    Updated: 2022/09/21 17:51:47 by ddemarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = includes/server.a

NAME_C = includes/client.a

BONUS_S = includes/server_bonus.a

BONUS_C = includes/client_bonus.a

EXE_S = server.out

EXE_C1 = client.out

EXE_C2 = client2.out

EXE_BS = server_bonus.out

EXE_BC1 = client_bonus.out

EXE_BC2 = client2_bonus.out

LIBFT = ft_libft/libft.a

CC = gcc

FLAGS =  -Wall -Wextra -Werror

INCLUDES_S = includes/server.h ft_libft/libft.a

INCLUDES_C = includes/client.h ft_libft/libft.a

INCLUDES_BS = includes/server_bonus.h ft_libft/libft.a

INCLUDES_BC = includes/client_bonus.h ft_libft/libft.a

SRCS_S = src/server.c

SRCS_C = src/client.c src/client_extras.c

SRCS_BS = src/server_bonus.c src/server_extras.c

SRCS_BC = src/client_bonus.c src/client_extras.c

OBJS_S = ${SRCS_S:.c=.o}

OBJS_C = ${SRCS_C:.c=.o}

OBJS_BC = ${SRCS_BC:.c=.o}

OBJS_BS = ${SRCS_BS:.c=.o}

$(NAME): $(OBJS_S)
		make all -C ft_libft/
		$(CC) $(FLAGS) $(INCLUDES_S) $(SRCS_S)
		ar -rcs $(NAME) $(OBJS_S)
		rm -rf a.out

$(NAME_C): $(OBJS_C)
		make all -C ft_libft/
		$(CC) $(FLAGS) $(INCLUDES_C) $(SRCS_C)
		ar -rcs $(NAME_C) $(OBJS_C)
		rm -rf a.out

$(EXE_S): $(NAME) $(LIBFT)
		gcc -Wall -Wextra -Werror -o server.out $(NAME) $(LIBFT)
		
$(EXE_C1): $(NAME_C) $(LIBFT)
		gcc -Wall -Wextra -Werror -o client.out $(NAME_C) $(LIBFT)
		
$(EXE_C2): $(NAME_C) $(LIBFT)
		gcc -Wall -Wextra -Werror -o client2.out $(NAME_C) $(LIBFT)

$(BONUS_S): $(OBJS_BS)
		make all -C ft_libft/
		$(CC) $(FLAGS) $(INCLUDES_BS) $(SRCS_BS)
		ar -rcs $(BONUS_S) $(OBJS_BS)
		rm -rf a.out

$(BONUS_C): $(OBJS_BC)
		make all -C ft_libft/
		$(CC) $(FLAGS) $(INCLUDES_BC) $(SRCS_BC)
		ar -rcs $(BONUS_C) $(OBJS_BC)
		rm -rf a.out
		
$(EXE_BS): $(BONUS_S) $(LIBFT)
		gcc -Wall -Wextra -Werror -o server_bonus.out $(BONUS_S) $(LIBFT)
		
$(EXE_BC1): $(BONUS_C) $(LIBFT)
		gcc -Wall -Wextra -Werror -o client_bonus.out $(BONUS_C) $(LIBFT)
		
$(EXE_BC2): $(BONUS_C) $(LIBFT)
		gcc -Wall -Wextra -Werror -o client2_bonus.out $(BONUS_C) $(LIBFT)
	
all : mandatory bonus

mandatory: $(NAME) $(NAME_C) $(EXE_S) $(EXE_C1)

mclienttwo: $(NAME) $(NAME_C) $(EXE_C2)

bonus : $(BONUS_S) $(BONUS_C) $(EXE_BS) $(EXE_BC1)

bonusclienttwo: $(BONUS_S) $(BONUS_C) $(EXE_BC2)

clean : 
		rm -rf $(OBJS_S)
		rm -rf $(OBJS_C)
		rm -rf $(OBJS_BS)
		rm -rf $(OBJS_BC)
		rm -rf includes/server.h.gch		
		rm -rf includes/client.h.gch
		rm -rf includes/server_bonus.h.gch	
		rm -rf includes/client_bonus.h.gch
		make clean -C ft_libft/
fclean : clean
		rm -rf $(NAME) $(NAME_C) $(BONUS_S) $(BONUS_C) $(EXE_S) $(EXE_C1) $(EXE_C2) $(EXE_BS) $(EXE_BC1) $(EXE_BC2)
		rm -rf ./bin
		make fclean -C ft_libft/

re : fclean all

.PHONY : all bonus clean fclean re