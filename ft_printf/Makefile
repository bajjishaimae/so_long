# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 11:46:06 by cbajji            #+#    #+#              #
#    Updated: 2023/12/12 11:49:39 by cbajji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a
HEAD	:=	ft_printf.h
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
AR		:=	ar rcs
RM		:=	rm -f

SRCS	:=	ft_printf.c ft_putadr.c ft_putchar.c ft_putnbr_hex.c ft_putnbr_uns.c ft_putnbr.c ft_putstr.c

OBJS	:=	$(SRCS:%c=%o)

all		:	 $(NAME)

%o		:	%c $(HEAD)
			$(CC) $(CFLAGS) -c -o $@ $<

$(NAME)	:	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all