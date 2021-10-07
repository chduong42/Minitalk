/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:20:04 by chduong           #+#    #+#             */
/*   Updated: 2021/10/07 16:20:53 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	receive_byte(char *byte, int signal, int pid_client)
{
	static int		i = 0;
	
	if (i == 8)
	{
		*byte = 0;
		i = 0;
	}
	if (i < 8)
	{
		if (signal == SIGUSR1 && i < 8)
			*byte |= (1 << i++);
		else if (signal == SIGUSR2 && i < 8)
			*byte |= (0 << i++);
		kill(pid_client, SIGUSR1);
	}
	return(i);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static char		*str;
	static char		c = 0;
	int				i;
	
	(void)context;
	i = receive_byte(&c, signal, info->si_pid);
	if (i == 8 && c)
		str = str_join(str, c);
	if (i == 8 && !c)
	{
		ft_printf("Client(PID: %d) : %s\n", info->si_pid, str);
		free(str);
		str = NULL;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	ft_printf("Server PID : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
