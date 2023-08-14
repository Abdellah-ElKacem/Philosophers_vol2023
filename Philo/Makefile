# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 10:27:20 by ael-kace          #+#    #+#              #
#    Updated: 2023/08/14 11:11:44 by ael-kace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = philo.h

SRC = philo.c utils.c linked_list_tool.c init.c routine.c util_death.c 

OBJ = $(SRC:.c=.o)

CC = cc 

CFLAG = -Wall -Wextra -Werror -pthread 
#CFLAG = -Wall -Wextra -Werror -pthread -fsanitize=address

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG)  $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAG) -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY = all clean fclean re