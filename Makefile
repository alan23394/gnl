# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 07:28:52 by abarnett          #+#    #+#              #
#    Updated: 2018/06/26 15:29:44 by abarnett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := gnl
LIB := libft.a
C_OBJS := $(patsubst %.c,%.o,$(wildcard ./*.c))
L_OBJS := $(patsubst %.c,%.o,$(wildcard ./libft/*.c))
INCLUDE_DIRS := ./libft
CFLAGS += -Wall -Wextra -Werror -g -I$(INCLUDE_DIRS)
LDFLAGS += -L./ -lft

.PHONY: all clean fclean re

all: $(NAME)
	./gnl

$(LIB): $(L_OBJS)
	ar rc $(LIB) $(L_OBJS)
	ranlib $(LIB)

$(NAME): $(LIB) $(C_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LDFLAGS)

clean:
	@- $(RM) $(C_OBJS) $(L_OBJS)

fclean: clean
	@- $(RM) $(NAME) $(LIB)

re: fclean all
