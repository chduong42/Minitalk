# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chduong <chduong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 15:26:43 by chduong           #+#    #+#              #
#    Updated: 2021/10/07 16:22:35 by chduong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################
#		Programmes			#
#############################
NAME			=	minitalk
SERVER			=	server
CLIENT			=	client

#############################
#		Compilation			#
#		& Flags				#
#############################
CC		=	gcc $(CFLAGS)
CFLAGS	=	-Wall -Wextra -Werror

IFLAGS	= -I./ft_printf
LFLAGS	= -L./ft_printf

#############################
#		DIRECTORIES &		#
#		Sources Files		#
#############################
PRINTF_DIR	= ./ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

# SERVER_DIR = ./src/server
SERVER_FILES = server.c utils.c $(PRINTF) 

# CLIENT_DIR = ./src/client
CLIENT_FILES = client.c utils.c $(PRINTF) 

#############################
#		MAKE	RULES		#
#############################
$(NAME) : $(SERVER) $(CLIENT)

all:	$(NAME) 

bonus :	$(NAME)

$(SERVER) : $(SERVER_FILES)
	$(CC) $(LFLAGS) $(SERVER_FILES) -o $(SERVER)

$(CLIENT) : $(CLIENT_FILES)
	$(CC) $(LFLAGS) $(CLIENT_FILES) -o $(CLIENT)

$(PRINTF):
	make -C $(PRINTF_DIR)
	make -C $(PRINTF_DIR) clean

clean:
	make -C $(PRINTF_DIR) clean
#	$(RM) $(OBJ)

fclean: clean 
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	$(RM) $(SERVER_BONUS)
	$(RM) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re
