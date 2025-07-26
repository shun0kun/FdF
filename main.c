#include "header.h"

void	init_param(t_param *param)
{
	param->Tx = 0;
	param->Ty = 0;
	param->S = 1;
	param->theta_x = 0;
	param->theta_y = 0;
	param->theta_z = 0;
}

int	main(void)
{
	t_ctx	ctx;

	ctx.mlx = mlx_init();
	ctx.win = mlx_new_window(ctx.mlx, 960, 540, "Field");
	mlx_hook(ctx.win, 2, 1L<<0, ctl_keypress, &ctx);
	ctx.img = mlx_new_image(ctx.mlx, 960, 540);
	ctx.addr = mlx_get_data_addr(ctx.img, &ctx.bpp, &ctx.ll, &ctx.endian);
	init_param(&ctx.param);
	mlx_loop(ctx.mlx);
}

// int	ctl_keypress(int keycode, void *param)
// {
// 	printf("%d\n", keycode);
// 	return (0);
// }

// int	main(void)
// {
// 	t_ctx	ctx;

// 	ctx.mlx = mlx_init();
// 	ctx.win = mlx_new_window(ctx.mlx, 960, 540, "Field");
// 	mlx_hook(ctx.win, 2, 1L<<0, ctl_keypress, &ctx);
// 	ctx.img = mlx_new_image(ctx.mlx, 960, 540);
// 	ctx.addr = mlx_get_data_addr(ctx.img, &ctx.bpp, &ctx.ll, &ctx.endian);
// 	// init_param(&ctx.param);
// 	mlx_loop(ctx.mlx);
// }
