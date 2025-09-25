/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:54:07 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 12:55:19 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

void	update_point(t_point *pt, t_mat4 model)
{
	float	vec[4][1];

	vec[0][0] = pt->x;
	vec[1][0] = pt->y;
	vec[2][0] = pt->z;
	vec[3][0] = 1;
	mat4_mul_vec4(model, vec);
	pt->x = vec[0][0];
	pt->y = vec[1][0];
	pt->z = vec[2][0];
}

void	update_points(t_grid grid, t_mat4 model)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid.rows)
	{
		j = 0;
		while (j < grid.cols)
		{
			update_point(&grid.pts[i][j], model);
			j++;
		}
		i++;
	}
}

void	update_base_point(t_point *pt_base, t_mat4 model)
{
	update_point(pt_base, model);
}
