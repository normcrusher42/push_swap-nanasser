# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 21:00:03 by nanasser          #+#    #+#              #
#    Updated: 2025/05/07 23:31:53 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_PATH = Lib_obj/

SRC = ./ft_atoi.c \
./ft_bzero.c \
./ft_calloc.c \
./ft_isalnum.c \
./ft_isalpha.c \
./ft_isascii.c \
./ft_isdigit.c \
./ft_isprint.c \
./ft_memchr.c \
./ft_memcmp.c \
./ft_memcpy.c \
./ft_memmove.c \
./ft_memset.c \
./ft_strchr.c \
./ft_strdup.c \
./ft_strlcat.c \
./ft_strlcpy.c \
./ft_strlen.c \
./ft_strncmp.c \
./ft_strnstr.c \
./ft_strrchr.c \
./ft_tolower.c \
./ft_toupper.c \
./ft_substr.c \
./ft_strjoin.c \
./ft_strtrim.c \
./ft_split.c \
./ft_itoa.c \
./ft_strmapi.c \
./ft_striteri.c \
./ft_putchar_fd.c \
./ft_putstr_fd.c \
./ft_putendl_fd.c \
./ft_putnbr_fd.c \
./ft_lstnew.c \
./ft_lstadd_front.c \
./ft_lstsize.c \
./ft_lstadd_back.c \
./ft_lstdelone.c \
./ft_lstclear.c \
./ft_lstiter.c \
./ft_lstlast.c \
./ft_printf.c ft_printf_str.c ft_printf_unsigned.c ft_printf_ptr.c ft_printf_hex.c \
./get_next_line.c get_next_line_utils.c \

OBJ = $(SRC:%.c=$(OBJ_PATH)%.o)

CC		= cc

CFLAGS += -Wall -Werror -Wextra

NAME = libft.a

GREEN=\033[0;32m
YELLOW=\033[0;33m

MAKEFLAGS += --no-print-directory

all:$(NAME)

$(NAME)	:	$(OBJ_PATH) $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo "$(GREEN)Libft done. Next."

$(OBJ_PATH)%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f *.out

re: fclean $(NAME)

.PHONY: all clean fclean re