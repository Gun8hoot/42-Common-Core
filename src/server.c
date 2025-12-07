/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:35:21 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/07 17:03:10 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/minitalk.h"

volatile int	g_number_bit = 0;

char *fucking_arr(unsigned char character, char *old_arr)
{
	char *new_arr;

	new_arr = NULL;
	if (character == '\0')
	{
		ft_printf("%s\n", old_arr);
		free(old_arr);
	}
	else
	{
		new_arr = ft_strjoin(old_arr, (char[]){character, '\0'});
		if (old_arr)
			free(old_arr);
		if (!new_arr)
		{
			sleep(4);
			return (NULL);
		}
	}
	return (new_arr);
}

static void	bit2ascii(int signum, siginfo_t *info, void *nptr)
{
	static unsigned char	character = 0;
	static char				*arr = NULL;

	(void) nptr;
	character |= (signum == SIGUSR2);
	kill(info->si_pid, SIGUSR2);
	if (++g_number_bit == 8)
	{
		if (!arr)
		{
			arr = malloc(1);
			if (!arr)
			{
				sleep(4);
				return ;
			}
			arr[0] = '\0';
		}
		arr = fucking_arr(character, arr);
		character = 0;
		g_number_bit = 0;
	}
	else
		character <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = bit2ascii;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	ft_printf("\x1b[0;32m[!] Server PID is : %d\x1b[0m\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) ==
		-1)
	{
		ft_printf("\x1b[0;31m[!] Failed to listen for SIGUSR1/2\x1b[0m\n");
		return (-1);
	}
	ft_printf("\x1b[0;33m--------   WAITING FOR MESSAGES   --------\x1b[0m\n");
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
