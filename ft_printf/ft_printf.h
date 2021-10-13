/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:55:38 by chduong           #+#    #+#             */
/*   Updated: 2021/10/13 16:50:49 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_format
{
	int	len;
	int	plus;
	int	space;
	int	hash;
}		t_format;

void		reset_flag(t_format *fmt);
void		ft_putchar(char c, t_format *fmt);
void		ft_putstr(char *s, t_format *fmt);
void		ft_putnbr(int nb, t_format *fmt);
void		ft_putunbr(unsigned int n, t_format *fmt);
void		ft_puthex(unsigned int nb, char *base, t_format *fmt);
void		ft_putnbr_hex(unsigned long int nb, char *base, t_format *fmt);
void		ft_putaddr(void *addr, t_format *fmt);
void		ft_putflag(t_format *fmt);

int			ft_printf(const char *str, ...);

size_t		ft_strlen(const char *s);
size_t		ft_substrlen(const char *s);

const char	*check_flag(const char *str, t_format *fmt);

#endif 