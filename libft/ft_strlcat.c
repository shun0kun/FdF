/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:10:34 by sshimots          #+#    #+#             */
/*   Updated: 2025/05/08 14:30:28 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	len;

	len = 0;
	while (len < size && dst[len])
		len++;
	if (len == size)
		return (size + ft_strlen(src));
	j = 0;
	while (j < size - len - 1 && src[j])
	{
		dst[len + j] = src[j];
		j++;
	}
	dst[len + j] = '\0';
	return (len + ft_strlen(src));
}
