# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 18:06:28 by nanasser          #+#    #+#              #
#    Updated: 2025/05/11 03:33:32 by marvin           ###   ########.fr        #
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
BGREEN=\033[1;32m
YELLOW=\033[0;33m
WHITE=\033[0;37m

MAKEFLAGS += --no-print-directory

all:$(NAME)

$(NAME): $(LIBFT) $(OBJ_PATH) $(OBJ_PATH2) $(OBJ) $(OBJ2)
	@echo "$(YELLOW)Main Make on the way, sir.$(WHITE)"
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJ) $(OBJ2)
	@cc push_swap.c *.a -o push_swap -fsanitize=address -g3
	@echo "$(GREEN)push_swap has been compiled with the library.$(WHITE)"
	@echo "$(BGREEN)fini. now fuck around and find out.$(WHITE)"

$(LIBFT):
	@echo "$(YELLOW)Libft Make on the way, sir.$(WHITE)"
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
	@echo "$(BGREEN)cleaned like the blackhole you're getting if you DON'T GET TO COOKING"

fclean: clean
	@rm -f $(NAME) 
	@rm -f $(LIBFT)
	@rm -f push_swap

re: fclean $(NAME)

.PHONY: all clean fclean re