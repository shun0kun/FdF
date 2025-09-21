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

	ft_memcpy(to_origin, mat1, sizeof(t_mat4));
	ft_memcpy(from_origin, mat2, sizeof(t_mat4));
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
		destroy_points(render->grid.current_points, render->grid.rows);
		mlx_destroy_image(render->mlx.mlx, render->mlx.img);
		mlx_destroy_window(render->mlx.mlx, render->mlx.win);
		mlx_destroy_display(render->mlx.mlx);
		exit(0);
	}	
	else
	{
		update_to_from_origin(render->transforms.to_origin, render->transforms.from_origin, render->grid.current_base_point);
		update_model(render->model, render->transforms, keycode);
		update_current_points(render->grid, render->model);
		update_current_base_point(&render->grid, render->model);
		clean_image(render->mlx);
		draw_grid(render->mlx, render->grid);
		put_pixel_to_image(render->mlx, render->grid.current_base_point);
		mlx_put_image_to_window(render->mlx.mlx, render->mlx.win, render->mlx.img, 0, 0);
	}
	return (1);//返すの1でいいの？
}

void	print_model(t_render render)
{
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%f, ", render.model[i][j]);
			j++;
		}
		printf("\n");
		i++;
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
	render.grid.current_points = create_points(render.grid.cols, render.grid.rows);
	mlx_hook(mlx.win, 2, 1L << 0, control_keypress, &render);
	print_model(render);
	update_current_points(render.grid, render.model);
	update_current_base_point(&render.grid, render.model);
	draw_grid(render.mlx, render.grid);	
	put_pixel_to_image(render.mlx, render.grid.current_base_point);
	mlx_put_image_to_window(render.mlx.mlx, render.mlx.win, render.mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}
