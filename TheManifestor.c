/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheManifestor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:59 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/07 20:16:06 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_to_image()
{

}

void	f()
{
}

void	render_unit(t_ctx *ctx)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	color;

	i = 0;
	while (i < ctx->height)
	{
		j = 0;
		y = ctx->points[i][j].y;
		while (j < ctx->width)
		{
			x = ctx->points[i][j].x;
			while (x < ctx->points[i][j + 1].x)
			{
				if (x % GRID_DENSITY_INVERSE == 0)
				{
					put_pixel_to_image(x, y, (ctx->points[i][j + 1].z - ctx->points[i][j].z) / (ctx->points[i][j + 1].x - ctx->points[i][j].x) * (x - ctx->points[i][j].x) + ctx->points[i][j].z, color, f);
					x++;
				}
			}
			j++;
		}
		if (i < ctx->height - 1)
		{

		}
	}
}

//縦棒と横棒で分けて描写するのも綺麗で効率的かも。
//使用メモリは増えるけど、x[iy[j], [i][j], z[i][j], color[i][j]みたいにする設計でも良さそう。

int	ctl_keypress(int keycode, void *param)
{

}

void	TheManifestor(t_ctx *ctx)
{
	ctx->param.x0 = IMAGE_WIDTH / 2 - GRID_WIDTH * (ctx->width - 1);
	ctx->param.y0 = IMAGE_HEIGHT / 2 - GRID_HEIGHT * (ctx->height - 1);
	ctx->mlx.mlx = mlx_init();
	mlx_new_window(ctx->mlx.win, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	mlx_hook(ctx->mlx.win, 2, 1L<<0, ctl_keypress, ctx);
	mlx_new_image(ctx->mlx.img, IMAGE_WIDTH, IMAGE_HEIGHT);
	mlx_loop(ctx->mlx.mlx);
}
