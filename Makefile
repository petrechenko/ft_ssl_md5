# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apetrech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 14:34:38 by apetrech          #+#    #+#              #
#    Updated: 2018/09/24 14:34:44 by apetrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = ft_ssl

FLAGS = -Wall -Wextra -Werror -g

LIBFT = libft

LIB = libft.a

SRCS = helper.c main.c print.c sha256.c md5.c flags.c

OBJS = helper.o main.o print.o sha256.o md5.o flags.o 

LIBFLAGS = -L./libft -lft

RED		=	\033[0;31m
YELL	=	\033[0;33m
PUR		=	\033[0;35m

all: $(NAME)

$(NAME):
	@echo "$(RED)compiling $@...$(PUR)"
	make -C $(LIBFT)
	@$(CC) $(FLAGS) -c $(SRCS) -I $(LIBFT)
	@$(CC) -o $(NAME) $(OBJS) $(LIBFLAGS)

clean:
	@echo "$(YELL)deleting $@...$(PUR)"
	@rm -f $(OBJS)
	@make fclean -C $(LIBFT)

fclean: clean
	@echo "$(YELL)deleting $@...$(PUR)"
	@rm -f $(NAME)
	@rm -f $(LIBFT)/$(LIB)

re: fclean all
