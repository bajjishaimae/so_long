# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 09:59:21 by cbajji            #+#    #+#              #
#    Updated: 2024/05/03 09:59:22 by cbajji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	so_long
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit
FTPRINTF	=	ft_printf/libftprintf.a

SRC			=	utiles.c utiles2.c so_long.c mouvements1.c mouvements2.c graphics.c check_map1.c check_map2.c\
				get_next_line.c get_next_line_ut.c\
				ft_printf/ft_printf.c ft_printf/ft_putadr.c ft_printf/ft_putchar.c\
				ft_printf/ft_putnbr_hex.c ft_printf/ft_putnbr_uns.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c\

OBJS        = $(SRC:.c=.o)

all         : $(NAME)

$(NAME)     : $(OBJS)
				make -C ft_printf
	            $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FTPRINTF) $(MLX_FLAGS)

%.o			:	%.c so_long.h
			$(CC) $(CFLAGS) -c $< -o $@

clean       :
				make -C ft_printf clean
	            @rm -f $(OBJS)

fclean      : clean
				make -C ft_printf fclean
	            @rm -f $(NAME)

re          : fclean all

.PHONY      : clean
