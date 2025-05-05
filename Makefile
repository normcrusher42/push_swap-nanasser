# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 18:06:28 by nanasser          #+#    #+#              #
#    Updated: 2025/05/06 00:48:05 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_PATH = obj/
LIBFT_PATH = libft/

NAME = push_swap.a
LIBFT = $(LIBFT_PATH)libft.a

SRC = ./swap.c swap_utils.c swap_errors.c stack_initializer.c \

OBJ = $(SRC:%.c=$(OBJ_PATH)%.o)

CC		=		cc

CFLAGS	= -Wall -Werror -Wextra

all:$(NAME)

$(NAME):  $(LIBFT) $(OBJ_PATH) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_PATH)%.o : %.c
	@echo "on the way, sir"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)
	@echo "yup, that's everything."

fclean: clean
	@rm -f $(NAME) 
	@rm -f $(LIBFT)
	@rm -f *.out

re: fclean $(NAME)

.PHONY: all clean fclean re