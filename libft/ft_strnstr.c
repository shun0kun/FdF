/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:09:27 by sshimots          #+#    #+#             */
/*   Updated: 2025/05/07 20:53:03 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(const char *str, const char *little, size_t rest)
{
	size_t	i;

	i = 0;
	while (i < rest && str[i] && little[i])
	{
		if (str[i] != little[i])
			return (0);
		i++;
	}
	if (!little[i])
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[0] && ft_check(&big[i], little, len - i))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
