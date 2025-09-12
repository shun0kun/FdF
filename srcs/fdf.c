/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimotsukasashunsuke <shimotsukasashuns    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:24 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/11 12:22:00 by shimotsukas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

t_point	**create_points(int cols, int rows)
{
	t_point	**points;
	int	i;

	points = malloc(sizeof(t_point *) * rows);
	if (!points)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		points[i] = malloc(sizeof(t_point) * cols);
		if (!points[i])
		{
			while (i > 0)
			{
				i--;
				free(points[i]);
			}
			free(points);
			return (NULL);
		}
		i++;
	}
	return (points);
}

void	destroy_points(t_point **points, int rows)
{
	int	i;

	if (!points)
		return ;
	i = 0;
	while (i < rows)
	{
		free(points[i])
		i++;
	}
	free(points);
}

int	fdf(char *filename)
{
	t_grid	grid;

	if (!validate_file(filename, &grid.cols, &grid.rows))
		return (0);
	grid.points = create_points(grid.cols, grid.rows);
	if (!grid.points)
		return (0);
	if (!convert_file_to_points(filename, grid))
	{
		destroy_points(grid.points, grid.rows);
		return (0);
	}
	start_rendering(&grid);
}

