/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheManifestor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:59 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/10 17:22:51 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_to_image(t_ctx *ctx, t_point point)
{
	if (point.x >= 0 && point.x < IMAGE_WIDTH && point.y >= 0
		&& point.y < IMAGE_HEIGHT)
	{
		*(unsigned int *)(ctx->mlx.addr + point.y * ctx->mlx.ll + point.x
				* (ctx->mlx.bpp / 8)) = point.color;
	}
}

void	initiate_dda_param(t_dda *dda, t_point p1, t_point p2)
{
	int	dx;
	int	dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	dda->steps = ft_max(ft_abs(dx), ft_abs(dy));
	if (dda->steps == 0)
		return ;
	dda->x = (float)p1.x;
	dda->y = (float)p1.y;
	dda->a = (float)((p1.color >> 24) & 0xFF);
	dda->r = (float)((p1.color >> 16) & 0xFF);
	dda->g = (float)((p1.color >> 8) & 0xFF);
	dda->b = (float)((p1.color) & 0xFF);
	dda->x_inc = dx / (float)dda->steps;
	dda->y_inc = dy / (float)dda->steps;
	dda->a_inc = (((p2.color >> 24) & 0xFF) - dda->a) / (float)dda->steps;
	dda->r_inc = (((p2.color >> 16) & 0xFF) - dda->r) / (float)dda->steps;
	dda->g_inc = (((p2.color >> 8) & 0xFF) - dda->g) / (float)dda->steps;
	dda->b_inc = (((p2.color) & 0xFF) - dda->b) / (float)dda->steps;
}

t_point	construct_pixel(t_dda dda)
{
	t_point	p;

	p.x = (int)lroundf(dda.x);
	p.y = (int)lroundf(dda.y);
	p.color = ((unsigned int)lroundf(dda.a) << 24) | ((unsigned int)lroundf(dda.r) << 16) | ((unsigned int)lroundf(dda.g) << 8) | (unsigned int)lroundf(dda.b);
	return (p);
}

void	draw_line_dda(t_ctx *ctx, t_point p1, t_point p2)
{
	t_point	p;
	t_dda	dda;
	int		i;

	initiate_dda_param(&dda, p1, p2);
	if (dda.steps == 0)
	{
		put_pixel_to_image(ctx, p1);
		return ;
	}
	i = 0;
	while (i <= dda.steps)
	{
		p = construct_pixel(dda);
		put_pixel_to_image(ctx, p);
		dda.x += dda.x_inc;
		dda.y += dda.y_inc;
		dda.a += dda.a_inc;
		dda.r += dda.r_inc;
		dda.g += dda.g_inc;
		dda.b += dda.b_inc;
		i++;
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

void	edit_points(t_ctx *ctx, int keycode)
{

}

int	ctl_keypress(int keycode, void *param)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)param;
	if (keycode == KEY_ENTER)
	{
		edit_points(ctx, );
		draw_grid(ctx);
		mlx_put_image_to_window(ctx->mlx.mlx, ctx->mlx.win, ctx->mlx.img, 0, 0);
	}
	if (keycode == KEY_ARROW_UP)
	{
		edit_points(ctx, keycode);
		draw_grid(ctx);
		mlx_put_image_to_window(ctx->mlx.mlx, ctx->mlx.win, ctx->mlx.img, 0, 0);
	}
}

void	TheManifestor(t_ctx *ctx)
{
	ctx->mlx.mlx = mlx_init();
	ctx->mlx.win = mlx_new_window(ctx->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"FdF");
	mlx_hook(ctx->mlx.win, 2, 1L << 0, ctl_keypress, ctx);
	ctx->mlx.img = mlx_new_image(ctx->mlx.mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
	ctx->mlx.addr = mlx_get_data_addr(ctx->mlx.img, &ctx->mlx.bpp, &ctx->mlx.ll,
			&ctx->mlx.endian);
	mlx_loop(ctx->mlx.mlx);
}

// DDAでやろう。Bresemhamでもやってみよう。
//縦棒と横棒で分けて描写するのも綺麗で効率的かも。
//使用メモリは増えるけど、x[i][j], y[i][j], z[i][j], color[i][j]みたいにする設計でも良さそう。
//頂点だけ先にアフィン変換してpointsの中身を変える。その後に、辺を描けば、濃度を調節できる。
//色は４次元で線形補間する。
//キー押されたら、pointsをアフィン転換で編集→draw_grid→put_image_to_windowをする！
//安全のためにclampいれてもいいかも！
//エンディアンを考慮して色を抽出する必要がある。週出自と再構成時は逆順でいれる。
//必要ならラッパ関数を作っても良い