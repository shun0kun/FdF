/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:42:08 by sshimots          #+#    #+#             */
/*   Updated: 2025/05/07 22:00:25 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	investigate(char	const *s, char c, size_t *start, size_t *end)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start[j] = i;
			while (s[i] && s[i] != c)
				i++;
			end[j] = i - 1;
			j++;
		}
	}
	start[j] = -1;
	end[j] = -1;
}

void	ft_free(char **res, size_t i)
{
	while (i > 0)
	{
		i--;
		free(res[i]);
	}
	free(res);
}

char	**make_result_1(size_t *start, size_t *end)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	**res;

	i = 0;
	j = 0;
	count = 0;
	while (start[count] != (size_t)-1)
		count++;
	res = malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < count)
	{
		res[i] = malloc((end[i] - start[i] + 2) * sizeof(char));
		if (!res[i])
		{
			ft_free(res, i);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**make_result_2(char **res, char const *s, size_t *start, size_t *end)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (start[count] != (size_t)-1)
		count++;
	while (i < count)
	{
		j = 0;
		while (start[i] + j <= end[i])
		{
			res[i][j] = s[start[i] + j];
			j++;
		}
		res[i][j] = '\0';
		i++;
	}
	return (res);
}

char	**ft_split(char	const *s, char c)
{
	size_t	*start;
	size_t	*end;
	char	**res;

	start = malloc((ft_strlen(s) / 2 + 2) * sizeof(size_t));
	end = malloc((ft_strlen(s) / 2 + 2) * sizeof(size_t));
	if (!start || !end)
	{
		free(start);
		free(end);
		return (NULL);
	}
	investigate(s, c, start, end);
	res = make_result_1(start, end);
	if (!res)
	{
		free(start);
		free(end);
		return (NULL);
	}
	res = make_result_2(res, s, start, end);
	free(start);
	free(end);
	return (res);
}
