# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chduong <chduong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/22 15:57:00 by chduong           #+#    #+#              #
#    Updated: 2021/09/09 17:42:05 by chduong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a

# --	Compilation flags  -- #
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

# --	Sources Files -- #
SRC	=	ft_printf.c		flag_utils.c	nbr_utils.c		str_utils.c\

OBJ	=	$(SRC:%.c=%.o)

$(NAME):	$(OBJ)
	ar -rcs $(NAME) $(OBJ)	

all:		$(NAME)

bonus :		$(NAME)

clean:
	$(RM) $(OBJ)

fclean: 
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
