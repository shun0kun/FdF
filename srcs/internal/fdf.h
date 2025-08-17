/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimotsukasashunsuke <shimotsukasashuns    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:29 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/17 11:33:40 by shimotsukas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include "../../include/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx_keycodes.h"
# include "config.h"

typedef float	t_mat4[4][4];

typedef struct s_dda
{
	int		steps;
	float	x;
	float	y;
	float	a;
	float	b;
	float	g;
	float	r;
	float	x_inc;
	float	y_inc;
	float	a_inc;
	float	b_inc;
	float	g_inc;
	float	r_inc;
}	t_dda;

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

typedef struct s_mats
{
	t_mat4	left;
	t_mat4	up;
	t_mat4	right;
	t_mat4	down;
	t_mat4	rotpx;
	t_mat4	rotmx;
	t_mat4	rotpy;
	t_mat4	rotmy;
	t_mat4	rotpz;
	t_mat4	rotmz;
	t_mat4	big;
	t_mat4	small;	
}	t_mats;

typedef struct s_ctx
{
	char	*filename;
	int		fd;
	int		width;
	int		height;
	t_mat4	affine_matrix;
	t_mats	mats;
	t_point	**points;
	t_point	base_point;
	t_point	start_point;
	t_mlx	mlx;
}	t_ctx;

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
