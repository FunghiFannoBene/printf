/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsprintf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:58:09 by shhuang           #+#    #+#             */
/*   Updated: 2022/12/28 06:18:14 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

long int	contatore(long int n)
{
	long int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long int n)
{
	long int	ndigit;
	char		*stringa;
	long		nconv;

	ndigit = contatore(n);
	nconv = n;
	stringa = (char *)malloc(sizeof(char) * ndigit + 1);
	if (stringa == 0)
		return (0);
	if (nconv < 0)
	{
		stringa[0] = '-';
		nconv = -nconv;
	}
	if (nconv == 0)
		stringa[0] = '0';
	stringa[ndigit--] = '\0';
	while (nconv)
	{
		stringa[ndigit] = nconv % 10 + '0';
		ndigit--;
		nconv = nconv / 10;
	}
	return (stringa);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		j--;
		i++;
	}
	return (str);
}
