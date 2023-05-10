# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 14:38:46 by edolgun           #+#    #+#              #
#    Updated: 2022/11/13 16:08:08 by edolgun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash

NAME		= client
NAMESV		= server
NAMEBC		= client_bonus
NAMEBS		= server_bonus
PRINTF		= ft_printf
INC			= inc
HEADER		= -I inc
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -f
ECHO		= echo -e
FSANITIZE	= -fsanitize=address -g3

SRCCL_FILES	=	client
SRCSV_FILES	=	server
SRCBC_FILES	=	client_bonus
SRCBS_FILES	=	server_bonus

SRCCL 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCCL_FILES)))
OBJCL 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCCL_FILES)))

SRCSV 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCSV_FILES)))
OBJSV 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCSV_FILES)))

SRCBC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBC_FILES)))
OBJBC 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBC_FILES)))

SRCBS 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBS_FILES)))
OBJBS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBS_FILES)))


OBJF		=	.cache_exists

start:
			@make -C $(PRINTF)
			@mkdir $(OBJ_DIR)
			@cp $(PRINTF)/libftprintf.a .
			@make all

all:		$(NAME) $(NAMESV)

$(NAME):	$(OBJCL) $(OBJF)
			@$(CC) $(FLAGS) $(OBJCL) $(HEADER) libftprintf.a -o $(NAME)

$(NAMESV):	$(OBJSV) $(OBJF)
			@$(CC) $(FLAGS) $(OBJSV) $(HEADER) libftprintf.a -o $(NAMESV)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
			@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@touch $(OBJF)

bonus:
			@make -C $(PRINTF)
			@cp $(PRINTF)/libftprintf.a .
			@make allbonus

allbonus:		$(NAMEBC) $(NAMEBS)

$(NAMEBC):	$(OBJBC) $(OBJF)
			@$(CC) $(FLAGS) $(OBJBC) $(HEADER) libftprintf.a -o $(NAMEBC)

$(NAMEBS):	$(OBJBS) $(OBJF)
			@$(CC) $(FLAGS) $(OBJBS) $(HEADER) libftprintf.a -o $(NAMEBS)

clean:
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(OBJF)
			@make clean -C $(PRINTF)

fclean:		clean
			@$(RM) $(NAME) $(NAMESV) $(NAMEBC) $(NAMEBS)
			@$(RM) $(PRINTF)/libftprintf.a
			@$(RM) libftprintf.a
			@find . -name ".DS_Store" -delete

re:			fclean all

.PHONY:		start all clean fclean re bonus