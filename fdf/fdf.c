/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:24 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/21 12:24:14 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

void	print_points(t_grid grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid.rows)
	{
		j = 0;
		while (j < grid.cols)
		{
			printf("(%d, %d, %d, %u), ", grid.points[i][j].x, grid.points[i][j].y, grid.points[i][j].z, grid.points[i][j].color);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	fdf(const char *filename)
{
	t_grid	grid;

	if (!validate_file(filename, &grid.cols, &grid.rows))
		return (0);
	grid.points = create_points(grid.cols, grid.rows);
	if (!grid.points)
		return (0);
	if (!convert_file_to_points(filename, &grid))
	{
		destroy_points(grid.points, grid.rows);
		return (0);
	}
	create_base_point(&grid);
	print_points(grid);//debug
	start_rendering(&grid);
	return (1);
}

