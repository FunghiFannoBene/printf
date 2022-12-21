# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>

int  converter_dex_hex(int a);
void    	ft_putchar(char c);
void meno(char *output);
char *creaoutput(int a, char *output);

//libreria
int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}

long int contatore(long int n)
{
    long int   i;

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

int contatoresedici(int n)
{
    int digits;

    digits = 0;
    if (n > 0)
    {
        while (n > 0)
        {
          n /= 16;
        digits++;
        }
    }
    else if (n < 0) 
    {
        digits = 1;
        while (n < 0)
        {
            n /= 16;
            digits++;
        }
    }
    else if (n == 0)
    {
        digits = 1;
    }
    return (digits);
}

char    *ft_itoa(long int n)
{
    long int    ndigit;
    char    *stringa;
    long    nconv;

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

void    ft_putchar(char c) {
    write(1, &c, 1);
}

int       ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char *ft_strrev(char *str)
{
    char tmp;
    int i;
    int j;

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

//caratteri %c
int caratteri(char c)
{
ft_putchar(c);
return(1);
}

//%p
int memoryprintP(void* a)
{
	unsigned long b;
	b = (unsigned long)a;
	int lunghezza;
	ft_putchar('0');
	ft_putchar('x');
	lunghezza = converter_dex_hex(b) + 2;
	return(lunghezza);
}

//%%
int percent(char c)
{
	ft_putchar(c);
	return(1);
}

//%s
int stringa(char *strvar)
{
	return(ft_putstr(strvar));
}

//%u

int printUnsigned(int a)
{
    char *result;
    unsigned long b;
    if(a > 0 && a <= 9)
    {
        *result = a + 48;
    }
    else if (a >= 10)
    {
        result = ft_itoa(a);
    }
    else if(a < 0)
    {
        b = 4294967296 + a;
        result = ft_itoa(b);
    }
	return(ft_putstr(result));
}

//%d %i
long int writeDandI(int numeri)
{
    char *a;
    size_t i;
    
    i = 0;
    int ogni10numeri;
    a = malloc(contatore(numeri)+1);
    
    if(numeri > 9)
    {
    a = ft_itoa(numeri);
    ogni10numeri = contatore(numeri);
    while(ogni10numeri-- >= 0)
    {
        ft_putchar(a[i]);
        i++;
    }
    i=i-1;
    }
    else
    {
    a[i] = numeri + 48;
    a[1] = '\0';
    ft_putchar(a[i]);
    i++;
    }
    return(ft_strlen(a));
}

//hex

int  converter_dex_hex(int a)
{
    char    *output;
	int		neg;

	neg = a;
	output = (char *)malloc(sizeof(char)* (contatoresedici(a) + 1));
	if (a < 0)
	a = (a * -1) - 1;
    creaoutput(a, output);
	if(neg < 0)
		meno(output);
    else
        return(ft_putstr(output));
    return(8);
}


void meno(char *output)
{
    int result;
    int FDaMettere;
    int i;
    i=0;
    FDaMettere = 8-ft_strlen(output);
    while(FDaMettere > 0)
    {
        ft_putchar('F');
        FDaMettere--;
    }
	while(output[i] != 0)
	{
        if(output[i] >= 48 && output[i] <= 53)
        {
            result = output[i] - 48;
            ft_putchar(70-result);
        }
        else if (output[i] >= 54 && output[i]<= 70)
        {
            result =  57 - (output[i] - 54);
            if(output[i] >= 65)
            result +=7;
            ft_putchar(result);
        }
        i++;
	}
}

char *creaoutput(int a, char *output)
{
	int temp;
	int i;
	i=0;
	while (a > 15)
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
        output[i] =  a + 48;
    else if (a < 16)                     
        output[i] = a + 55;
	output[++i] = '\0';
	output = ft_strrev(output);
	return(output);
}


int  converter_dex_hex2(int a)
{
    char    *output;
	int		neg;

	neg = a;
	output = (char *)malloc(sizeof(char)* (contatoresedici(a) + 1));
	if (a < 0)
	a = (a * -1) - 1;
    creaoutput2(a, output);
	if(neg < 0)
		meno2(output);
    else
        return(ft_putstr(output));
    return(8);
}


void meno2(char *output)
{
    int result;
    int FDaMettere;
    int i;
    i=0;
    FDaMettere = 8-ft_strlen(output);
    while(FDaMettere > 0)
    {
        ft_putchar('f');
        FDaMettere--;
    }
	while(output[i] != 0)
	{
        if(output[i] >= 48 && output[i] <= 53)
        {
            result = output[i] - 48;
            ft_putchar(102-result);
        }
        else if (output[i] >= 54 && output[i]<= 102)
        {
            result =  57 - (output[i] - 54);
            if(output[i] >= 97)// siamo arrivati qui
            result +=39;
            ft_putchar(result);
        }
        i++;
	}
}
// siamo arrivati qui

char *creaoutput2(int a, char *output)
{
	int temp;
	int i;
	i=0;
	while (a > 15)
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
        output[i] =  a + 48;
    else if (a < 16)                     
        output[i] = a + 55;
	output[++i] = '\0';
	output = ft_strrev(output);
	return(output);
}

int main() {
  int a = -1100000;
  printf("%d", converter_dex_hex(a));
  return 0;
}