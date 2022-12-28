/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsprintf2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:08:52 by shhuang           #+#    #+#             */
/*   Updated: 2022/12/28 06:48:12 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	meno(char *output)
{
	int	result;
	int	fdamettere;
	int	i;

	i = 0;
	if (ft_strlen(output) < 8)
		fdamettere = 8 - ft_strlen(output);
	else
		fdamettere = 0;
	while (fdamettere-- > 0)
		ft_putchar('F');
	while (output[i])
	{
		if (output[i] >= 48 && output[i] <= 53)
			ft_putchar(70 - (output[i] - 48));
		else if (output[i] >= 54 && output[i] <= 70)
		{
			result = 57 - (output[i] - 54);
			if (output[i] >= 65)
				result += 7;
			ft_putchar(result);
		}
		i++;
	}
	return (i);
}

char	*creaoutput(long int a, char *output)
{
	int	temp;
	int	i;

	i = 0;
	while (a > 15 && i < 8)
	{
		temp = a % 16;
		a /= 16;
		if (temp < 10)
			output[i] = temp + 48;
		else if (temp < 16)
			output[i] = temp + 55;
		i++;
	}
	if (a < 10)
		output[i] = a + 48;
	else if (a < 16)
		output[i] = a + 55;
	if (output[i] != '\0')
		i++;
	output = ft_strrev(output);
	return (output);
}

int	meno2(char *output)
{
	int	result;
	int	fdamettere;
	int	i;

	i = 0;
	if (ft_strlen(output) < 8)
		fdamettere = 8 - ft_strlen(output);
	else
		fdamettere = 0;
	while (fdamettere-- > 0)
		ft_putchar('f');
	while (output[i])
	{
		if (output[i] >= 48 && output[i] <= 53)
			ft_putchar(102 - (output[i] - 48));
		else if (output[i] >= 54 && output[i] <= 102)
		{
			result = 57 - (output[i] - 54);
			if (output[i] >= 97)
				result += 39;
			ft_putchar(result);
		}
		i++;
	}
	return (i);
}

char	*creaoutput2(unsigned long int a, char *output)
{
	int	temp;
	int	i;

	i = 0;
	while (a > 15 && i < 8)
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

int	contatoresedici(unsigned long int n)
{
	unsigned long int	digits;

	digits = 0;
	if (n > 0)
	{
		while (n > 0)
		{
			n /= 16;
			digits++;
		}
	}
	else if (n == 0)
		digits = 1;
	return (digits);
}
