# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 18:06:28 by nanasser          #+#    #+#              #
#    Updated: 2025/05/08 21:55:03 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_PATH = obj/
OBJ_PATH2 = swap_operations/obj/
LIBFT_PATH = libft/

NAME = push_swap.a
LIBFT = $(LIBFT_PATH)libft.a

SRC = ./push_swap.c swap_utils.c swap_errors.c stack_initializer.c initialize_a_to_b.c initialize_b_to_a.c \

SRC2 = swap_operations/swap.c swap_operations/sort_three.c swap_operations/rotate.c swap_operations/r_rotate.c swap_operations/sort_stacks.c swap_operations/push.c \

OBJ = $(SRC:%.c=$(OBJ_PATH)%.o)
OBJ2 = $(SRC2:swap_operations/%.c=$(OBJ_PATH2)%.o)

CC		=		cc

CFLAGS	= -Wall -Werror -Wextra

GREEN=\033[0;32m
YELLOW=\033[0;33m

MAKEFLAGS += --no-print-directory

all:$(NAME)

$(NAME): $(LIBFT) $(OBJ_PATH) $(OBJ_PATH2) $(OBJ) $(OBJ2)
	@echo "$(YELLOW)Main Make on the way, sir."
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJ) $(OBJ2)
	@echo "$(GREEN)fini. now fuck around and find out."

$(LIBFT):
	@echo "$(YELLOW)Libft Make on the way, sir."
	@make -C $(LIBFT_PATH) all

$(OBJ_PATH)%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH2)%.o : swap_operations/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH2):
	@mkdir -p $(OBJ_PATH2)

clean:
	@rm -rf $(OBJ_PATH) $(OBJ_PATH2)
	@make clean -C $(LIBFT_PATH)
	@echo "$(GREEN)cleaned like the blackhole you're getting if you don't STOP COOKING"

fclean: clean
	@rm -f $(NAME) 
	@rm -f $(LIBFT)
	@rm -f *.out

re: fclean $(NAME)

.PHONY: all clean fclean re