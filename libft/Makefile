# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 20:01:36 by etieberg          #+#    #+#              #
#    Updated: 2019/09/09 15:56:41 by tmerli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_memset.c				\
	  ft_malloc_check.c			\
	  ft_bzero.c				\
	  ft_memcpy.c				\
	  ft_memccpy.c				\
	  ft_memmove.c				\
	  ft_memchr.c				\
	  ft_memcmp.c				\
	  ft_strlen.c				\
	  ft_strdup.c				\
	  ft_strcpy.c				\
	  ft_strncpy.c				\
	  ft_strcat.c				\
	  ft_strncat.c				\
	  ft_strlcat.c				\
	  ft_strchr.c				\
	  ft_strrchr.c				\
	  ft_strichr.c				\
	  ft_strstr.c				\
	  ft_strchrr.c				\
	  ft_strnstr.c				\
	  ft_strcmp.c				\
	  ft_strncmp.c				\
	  ft_arraylen.c				\
	  ft_arraydup.c				\
	  ft_atoi.c					\
	  ft_isalpha.c				\
	  ft_isdigit.c				\
	  ft_isalnum.c				\
	  ft_isascii.c				\
	  ft_isprint.c				\
	  ft_toupper.c				\
	  ft_tolower.c				\
	  ft_memalloc.c				\
	  ft_memdel.c				\
	  ft_strnew.c				\
	  ft_strdel.c				\
	  ft_strclr.c				\
	  ft_striter.c				\
	  ft_striteri.c				\
	  ft_strmap.c				\
	  ft_strmapi.c				\
	  ft_strequ.c				\
	  ft_strnequ.c				\
	  ft_strsub.c				\
	  ft_strjoin.c				\
	  ft_strjoinfree.c			\
	  ft_strtrim.c				\
	  ft_putchar.c				\
	  ft_putstr.c				\
	  ft_putendl.c				\
	  ft_putnbr.c				\
	  ft_putchar_fd.c			\
	  ft_putstr_fd.c			\
	  ft_putendl_fd.c			\
	  ft_putnbr_fd.c			\
	  ft_itoa.c					\
	  ft_itoabase.c				\
	  ft_strsplit.c				\
	  ft_lstnew.c				\
	  ft_lstdelone.c			\
	  ft_lstdel.c				\
	  ft_lstadd.c				\
	  ft_lstiter.c				\
	  ft_lstmap.c				\
	  ft_sqrt.c					\
	  ft_foreach.c				\
	  ft_range.c				\
	  ft_recursive_factorial.c	\
	  ft_iswhitespace.c			\
	  ft_wstrlen.c				\
	  ft_wcharlen.c				\
	  ft_wstrcpy.c				\
	  ft_charcmp.c				\
	  ft_charjoin.c				\
	  ft_intlen.c				\
	  ft_realloc.c				\
	  ft_free.c					\
	  ft_stradd.c				\
	  get_next_line.c			\
	  ft_get_input.c			\
	  ft_abs.c					\
	  ft_in_interval.c			\

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS += -g -Wall -Werror -Wextra -O3 -I ./includes

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
