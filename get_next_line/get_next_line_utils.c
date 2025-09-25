/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:05:37 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 13:36:48 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*free1_and_return_null(char **p)
{
	if (*p)
		free(*p);
	*p = NULL;
	return (NULL);
}

char	*free2_and_return_null(char **p1, char **p2)
{
	if (*p1)
	{
		free(*p1);
		*p1 = NULL;
	}
	if (*p2)
	{
		free(*p2);
		*p2 = NULL;
	}
	return (NULL);
}

bool	has_nl(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (true);
		s++;
	}
	return (false);
}
