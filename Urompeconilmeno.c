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

int printUnsigned(int a)
{
    char *result;
    unsigned long b;
    if(a > 0 && a <= 9)
    {
        result = a+48;
    }
    else if (a >= 10)
    {
        result = ft_itoa(a);
    }
    else if(a < 0)
    {
        b = 4294967296+a;
        result = ft_itoa(b);
    }
    return(result);
}