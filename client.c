/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:19:58 by chduong           #+#    #+#             */
/*   Updated: 2021/10/07 16:20:50 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receipt(int signal, siginfo_t *info, void *context)
{
	(void) context;
	if (signal == SIGUSR1)
		ft_printf("Server(PID: %d) received the signal.\n", info->si_pid);
}

int	send_byte(char byte, int pid_server)
{
	int					i;
	unsigned int		error;

	i = 0;
	error = 0;
	while (i < 8)
	{
		if (byte & (1 << i))
			error -= kill(pid_server, SIGUSR1);
		else
			error -= kill(pid_server, SIGUSR2);
		++i;
		pause();
	}
	return (error);
}

void	send_msg(char *str, int pid_server)
{
	unsigned int	error;

	error = 0;
	while (*str)
	{
		error += send_byte(*str, pid_server);
		++str;
	}
	error += send_byte(0, pid_server);
	if (error == 0)
		ft_printf("Message sent !\n");
	else
		ft_printf("%u signal(s) failed : message not sent...\n", error);
}

int	main(int argc, char **argv)
{
	int	pid;
	struct sigaction	sa;
	
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_receipt;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			ft_printf("Error, bad pid !\n");
		send_msg(argv[2], pid);
	}
	else
		ft_printf("Error, standard use is : \"./client_bonus <pidnumber> <your_message>\n");
	return (0);
}
