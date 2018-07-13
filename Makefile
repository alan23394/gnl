# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 07:28:52 by abarnett          #+#    #+#              #
#    Updated: 2018/07/12 18:58:06 by abarnett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := gnl
C_OBJS := $(patsubst %.c,%.o,$(wildcard ./*.c))
INCLUDE_DIRS := ./libft/includes
CFLAGS += -Wall -Wextra -Werror -g -fsanitize=address -I$(INCLUDE_DIRS)
LDFLAGS += -L./libft -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(C_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LDFLAGS)

clean:
	@- $(RM) $(C_OBJS)

fclean: clean
	@- $(RM) $(NAME)

re: fclean all
