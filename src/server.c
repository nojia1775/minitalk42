/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:03:30 by nadjemia          #+#    #+#             */
/*   Updated: 2024/01/13 11:09:45 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "../include/libft.h"
#include "../include/ft_printf.h"

int	count = 0;

void	handler1(int sig);
void	handler2(int sig);

int	main(void)
{
	struct sigaction	recep;
	struct sigaction	print;

	recep.sa_handler = handler1;
	print.sa_handler = handler2;
	sigaction(SIGUSR1, &recep, NULL);
	sigaction(SIGUSR2, &print, NULL);
	ft_printf("PID = %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}

void	handler1(int sig)
{
	if (sig != SIGUSR1)
		return ;
	count++;
}

void	handler2(int sig)
{
	if (sig != SIGUSR2)
		return ;
	ft_printf("%d\n", count);
	count = 0;
}
