/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:29 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/10 17:22:59 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
// # include <ft.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx_keycodes.h"

# define WINDOW_WIDTH			1920
# define WINDOW_HEIGHT			1080
# define IMAGE_WIDTH			1920
# define IMAGE_HEIGHT			1080
# define GRID_WIDTH				30
# define GRID_HEIGHT			40
# define GRID_ELEVATION			3
# define GRID_DENSITY_INVERSE	2

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

typedef struct s_ctx
{
	char	*filename;
	int		fd;
	int		width;
	int		height;
	float	affine_matrix[4][4];
	t_point	**points;
	t_point	base_point;
	t_point	start_point;
	t_mlx	mlx;
}	t_ctx;

void	fdf(char *filename);
void	TheInitializer(char *filename, t_ctx *ctx);
void	TheExaminer(t_ctx *ctx);
void	TheArchitect(t_ctx *ctx);
void	TheManifestor(t_ctx *ctx);
void	TheAnnihilator(char *message, t_ctx *ctx);

int		ft_abs(int n);
int		ft_max(int m, int n);
int		iroundf(float x);

#endif

//TheExaminerにオーバーフロー処理入れる。