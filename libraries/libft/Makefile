# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 19:16:59 by bnidia            #+#    #+#              #
#    Updated: 2021/10/26 16:05:02 by bnidia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Manual for Makefile
# https://www.gnu.org/software/make/manual/html_node/index.html
NAME = libft.a

SRCDIR = ./
OBJDIR = ./obj/

SRC	= ft_isalpha.c ft_toupper.c ft_calloc.c ft_isdigit.c ft_tolower.c \
ft_strdup.c ft_isalnum.c ft_strchr.c ft_realloc.c ft_isascii.c ft_strrchr.c \
get_next_line.c ft_isprint.c ft_strncmp.c ft_max_double.c ft_strlen.c \
ft_memchr.c ft_abs_double.c ft_memset.c ft_memcmp.c ft_bzero.c ft_strnstr.c \
ft_memcpy.c	ft_atoi.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_quick_sort.c \
ft_malloc.c ft_substr.c ft_striteri.c ft_strjoin.c ft_putchar_fd.c \
ft_strtrim.c ft_putstr_fd.c ft_split.c ft_putendl_fd.c ft_itoa.c ft_putnbr_fd.c\
ft_strmapi.c ft_numlen.c

SRC += ft_lstnew.c ft_lstdelone.c ft_lstadd_front.c ft_lstclear.c \
ft_lstsize.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstadd_back.c \
ft_lstc_add.c ft_lstc_del_one.c ft_lstc_clear.c ft_lstc_size.c \
ft_lstc_new.c ft_lstc_pop.c

SRC += ft_printf.c ft_printf_c.c ft_printf_d.c ft_printf_p.c \
ft_printf_s.c ft_printf_u.c ft_printf_x.c \
ft_itoa_base.c ft_printf_common_functions.c

OBJ = $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))
D_FILES = $(addprefix $(OBJDIR), $(notdir$(SRC:.c=.d)))
HEADER = libft.h

CC = gcc -Wall -Werror -Wextra
DEBUG_SWITCH = TRUE
ifeq ($(DEBUG_SWITCH), TRUE)
	DEBUG = -g
else
	OPTIMIZATION = -O1
endif

all: $(NAME)

# translation of assembly language code into machine code
# -c, stops after assembly stage
# -MD lists both system header files and user header files, dependencies
# -MMD lists only user header files, dependencies
# $< the first prerequisite (usually a source file) main.c (dependency %.c)
# $@ is the name of the target being generated main.o (target %.o)
$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER) | obj
	$(CC) $(DEBUG) $(OPTIMIZATION) $(LIBINC) -c $< -o $@ -MMD

# linking stage
# ar - create, modify, and extract from archives ar is considered a binary
# utility because archives of this sort are most often used as libraries
# holding commonly needed subroutines
# r Insert the files member... into archive (with replacement)
# c Create the archive. The specified archive is always created if it
# did not exist, when you request an update.
# s Write an object-file index into the archive, or update an existing one,
# even if no other change is made to the archive. You may use this modifier
# flag either with any operation, or alone. Running ar s on an archive is
# equivalent to running ranlib on it.
$(NAME): $(OBJ)
	ar rcs $(NAME) $?

obj:
	mkdir -p $(OBJDIR)

include $(wildcard $(D_FILES))

norm:
	norminette $(SRC) $(HEADER)

test: all
	gcc -Wall -Werror -Wextra -g main.c libft.a

# rule for the cleaning
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

# rule for rebuild a project
re: fclean all

# directory exceptions
.PHONY: all test clean fclean re
