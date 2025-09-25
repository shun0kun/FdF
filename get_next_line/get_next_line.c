/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:05:32 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 13:37:34 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*if_has_nl_get_line(char **p_stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	while ((*p_stash)[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (free1_and_return_null(p_stash));
	i = 0;
	while ((*p_stash)[i++] != '\n')
		line[i - 1] = (*p_stash)[i - 1];
	line[--i] = '\n';
	line[++i] = '\0';
	while ((*p_stash)[i + j])
	{
		(*p_stash)[j] = (*p_stash)[i + j];
		j++;
	}
	(*p_stash)[j] = '\0';
	return (line);
}

char	*get_last_line(char **p_stash)
{
	char	*last_line;

	last_line = *p_stash;
	*p_stash = NULL;
	return (last_line);
}

char	*buf_join(char **p_stash, char **p_buf)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	if (!*p_stash)
		return (*p_buf);
	new_stash = malloc(gnl_strlen(*p_stash) + gnl_strlen(*p_buf) + 1);
	if (!new_stash)
		return (free2_and_return_null(p_stash, p_buf));
	i = 0;
	j = 0;
	while ((*p_stash)[i])
	{
		new_stash[i] = (*p_stash)[i];
		i++;
	}
	while ((*p_buf)[j])
	{
		new_stash[i + j] = (*p_buf)[j];
		j++;
	}
	new_stash[i + j] = '\0';
	free2_and_return_null(p_stash, p_buf);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	ssize_t		size;

	if (stash && has_nl(stash))
		return (if_has_nl_get_line(&stash));
	while (1)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (free2_and_return_null(&stash, &buf));
		size = read(fd, buf, BUFFER_SIZE);
		if ((size == 0 && (!stash || gnl_strlen(stash) == 0)) || size == -1)
			return (free2_and_return_null(&stash, &buf));
		buf[size] = '\0';
		stash = buf_join(&stash, &buf);
		if (!stash)
			return (NULL);
		if (has_nl(stash))
			return (if_has_nl_get_line(&stash));
		else if (size != BUFFER_SIZE)
			return (get_last_line(&stash));
	}
}
