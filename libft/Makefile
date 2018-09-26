# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apetrech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 18:02:09 by apetrech          #+#    #+#              #
#    Updated: 2018/08/01 13:50:05 by apetrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_*.c \
	   get_next_line.c \
	   cases.c \
	   flags.c \

OBJS = ft_*.o \
		get_next_line.o \
		cases.o \
		flags.o \

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
