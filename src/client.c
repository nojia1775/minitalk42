/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:52:30 by nadjemia          #+#    #+#             */
/*   Updated: 2024/01/24 11:29:02 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../include/color.h"

void	send(char *str, int pid);
void	handle(int sig);

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	action;

	action.sa_handler = handle;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		return (1);
	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	send(argv[2], pid);
	pause();
	return (0);
}

void	send(char *str, int pid)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 1 << 7;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if (str[i] & (x >> j++))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(400);
		}
		i++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(400);
	}
}

void	handle(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("%sLe message a ete recu%s\n", BGREEN, RESET);
}
