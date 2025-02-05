#include "../libft.h"

int	countdigits(int n)
{
	int		count;
	long	num;

	count = 1;
	num = n;
	if (num < 0)
		num = -num;
	while (num >= 10)
	{
		num /= 10;
		count++;
	}
	return (count);
}

void	ft_putnbr_base(int n, const char *base, int *pcount)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n < base_len)
	{
		ft_putchar_fd(base[n], 1);
		*pcount += 1;
	}
	else
	{
		ft_putnbr_base(n / base_len, base, pcount);
		ft_putnbr_base(n % base_len, base, pcount);
	}
}
