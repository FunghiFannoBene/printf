int memoryprintP(void* a)
{
	unsigned long b;
	b = (unsigned long)a;
	int lunghezza;
	ft_putchar('0');
	ft_putchar('x');
	lunghezza = converter_dex_hex(a) + 2;
	return(lunghezza);
}