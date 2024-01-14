#include "../include/minitalk.h"

void	lbl(char *dec, char *tmp, int len, char *bin);
int	conv(char *tmp);
void	clear(char *tmp);

char	*convert_dec(char *bin)
{
	char	tmp[9];
	char	*dec;
	int		len;

	len = (ft_strlen(bin) - 8) / 8;
	dec = malloc(sizeof(char) * (len + 1));
	if (!dec)
		return (NULL);
	dec[len] = '\0';
	/*
	while (i < len)
	{
		j = 0;
		while (j < 8)
		{
			tmp[j] = bin[i + j];
			j++;
		}
		i += 8;
		tmp[8] = '\0';
		lbl(dec, tmp, len);
	}*/
	lbl(dec, tmp, len, bin);
	return (dec);
}

void	lbl(char *dec, char *tmp, int len, char *bin)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	while (i < len * 8)
	{
		j = 0;
		while (j < 8)
		{
			tmp[j] = bin[i + j];
			j++;
		}
		i += 8;
		tmp[8] = '\0';
		dec[count++] = conv(tmp);
		clear(tmp);
	}
	/*
	int	i;

	i = 0;
	while (i < len)
		dec[i++] = conv(tmp);*/
}

int	conv(char *tmp)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (tmp[i] != '1')
		i++;
	while (tmp[i])
		result = result * 2 + (tmp[i++] - '0');
	return (result);
}

void	clear(char *tmp)
{
	int		i;

	i = 0;
	while (i < 8)
		tmp[i++] = '\0';
}