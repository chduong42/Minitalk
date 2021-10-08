# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chduong <chduong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 15:26:43 by chduong           #+#    #+#              #
#    Updated: 2021/10/08 12:23:35 by chduong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################
#		Programmes			#
#############################
NAME			=	minitalk
SERVER			=	server
CLIENT			=	client
SERVER_BONUS	=	server_bonus
CLIENT_BONUS	=	client_bonus

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

SERVER_FILES = server.c $(PRINTF)
SBONUS_FILES = server_bonus.c $(PRINTF)

CLIENT_FILES = client.c $(PRINTF) 
CBONUS_FILES = client_bonus.c $(PRINTF) 

#############################
#		MAKE	RULES		#
#############################
$(NAME) : $(SERVER) $(CLIENT)

all:	$(NAME) bonus

bonus :	$(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER) : $(SERVER_FILES)
	$(CC) $(LFLAGS) $(SERVER_FILES) -o $(SERVER)

$(CLIENT) : $(CLIENT_FILES)
	$(CC) $(LFLAGS) $(CLIENT_FILES) -o $(CLIENT)

$(SERVER_BONUS) : $(SBONUS_FILES)
	$(CC) $(LFLAGS) $(SBONUS_FILES) -o $(SERVER_BONUS)

$(CLIENT_BONUS) : $(CBONUS_FILES)
	$(CC) $(LFLAGS) $(CBONUS_FILES) -o $(CLIENT_BONUS)

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
