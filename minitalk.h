/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:20:02 by chduong           #+#    #+#             */
/*   Updated: 2021/10/07 16:09:41 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

# define ERROR -1
# define SUCCESS 0

int		ft_atoi(const char *str);
char	*str_join(char *str, char c);

#endif
