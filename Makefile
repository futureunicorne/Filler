# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 11:53:06 by hel-hadi          #+#    #+#              #
#    Updated: 2017/02/10 18:32:54 by hel-hadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ayam.filler
PREF = ./srcs/
HEADER = ./includes/
SRCS = 	filler.c	\
		main.c		\

OBJ = $(SRCS:.c=.o)
OBJ1 = objets/*.o
FLAGS = -Wall -Werror -Wextra
CC = gcc
OPT1 = -c
OPT2 = -o

all: $(NAME)

$(NAME):
		make -C libft fclean && make -C libft
		$(CC) $(FLAGS) -I$(HEADER) -c $(SRCS)
		$(CC) $(OBJ) -L./libft/ -lft $(OPT2) $(NAME)
		@echo "\033[36m === Creation de l'executable filler ===\033[0m"


clean	:
	@make clean -C libft/
	@rm -rf objets
	rm -rf *.o
	@echo "\033[31m === Suppression des fichiers objets===\033[0m"

fclean: clean
	@make fclean -C libft/
	rm -f $(NAME)
	@echo "\033[31m === Suppression du fichier executable===\033[0m"


re: fclean all
	 @echo "\033[35m === Renouvellement executable ====\033[0m"

.PHONY: clean fclean re
