#include "../minitalk.h"

static int	n_len(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		if (n != -2147483648)
			count += 1;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*a;
	int			l;
	long long	nb;

	nb = n;
	l = n_len(nb);
	a = (char *)malloc(sizeof(char) * (l + 1));
	if (!a)
		return (NULL);
	a[l--] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		if (nb != -2147483648)
			a[0] = '-';
	}
	if (nb == 0)
		a[l] = 0 + '0';
	while (nb > 0)
	{
		a[l--] = nb % 10 + '0';
		nb /= 10;
	}
	return (a);
}
