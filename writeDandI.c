# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>


void    ft_putchar(char c) {
    write(1, &c, 1);
}

int contatore(int n)
{
    int    i;

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

char    *ft_itoa(int n)
{
    size_t    ndigit;
    char    *stringa;
    long    nconv;

    ndigit = contatore(n);
    nconv = n;
    stringa = (char *)malloc(sizeof(char) * ndigit + 1);
    if (stringa == NULL)
        return (NULL);
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

int writeDandI(int numeri)
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
}

int main()
{
int i = 1000;
printf("%d", writeDandI(i));
}