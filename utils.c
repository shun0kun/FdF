#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_max(int m, int n)
{
	if (m > n)
		return (m);
	else
		return (n);
}

int	iroundf(float x)
{
	if (x >= 0.0f)
		return ((int)(x + 0.5f));
	else
		return ((int)(x - 0.5f));
}