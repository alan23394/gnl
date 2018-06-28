# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/17 14:22:04 by abarnett          #+#    #+#              #
#    Updated: 2018/06/06 17:27:04 by abarnett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
C_SRCS := $(wildcard ./*.c)
C_OBJS := $(patsubst %.c,%.o,$(C_SRCS))
INCLUDE_DIRS := ./includes
CFLAGS += -Wall -Wextra -Werror -I$(INCLUDE_DIRS)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(C_SRCS)
	$(CC) $(CFLAGS) -c $(C_SRCS)
	ar rc $(NAME) $(C_OBJS)
	ranlib $(NAME)

clean:
	@- $(RM) $(C_OBJS)

fclean: clean
	@- $(RM) $(NAME)

re: fclean all
