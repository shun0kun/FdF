#include "header.h"

void	edit_param(int keycode, t_param *param)
{
	switch (keycode)
	{
		case KEY_UP:
			param->Ty -= 5;
			break ;
		case KEY_DOWN:
			param->Ty += 5;
			break ;
		case KEY_LEFT:
			param->Tx -= 5;
			break ;
		case KEY_RIGHT:
			param->Tx += 5;
			break ;
		case KEY_D:
			param->theta_x += M_PI / 90;
			break ;
		case KEY_F:
			param->theta_x -= M_PI / 90;
			break ;
		case KEY_A:
			param->theta_y += M_PI / 90;
			break ;
		case KEY_S:
			param->theta_y -= M_PI / 90;
			break ;
		case KEY_W:
			param->theta_z += M_PI / 90;
			break ;
		case KEY_E:
			param->theta_z -= M_PI / 90;
			break ;
		case KEY_PLUS:
			param->S += 0.05;
			break ;
		case KEY_MINUS:
			param->S -= 0.05;
			break ;
	}
}

int	ctl_keypress(int keycode, void *param)
{
	t_ctx	ctx;

	ctx = *(t_ctx *)param;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(ctx.mlx, ctx.img);
		mlx_destroy_window(ctx.mlx, ctx.win);
		exit(0);
	}
	else if (keycode == KEY_SPACE)
	{
		init_param(&((t_ctx *)param)->param);
		clear_image(ctx);
		create_object(ctx);
		mlx_put_image_to_window(ctx.mlx, ctx.win, ctx.img, 0, 0);
	}
	else
	{
		edit_param(keycode, &((t_ctx *)param)->param);
		clear_image(ctx);
		create_object(ctx);
		mlx_put_image_to_window(ctx.mlx, ctx.win, ctx.img, 0, 0);
	}
	return (0);
}

// if (keycode == KEY_ENTER)
// {
// 	clear_image(ctx);
// 	create_object(ctx, NUTRAL);
// 	mlx_put_image_to_window(ctx.mlx, ctx.win, ctx.img, 0, 0);
// }
// if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_RIGHT)
// {
// 	clear_image(ctx);
// 	create_object(ctx, TRANSLATE);
// 	mlx_put_image_to_window(ctx.mlx, ctx.win, ctx.img, 0, 0);
// }
// if (keycode == KEY_D || keycode == KEY_F || keycode == KEY_A || keycode == KEY_S || keycode == KEY_W || keycode == KEY_E )
// {
// 	clear_image(ctx);
// 	create_object(ctx, ROTATE);
// 	mlx_put_image_to_window(ctx.mlx, ctx.win, ctx.img, 0, 0);
// }
// if (keycode == KEY_PLUS || keycode == KEY_MINUS)
// {
// 	clear_image(ctx);
// 	create_object(ctx, SCALE);
// 	mlx_put_image_to_window(ctx.mlx, ctx.win, ctx.img, 0, 0);
// }