/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheManifestor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:59 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/08 17:50:03 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_to_image(t_ctx *ctx, t_point point)
{
	if (point.x >= 0 && point.x < IMAGE_WIDTH && point.y >= 0 && point.y < IMAGE_HEIGHT)
	{
		*(unsigned int *)(ctx->mlx.addr + point.y * ctx->mlx.ll + point.x * (ctx->mlx.bpp / 8)) = point.color;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_max(int m, int n)
{
	if (m > n)
		return (m);
	else
		return (n);
}

int	iroundf(float x)
{
	if (x >= 0.0f)
		return ((int)(x + 0.5f));
	else
		return ((int)(x - 0.5f));
}

void	draw_line_dda(t_ctx *ctx, t_point p1, t_point p2)
{
	t_point	p;
	int		steps;
	float	x;
	float	y;
	float	x_inc;
	float	y_inc;

	steps = ft_max(ft_abs(p2.x - p1.x), ft_abs(p2.y - p1.y));
	if (steps == 0)
	{
		put_pixel_to_image(ctx, p1);
		return ;
	}
	x_inc = (float)(p2.x - p1.x) / (float)steps;
	y_inc = (float)(p2.y - p1.y) / (float)steps;
	x = (float)p1.x;
	y = (float)p1.y;
	while (steps-- + 1)
	{
		p.x = iroundf(x);
		p.y = iroundf(y);
		put_pixel_to_image(ctx, p);
		x += x_inc;
		y += y_inc;
	}
}

void	draw_grid(t_ctx *ctx)
{
	int	i;
	int	j;

	i = 0;
	while (i < ctx->height)
	{
		j = 0;
		while (j < ctx->width)
		{
			if (j + 1 < ctx->width)
				draw_line_dda(ctx, ctx->points[i][j], ctx->points[i][j + 1]);
			if (i + 1 < ctx->height)
				draw_line_dda(ctx, ctx->points[i][j], ctx->points[i + 1][j]);
			j++;
		}
		i++;
	}
}

int	ctl_keypress(int keycode, void *param)
{

}

void	TheManifestor(t_ctx *ctx)
{
	ctx->mlx.mlx = mlx_init();
	ctx->mlx.win = mlx_new_window(ctx->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	mlx_hook(ctx->mlx.win, 2, 1L<<0, ctl_keypress, ctx);
	ctx->mlx.img = mlx_new_image(ctx->mlx.mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
	ctx->mlx.addr = mlx_get_data_addr(ctx->mlx.img, &ctx->mlx.bpp, &ctx->mlx.ll, &ctx->mlx.endian);
	mlx_loop(ctx->mlx.mlx);
}

//DDAでやろう。Bresemhamでもやってみよう。
//縦棒と横棒で分けて描写するのも綺麗で効率的かも。
//使用メモリは増えるけど、x[i][j], y[i][j], z[i][j], color[i][j]みたいにする設計でも良さそう。
//頂点だけ先にアフィン変換してpointsの中身を変える。その後に、辺を描けば、濃度を調節できる。
//色は４次元で線形補間する。
//キー押されたら、pointsをアフィン転換で編集→draw_grid→put_image_to_windowをする！