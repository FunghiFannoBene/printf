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

	neg = a;
	if (contatoresedici(a) <= 8)
		output = (char *)malloc(sizeof(char) * (contatoresedici(a) + 1));
	else
		output = (char *)malloc(sizeof(char) * 9);
	if (a < 0)
		a = (a * -1) - 1;
	output = creaoutput(a, output);
	if (neg < 0)
		meno(output);
	else
	{
		ft_putstr(output);
		neg = ft_strlen(output);
		free(output);
		return (neg);
	}
	free(output);
	return (8);
}

int	converter_dex_hex2(long int a)
{
	char		*output;
	long int	neg;

	neg = a;
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
	{
		ft_putstr(output);
		neg = ft_strlen(output);
		free(output);
		return (neg);
	}
	free(output);
	return (8);
}
