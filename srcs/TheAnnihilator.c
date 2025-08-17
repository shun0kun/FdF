/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheAnnihilator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimotsukasashunsuke <shimotsukasashuns    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:43 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/17 16:17:01 by shimotsukas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

void	free_points(t_ctx *ctx)
{
	int	i;

	i = 0;
	if (ctx->points == NULL)
		return ;
	else
	{
		while (ctx->points[i])
		{
			free(ctx->points[i]);
			i++;
		}
	}
}

void	cleanup_context(char *message, t_ctx *ctx)
{
	if (ctx->fd < 0)
		close(ctx->fd);
	if (ctx->points != NULL)
		free_points(ctx);
	if (ctx->mlx.img != NULL)
		mlx_destroy_image(ctx->mlx.mlx, ctx->mlx.img);
	if (ctx->mlx.win != NULL)
		mlx_destroy_window(ctx->mlx.mlx, ctx->mlx.win);
	if (ctx->mlx.mlx != NULL)
		mlx_destroy_display(ctx->mlx.mlx);
	if (message)
	{
		ft_putendl_fd(message, STDERR_FILENO);
		exit(1);
	}
	exit(0);
}
