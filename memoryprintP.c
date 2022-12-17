int memoryprintP(void* a)
{
	int lunghezza;
	if(ft_isnum(a))
	{
		ft_putchar('0');
		ft_putchar('x');
		lunghezza = converter_dex_hex(a) + 2;
	}
	else if(ft_isstr(a))
	{

	}
}