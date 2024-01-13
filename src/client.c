/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:52:30 by nadjemia          #+#    #+#             */
/*   Updated: 2024/01/13 12:59:07 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	*convert_bin(char *str);
void	fill(char *bin, int c, int *i);
void	send(char *bin, int pid);

int	main(int argc, char **argv)
{
	int		pid;
	char	*bin;
	int		i;

	i = 0;
	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	bin = convert_bin(argv[2]);
	if (!bin)
		return (2);
	send(bin, pid);
	free(bin);
	return (0);
}

void	send(char *bin, int pid)
{
	int		i;

	i = 0;
	while (bin[i])
	{
		if (bin[i] == '0')
		{
			kill(pid, SIGUSR1);
			usleep(10000);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(10000);
		}
		i++;
	}
}

char	*convert_bin(char *str)
{
	char	*bin;
	size_t	len;
	int		i;
	int		x;

	x = 0;
	i = 0;
	len = ft_strlen(str) * 8;
	bin = malloc(sizeof(char) * (len + 1));
	if (!bin)
		return (NULL);
	while (str[i])
	{
		fill(bin, str[i], &x);
		i++;
	}
	bin[x] = '\0';
	return (bin);
}

void	fill(char *bin, int c, int *i)
{
	if (c >= 2)
	{
		fill(bin, c / 2, i);
		fill(bin, c % 2, i);
	}
	else
		bin[(*i)++] = '0' + c;
}
