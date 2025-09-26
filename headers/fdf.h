/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:29 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 14:57:05 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
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

typedef struct s_trs
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
	t_mat4	to_origin;
	t_mat4	from_origin;
}	t_trs;

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
	int		cols;
	int		rows;
	t_point	**pts;
	t_point	**pts_cur;
	t_point	pt_base;
	t_point	pt_base_cur;
}	t_grid;

typedef struct s_render
{
	t_grid			grid;
	t_mlx			mlx;
	t_mat4			model;
	t_trs			trs;
	int				proj_type;
}	t_render;

int			fdf(const char *filename);
int			validate_file(const char *filename, int *out_cols, int *out_rows);
t_point		**create_points(int cols, int rows);
void		destroy_points(t_point **pts, int rows);
int			convert_file_to_points(const char *filename, t_grid *grid);
void		convert_newline_to_null(char *line);
void		free_tokens(char **tokens);
void		create_base_point(t_grid *grid);
void		start_rendering(t_grid *grid);
void		init_model(t_mat4 model, int proj_type);
void		init_transforms(t_trs *trs);
void		init_to_origin_transform(t_trs *trs);
void		init_from_origin_transform(t_trs *trs);
int			ft_abs(int n);
int			ft_max(int m, int n);
void		put_pixel_to_image(t_mlx mlx, t_point pt);
void		clean_image(t_mlx mlx);
void		fill_matrix4x4_zero(t_mat4 mat);
void		multiply_matrix4x4(const t_mat4 leftmat, const t_mat4 rightmat,
				t_mat4 res);
bool		is_digit(char c);
bool		is_hex_digit(char c);
bool		is_hex_unsigned_int(char *token);
bool		is_int(char *n, bool is_minus);
bool		is_octal_number(char *token);
void		update_model(t_mat4 model, t_trs trs, int keycode);
void		update_current_points(t_grid grid, t_mat4 model);
void		update_current_base_point(t_grid *grid, t_mat4 model);
void		draw_grid(t_mlx mlx, t_grid grid);
void		mat4_mul_vec4(t_mat4 model, float vec[4][1]);
void		update_to_from_origin(t_mat4 to_origin, t_mat4 from_origin,
				t_point pt_base_cur);
t_render	init_render(t_grid *grid, t_mlx mlx);
void		clean_up(t_render *render);

#endif
