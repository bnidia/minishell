# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 21:29:10 by fdonna            #+#    #+#              #
#    Updated: 2021/10/19 18:49:28 by fdonna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a

CC			:= gcc
CC_LIB		:= ar rsc
CFLAGS		:= -Wall -Wextra -Werror -std=c99

SOURCE_FOLDER	:= $(shell pwd)
HEADER_FOLDER	:= $(shell pwd)

BONUS_SOURCES	:= $(shell find $(SOURCE_FOLDER) -maxdepth 1 -name 'ft_lst*.c')
BONUS_OBJECTS	:= $(BONUS_SOURCES:%.c=%.o)

SOURCES	:= $(shell find $(SOURCE_FOLDER) -maxdepth 1 -name '*.c' ! -name 'ft_lst*.c')
HEADERS := $(shell find $(HEADER_FOLDER) -maxdepth 1 -name '*.h')
OBJECTS	:= $(SOURCES:%.c=%.o)
INCLUDE	:= -I$(HEADER_FOLDER)
REMOVE	:= rm -f

.PHONY: all bonus re clean fclean

all: $(NAME)

bonus: $(BONUS_OBJECTS)
	$(CC_LIB) $(NAME) $^

re: fclean all

$(NAME): $(OBJECTS)
	$(CC_LIB) $(NAME) $^
#	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) $< -c -o $@

clean:
	$(REMOVE) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

#so: $(OBJECTS)
#	$(CC) -shared -nostartfiles -o libft.so $(OBJECTS)
