/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:03:30 by nadjemia          #+#    #+#             */
/*   Updated: 2024/01/13 13:32:34 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	buf[1000000] = {0};

void	handler0(int sig);
void	handler1(int sig);
void	clean(char *buf);

int	main(void)
{
	struct sigaction	zero;
	struct sigaction	un;

	zero.sa_handler = handler0;
	un.sa_handler = handler1;
	sigaction(SIGUSR1, &zero, NULL);
	sigaction(SIGUSR2, &un, NULL);
	ft_printf("PID = %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}

void	handler0(int sig)
{
	int		i;

	i = 0;
	if (sig == SIGUSR1)
	{
		ft_printf("0");
		while (buf[i])
			i++;
		buf[i] = '0';
	}
}

void	handler1(int sig)
{
	int		i;

	i = 0;
	if (sig == SIGUSR2)
	{
		ft_printf("1");
		while (buf[i])
			i++;
		buf[i] = '1';
	}
}

void	clean(char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
		buf[i++] = '\0';
}
