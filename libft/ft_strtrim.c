/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:50:54 by sshimots          #+#    #+#             */
/*   Updated: 2025/05/08 14:31:08 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_included(char c, char	const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*return_empty_string(void)
{
	char	*p;

	p = malloc(1);
	if (!p)
		return (NULL);
	*p = '\0';
	return (p);
}

char	*return_string(char const *s1, size_t	len, size_t start, size_t end)
{
	size_t	i;
	char	*p;

	i = 0;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (start + i <= end)
	{
		p[i] = s1[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strtrim(char	const	*s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	while (s1[start] && is_included(s1[start], set))
	{
		start++;
		len--;
	}
	if (len == 0)
		return (return_empty_string());
	end = ft_strlen(s1) - 1;
	while (is_included(s1[end], set))
	{
		end--;
		len--;
	}
	return (return_string(s1, len, start, end));
}
