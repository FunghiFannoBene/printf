/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentualelist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:59:34 by shhuang           #+#    #+#             */
/*   Updated: 2022/12/28 06:26:01 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	writedandi(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		ft_putchar('-');
		len += 1;
		n = -n;
	}
	len += ft_put_u(n);
	return (len);
}

//hex

int	converter_dex_hex(long int a)
{
	char		*output;
	long int	neg;
	long int	x;

	neg = a;
	if (a == LONG_MIN)
	{
		ft_putchar('0');
		return (1);
	}
	if (contatoresedici(a) <= 8)
		output = (char *)malloc(sizeof(char) * (contatoresedici(a) + 1));
	else
		output = (char *)malloc(sizeof(char) * 9);
	if (a < 0)
		a = (a * -1) - 1;
	output = creaoutput(a, output);
	if (neg < 0)
		x = meno(output);
	else
		return (ft_putstr(output));
	if (x < 8)
		return (8);
	else
		return (x);
}

int	converter_dex_hex2(long int a)
{
	char		*output;
	long int	neg;
	int			i;

	i = 0;
	neg = a;
	if (a == LONG_MIN)
	{
		ft_putchar('0');
		return (1);
	}
	if (contatoresedici(a) <= 8)
		output = (char *)malloc(sizeof(char) * (contatoresedici(a) + 1));
	else
		output = (char *)malloc(sizeof(char) * 9);
	if (a < 0)
		a = (a * -1) - 1;
	output = creaoutput2(a, output);
	if (neg < 0)
		meno2(output);
	else
		return (ft_putstr(output));
	return (8);
}
