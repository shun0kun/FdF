/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:24 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 11:58:11 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

int	fdf(const char *filename)
{
	t_grid	grid;

	if (!validate_file(filename, &grid.cols, &grid.rows))
		return (0);
	grid.pts = create_points(grid.cols, grid.rows);
	if (!grid.pts)
		return (0);
	if (!convert_file_to_points(filename, &grid))
	{
		destroy_points(grid.pts, grid.rows);
		return (0);
	}
	create_base_point(&grid);
	start_rendering(&grid);
	return (1);
}
