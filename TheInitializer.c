/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheInitializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:56 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/10 17:22:52 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_isometric_projection_matrix(float matrix[4][4])
{

}

void	TheInitializer(char *filename, t_ctx *ctx)
{
	ctx->filename = filename;
	ctx->fd = -1;
	ctx->width = 0;
	ctx->height = 0;
	ctx->points = NULL;
	ctx->mlx.mlx = NULL;
	ctx->mlx.win = NULL;
	ctx->mlx.img = NULL;
	initialize_isometric_projection_matrix(ctx->affine_matrix);
}
