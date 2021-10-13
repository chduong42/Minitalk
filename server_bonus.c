/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:20:04 by chduong           #+#    #+#             */
/*   Updated: 2021/10/13 15:21:40 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

int	receive_byte(char *byte, int signal)
{
	static int	i = 0;

	if (i == 8)
	{
		*byte = 0;
		i = 0;
	}
	if (signal == SIGUSR1 && i < 8)
		*byte |= (1 << i++);
	else if (signal == SIGUSR2 && i < 8)
		*byte |= (0 << i++);
	return (i);
}

void	receive_msg(int signal, siginfo_t *info, void *context)
{
	static char		*str;
	static char		c = 0;
	int				bit;

	(void)context;
	bit = receive_byte(&c, signal);
	if (bit == 8 && c)
		str = str_join(str, c);
	if (bit == 8 && !c)
	{
		ft_printf("Client(PID: %d) : %s\n\n", info->si_pid, str);
		free(str);
		str = NULL;
	}
	usleep(300);
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_msg;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	(void)argv;
	if (argc > 1)
	{
		ft_printf("Server don't take any argument\n");
		exit(EXIT_FAILURE);
	}
	else
		ft_printf("Server's PID: %d\n", getpid());
	while (42)
		pause();
	return (0);
}
