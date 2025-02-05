#include "../libft.h"

void	string(va_list arg, int *pcount)
{
	char	*tmp;

	tmp = va_arg(arg, char *);
	if (!tmp)
		tmp = "(null)";
	ft_putstr_fd(tmp, 1);
	*pcount += ft_strlen(tmp);
}

void	pointer(va_list arg, int *pcount)
{
	unsigned long long	p;

	p = va_arg(arg, unsigned long long);
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(p, "0123456789abcdef", pcount);
	*pcount += 2;
}

void	integer(va_list arg, int *pcount)
{
	int	i;

	i = va_arg(arg, int);
	ft_putnbr_fd(i, 1);
	*pcount += countdigits(i);
}

void	unsigned_int(va_list arg, int *pcount)
{
	unsigned int	u;

	u = va_arg(arg, unsigned int);
	ft_putnbr_fd(u, 1);
	*pcount += countdigits(u);
}

void	hexadecimal(va_list arg, int *pcount, char c)
{
	unsigned int	x;

	x = va_arg(arg, unsigned int);
	if (c == 'x')
		ft_putnbr_base(x, "0123456789abcdef", pcount);
	else
		ft_putnbr_base(x, "0123456789ABCDEF", pcount);
}
