# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>

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
int  converter_dex_hex(int a)
{
    int    temp;
    int i;
    char    *output;
	char	*outputmeno;
	int		neg;
	neg = a;
	outputmeno = malloc(800);
    i = 0;
	if (a<0)
	{
		a *= -1;
		a -= 1;
	}
	
    output = (char *)malloc(sizeof(char)* (contatore(a) + 1));

    while (a > 15)
    {outputmeno[i] = '\0';
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
	output = ft_strrev(output);
	if(neg < 0)
	{
	i=0;
	while(output[i] != 0)
	{
		if (output[i] == '0')
		outputmeno[i] = 'F';
		else if (output[i] == '1') 
		outputmeno[i] = 'E';
		else if (output[i] == '2') 
		outputmeno[i] = 'D';
		else if (output[i] == '3') 
		outputmeno[i] = 'C';
		else if (output[i] == '4') 
		outputmeno[i] = 'B';
		else if (output[i] == '5') 
		outputmeno[i] = 'A';
		else if (output[i] == '6') 
		outputmeno[i] = '9';
		else if (output[i] == '7') 
		outputmeno[i] = '8';
		else if (output[i] == '8') 
		outputmeno[i] = '7';
		else if (output[i] == '9') 
		outputmeno[i] = '6';
		else if (output[i] == 'A') 
		outputmeno[i] = '5';
		else if (output[i] == 'B') 
		outputmeno[i] = '4';
		else if (output[i] == 'C') 
		outputmeno[i] = '3';
		else if (output[i] == 'D') 
		outputmeno[i] = '2';
		else if (output[i] == 'E') 
		outputmeno[i] = '1';
		else if (output[i] == 'F') 
		outputmeno[i] = '0';
		i++;
	}
	}
	outputmeno[i] = '\0';
  return(outputmeno);
}
int main() {
  int a = -9999999;
  printf("%s", converter_dex_hex(a));
  return 0;
}

int main() {
  char a[22222] = "ffffffgggjjgjgy";
  printf("%d", memoryprintP(a));
  return 0;
}