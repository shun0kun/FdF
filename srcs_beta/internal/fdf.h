/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimotsukasashunsuke <shimotsukasashuns    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:29 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/11 13:26:36 by shimotsukas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <get_next_line.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "mlx_keycodes.h"
# include "config.h"

typedef float	t_mat4[4][4];

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_point;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_mlx;

typedef struct s_transforms
{
	t_mat4	translate_left;
	t_mat4	translate_up;
	t_mat4	translate_right;
	t_mat4	translate_down;
	t_mat4	rotate_x_plus;
	t_mat4	rotate_x_minus;
	t_mat4	rotate_y_plus;
	t_mat4	rotate_y_minus;
	t_mat4	rotate_z_plus;
	t_mat4	rotate_z_minus;
	t_mat4	scale_up;
	t_mat4	scale_down;	
}	t_transforms;

typedef struct s_dda
{
	int		steps;
	float	x;
	float	y;
	float	r;
	float	g;
	float	b;
	float	a;
	float	x_inc;
	float	y_inc;
	float	r_inc;
	float	g_inc;
	float	b_inc;
	float	a_inc;
}	t_dda;

typedef struct s_grid
{
	t_point	**points;
	int		cols;
	int		rows;
	t_point	base_point;
}	t_grid;

typedef struct s_render
{
	t_grid			grid;
	t_mlx			mlx;
	t_mat4			model;
	t_transforms	transforms;
}	t_render;

void	fdf(char *filename);
void	TheInitializer(char *filename, t_ctx *ctx);
void	check_input_file(t_ctx *ctx);
void	TheArchitect(t_ctx *ctx);
void	TheManifestor(t_ctx *ctx);
void	TheAnnihilator(char *message, t_ctx *ctx);

int		ft_abs(int n);
int		ft_max(int m, int n);
int		iroundf(float x);

#endif

//TheExaminerにオーバーフロー処理入れる。
