/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:41:02 by sshimots          #+#    #+#             */
/*   Updated: 2025/05/23 09:33:50 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

bool	has_line_break(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (true);
		s++;
	}
	return (false);
}

char	*free_and_return_null(char **p1, char **p2)
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

// if (stash != s) /*これがあったらメモリリーク、これがなかったらダブルフリーしてる。*/

// char	*free_and_return_null(char **p1, char **p2)
// {
// 	if (*p1)
// 	{
// 		free(*p1);
// 		*p1 = NULL;
// 	}
// 	if (*p2)
// 	{
// 		free(*p2);
// 		free(*p2);
// 	}
// 	return (NULL);
// }