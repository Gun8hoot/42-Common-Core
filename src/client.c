/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0025/11/15 13:35:47 by clavel            #+#    #+#             */
/*   Updated: 2025/11/19 14:17:04 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/minitalk.h"

volatile sig_atomic_t	g_ack_status = 0;

void	acknowledge(int signum, siginfo_t *info, void *nptr)
{
	(void)signum;
	(void)info;
	(void)nptr;
	g_ack_status = 1;
}

int	sendbits(pid_t pid, int bit)
{
	int	timeout;

	timeout = 0;
	g_ack_status = 0;
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1))
			return (EXIT_FAILURE);
	}
	else
	{
		if (kill(pid, SIGUSR2))
			return (EXIT_FAILURE);
	}
	while (!g_ack_status && ++timeout < 60000)
		usleep(1);
	if (!g_ack_status)
	{
		ft_printf("\x1b[0;33m[!] TIMEOUT\x1b[0m\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	converttobits(pid_t pid, char *message)
{
	int	bit;
	int	i;

	while (*message)
	{
		i = 8;
		while ((i--) > 0)
		{
			bit = (*message >> i & 1);
			if (sendbits(pid, bit) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		message++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(800);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = acknowledge;
	sigemptyset(&sa.sa_mask);
	if (argc < 3 || argc > 3)
	{
		ft_printf("\x1b[0;33m[!] Arguments error : %s {PID} {MSG}\x1b[0m\n",
			argv[0]);
		return (EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("\x1b[0;31m[!] Acknowledge server failed.\x1b[0m\n");
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (converttobits(pid, argv[2]) == EXIT_FAILURE)
	{
		ft_printf("\x1b[0;31m[!] Failed to send the message\x1b[0m\n");
		return (EXIT_FAILURE);
	}
	ft_printf("\x1b[0;32m[!] The message has been succesfully send\x1b[0m\n");
	return (EXIT_SUCCESS);
}
