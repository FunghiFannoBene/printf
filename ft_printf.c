/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:22:11 by shhuang           #+#    #+#             */
/*   Updated: 2022/12/28 06:50:09 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putpercent(char c)
{
	write(1, &c, 1);
	return (1);
}

int	caratteri(int c)
{
	ft_putchar(c);
	return (1);
}

int	checkb(va_list percent, const char type)
{
	size_t	x;

	x = 1;
	if (type == 'c')
		x = caratteri(va_arg(percent, int));
	else if (type == 's')
		x = stringa(va_arg(percent, char *));
	else if (type == 'p')
		x = memoryprintp(va_arg(percent, void *));
	else if (type == 'd' || type == 'i')
		x = writedandi(va_arg(percent, int));
	else if (type == 'u')
		x = ft_put_u(va_arg(percent, int));
	else if (type == 'x')
		x = converter_dex_hex2(va_arg(percent, int));
	else if (type == 'X')
		x = converter_dex_hex(va_arg(percent, int));
	else if (type == '%')
		x = ft_putpercent('%');
	return (x);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	char	*str;
	va_list	percent;

	str = (char *)s;
	i = 0;
	va_start(percent, s);
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			i++;
		}
		else
		{
			i += checkb(percent, str[1]);
			str++;
		}
		str++;
	}
	va_end(percent);
	return (i);
}
