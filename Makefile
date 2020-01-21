# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 19:33:09 by ajeannot          #+#    #+#              #
#    Updated: 2019/12/12 20:14:43 by ajeannot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NAME_LIB = libft.a

SRCS_DIR = srcs/
LIBFT_DIR = libft/

SRCS = ft_add_arg.c ft_ajust_arg.c ft_ajust_arg_int_min.c ft_ajust_dispatch.c ft_annex.c ft_convert.c ft_manage_struct.c ft_parsing_arg.c ft_parsing_percent.c ft_printf.c ft_write.c ft_strlen.c ft_write_annex.c ft_convert_annex.c

OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

PRINTF_H =	-I /srcs/includes

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all:		$(NAME)

$(NAME_LIB):
							make -C $(LIBFT_DIR)
							cp $(LIBFT_DIR)$(NAME_LIB) $(NAME)

$(NAME):			$(NAME_LIB) $(OBJS)
							ar rcs $(NAME) $(OBJS)

clean:
							$(RM) $(OBJS)
							make clean -C $(LIBFT_DIR)

fclean:				clean
							$(RM) $(NAME) $(NAME_LIB)
							make fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY: clean fclean all re
