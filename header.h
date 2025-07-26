#ifndef HEADER_H
# define HEADER_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define KEY_ESC	53
# define KEY_ENTER	36
# define KEY_SPACE	49
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_F		3
# define KEY_W		13
# define KEY_E		14
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_PLUS	41
# define KEY_MINUS	27

enum TransformType
{
	NUTRAL,
	TRANSLATE,
	ROTATE,
	SCALE
};

typedef struct s_param
{
	double	Tx;
	double	Ty;
	double	S;
	double	theta_x;
	double	theta_y;
	double	theta_z;
}	t_param;

typedef struct s_ctx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	t_param	param;
}	t_ctx;

void	init_param(t_param *param);
int		ctl_keypress(int keycode, void *param);
void	put_pixel_to_image(t_ctx ctx, int x, int y, unsigned int color, void (*f)(int, int, int *, int *, t_param));
void	clear_image(t_ctx ctx);
void	init_v(double v[4][1], int x, int y);
void	mat_mul(double A[4][4], double v[4][1]);
void	create_object(t_ctx ctx);
void	move_object(int x, int y, int *tx, int *ty, t_param param);
// void	translate_object(int x, int y, int *tx, int *ty, t_param param);
// void	rotate_object(int x, int y, int *tx, int *ty, t_param param);
// void	scale_object(int x, int y, int *tx, int *ty, t_param param);
void	init_go_to_origin_mat(double A[4][4], t_param param);
void	init_return_mat(double A[4][4], t_param param);
void	init_translate_mat(double A[4][4], t_param param);
void	init_rotatex_mat(double A[4][4], t_param param);
void	init_rotatey_mat(double A[4][4], t_param param);
void	init_rotatez_mat(double A[4][4], t_param param);
void	init_scale_mat(double A[4][4], t_param param);

#endif
