# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 23:18:54 by fdonna            #+#    #+#              #
#    Updated: 2022/07/19 17:01:02 by fdonna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell

MAKE	:= make -s -C
DELETE	:= rm -rf
PRINT	:= printf
ECHO	:= echo

WORKSPACE	:= $(shell pwd)
INC			:= $(WORKSPACE)/include
SRC			:= $(shell find $(WORKSPACE) -name '*.c')
OBJ			:= $(SRC:%.c=%.o)
DEP			:= $(SRC:%.c=%.d)

COLOR_BLACK		:= \033[1;30m
COLOR_RED		:= \033[1;31m
COLOR_GREEN		:= \033[1;32m
COLOR_YELLOW	:= \033[1;33m
COLOR_BLUE		:= \033[1;34m
COLOR_MAGENTA	:= \033[1;35m
COLOR_CYAN		:= \033[1;36m
COLOR_WHITE		:= \033[1;37m

NORME_H		:= norminette -R CheckDefine
NORME_C		:= norminette -R CheckForbiddenSourceHeader

DEP_LIBFT	:= $(WORKSPACE)/libft
LFT_SRC		:= $(shell find $(DEP_LIBFT) -name '*.c')
LFT_OBJ		:= $(LFT_SRC:%.c=%.o)
LFT_LIB		:= $(WORKSPACE)/libft/libft.a

CFLAGS		:= -I$(INC) -I$(DEP_LIBFT) -Wall -Wextra -std=c99 -MMD -MP -g

all: $(NAME)

-include $(DEP)
$(NAME): $(OBJ) $(LFT_LIB)
	@$(PRINT) "$(COLOR_BLACK)"
	@$(PRINT) "\n\
	░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\
	░░░███╗░░░███╗██╗███╗░░██╗██╗░██████╗██╗░░██╗███████╗██╗░░░░░██╗░░░░░░░░\n\
	░░░████╗░████║██║████╗░██║██║██╔════╝██║░░██║██╔════╝██║░░░░░██║░░░░░░░░\n\
	░░░██╔████╔██║██║██╔██╗██║██║╚█████╗░███████║█████╗░░██║░░░░░██║░░░░░░░░\n\
	░░░██║╚██╔╝██║██║██║╚████║██║░╚═══██╗██╔══██║██╔══╝░░██║░░░░░██║░░░░░░░░\n\
	░░░██║░╚═╝░██║██║██║░╚███║██║██████╔╝██║░░██║███████╗███████╗███████╗░░░\n\
	░░░╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝╚═════╝░╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝░░░\n\
	░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\
	\n"
	@$(PRINT) "$(COLOR_WHITE)Linking $(COLOR_GREEN)$@"
	@$(CC) -lpthread -lreadline -L$(DEP_LIBFT) -lft $(OBJ) -o $@
	@$(PRINT) "$(COLOR_WHITE) Done!\n"

$(LFT_LIB):
	@$(MAKE) $(DEP_LIBFT)

%.o: %.c
	@$(PRINT) "$(COLOR_GREEN)%-15s$(COLOR_CYAN)%-25s$(COLOR_WHITE)-> $(COLOR_MAGENTA)%-25s\n$(COLOR_WHITE)" "[$(NAME)]" "$(shell basename $<)" "$(shell basename $@)"
	@$(CC) $(CFLAGS) $< -c -o $@

clean:
	@$(DELETE) $(DEP) $(OBJ)

fclean: clean
	@$(DELETE) $(NAME)
	@$(MAKE) $(DEP_LIBFT) fclean

re: fclean all

norme:
	@$(PRINT) "$(COLOR_WHITE)Run $(COLOR_GREEN)%s $(COLOR_WHITE)in $(COLOR_YELLOW)%s$(COLOR_WHITE):\n" "$(NORME_C)" "$(WORKSPACE)/src"
	@$(NORME_C) $(WORKSPACE)/src
	@$(PRINT) "$(COLOR_WHITE)Run $(COLOR_GREEN)%s $(COLOR_WHITE)in $(COLOR_YELLOW)%s$(COLOR_WHITE):\n" "$(NORME_H)" "$(WORKSPACE)/include"
	@$(NORME_H) $(WORKSPACE)/include

.PHONY: all clean fclean re
