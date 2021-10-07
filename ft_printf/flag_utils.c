/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:38:34 by chduong           #+#    #+#             */
/*   Updated: 2021/09/09 17:45:38 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flag(t_format *fmt)
{
	fmt->space = 0;
	fmt->plus = 0;
	fmt->hash = 0;
}

const char	*check_flag(const char *str, t_format *fmt)
{
	int	flags;

	flags = 1;
	while (flags > 0)
	{
		if (*str == '#')
			fmt->hash = 1;
		else if (*str == ' ')
			fmt->space = 1;
		else if (*str == '+')
			fmt->plus = 1;
		else
		{
			flags = 0;
			break ;
		}
		++str;
	}
	return (str);
}

void	ft_putflag(t_format *fmt)
{
	if (fmt->space && !fmt->plus)
		ft_putchar(' ', fmt);
	else if (fmt->plus)
		ft_putchar('+', fmt);
	reset_flag(fmt);
}
