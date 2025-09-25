/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:51:23 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 11:57:47 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

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
	p.color = ((unsigned int)lroundf(dda.a) << 24)
		| ((unsigned int)lroundf(dda.r) << 16)
		| ((unsigned int)lroundf(dda.g) << 8)
		| (unsigned int)lroundf(dda.b);
	return (p);
}

void	draw_line_dda(t_mlx mlx, t_point p1, t_point p2)
{
	t_point	p;
	t_dda	dda;
	int		i;

	initiate_dda_param(&dda, p1, p2);
	if (dda.steps == 0)
	{
		put_pixel_to_image(mlx, p1);
		return ;
	}
	i = 0;
	while (i <= dda.steps)
	{
		p = construct_pixel(dda);
		put_pixel_to_image(mlx, p);
		dda.x += dda.x_inc;
		dda.y += dda.y_inc;
		dda.a += dda.a_inc;
		dda.r += dda.r_inc;
		dda.g += dda.g_inc;
		dda.b += dda.b_inc;
		i++;
	}
}

void	draw_grid(t_mlx mlx, t_grid grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid.rows)
	{
		j = 0;
		while (j < grid.cols)
		{
			if (j + 1 < grid.cols)
				draw_line_dda(mlx, grid.pts_cur[i][j], grid.pts_cur[i][j + 1]);
			if (i + 1 < grid.rows)
				draw_line_dda(mlx, grid.pts_cur[i][j], grid.pts_cur[i + 1][j]);
			j++;
		}
		i++;
	}
}

//ctxの内、height, width, pointsを使う
//ddaはローカルにしよう。