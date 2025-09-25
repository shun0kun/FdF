/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_current_points.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:43:46 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 12:43:46 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

void	mat4_mul_vec4(t_mat4 model, float vec[4][1])
{
	int		i;
	int		j;
	float	new_vec[4][1];

	new_vec[0][0] = 0;
	new_vec[1][0] = 0;
	new_vec[2][0] = 0;
	new_vec[3][0] = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			new_vec[i][0] += model[i][j] * vec[j][0];
			j++;
		}
		i++;
	}
	vec[0][0] = new_vec[0][0];
	vec[1][0] = new_vec[1][0];
	vec[2][0] = new_vec[2][0];
	vec[3][0] = new_vec[3][0];
}

t_point	update_current_point(t_point point, t_mat4 model)
{
	t_point	res;
	float	vec4[4][1];

	vec4[0][0] = point.x;
	vec4[1][0] = point.y;
	vec4[2][0] = point.z;
	vec4[3][0] = 1;
	mat4_mul_vec4(model, vec4);
	res.x = vec4[0][0];
	res.y = vec4[1][0];
	res.z = vec4[2][0];
	res.color = point.color;
	return (res);
}

void	update_current_points(t_grid grid, t_mat4 model)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid.rows)
	{
		j = 0;
		while (j < grid.cols)
		{
			grid.pts_cur[i][j] = update_current_point(grid.pts[i][j], model);
			j++;
		}
		i++;
	}
}

void	update_current_base_point(t_grid *grid, t_mat4 model)
{
	grid->pt_base_cur = update_current_point(grid->pt_base, model);
}
