/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:19:58 by chduong           #+#    #+#             */
/*   Updated: 2021/10/08 13:19:58 by chduong          ###   ########.fr       */
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

void	signal_receipt(int signal, siginfo_t *info, void *context)
{
	(void) context;
	if (signal == SIGUSR1)
		ft_printf("Server(PID: %d) received the signal.\n", info->si_pid);
}

void	send_byte(char byte, int pid)
{
	int					i;
	unsigned int		error;

	i = 0;
	error = 0;
	while (i < 8)
	{
		if (byte & (1 << i))
			error -= kill(pid, SIGUSR1);
		else
			error -= kill(pid, SIGUSR2);
		++i;
		if (error)
		{
			ft_printf("A signal failed : message not sent...\n");
			exit(EXIT_FAILURE);
		}
		pause();
	}
}

void	send_msg(char *str, int pid)
{
	while (*str)
	{
		send_byte(*str, pid);
		++str;
	}
	send_byte(0, pid);
	ft_printf("Message sent !\n");
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_receipt;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			ft_printf("Error, bad pid !\n");
		send_msg(argv[2], pid);
	}
	else
		ft_printf("/!\\Standard use is: \"./client_bonus <pid> <youur_msg>\n");
	return (0);
}
