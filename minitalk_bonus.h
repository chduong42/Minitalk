/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:20:02 by chduong           #+#    #+#             */
/*   Updated: 2021/10/12 13:38:23 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

# define ERROR -1
# define SUCCESS 0

char	*str_join(char *str, char c);

int		ft_atoi(const char *str);
int		receive_byte(char *byte, int signal);

void	send_byte(char byte, int pid);
void	send_msg(char *str, int pid);
void	reveive_msg(int signal, siginfo_t *info, void *context);
void	signal_receipt(int signal);

#endif
