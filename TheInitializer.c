/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheInitializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:56 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/08 18:52:41 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
}
