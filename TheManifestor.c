/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheManifestor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:59 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/14 16:05:29 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ctl_keypress(int keycode, void *param)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)param;
	if (keycode == KEY_ESC)
	{
		TheAnnihilator(NULL, ctx);
	}
	else
	{
		updata_affine_matrix(ctx, keycode);
		edit_points(ctx, keycode);
		clean_image(ctx);
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