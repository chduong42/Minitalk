/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:30:22 by kennyduong        #+#    #+#             */
/*   Updated: 2021/10/07 16:09:17 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	nb;

	sign = 1;
	nb = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\v' || *str == '\f')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - 48;
		++str;
	}
	return (sign * nb);
}

char	*str_join(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * (ft_strlen(str) + 2));
	if (!new)
		return (NULL);
	while (str && str[i])
	{
		new[i] = str[i];
		++i;
	}
	new[i++] = c;
	new[i] = 0;
	if (str)
		free(str);
	return (new);
}