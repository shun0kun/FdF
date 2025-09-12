#include "internal/fdf.h"

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
		update_model(render->model, render->transforms);
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
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp. &mlx.ll, &mlx.endian);
	render = init_render(grid, mlx);
	mlx_hook(mlx.win, 2, 1L << 0, control_keypress, &render);
	mlx_loop(mlx.mlx);
}

mlx_destroy_image(ctx->mlx.mlx, ctx->mlx.img);
mlx_destroy_window(ctx->mlx.mlx, ctx->mlx.win);
mlx_destroy_display(ctx->mlx.mlx);