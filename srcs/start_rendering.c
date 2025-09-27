/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:21:14 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/27 13:42:31 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	switch_projection_type(t_render *render)
{
	if (render->proj_type == ISOMETRIC_PROJECTION)
	{
		render->proj_type = ORTHOGRAPHIC_PROJECTION;
		init_model(render->model, render->proj_type);
	}
	else
	{
		render->proj_type = ISOMETRIC_PROJECTION;
		init_model(render->model, render->proj_type);
	}
}

void	render_grid(t_render *render)
{
	update_current_points(render->grid, render->model);
	update_current_base_point(&render->grid, render->model);
	clean_image(render->mlx);
	draw_grid(render->mlx, render->grid);
	put_pixel_to_image(render->mlx, render->grid.pt_base_cur);
	mlx_put_image_to_window(render->mlx.mlx, render->mlx.win,
		render->mlx.img, 0, 0);
}

int	control_keypress(int keycode, void *param)
{
	t_render	*render;

	render = (t_render *)param;
	if (keycode == KEY_ESC)
	{
		clean_up(render);
		exit(0);
	}
	else if (keycode == KEY_SPACE)
	{
		switch_projection_type(render);
		render_grid(render);
	}
	else
	{
		update_to_from_origin(render->trs.to_origin, render->trs.from_origin,
			render->grid.pt_base_cur);
		update_model(render->model, render->trs, keycode);
		render_grid(render);
	}
	return (0);
}

int	destroy_notify(void *param)
{
	t_render	*render;

	render = (t_render *)param;
	clean_up(render);
	exit(0);
}

void	start_rendering(t_grid *grid)
{
	t_mlx		mlx;
	t_render	render;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	mlx.img = mlx_new_image(mlx.mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.ll, &mlx.endian);
	render = init_render(grid, mlx);
	render.grid.pts_cur = create_points(render.grid.cols, render.grid.rows);
	mlx_hook(mlx.win, 2, 1L << 0, control_keypress, &render);
	mlx_hook(mlx.win, 17, 0, destroy_notify, &render);
	render_grid(&render);
	mlx_loop(mlx.mlx);
}
