# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 14:42:41 by pruenrua          #+#    #+#              #
#    Updated: 2023/05/29 22:47:41 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex

SRC = runcmd.c error.c pipework.c pipex_tool.c help.c help2.c free.c pipex.c

SRC_B = runcmd_bonus.c error_bonus.c pipework_bonus.c get_next_line_utils.c get_next_line.c pipex_tool_bonus.c help_bonus.c help2_bonus.c free_bonus.c doctype.c pipex_bonus.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

BOBJ = $(SRC_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	 $(CC) $(OBJ) -o $(NAME)

bonus : $(BOBJ)
	$(CC) $(BOBJ) -o $(NAME_BONUS)

clean :
	rm -rf $(OBJ) $(BOBJ)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)
	
re : fclean $(NAME)

.PHONY : clean fclean re all bonus