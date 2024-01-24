/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:03:30 by nadjemia          #+#    #+#             */
/*   Updated: 2024/01/24 16:34:55 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../include/color.h"

char	g_buf[1000000] = {0};

void	handler(int sig, siginfo_t *info, void *context);
void	clean(char *buf);
void	print(void);
int		verif(int pid);

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		exit(EXIT_FAILURE);
	usleep(1000);
	ft_printf("\n\t\t  %sSERVER MINITALK%s\n\n", BRED, RESET);
	ft_printf("PID = %s%d%s\n", GREEN, getpid(), RESET);
	ft_printf("Zone de texte :\n");
	ft_printf("_____________________________________________________\n\n");
	while (1)
		sleep(1);
	return (0);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	int		i;

	(void)context;
	i = 0;
	while (g_buf[i])
		i++;
	if (sig == SIGUSR1)
		g_buf[i] = '0';
	else
		g_buf[i] = '1';
	if (verif(info->si_pid))
		return ;
}

int	verif(int pid)
{
	int		i;
	int		count;

	count = 0;
	i = ft_strlen(g_buf) - 1;
	while (g_buf[i])
	{
		if (g_buf[i--] == '0')
			count++;
		else
			count = 0;
		if (count == 8 && ft_strlen(g_buf) % 8 == 0)
		{
			print();
			clean(g_buf);
			usleep(10000);
			kill(pid, SIGUSR1);
			return (1);
		}
	}
	return (0);
}

void	print(void)
{
	char	*dec;

	dec = convert_dec(g_buf);
	if (!dec)
		return ;
	ft_printf("%s%s%s\n", BLUE, dec, RESET);
	free(dec);
}

void	clean(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\0')
		buf[i++] = '\0';
}
