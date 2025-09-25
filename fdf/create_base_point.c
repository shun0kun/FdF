/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_base_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:49:07 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 13:15:42 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

void	create_base_point(t_grid *grid)
{
	int	z_max;
	int	z_min;
	int	i;
	int	j;

	z_max = 0;
	z_min = 0;
	i = 0;
	while (i < grid->rows)
	{
		j = 0;
		while (j < grid->cols)
		{
			if (z_max > grid->pts[i][j].z)
				z_max = grid->pts[i][j].z;
			if (z_min < grid->pts[i][j].z)
				z_min = grid->pts[i][j].z;
			j++;
		}
		i++;
	}
	grid->pt_base.x = IMAGE_WIDTH / 2;
	grid->pt_base.y = IMAGE_HEIGHT / 2;
	grid->pt_base.z = (int)((z_max + z_min) * 0.5f);
	grid->pt_base.color = 0x00FF0000;
}
