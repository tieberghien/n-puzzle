# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 12:25:25 by etieberg          #+#    #+#              #
#    Updated: 2019/09/24 12:19:43 by etieberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	solver

SRC				=	main.c		\
					read_file.c	\
					ft_split.c \
					A-star.c \
					A-star2.c \
					heuristic.c \
					utils.c \
					utils2.c \
					f_score.c

OBJ_NAME		=	$(SRC:.c=.o)

SRC_PATH		=	srcs/
OBJ_PATH		=	objs/

OBJ				=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g3 -fsanitize=address
LDFLAGS			=	-Llibft -lft

INC_DIR			=	includes
INCS			=	-I $(INC_DIR) -I libft/includes/.

all:			library $(NAME)

$(NAME):		$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

library :
	make -C libft

clean:
	rm -fv $(OBJ)
	rm -rfv $(OBJ_PATH)
	make clean -C libft/

fclean: clean
	rm -fv $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all, clean, fclean, re
