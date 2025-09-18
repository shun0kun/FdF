#include "internal/fdf.h"

void	update_to_from_origin(t_mat4 to_origin, t_mat4 from_origin, t_point base_point)
{
	const t_mat4	mat1 = {{1, 0, 0, -(float)base_point.x},
							{0, 1, 0, -(float)base_point.y},
							{0, 0, 1, -(float)base_point.z},
							{0, 0, 0, 1}};
	const t_mat4	mat2 = {{1, 0, 0, (float)base_point.x},
							{0, 1, 0, (float)base_point.y},
							{0, 0, 1, (float)base_point.z},
							{0, 0, 0, 1}};

	ft_memcpy(to_origin, mat1, sizeof(mat1));
	fd_memcpy(from_origin, mat2, sizeof(mat2));
}

t_render	init_render(t_grid *grid, t_mlx mlx)
{
	t_render	render;

	render.grid = *grid;
	render.mlx = mlx;
	init_model(render.model);
	init_transforms(&render.transforms);
	return (render);
}

int	control_keypress(int keycode, void *param)
{
	t_render	*render;

	render = (t_render *)param;
	if (keycode == KEY_ESC)
	{
		destroy_points(render->grid.points, render->grid.rows);
		mlx_destroy_image(render->mlx.mlx, render->mlx.img);
		mlx_destroy_window(render->mlx.mlx, render->mlx.win);
		mlx_destroy_display(render->mlx.mlx);
		exit(0);
	}
	else
	{
		update_to_from_origin(render->transforms.to_origin, render->transforms.from_origin, render->grid.base_point);
		update_model(render->model, render->transforms, keycode);
		update_points(render->grid, render->model);
		clean_image(render->mlx);
		draw_grid(render->mlx, render->grid);
	}
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
	mlx_hook(mlx.win, 2, 1L << 0, control_keypress, &render);
	mlx_loop(mlx.mlx);
}
