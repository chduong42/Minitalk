/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:12:42 by chduong           #+#    #+#             */
/*   Updated: 2021/09/09 18:02:13 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_parse(const char *str, va_list args, t_format *fmt)
{
	str = check_flag(str, fmt);
	if (*str == 'c')
		ft_putchar(va_arg(args, int), fmt);
	else if (*str == 's')
		ft_putstr(va_arg(args, char *), fmt);
	else if (*str == 'p')
		ft_putaddr(va_arg(args, void *), fmt);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(args, int), fmt);
	else if (*str == 'u')
		ft_putunbr(va_arg(args, unsigned int), fmt);
	else if (*str == 'x')
		ft_puthex(va_arg(args, unsigned int), "0123456789abcdef", fmt);
	else if (*str == 'X')
		ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF", fmt);
	else if (*str == '%')
		ft_putchar('%', fmt);
	reset_flag(fmt);
	return (str + 1);
}

int	ft_printf(const char *str, ...)
{
	t_format	fmt;
	va_list		args;

	fmt.len = 0;
	reset_flag(&fmt);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			str = ft_parse(++str, args, &fmt);
		else
		{
			fmt.len += write (1, str, ft_substrlen(str));
			str += ft_substrlen(str);
		}
	}
	va_end(args);
	return (fmt.len);
}
