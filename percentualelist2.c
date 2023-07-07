/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentualelist2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:07:56 by shhuang           #+#    #+#             */
/*   Updated: 2022/12/28 06:49:49 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%p
int	memoryprintp(void *a)
{
	uintptr_t	lunghezza;

	if (a)
	{
		ft_putchar('0');
		ft_putchar('x');
		lunghezza = convmemory((uintptr_t)a) + 2;
	}
	else
	{
		ft_putstr("(nil)");
		lunghezza = 6;
	}
	return (lunghezza);
}

int	convmemory(long int a)
{
	char				*output;
	long int			neg;
	long int			x;
	unsigned long int	value;

	value = a;
	neg = a;
	output = (char *)malloc(sizeof(char) * (contatoresedici(value) + 1));
	if (a < 0)
		a = (a * -1) - 1;
	output = creaoutput3(value, output);
	if (neg < 0 && !LONG_MIN)
	{
		x = meno2(output);
		free(output);
		if (x < 8)
			return (8);
	}
	else
	{
		ft_putstr(output);
		x = ft_strlen(output);
		free(output);
	}
	return (x);
}

char	*creaoutput3(unsigned long int a, char *output)
{
	int	temp;
	int	i;

	i = 0;
	while (a > 15)
	{
		temp = a % 16;
		a /= 16;
		if (temp < 10)
			output[i] = temp + 48;
		else if (temp < 16)
			output[i] = temp + 87;
		i++;
	}
	if (a < 10)
		output[i] = a + 48;
	else if (a < 16)
		output[i] = a + 87;
	if (output[i] != '\0')
		i++;
	output[i] = '\0';
	output = ft_strrev(output);
	return (output);
}

int	stringa(char *strvar)
{
	if (strvar)
		return (ft_putstr(strvar));
	else
		return (ft_putstr("(null)"));
}

int	ft_put_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_put_u(n / 10);
		n %= 10;
	}
	ft_putchar("0123456789"[n]);
	len += 1;
	return (len);
}
