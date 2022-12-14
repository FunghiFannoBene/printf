


int        ft_strlen(char *s)
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

static  int contatore(int n)
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
char    *converter_dex_hex(int a)
{
    int    temp;
    int i;
    char    *output;

    i = 0;
    output = (char *)malloc(sizeof(char)* (contatore(a) + 1));  
    while (a > 15)
    {output[i] = '\0';
        temp = a % 16; //salvo modulo in temporanea
        a /= 16; // divido a per 16 perche' al momento in cui sara'
        //<16 il mio ciclo while dovra' terminare
        
        
        if (temp < 10)
        {
            output[i] = temp + 48;
            i++;
        }
        else if (temp < 16)
        {                        
            output[i] = temp + 55;
            i++;
        }
    }
    if (a < 16)
    {
        if (a < 10)
        {
            output[i] =  a + 48;
            i++;
        }
        else if (a < 16)
        {                        
            output[i] = a + 55;
            i++;
        }
    }
    output[i] = '\0';
  return(ft_strrev(output));
}
int main() {
  int a = 18;
  printf("%s", converter_dex_hex(a));
  return 0;
}
/*
1.100.000 /16 = 68750 1.100.000 % 16 = 0
68750 /16 = 4296
14
4296 /16 = 268
8
268/16 = 16
12
16/16 = 1
0
 

10c8e0 
0e8c01
*/
