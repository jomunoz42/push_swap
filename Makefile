# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jomunoz <jomunoz@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 20:12:32 by jomunoz           #+#    #+#              #
#    Updated: 2025/07/09 23:07:57 by jomunoz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Iinc -Wall -Werror -Wextra
SRC = programs/push_swap.c sorting/sorting.c sorting/sorting_utils1.c \
	sorting/sorting_utils2.c parsing/parsing.c parsing/parse_util.c \
	operations/swap.c operations/rotate.c operations/reverse_rotate.c \
	operations/push.c utils/utils.c \

SRC_BONUS = programs/checker.c utils/get_next_line.c utils/utils.c \
	parsing/parsing.c parsing/parse_util.c operations/swap.c \
	operations/push.c operations/rotate.c operations/reverse_rotate.c \
	sorting/sorting_utils1.c sorting/sorting_utils2.c

SRCOBJ = obj/
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(SRCOBJ),$(OBJ))
OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJ_BONUS := $(addprefix $(SRCOBJ),$(OBJ_BONUS))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS)

bonus: $(BONUS)

obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus