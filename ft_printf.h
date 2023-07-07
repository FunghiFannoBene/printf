/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:17:27 by shhuang           #+#    #+#             */
/*   Updated: 2022/12/28 06:17:31 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int			ft_printf(const char *s, ...);
int			checkb(va_list percent, const char type);

int			converter_dex_hex(long int a);
int			converter_dex_hex2(long int a);
char		*creaoutput(long int a, char *output);
char		*creaoutput2(unsigned long int a, char *output);
int			meno(char *output);
int			meno2(char *output);
int			contatoresedici(unsigned long int n);
char		*creaoutput3(unsigned long int a, char *output);

int			ft_putstr(char *str);
char		*ft_strrev(char *str);
long int	contatore(long int n);
char		*ft_itoa(long int n);
int			ft_strlen(char *s);
void		ft_putchar(char c);

int			caratteri(int c);
int			memoryprintp(void *a);
int			stringa(char *strvar);
int			ft_put_u(unsigned int n);
int			writedandi(int n);
int			ft_putpercent(char c);
int			convmemory(long int a);

#endif