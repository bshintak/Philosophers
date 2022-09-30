# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 12:19:31 by bshintak          #+#    #+#              #
#    Updated: 2022/09/29 17:16:17 by bshintak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME		=	philosophers
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
PHI_FLAG	=	-pthread
MKD			=	mkdir
RM			=	rm -f

SRC_NAME	=	args_checker.c	\
				death_checker.c	\
				eat_checker.c	\
				finish.c		\
				init.c			\
				philosophers.c	\
				print.c			\
				thread.c		\
				time.c
				
SRCS		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJS		=	$(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRCS))
DEPS		=	./libft/libft.a

SRC_PATH	=	./src
OBJ_PATH	=	./objects

all: $(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(DEPS) $(OBJ_PATH) $(OBJS)
	$(CC) $(PHI_FLAG) $(CFLAGS) $(OBJS) -o $(NAME) $(DEPS)
	echo "[PHILOSOPHERS COMPILED]"

LIBFT_PATH	= ./libft
./libft/libft.a: $(shell make -C $(LIBFT_PATH) -q libft.a || echo force)
	make -C $(LIBFT_PATH)

$(OBJ_PATH):
	$(MKD) -p objects

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) -r $(OBJ_PATH)
	echo "all $(NAME).o files are removed"

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
	echo "$(NAME) is deleted"

re:	fclean all

.PHONY: all clean fclean re force