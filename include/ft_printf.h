/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:54:57 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/22 15:14:30 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int			ft_printf(const char *format, ...);
void		ft_putchar(char c);
void		ft_putstr(const char *str);
void		ft_puthex(int n);
char		*ft_strupper(char *str);
void		ft_putun(unsigned int n, size_t *compt);
void		ft_putnbr_m(long long unsigned int n, size_t *compt, char *base);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *s, int c, size_t n);
int			ft_p(size_t n, size_t *compt, int *i);
void		ft_putnbr(int n, size_t *compt);

#endif
