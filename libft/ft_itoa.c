/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:47:56 by sshimots          #+#    #+#             */
/*   Updated: 2025/05/07 20:52:44 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calculate_pseudo_digits(int n)
{
	int	pdig;

	pdig = 0;
	if (n == INT_MIN)
		return (11);
	else if (n == 0)
		return (1);
	else if (n > 0)
	{
		while (n > 0)
		{
			n /= 10;
			pdig++;
		}
		return (pdig);
	}
	else
		return (calculate_pseudo_digits(-n) + 1);
}

char	*return_zero(char *res)
{
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*return_positive(char *res, int n, int pdig)
{
	int	i;

	i = 0;
	while (pdig - i - 1 >= 0)
	{
		res[pdig - i - 1] = '0' + (n % 10);
		n /= 10;
		i++;
	}
	res[pdig] = '\0';
	return (res);
}

char	*return_negative(char *res, int n, int pdig)
{
	int	flag;

	flag = 0;
	res[0] = '-';
	if (n == INT_MIN)
	{
		n++;
		flag = 1;
	}
	return_positive(&res[1], -n, pdig - 1);
	if (flag)
		res[pdig - 1] = '0' - (INT_MIN % 10);
	return (res);
}

char	*ft_itoa(int n)
{
	int		pdig;
	char	*res;

	pdig = calculate_pseudo_digits(n);
	res = malloc(pdig + 1);
	if (!res)
		return (NULL);
	if (n == 0)
		return (return_zero(res));
	else if (n > 0)
		return (return_positive(res, n, pdig));
	else
		return (return_negative(res, n, pdig));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *res;

// 	printf("%s\n", ft_itoa(32456));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(-6543456));
// 	printf("%s\n", ft_itoa(INT_MAX));
// 	printf("%s\n", ft_itoa(INT_MIN));
// 	return (0);
// }