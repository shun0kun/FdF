/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:00:16 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 12:00:36 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

t_point	**create_points(int cols, int rows)
{
	t_point	**pts;
	int		i;

	pts = malloc(sizeof(t_point *) * rows);
	if (!pts)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		pts[i] = malloc(sizeof(t_point) * cols);
		if (!pts[i])
		{
			while (i > 0)
			{
				i--;
				free(pts[i]);
			}
			free(pts);
			return (NULL);
		}
		i++;
	}
	return (pts);
}

void	destroy_points(t_point **pts, int rows)
{
	int	i;

	if (!pts)
		return ;
	i = 0;
	while (i < rows)
	{
		free(pts[i]);
		i++;
	}
	free(pts);
}
