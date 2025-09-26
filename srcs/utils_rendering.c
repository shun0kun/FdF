/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:54:34 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 14:56:36 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

void	update_to_from_origin(t_mat4 to_origin, t_mat4 from_origin,
	t_point pt_base_cur)
{
	const t_mat4	mat1 = {{1, 0, 0, (float)(-pt_base_cur.x)},
	{0, 1, 0, (float)(-pt_base_cur.y)},
	{0, 0, 1, (float)(-pt_base_cur.z)},
	{0, 0, 0, 1}};
	const t_mat4	mat2 = {{1, 0, 0, (float)pt_base_cur.x},
	{0, 1, 0, (float)pt_base_cur.y},
	{0, 0, 1, (float)pt_base_cur.z},
	{0, 0, 0, 1}};

	ft_memcpy(to_origin, mat1, sizeof(t_mat4));
	ft_memcpy(from_origin, mat2, sizeof(t_mat4));
}

t_render	init_render(t_grid *grid, t_mlx mlx)
{
	t_render	render;

	render.grid = *grid;
	render.mlx = mlx;
	render.proj_type = DEFAULT_PROJECTION;
	init_model(render.model, render.proj_type);
	init_transforms(&render.trs);
	return (render);
}

void	clean_up(t_render *render)
{
	if (!render)
		return ;
	destroy_points(render->grid.pts, render->grid.rows);
	destroy_points(render->grid.pts_cur, render->grid.rows);
	mlx_destroy_image(render->mlx.mlx, render->mlx.img);
	mlx_destroy_window(render->mlx.mlx, render->mlx.win);
	mlx_destroy_display(render->mlx.mlx);
	free(render->mlx.mlx);
}
