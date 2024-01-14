#include "../include/minitalk.h"

int	up(int n, int pow)
{
	int	x;
	int	i;

	if (pow <= 0)
		return (1);
	x = n;
	i = 1;
	while (i++ < pow)
		n *= x;
	return (n);
}
