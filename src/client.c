/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:52:30 by nadjemia          #+#    #+#             */
/*   Updated: 2024/01/13 11:03:12 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"

int main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	count;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	count = ft_atoi(argv[2]);
	i = 0;
	while (i++ < count)
	{
		kill(pid, SIGUSR1);
		usleep(10000);
	}
	kill(pid, SIGUSR2);
	return (0);
}
