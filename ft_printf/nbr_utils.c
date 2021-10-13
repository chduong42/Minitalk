/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:37:08 by chduong           #+#    #+#             */
/*   Updated: 2021/09/10 16:47:40 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, t_format *fmt)
{
	unsigned int	n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-', fmt);
		reset_flag(fmt);
		n = -nb;
	}
	else
		ft_putflag(fmt);
	if (n > 9)
		ft_putnbr((n / 10), fmt);
	ft_putchar(((n % 10) + 48), fmt);
}

void	ft_putunbr(unsigned int n, t_format *fmt)
{
	if (n > 9)
		ft_putunbr((n / 10), fmt);
	ft_putchar(((n % 10) + 48), fmt);
}

void	ft_putnbr_hex(unsigned long int nb, char *base, t_format *fmt)
{
	if (nb > 15)
		ft_putnbr_hex(nb / 16, base, fmt);
	ft_putchar(base[nb % 16], fmt);
}

void	ft_puthex(unsigned int nb, char *base, t_format *fmt)
{
	if (nb != 0 && base[15] == 'f' && fmt->hash)
		ft_putstr("0x", fmt);
	else if (nb != 0 && base[15] == 'F' && fmt->hash)
		ft_putstr("0X", fmt);
	ft_putnbr_hex(nb, base, fmt);
}

void	ft_putaddr(void *addr, t_format *fmt)
{
	ft_putstr("0x", fmt);
	ft_putnbr_hex((uintptr_t)addr, "0123456789abcdef", fmt);
}
