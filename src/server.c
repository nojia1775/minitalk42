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

char	g_buf[1000000] = {0};

void	handler(int sig);
void	clean(char *buf);
void	print(void);

int	main(void)
{
	struct sigaction	action;
	
	action.sa_handler = handler;
	if (sigaction(SIGUSR1, &action, NULL) == -1 ||
		sigaction(SIGUSR2, &action, NULL) == -1)
		exit(EXIT_FAILURE);
	ft_printf("PID = %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}

void	handler(int sig)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (g_buf[i])
		i++;
	if (sig == SIGUSR1)
	{
		ft_printf("0");
                g_buf[i] = '0';
	}
	else
	{
		ft_printf("1");
		g_buf[i] = '1';
	}
	i = ft_strlen(g_buf) - 1;
	while (g_buf[i])
	{	
		if (g_buf[i--] == '0')
			count++;
		else
			count = 0;
		if (count == 8)
		{
			//print();
			clean(g_buf);
			return ;
		}
	}
}

void	print(void)
{
	char	*dec;

	dec = convert_dec(g_buf);
	if (!dec)
		return ;
	ft_printf("%s\n", dec);
}

void	clean(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\0')
		buf[i++] = '\0';
}
